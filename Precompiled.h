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

#ifndef PRECOMPILED_H
#define PRECOMPILED_H

//If the compiler defines one of these items we can assume that it is windows running
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
    //so we will standardize on WIN32 for windows specific code
    #ifndef WIN32
    #define WIN32
    #endif
#endif

#ifdef WIN32
#include <Windows.h>
#endif

#undef min
#undef max

#include <cstring> // strlen, memcpy, etc.
#include <cstdlib> // exit
#include <cfloat>  // FLT_MAX
#include <vector>

#include "glut.h"
#include "IEMath.h"
#include "Clock.h"
#include "Render.h"
#include "Body.h"
#include "Shape.h"
#include "Collision.h"
#include "Manifold.h"
#include "Scene.h"

#endif // PRECOMPILED_H