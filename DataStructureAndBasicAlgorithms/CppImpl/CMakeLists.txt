cmake_minimum_required(VERSION 3.12)
project(CppImpl)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/include test/include)

add_executable(test
        src/include/others_patrick.h
        src/include/sort_patrick.h
        src/include/linear_structure.h
        src/include/tree_structure.h
        src/include/priority_structure.h
        src/others_patrick.cpp
        src/sort_patrick.cpp
        src/linear_structure.cpp
        src/tree_structure.cpp
        src/priority_structure.cpp
        src/include/exception.h
        src/hash_map.cpp
        src/include/hash_map.h
        test/linear_structure_test.cpp
        test/include/linear_structure_test.h
        test/testmain.cpp test/others_test.cpp test/include/others_test.h)
