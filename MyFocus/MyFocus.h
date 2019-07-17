#pragma once

#include "resource.h"
#include "memory"

#define DEFAULT_WAIT_TIME_MIN   20
#define MIN_TO_MILI_SEC(x)      ((x)*60000)

class CPomodoro;

class IPomodoro {
public:
    static bool Init() { g_Pomo.reset(CPomodoro::Init()); }
    virtual DWORD Start(UINT time_in_min) = 0;
    virtual DWORD Reset(UINT time_in_min) = 0;
};

std::unique_ptr<IPomodoro> g_Pomo;
