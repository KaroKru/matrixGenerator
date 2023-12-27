#include <gtest/gtest.h>
#include "ReadWindowsSize.hpp"

class ReadWindowsSizeTest : public ::testing::Test
{
    protected:
    ReadWindowsSize* windowsSize;
   
    void SetUp()
    {
        windowsSize = new ReadWindowsSize();

        windowsSize -> getWindowsSize();
    }

    void TearDown()
    {
        delete windowsSize;
    }
};

TEST_F(ReadWindowsSizeTest, CheckSavedDataTest)
{
    EXPECT_THROW(windowsSize->saveWindowsSize(), std::runtime_error);
}

TEST_F(ReadWindowsSizeTest, CheckWindowsSizeTest)
{
    int columns = windowsSize->getColumnNumbers();
    int rows = windowsSize->getRowNumbers();

    EXPECT_GE(columns, 0);
    EXPECT_GE(rows, 0);
}

TEST_F(ReadWindowsSizeTest, CheckColumnValueTest)
{
    int columns = windowsSize->getColumnNumbers();

    EXPECT_EQ(columns, 0);
}

TEST_F(ReadWindowsSizeTest, CheckRowValueTest)
{
    int rows = windowsSize->getRowNumbers();

    EXPECT_EQ(rows, 0);
}