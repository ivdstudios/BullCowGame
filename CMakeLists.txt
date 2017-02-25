cmake_minimum_required(VERSION 3.6)
project(BullCowGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror=return-type")

set(SOURCE_FILES main.cpp FBullCowGame.cpp FBullCowGame.h)
add_executable(BullCowGame ${SOURCE_FILES})