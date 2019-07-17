#pragma once


class CPomodoro : public IPomodoro
{
public:
    ~CPomodoro() = default;

    static IPomodoro* Init();
    static void TimeProc(HWND, UINT, UINT_PTR, DWORD);
    static bool TurnOffTheScreen(); //lock active user screen
    static bool DetectUserLogin(); // detect user login

protected:
    DWORD Start(UINT time_in_min) override;
    DWORD Reset(UINT time_in_min) override;

private: //methods
    CPomodoro();
    bool StartTimer();

private: //varibles
    UINT m_timer;
    UINT m_big_break_intervals;
    UINT m_small_break_count;

    UINT_PTR m_id_event;
};

