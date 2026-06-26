message(STATUS "CMAKE ВЕРСИИ 3.20")
cmake_minimum_required(VERSION 3.20)

message(STATUS "ИМЯПРОЕКТА Converter")
project(Conveter LANGUAGES CXX)
message(STATUS "УСТАНОВЛЕН СТАНДАРТ С++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "СОБРАНЫЙ ФАЙЛЫ")
set(SOURCES length.h 
            length.cpp
            temperature.h
            temperature.cpp
            weight.h
            weight.cpp
            main.cpp)
message(STATUS "СОЗДАЕМ converter")
add_executable(converter ${SOURCES})

