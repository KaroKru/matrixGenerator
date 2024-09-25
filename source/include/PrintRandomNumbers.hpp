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
    void readRandomNumbers(const std::string& filePath);
    void saveChoosenNumbers();

    private:
    std::vector<int> randomData;
    RandomGeneratorAbstract& randomGenerator;
    int minVal;
    int maxVal;
    int nrSamples;
};

#endif //PRINTRANDOMNUMBERS_HPP