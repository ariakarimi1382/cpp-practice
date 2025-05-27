
#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <string>
#include <chrono>

namespace seneca{
      struct Task {
        std::string taskName{};
        std::string timeUnit{};
        std::chrono::steady_clock::duration duration{};
        };
    class TimedTask {
        int numRecord{};
        std::chrono::steady_clock::time_point startTime{};
        std::chrono::steady_clock::time_point stopTime{};
        Task taskArr[10];
    public:
        TimedTask(){};
        ~TimedTask(){};
        TimedTask(const TimedTask&);
        TimedTask(TimedTask&&);
        TimedTask& operator=(const TimedTask&);
        TimedTask& operator=(TimedTask&&);
        void startClock();
        void stopClock();
        void addTask(std::string);
        friend std::ostream& operator<<(std::ostream&, const TimedTask&);
    };
}


#endif