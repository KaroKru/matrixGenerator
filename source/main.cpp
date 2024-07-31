#include "ReadWindowsSize.hpp"
#include "RandomGenerator.hpp"
#include "PrintRandomNumbers.hpp"
#include "TimeMeasurements.hpp"

int main(int argc, char* argv[])
{
    TimeMeasurements time;
    time.runTask();

    ReadWindowsSize windowsSize;
    windowsSize.getWindowsSize();

    try
    {
        windowsSize.saveWindowsSize();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Problem: " << e.what() << std::endl;
    }
    
    unsigned int columnsNumber = static_cast<unsigned int> (windowsSize.getColumnNumbers());

    RandomGenerator random;
    PrintRandomNumbers print{random};

    try
    {
        print.readRandomNumbers();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Problem: " << e.what() << std::endl;
    }

    print.printChoosenNumbers(columnsNumber);

    try
    {
        print.saveChoosenNumbers();
    }
    catch (const std::runtime_error& c)
    {
        std::cout << "Problem: " << c.what() << std::endl;
    }

    time.endTask();

    std::cout << std::endl;

    time.measureTime();

    time.getTime();

    return 0;
}