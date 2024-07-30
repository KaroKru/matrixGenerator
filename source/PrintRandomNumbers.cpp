#include "PrintRandomNumbers.hpp"
#include <iomanip>
#include <fstream>
#include <stdexcept>

PrintRandomNumbers::PrintRandomNumbers(RandomGeneratorAbstract& random) : randomGenerator{random}
{}

void PrintRandomNumbers::printChoosenNumbers(unsigned int columns)
{
    int maximumCounterValue{5000};

    randomGenerator.initialValues(0, 10);

    for (unsigned int counter = 0; counter < maximumCounterValue; counter++)
    {
        randomData.push_back(randomGenerator.randomNumber());

        std::cout << std::setw(5) << randomGenerator.randomNumber();

        if ((counter + 1) % columns == 0)
        {
            std::cout << std::endl;
        }
    }
}

void PrintRandomNumbers::saveChoosenNumbers()
{
    std::ofstream randomNumbers("randomData.txt", std::ios::out);

    if (!randomNumbers.is_open())
    {
        throw std::runtime_error("Problem with opening the randomData file");
    }
    else
    {
        for (const auto i : randomData)
        {
            randomNumbers << i << std::endl;
        }

        randomNumbers.close();
    }
}