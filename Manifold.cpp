#include "Precompiled.h"

void Manifold::Solve( void )
{
  Dispatch[A->shape->GetType( )][B->shape->GetType( )]( this, A, B );
}

void Manifold::Initialize( void )
{
  // Calculate average restitution
  e = std::min( A->restitution, B->restitution );

  // Calculate static and dynamic friction
  sf = std::sqrt( A->staticFriction * A->staticFriction );
  df = std::sqrt( A->dynamicFriction * A->dynamicFriction );

  for(uint32 i = 0; i < contact_count; ++i)
  {
    // Calculate radii from COM to contact
    Vec2 ra = contacts[i] - A->position;
    Vec2 rb = contacts[i] - B->position;

    Vec2 rv = B->velocity + Cross( B->angularVelocity, rb ) -
              A->velocity - Cross( A->angularVelocity, ra );


    // Determine if we should perform a resting collision or not
    // The idea is if the only thing moving this object is gravity,
    // then the collision should be performed without any restitution
    if(rv.LenSqr( ) < (dt * gravity).LenSqr( ) + EPSILON)
      e = 0.0f;
  }
}

void Manifold::ApplyImpulse( void )
{
  // Early out and positional correct if both objects have infinite mass
  if(Equal( A->im + B->im, 0 ))
  {
    InfiniteMassCorrection( );
    return;
  }

  for(uint32 i = 0; i < contact_count; ++i)
  {
    // Calculate radii from COM to contact
    Vec2 ra = contacts[i] - A->position;
    Vec2 rb = contacts[i] - B->position;

    // Relative velocity
    Vec2 rv = B->velocity + Cross( B->angularVelocity, rb ) -
              A->velocity - Cross( A->angularVelocity, ra );

    // Relative velocity along the normal
    real contactVel = Dot( rv, normal );

    // Do not resolve if velocities are separating
    if(contactVel > 0)
      return;

    real raCrossN = Cross( ra, normal );
    real rbCrossN = Cross( rb, normal );
    real invMassSum = A->im + B->im + Sqr( raCrossN ) * A->iI + Sqr( rbCrossN ) * B->iI;

    // Calculate impulse scalar
    real j = -(1.0f + e) * contactVel;
    j /= invMassSum;
    j /= (real)contact_count;

    // Apply impulse
    Vec2 impulse = normal * j;
    A->ApplyImpulse( -impulse, ra );
    B->ApplyImpulse(  impulse, rb );

    // Friction impulse
    rv = B->velocity + Cross( B->angularVelocity, rb ) -
         A->velocity - Cross( A->angularVelocity, ra );

    Vec2 t = rv - (normal * Dot( rv, normal ));
    t.Normalize( );

    // j tangent magnitude
    real jt = -Dot( rv, t );
    jt /= invMassSum;
    jt /= (real)contact_count;

    // Don't apply tiny friction impulses
    if(Equal( jt, 0.0f ))
      return;

    // Coulumb's law
    Vec2 tangentImpulse;
    if(std::abs( jt ) < j * sf)
      tangentImpulse = t * jt;
    else
      tangentImpulse = t * -j * df;

    // Apply friction impulse
    A->ApplyImpulse( -tangentImpulse, ra );
    B->ApplyImpulse(  tangentImpulse, rb );
  }
}

void Manifold::PositionalCorrection( void )
{
  const real k_slop = 0.05f; // Penetration allowance
  const real percent = 0.4f; // Penetration percentage to correct
  Vec2 correction = (std::max( penetration - k_slop, 0.0f ) / (A->im + B->im)) * normal * percent;
  A->position -= correction * A->im;
  B->position += correction * B->im;
}

void Manifold::InfiniteMassCorrection( void )
{
  A->velocity.Set( 0, 0 );
  B->velocity.Set( 0, 0 );
}
