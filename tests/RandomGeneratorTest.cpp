#include <gtest/gtest.h>
#include "RandomGenerator.hpp"

class RandomGeneratorTest : public ::testing::Test
{
    public:
    RandomGenerator* randomGenerator;


    void SetUp()
    {
        randomGenerator = new RandomGenerator;
    }

    void TearDown()
    {
        delete randomGenerator;
    }
};

TEST_F(RandomGeneratorTest, GenerateRandomNumbersTest)
{
    int initMinVal = 10;
    int initMaxVal = 20;

    randomGenerator->initialValues(initMinVal, initMaxVal);

    int randomNumber = randomGenerator->randomNumber();

    int chooseNumbers = 100;

    for (int i = 0; i < chooseNumbers; i++)
    {
        EXPECT_GE(randomNumber, initMinVal);
        EXPECT_LT(randomNumber, initMaxVal);
    }
}