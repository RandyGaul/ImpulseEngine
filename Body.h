#ifndef BODY_H
#define BODY_H

struct Shape;

struct Body
{
  Body( Shape *shape_, uint32 x, uint32 y );

  void ApplyForce( const Vec2& f )
  {
    force += f;
  }

  void ApplyImpulse( const Vec2& impulse, const Vec2& contactVector )
  {
    velocity += im * impulse;
    angularVelocity += iI * Cross( contactVector, impulse );
  }

  void SetStatic( void )
  {
    I = 0.0f;
    iI = 0.0f;
    m = 0.0f;
    im = 0.0f;
  }

  void SetOrient( real radians );

  Vec2 position;
  Vec2 velocity;

  real angularVelocity;
  real torque;
  real orient; // radians

  Vec2 force;
  Vec2 oldForce;

  // Set by shape
  real I;  // moment of inertia
  real iI; // inverse inertia
  real m;  // mass
  real im; // inverse masee

  real staticFriction;
  real dynamicFriction;
  real restitution;

  Shape *shape;

  real r, g, b;
};

#endif // BODY_H