#ifndef TIMEMEASUREMETS_HPP
#define TIMEMEASUREMETS_HPP

#include <iostream>
#include <chrono>

class TimeMeasurements
{
    public:
    TimeMeasurements() = default;
    ~TimeMeasurements() = default;

    void runTask();
    void endTask();
    double measureTime();
    double timeValue();

    private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    std::chrono::duration<double> totalTime;
};

#endif
