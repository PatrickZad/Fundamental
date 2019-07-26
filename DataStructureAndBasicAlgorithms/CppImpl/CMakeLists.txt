cmake_minimum_required(VERSION 3.12)
project(CppImpl)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/include)

add_executable(test
        src/include/others_patrick.h
        src/include/sort_patrick.h
        src/include/basic_data_structure.h
        src/others_patrick.cpp
        src/sort_patrick.cpp
        src/basic_data_structure.cpp
        src/test.cpp
        )
