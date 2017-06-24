cmake_minimum_required(VERSION 3.7)
project(PHONEBOOK)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        main.c
        supplement.c
        supplement.h
        )
add_executable(PHONEBOOK ${SOURCE_FILES})