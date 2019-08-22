cmake_minimum_required (VERSION 3.14.3)
project (cpp-singles)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -std=c++1z)

add_executable(abbreviation hr_abbreviation.cpp)
add_executable(regex_matcher regex_matcher.cpp)
