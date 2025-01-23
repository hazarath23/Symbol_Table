cmake_minimum_required(VERSION 3.10)
project(SymbolTableProject)

# Enable testing support
enable_testing()

# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add source files
set(SOURCES SymTable.cpp main.cpp)

# main executable
add_executable(symbol_table ${SOURCES})

target_link_libraries(symbol_table pthread)

# Add test executable
add_executable(run_tests symtable_test.cpp SymTable.cpp)
target_link_libraries(run_tests gtest gtest_main)
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)

# Add tests
add_test(NAME SymbolTableTest COMMAND run_tests)