#include "TimeMeasurements.hpp"


void TimeMeasurements::runTask()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void TimeMeasurements::endTask()
{
    endTime = std::chrono::high_resolution_clock::now();
}

double TimeMeasurements::measureTime()
{
    totalTime = endTime - startTime;

    return totalTime.count();  
}

double TimeMeasurements::timeValue()
{
    return totalTime.count();
}

