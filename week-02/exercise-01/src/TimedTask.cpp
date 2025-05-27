#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "TimedTask.h"


namespace seneca{

    void TimedTask::startClock(){
        startTime = std::chrono::steady_clock::now();
    }
    void TimedTask::stopClock(){
        stopTime = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(std::string name){
        taskArr[numRecord].taskName = name;
        taskArr[numRecord].timeUnit = "nanoseconds";
        taskArr[numRecord].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
        ++numRecord;
    }

    std::ostream& operator<<(std::ostream& os, const TimedTask& tc){
        os << "Execution Times:\n--------------------------\n";

        for (int i = 0; i < tc.numRecord; i++){

        os <<  std::left << std::setw(21) << tc.taskArr[i].taskName << ' ';
        os << std::right << std::setw(13) << tc.taskArr[i].duration.count() << ' ';
        os << tc.taskArr[i].timeUnit << '\n';
        }
        os << "--------------------------\n";
        return os;
    }


}