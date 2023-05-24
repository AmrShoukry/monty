cmake_minimum_required(VERSION 3.25)
project(monty C)

set(CMAKE_C_STANDARD 90)

add_executable(monty main.c mandatory.h mandatory.c utilities.h datastructures.h utilities.c memoryManagement.c)
