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
  f32 Elapsed( void );

  // Time between last Start and Stop calls
  f32 Difference( void );

  // Get the current clock count
  LONGLONG Current( void );

private:
  LARGE_INTEGER m_freq;
  LARGE_INTEGER m_start, m_stop, m_current;

  friend class Timer;
  // Callbacks for Timer
  void Query( LARGE_INTEGER& query );
};