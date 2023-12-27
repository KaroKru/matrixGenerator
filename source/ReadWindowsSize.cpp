#include <iostream>
#include <fstream>
#include "ReadWindowsSize.hpp"

void ReadWindowsSize::getWindowsSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int ReadWindowsSize::getColumnNumbers()
{
    return columns;
}

int ReadWindowsSize::getRowNumbers()
{
    return rows;
}

void ReadWindowsSize::saveWindowsSize()
{
    std::ofstream windowsFile("windowsData.txt", std::ios::out);

    if (!windowsFile.is_open())
    {
        throw std::runtime_error("Problem with opening the windowsData file");
    }
    else
    {
        windowsFile << columns << " " << rows;
        windowsFile.close();
    }
}