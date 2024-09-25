#include "PrintRandomNumbers.hpp"
#include <iomanip>
#include <fstream>
#include <stdexcept>

PrintRandomNumbers::PrintRandomNumbers(RandomGeneratorAbstract& random) : randomGenerator{random}
{}

void PrintRandomNumbers::printChoosenNumbers(unsigned int columns)
{
    randomGenerator.initialValues(minVal, maxVal);

    for (unsigned int counter = 0; counter < nrSamples; counter++)
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

void PrintRandomNumbers::readRandomNumbers(const std::string& filePath)
{
    std::ifstream readData(filePath);

    if (!readData.is_open())
    {
        throw std::runtime_error("Problem with opening the config file");
    }
    else
    {
        readData >> nrSamples >> minVal >> maxVal;
        std::cout << nrSamples << " " << minVal << " " << maxVal << std::endl;

        if (readData.fail()) 
        {
            throw std::runtime_error("Error reading values from config file");
        }

         readData.close();
    }
}