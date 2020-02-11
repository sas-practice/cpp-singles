cmake_minimum_required(VERSION 3.14.3)
project(cpp-singles)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -std=c++1z)

add_executable(abbreviation hr_abbreviation.cpp)
add_executable(coin_change coin_change.cpp)
add_executable(regex_matcher regex_matcher.cpp)
add_executable(eat_gems eat_gems.cpp)
add_executable(testbed testbed.cpp)

add_executable(bin_src binary_search/bin_src.cpp)
add_executable(bin_stride binary_search/bin_stride.cpp)
add_executable(find_first binary_search/find_first.cpp)
add_executable(find_last binary_search/find_last.cpp)
