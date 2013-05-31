#ifndef MANIFOLD_H
#define MANIFOLD_H

struct Body;

struct Manifold
{
  Manifold( Body *a, Body *b )
    : A( a )
    , B( b )
  {
  }

  void Solve( void );                 // Generate contact information
  void Initialize( void );            // Precalculations for impulse solving
  void ApplyImpulse( void );          // Solve impulse and apply
  void PositionalCorrection( void );  // Naive correction of positional penetration
  void Manifold::InfiniteMassCorrection( void );

  Body *A;
  Body *B;

  real penetration;     // Depth of penetration from collision
  Vec2 normal;          // From A to B
  Vec2 contacts[2];     // Points of contact during collision
  uint32 contact_count; // Number of contacts that occured during collision
  real e;               // Mixed restitution
  real df;              // Mixed dynamic friction
  real sf;              // Mixed static friction
};

#endif // MANIFOLD_H