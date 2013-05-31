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