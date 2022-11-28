cmake_minimum_required(VERSION 2.8.3)
project(showProgress)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")

include_directories( include )

# yjz_lucky_boy
add_executable(show_progress src/test.cpp)