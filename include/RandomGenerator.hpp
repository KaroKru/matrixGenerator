#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <random>
#include "RandomGeneratorAbstract.hpp"

class RandomGenerator : public RandomGeneratorAbstract
{
    public:
    RandomGenerator() = default;
    ~RandomGenerator() = default;

    void initialValues(int minimum, int maximum) override;
    int randomNumber() override;
};

#endif // RANDOMGENERATOR_HPP