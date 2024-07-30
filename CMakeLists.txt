cmake_minimum_required(VERSION 3.10)

project(matrixGenerator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ustawienie flag do pokrycia kodu
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

include_directories(include)

# Dodajemy bibliotekę dla głównego kodu
add_library(matrixGenerator
    source/PrintRandomNumbers.cpp
    source/RandomGenerator.cpp
    source/ReadWindowsSize.cpp
    source/TimeMeasurements.cpp
)

# Dodajemy plik wykonywalny dla głównego programu jako aplikację GUI
add_executable(run WIN32
    source/main.cpp
)

# Linkowanie biblioteki do pliku wykonywalnego
target_link_libraries(run matrixGenerator)

# Konfiguracja GoogleTest i GoogleMock
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Dodajemy plik wykonywalny dla testów jako aplikację konsolową
add_executable(matrixGeneratorTests
    tests/PrintRandomNumbersTest.cpp
    tests/RandomGeneratorTest.cpp
    tests/ReadWindowsSizeTest.cpp 
    tests/TimeMeasurementsTest.cpp
)

target_link_libraries(matrixGeneratorTests gtest gmock gtest_main matrixGenerator)

# Dodajemy testy do CTest
add_test(NAME MatrixGeneratorTests COMMAND matrixGeneratorTests --gtest_output=xml:report.xml)
