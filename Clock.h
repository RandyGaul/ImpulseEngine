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

#include <chrono>

typedef std::chrono::high_resolution_clock hr_clock;
typedef std::chrono::nanoseconds clock_freq;

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
  long long Elapsed( void );

  // Time between last Start and Stop calls
  long long Difference( void );

  // Get the current clock count
  long long Current( void );

private:
  hr_clock::time_point m_start;
  hr_clock::time_point m_stop;
  hr_clock::time_point m_current;
};
