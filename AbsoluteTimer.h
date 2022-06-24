/*
    the idea of half period come from MIT
    multiThread package is useful to check AbsoluteTimer,
    Example: bianLib/multiThread/src/Loop.cpp
*/

#ifndef ABSOLUTETIMER_H
#define ABSOLUTETIMER_H

#include <sys/timerfd.h>
#include <stdint.h>

/*
waitTimeS = 0 means do not care time out
*/
class AbsoluteTimer{
public:
    AbsoluteTimer(double waitTimeS);
    ~AbsoluteTimer();
    void start();
    bool wait();
private:
    void _updateWaitTime(double waitTimeS);
    int _timerFd;
    uint64_t _missed;
    double _waitTime;
    double _startTime;
    double _leftTime;
    double _nextWaitTime;
    itimerspec _timerSpec;
};

#endif  // ABSOLUTETIMER_H