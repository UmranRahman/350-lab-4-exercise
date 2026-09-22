#ifndef TIMER_H
#define TIMER_H

// replace with yours from the prep...

#include <chrono>
#include <cstdint>

class Timer {
public:
    using Nanos =  std::chrono::nanoseconds;
    using Micros = std::chrono::microseconds;
    using Millis = std::chrono::milliseconds;
    using Seconds = std::chrono::seconds;
    using Minutes = std::chrono::minutes;
    using Hours = std::chrono::hours;

    Timer(){ //Default constructor
        restart();
    }
    void restart(){ //resets the state of the Timer as if it has only started timing now
        lastTime = std::chrono::steady_clock::now();
    }

    //both click and glance check for difference in time but only click updates the last time the timer was clicked
    template <typename T>
    uint64_t click(){
        auto now = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<T>(now - lastTime).count();
        lastTime = now;
        return diff;
    }

    template <typename T> uint64_t glance(){
        auto now = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<T>(now - lastTime).count();
        return diff;
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> lastTime;
};


#endif  // TIMER_H
