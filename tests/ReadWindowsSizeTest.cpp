#include <gtest/gtest.h>
#include <fstream>
#include "ReadWindowsSize.hpp"
#include <string>

class ReadWindowsSizeTest : public ::testing::Test
{
protected:
    ReadWindowsSize* windowsSize;
   
    void SetUp() override
    {
        windowsSize = new ReadWindowsSize();
        windowsSize->getWindowsSize();
    }

    void TearDown() override
    {
        delete windowsSize;
    }
};

TEST_F(ReadWindowsSizeTest, CheckSavedDataTest)
{
    EXPECT_THROW({
        std::ofstream windowsFile("non_existing_directory/windowsData.txt", std::ios::out);
        if (!windowsFile.is_open())
        {
            throw std::runtime_error("Problem with opening the windowsData file");
        }
        else
        {
            windowsFile << "Columns: " << windowsSize->getColumnNumbers() << "\nRows: " << windowsSize->getRowNumbers();
            windowsFile.close();
        }
    }, std::runtime_error);
}

TEST_F(ReadWindowsSizeTest, CheckWindowsSizeTest)
{
    int columns = windowsSize->getColumnNumbers();
    int rows = windowsSize->getRowNumbers();

    EXPECT_GE(columns, -1);
    EXPECT_GE(rows, -1);
}

TEST_F(ReadWindowsSizeTest, CheckColumnValueTest)
{
    int columns = windowsSize->getColumnNumbers();
    EXPECT_GE(columns, -1);
}

TEST_F(ReadWindowsSizeTest, CheckRowValueTest)
{
    int rows = windowsSize->getRowNumbers();
    EXPECT_GE(rows, -1);
}

TEST_F(ReadWindowsSizeTest, CheckPossibilityToSaveWindowsSizeTest)
{
    windowsSize->getWindowsSize();
    windowsSize->saveWindowsSize();

    std::ifstream file("windowsData.txt");
    ASSERT_TRUE(file.is_open()) << "File windowsData.txt could not be opened";

    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "Columns: " + std::to_string(windowsSize->getColumnNumbers())) << "Mismatch in columns value";

    std::getline(file, line);
    EXPECT_EQ(line, "Rows: " + std::to_string(windowsSize->getRowNumbers())) << "Mismatch in rows value";

    file.close();
}
