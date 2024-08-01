# matrixGenerator
Matrix Generator is a project that displays changing values on the console from a range entered by the user. The displayed values mimic the visual effect known from the movie "Matrix".

## Features
- Generate random values within a specified range.
- Display values in a style reminiscent of the "Matrix" movie effects.
- Configurable settings for value range and update speed.

## Requirements
C++ compiler (e.g., GCC)
CMake 3.10 or higher

## How to displayed values
Modified values in source/config/values.txt file. 
First value is the number of samples
Second value is the min value of range
Third value is the max value of range. 

## How to use
Navigate to the proejct directory and build the project using CMake

```
cd matrixGenerator
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
./run.exe
```

How to run tests
```
ctest -V
```

## Result of usage
![Matrix Effect](/photo/result.png)