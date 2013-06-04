/*
    Copyright (c) 2013 Randy Gaul http://RandyGaul.net

    This software is provided 'as-is', without any express or implied
    warranty. In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:
      1. The origin of this software must not be misrepresented; you must not
         claim that you wrote the original software. If you use this software
         in a product, an acknowledgment in the product documentation would be
         appreciated but is not required.
      2. Altered source versions must be plainly marked as such, and must not be
         misrepresented as being the original software.
      3. This notice may not be removed or altered from any source distribution.
*/

#ifndef MANIFOLD_H
#define MANIFOLD_H

struct Body;

// http://gamedev.tutsplus.com/tutorials/implementation/create-custom-2d-physics-engine-aabb-circle-impulse-resolution/
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
  void InfiniteMassCorrection( void );

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