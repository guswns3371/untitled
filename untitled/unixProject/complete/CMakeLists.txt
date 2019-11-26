cmake_minimum_required(VERSION 3.15)
project(complete C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(complete
        display.c
        function.c
        main.h
        mcdonald.c)
