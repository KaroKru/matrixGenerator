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

    return std::chrono::duration<double>(totalTime).count();  
}

void TimeMeasurements::getTime()
{
   double timeValue = std::chrono::duration<double>(totalTime).count();
   std::cout << "Time in seconds: " << timeValue << " seconds" << std::endl;

   uint8_t hours = static_cast<uint8_t>(timeValue / 3600);
   timeValue -= hours * 3600;

   uint8_t minutes = static_cast<uint8_t>(timeValue / 60);
   timeValue -= minutes * 60;

   uint8_t seconds = static_cast<uint8_t>(timeValue);
   timeValue -= seconds;

   uint8_t milliseconds = static_cast<uint8_t>(timeValue * 1000);

   std::cout << "Formatted time: " << static_cast<int>(hours) << ":" 
   << static_cast<int>(minutes) << ":" << static_cast<int>(seconds) << 
   ":" << static_cast<int>(milliseconds) << std::endl;
}

