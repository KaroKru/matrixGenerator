add_library(matrixGenerator STATIC)

target_sources(matrixGenerator PRIVATE
    src/PrintRandomNumbers.cpp
    src/RandomGenerator.cpp
    src/ReadWindowsSize.cpp
    src/TimeMeasurements.cpp
)

target_include_directories(matrixGenerator PUBLIC
    "${CMAKE_SOURCE_DIR}/source/include"
)

add_executable(run WIN32
    src/main.cpp
)

target_link_libraries(run PRIVATE matrixGenerator)

if(ENABLE_CODE_COVERAGE)
    target_compile_options(matrixGenerator PRIVATE --coverage)
    target_link_libraries(matrixGenerator PRIVATE --coverage)
endif()
