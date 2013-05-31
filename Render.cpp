#include "Precompiled.h"

void RenderString( int32 x, int32 y, const char *s )
{
  glColor3f( 0.5f, 0.5f, 0.9f );
  glRasterPos2i( x, y );
  uint32 l = (uint32)std::strlen( s );
  for(uint32 i = 0; i < l; ++i)
    glutBitmapCharacter( GLUT_BITMAP_9_BY_15, *(s + i) );
}
