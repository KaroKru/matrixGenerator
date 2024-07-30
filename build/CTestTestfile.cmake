# CMake generated Testfile for 
# Source directory: C:/workspace/matrixGenerator
# Build directory: C:/workspace/matrixGenerator/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MatrixGeneratorTests "C:/workspace/matrixGenerator/build/matrixGeneratorTests.exe" "--gtest_output=xml:report.xml")
set_tests_properties(MatrixGeneratorTests PROPERTIES  _BACKTRACE_TRIPLES "C:/workspace/matrixGenerator/CMakeLists.txt;48;add_test;C:/workspace/matrixGenerator/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
