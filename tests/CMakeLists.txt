include(GoogleTest)
include(CTest)

add_executable(matrixGeneratorTests
    src/main.cpp
    src/PrintRandomNumbersTest.cpp
    src/RandomGeneratorTest.cpp
    src/ReadWindowsSizeTest.cpp 
    src/TimeMeasurementsTest.cpp
)

target_include_directories(matrixGeneratorTests PUBLIC
    "${gtest_SOURCE_DIR}/include"
    "${gmock_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/tests/include"
    "${CMAKE_SOURCE_DIR}/source/include"
)

target_link_libraries(matrixGeneratorTests PRIVATE
    matrixGenerator
    gtest_main
    gmock_main
)

if(ENABLE_CLANG_TIDY AND CLANG_TIDY_EXE)
    set_target_properties(matrixGeneratorTests PROPERTIES CXX_CLANG_TIDY "")
endif()

gtest_discover_tests(matrixGeneratorTests XML_OUTPUT_DIR ${CMAKE_BINARY_DIR}/tests/matrixGeneratorTests)

if(ENABLE_CODE_COVERAGE)
    target_compile_options(matrixGeneratorTests PRIVATE --coverage)
    target_link_libraries(matrixGeneratorTests PRIVATE --coverage)
endif()
