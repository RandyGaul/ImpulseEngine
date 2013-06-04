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

Clock::Clock( )
{
#ifdef WIN32
  // Assign to a single processor
  SetThreadAffinityMask( GetCurrentThread( ), 1 );

  // Grab frequency of this processor
  QueryPerformanceFrequency( &m_freq );
#endif

  // Setup initial times
  Start( );
  Stop( );
}

Clock::~Clock( )
{
}

// Records current time in start variable
void Clock::Start( void )
{
#ifdef WIN32
  QueryPerformanceCounter( &m_start );
#else
  m_start = hr_clock::now();
#endif
}

// Records current time in stop variable
void Clock::Stop( void )
{
#ifdef WIN32
  QueryPerformanceCounter( &m_stop );
#else
  m_stop = hr_clock::now();
#endif
}

// Get current time from previous Start call
#ifdef WIN32
  f32 Clock::Elapsed( void )
#else
  long long Clock::Elapsed( void )
#endif
{
#ifdef WIN32
  QueryPerformanceCounter( &m_current );
  return (m_current.QuadPart - m_start.QuadPart) / (float)m_freq.QuadPart;
#else
  m_current = hr_clock::now();
  return std::chrono::duration_cast<clock_freq>(m_current - m_start).count();
#endif
}

// Time between last Start and Stop calls
#ifdef WIN32
  f32 Clock::Difference( void )
#else
  long long Clock::Difference( void )
#endif
{
#ifdef WIN32
  return (m_stop.QuadPart - m_start.QuadPart) / (float)m_freq.QuadPart;
#else
  return std::chrono::duration_cast<clock_freq>(m_stop - m_start).count();
#endif
}

// Get the current clock count
#ifdef WIN32
  LONGLONG Clock::Current( void )
#else
  long long Clock::Current( void )
#endif
{
#ifdef WIN32
  QueryPerformanceCounter( &m_current );
  return m_current.QuadPart;
#else
  m_current = hr_clock::now();
  return std::chrono::duration_cast<clock_freq>(m_current.time_since_epoch()).count();
#endif
}