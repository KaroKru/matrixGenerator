#include "TimeConversion.hpp"

TimeConversion::TimeConversion(TimeMeasurements* time) : timeMeasurements{time}
{}

void TimeConversion::getTime()
{
   double total = timeMeasurements->timeValue();

   int totalTime = static_cast<int>(total);
   int milliseconds = static_cast<int>((total - totalTime) * 1000);

   
   hours = static_cast<uint8_t> (totalTime / 3600);
   totalTime -= hours*3600;

   minutes = static_cast<uint8_t> (totalTime / 60);
   totalTime -= minutes*60;

   seconds = static_cast<uint8_t> (totalTime);

   std::cout << "time " << hours << ":" << minutes << ":" << seconds << std::endl;
}
