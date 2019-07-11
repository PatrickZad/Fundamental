cmake_minimum_required(VERSION 3.12)
project(CppLanguage)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/include)

add_executable(CppLanguage
        src/include/testFuncs.h
        src/testFuncs.cpp
        src/testmain.cpp
        CMakeLists.txt)
