#ifndef PRINTRANDOMNUMBERS_HPP
#define PRINTRANDOMNUMBERS_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdexcept>
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

#endif