cmake_minimum_required(VERSION 3.20)

project(Conveter LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(SOURCES length.h 
            length.cpp
            temperature.h
            temperature.cpp
            weight.h
            weight.cpp
            main.cpp)

add_executable(converter ${SOURCES})

