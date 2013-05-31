
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
LONGLONG Clock::Current( void )
{
  QueryPerformanceCounter( &m_current );
  return m_current.QuadPart;
}

void Clock::Query( LARGE_INTEGER& query )
{
  QueryPerformanceCounter( &query );
}
