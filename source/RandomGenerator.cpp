#include "RandomGenerator.hpp"

void RandomGenerator::initialValues(int minimum, int maximum)
{
    minimumValue = static_cast<unsigned int> (minimum);
    maximumValue = static_cast<unsigned int> (maximum);
}

int RandomGenerator::randomNumber()
{
    std::random_device randomNum;
    std::mt19937 gen(randomNum());
    std::uniform_int_distribution<> dis(minimumValue, maximumValue-1);

    unsigned int number = dis(gen);

    return number;
}