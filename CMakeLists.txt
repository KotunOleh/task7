cmake_minimum_required(VERSION 3.15)
project(task7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task7 
    src/main.cpp
    src/randomcontroller.cpp
    src/tools.cpp
)

target_include_directories(task7 PUBLIC include)