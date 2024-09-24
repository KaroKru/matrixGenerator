#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "TimeMeasurements.hpp"

class TimeMeasurementsTest : public ::testing::Test
{
    public:
    TimeMeasurements* timeMeasurements;

    void SetUp() override
    {
        timeMeasurements = new TimeMeasurements;
    }

    void TearDown() override
    {
        delete timeMeasurements;
    }
};

TEST_F(TimeMeasurementsTest, MeasureTimeTest) 
{
    timeMeasurements->runTask();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    timeMeasurements->endTask();

    double elapsedTime = timeMeasurements->measureTime();

    ASSERT_GE(elapsedTime, 0.01); 
}

TEST_F(TimeMeasurementsTest, TimeValueTest) 
{
    timeMeasurements->runTask();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    timeMeasurements->endTask();

    double timeValue = timeMeasurements->measureTime();

    ASSERT_GE(timeValue, 0.05); 
    ASSERT_LE(timeValue, 0.1); 
}
