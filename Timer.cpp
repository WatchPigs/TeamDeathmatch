/**
 * @file Timer.cpp
 * @author Yexiang Zhou
 * @brief Timer implementation
 * @date 2024-06-02
 * 
 */

#include "Timer.h"

Timer Timer::NewTimer(Time time, std::function<void()> callback , bool start)
{
    return Timer(time, callback);
}

Time Timer::GetTime()
{
    return time_;
}

Timer::Timer(Time time, std::function<void()> callback) : time_(time), on_time_up_(callback)
{ 
}