cmake_minimum_required(VERSION 3.13)
project(cppHW)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER="/usr/bin/g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread -MMD -MP -DDEBUG -g")
set(EXT_LIBS pthread curses)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(cppHW main.cpp)

set(EXT_LIBS curses
        form
        curl
        menu
        jsoncpp
        pthread)

target_link_libraries(cppHW
        ${APP_MODULES} ${EXT_LIBS} )
