/**
 * @file Timer.h
 * @author Yexiang Zhou
 * @brief Timer declaration
 * @date 2024-06-02
 * 
 */

#pragma once
#include "Time.h"
#include <functional>
#include <set>

/**
 * @brief for countdown, and scheduling an action to be performed after a delay
 *        It's provided by common game engines, so only the key data and functions related to our game mode are listed
 * 
 */
class Timer
{
public:
    /**
     * @brief static factory method, for creating a new timer
     * 
     * @param time      total duration
     * @param callback  function to be called when time is up
     * @param start     whether start counting now
     * @return Timer    Timer object
     */
    static Timer NewTimer(Time time, std::function<void()> callback , bool start);

    /**
     * @brief (Unimplemented) create an timer and start,
     *        can be maintained by a static container and destroyed when the time is up.
     *        Implementation is not presented here.
     * 
     * @param time      total duration
     * @param callback  function to be called when time is up
     */
    static void DelayCall(Time time, std::function<void()> callback);

    /**
     * @brief get current time left
     * 
     * @return Time 
     */
    Time GetTime();

    /**
     * @brief (Unimplemented) start counting. The implementation is not presented as it supported by common game engines
     * 
     */
    void Start();
private:

    /**
     * @brief Construct a new Timer object, make it private so cannot be called from outside
     * 
     * @param time      total duration
     * @param callback  function to be called when time is up
     */
    Timer(Time time, std::function<void()> callback);

    Time                    time_;              //current time left
    std::function<void()>   on_time_up_;        //function to be called when time is up
};
