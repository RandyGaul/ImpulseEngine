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

#include "Precompiled.h"

Body::Body( Shape *shape_, uint32 x, uint32 y )
  : shape( shape_->Clone( ) )
{
  shape->body = this;
  Initialize( );
  shape->Initialize( );
  position.Set( (real)x, (real)y );
}

Body::Body( PolygonShape *poly_ )
  : shape( poly_->Clone( ) )
{
  shape->body = this;
  Initialize( );

  //Set Body position such that original PolygonShape vertices are preserved
  //Assume each vertex has been shifted equivalently during initialization
  PolygonShape *polyShape = (PolygonShape*) shape;
  Vec2 firstPoint = polyShape->m_vertices[0];
  polyShape->Initialize( );
  Vec2 shift = firstPoint - polyShape->m_vertices[0];
  position.Set( (real)shift.x, (real)shift.y );
  SetOrient( 0 );
}

void Body::Initialize( void )
{
  velocity.Set( 0, 0 );
  angularVelocity = 0;
  torque = 0;
  orient = Random( -PI, PI );
  force.Set( 0, 0 );
  staticFriction = 0.5f;
  dynamicFriction = 0.3f;
  restitution = 0.2f;
  r = Random( 0.2f, 1.0f );
  g = Random( 0.2f, 1.0f );
  b = Random( 0.2f, 1.0f );
}

void Body::SetOrient( real radians )
{
  orient = radians;
  shape->SetOrient( radians );
}
