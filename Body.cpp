#include "Precompiled.h"

Body::Body( Shape *shape_, uint32 x, uint32 y )
  : shape( shape_->Clone( ) )
{
  shape->body = this;
  position.Set( (real)x, (real)y );
  velocity.Set( 0, 0 );
  angularVelocity = 0;
  torque = 0;
  orient = Random( -PI, PI );
  force.Set( 0, 0 );
  staticFriction = 0.5f;
  dynamicFriction = 0.3f;
  restitution = 0.2f;
  shape->Initialize( );
  r = Random( 0.2f, 1.0f );
  g = Random( 0.2f, 1.0f );
  b = Random( 0.2f, 1.0f );
}

void Body::SetOrient( real radians )
{
  orient = radians;
  shape->SetOrient( radians );
}
