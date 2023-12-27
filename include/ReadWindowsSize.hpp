#ifndef READWINDOWSSIZE_HPP
#define READWINDOWSSIZE_HPP

#include <windows.h>
#include <stdexcept>

class ReadWindowsSize
{
    public:
    ReadWindowsSize() = default;
    ~ReadWindowsSize() = default;

    void getWindowsSize();
    int getColumnNumbers();
    int getRowNumbers();
    void saveWindowsSize();

    private:
    int columns{0};
    int rows{0};
};

#endif