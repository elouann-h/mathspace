cmake_minimum_required(VERSION 3.23)
project(mathspace C)

set(CMAKE_C_STANDARD 17)

set(SOURCE_FILES main.c twodims.c)

add_executable(mathspace ${SOURCE_FILES})
