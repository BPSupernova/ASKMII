#include <Windows.h>
#include "Clock.h"


df::Clock::Clock() {
    SYSTEMTIME before;  
    GetSystemTime(&before);

    long int before_msec = (before.wDay * 24 * 60 * 60 * 1000000) 
        + (before.wHour * 60 * 60 * 1000000) 
        + (before.wMinute * 60 * 1000000) 
        + (before.wSecond * 1000000) 
        + (before.wMilliseconds * 1000);

    m_prev_time = before_msec; 
}

long int df::Clock::delta()
{
    SYSTEMTIME after;  
    GetSystemTime(&after);

    long int after_msec = (after.wDay * 24 * 60 * 60 * 1000000)
        + (after.wHour * 60 * 60 * 1000000)
        + (after.wMinute * 60 * 1000000)
        + (after.wSecond * 1000000)
        + (after.wMilliseconds * 1000);

    long int elapsed_time = (after_msec - m_prev_time);

    m_prev_time = after_msec;
    return elapsed_time;
}

long int df::Clock::split() const
{
    SYSTEMTIME after;
    GetSystemTime(&after);

    long int after_msec = (after.wDay * 24 * 60 * 60 * 1000000) 
        + (after.wHour * 60 * 60 * 1000000)
        + (after.wMinute * 60 * 1000000) 
        + (after.wSecond * 1000000) 
        + (after.wMilliseconds * 1000); 

    long int elapsed_time = (after_msec - m_prev_time); 

    return elapsed_time; 
}



