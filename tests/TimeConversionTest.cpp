#include <gtest/gtest.h>
#include "TimeConversion.hpp"

class TimeConversionTest : public ::testing::Test
{
    public:
    TimeMeasurements* timeMeasurements;
    TimeConversion* timeConversion;

    void SetUp() override
    {
        timeMeasurements = new TimeMeasurements;
        timeConversion = new TimeConversion(timeMeasurements);
    }

    void TearDown() override
    {
        delete timeConversion;
        delete timeMeasurements;
    }
};

TEST_F(TimeConversionTest, TakeTimeConversionTest)
{
    double checkTime = 3600 + 1800 + 45;

    timeMeasurements->timeValue();

    timeConversion->getTime();

    ASSERT_EQ(timeConversion->hours, 1);
    ASSERT_EQ(timeConversion->minutes, 30);
    ASSERT_EQ(timeConversion->seconds, 45);
}
