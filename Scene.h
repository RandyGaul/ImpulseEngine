#ifndef SCENE_H
#define SCENE_H

#include "IEMath.h"

struct Scene
{
  Scene( f32 dt, uint32 iterations )
    : m_dt( dt )
    , m_iterations( iterations )
  {
  }

  void Step( void );
  void Render( void );
  Body *Add( Shape *shape, uint32 x, uint32 y );
  void Clear( void );

  f32 m_dt;
  uint32 m_iterations;
  std::vector<Body *> bodies;
  std::vector<Manifold> contacts;
};

#endif // SCENE_H