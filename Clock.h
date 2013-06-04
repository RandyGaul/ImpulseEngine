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

#ifndef CLOCK_H
#define CLOCK_H

#ifndef WIN32
#include <chrono>

typedef std::chrono::high_resolution_clock hr_clock;
typedef std::chrono::nanoseconds clock_freq;
#endif

class Clock
{
public:
  Clock( );
  ~Clock( );

  // Records current time in start variable
  void Start( void );

  // Records current time in stop variable
  void Stop( void );

  // Time since last Start call
#ifdef WIN32
  f32 Elapsed( void );
#else
  long long Elapsed( void );
#endif

  // Time between last Start and Stop calls
#ifdef WIN32
  f32 Difference( void );
#else
  long long Difference( void );
#endif

  // Get the current clock count
#ifdef WIN32
  LONGLONG Current( void );
#else
  long long Current( void );
#endif

#ifdef WIN32
private:
  LARGE_INTEGER m_freq;
  LARGE_INTEGER m_start, m_stop, m_current;

  void Query( LARGE_INTEGER& query );
#else
private:
  hr_clock::time_point m_start;
  hr_clock::time_point m_stop;
  hr_clock::time_point m_current;
#endif
};

#endif // CLOCK_H