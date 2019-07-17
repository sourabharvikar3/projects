#include <Windows.h>

//#include <memory>

#include "CPomodoro.h"
#include "MyFocus.h"

// let create a object of pomodor
extern std::unique_ptr<IPomodoro> g_Pomo;

CPomodoro::CPomodoro() { m_id_event = GetCurrentProcessId(); }

DWORD CPomodoro::Start(UINT time_in_min) {
  m_timer = MIN_TO_MILI_SEC(time_in_min);
  if (m_timer == 0) {
    m_timer = MIN_TO_MILI_SEC(DEFAULT_WAIT_TIME_MIN);
  }

  //start the timer
  if (!StartTimer()) {
      return ::GetLastError();
  }

  return 0;
}

DWORD CPomodoro::Reset(UINT time_in_min) {
  if (m_timer == 0) {
    m_timer = MIN_TO_MILI_SEC(time_in_min);
    if (m_timer == 0) {
      m_timer = MIN_TO_MILI_SEC(DEFAULT_WAIT_TIME_MIN);
    }
  }

  //start the timer
  if (!StartTimer()) {
      return ::GetLastError();
  }

  return 0;
}

IPomodoro* CPomodoro::Init() 
{
    return (new CPomodoro);
}

void CPomodoro::TimeProc(HWND, UINT, UINT_PTR, DWORD) {
  // timer has been expired

  // lets pop the message and lock the screen

  // we have permission from the user
  TurnOffTheScreen();
}

bool CPomodoro::TurnOffTheScreen() { return false; }

bool CPomodoro::DetectUserLogin()
{
    return false;
}

bool CPomodoro::StartTimer() {
  // Create a timer based on input time
  // if input time is ZERO then by default we'll wait 20 min
  SetTimer(nullptr, m_id_event, m_timer, CPomodoro::TimeProc);
  return false;
}
