#include "ReadWindowsSize.hpp"
#include <iostream>
#include <fstream>

void ReadWindowsSize::getWindowsSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    else
    {
        std::cerr << "Error reading console size\n";
        columns = -1;
        rows = -1;
    }
}

int ReadWindowsSize::getColumnNumbers() const
{
    return columns;
}

int ReadWindowsSize::getRowNumbers() const
{
    return rows;
}

void ReadWindowsSize::saveWindowsSize() const
{
    std::ofstream windowsFile("windowsData.txt", std::ios::out);

    if (!windowsFile.is_open())
    {
        std::cerr << "Problem with opening the windowsData file" << std::endl;
        throw std::runtime_error("Problem with opening the windowsData file");
    }
    else
    {
        windowsFile << "Columns: " << columns << "\nRows: " << rows;
        std::cerr << "Saving columns: " << columns << " and rows: " << rows << std::endl;
        windowsFile.close();
    }
}

