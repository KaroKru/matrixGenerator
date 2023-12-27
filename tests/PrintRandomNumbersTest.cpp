#include <gtest/gtest.h>
#include <fstream>
#include "PrintRandomNumbers.hpp"
#include "RandomGenerator.hpp"

class PrintRandomNumbersTest : public ::testing::Test
{
    public:
    RandomGenerator* randomGenerator;
    PrintRandomNumbers* printRandomNumbers;

    void SetUp()
    {
        randomGenerator = new RandomGenerator;   
        printRandomNumbers = new PrintRandomNumbers(*randomGenerator);
    }

    void TearDown()
    {
        delete printRandomNumbers;
        delete randomGenerator;
    }
};

TEST_F(PrintRandomNumbersTest, PrintNumbersTest)
{
    unsigned int columnsNumber = 100;
    printRandomNumbers->printChoosenNumbers(columnsNumber);

    ASSERT_NO_THROW(printRandomNumbers->saveChoosenNumbers());

    std::ifstream randomNumbersFile("randomData.txt");
    std::string line;
    std::vector<int> savedNumbers;

    while (std::getline(randomNumbersFile, line)) {
        savedNumbers.push_back(std::stoi(line));
    }

    ASSERT_FALSE(savedNumbers.empty());
}
