cmake_minimum_required(VERSION 3.10)

project(matrixGenerator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(matrixGenerator
    source/main.cpp
    source/PrintRandomNumbers.cpp
    source/RandomGenerator.cpp
    source/ReadWindowsSize.cpp
    source/TimeMeasurements.cpp
    source/TimeConversion.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0 
)
FetchContent_MakeAvailable(googletest)

add_executable(tests
    tests/PrintRandomNumbersTest.cpp
    tests/RandomGeneratorTest.cpp
    tests/ReadWindowsSizeTest.cpp
    tests/TimeMeasurementsTest.cpp 
    tests/TimeConversionTest.cpp
)

target_link_libraries(tests gtest gmock)

target_link_libraries(tests matrixGenerator)

enable_testing()
add_test(NAME AllTests COMMAND tests)



