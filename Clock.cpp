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
  // Assign to a single processor
  SetThreadAffinityMask( GetCurrentThread( ), 1 );

  // Grab frequency of this processor
  QueryPerformanceFrequency( &m_freq );

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
  QueryPerformanceCounter( &m_start );
}

// Records current time in stop variable
void Clock::Stop( void )
{
  QueryPerformanceCounter( &m_stop );
}

// Get current time from previous Start call
f32 Clock::Elapsed( void )
{
  QueryPerformanceCounter( &m_current );
  return (m_current.QuadPart - m_start.QuadPart) / (float)m_freq.QuadPart;
}

// Time between last Start and Stop calls
f32 Clock::Difference( void )
{
  return (m_stop.QuadPart - m_start.QuadPart) / (float)m_freq.QuadPart;
}

// Get the current clock count
int64_t Clock::Current( void )
{
  QueryPerformanceCounter( &m_current );
  return m_current.QuadPart;
}

void Clock::Query( int64_t& query )
{
  QueryPerformanceCounter( &query );
}
