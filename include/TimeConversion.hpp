#ifndef TIMECONVERSION_HPP
#define TIMECONVERSION_HPP

#include "TimeMeasurements.hpp"

class TimeConversion
{
    public:
    TimeConversion(TimeMeasurements* time);
    TimeConversion() = default;
    ~TimeConversion() = default;

    void getTime();
    uint8_t hours{0};
    uint8_t minutes{0};
    uint8_t seconds{0};

    private:
    TimeMeasurements* timeMeasurements;
};

#endif