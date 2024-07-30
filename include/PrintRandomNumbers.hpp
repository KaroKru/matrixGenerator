#ifndef PRINTRANDOMNUMBERS_HPP
#define PRINTRANDOMNUMBERS_HPP

#include <iostream>
#include <vector>
#include "RandomGenerator.hpp"


class PrintRandomNumbers 
{
    public:
    PrintRandomNumbers(RandomGeneratorAbstract& random);
    ~PrintRandomNumbers() = default;

    void printChoosenNumbers(unsigned int columns);
    void saveChoosenNumbers();

    private:
    std::vector<int> randomData;
    RandomGeneratorAbstract& randomGenerator;
};

#endif //PRINTRANDOMNUMBERS_HPP