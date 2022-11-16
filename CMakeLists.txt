cmake_minimum_required(VERSION 2.8)
project(Prova-intermedia-di-programmazione)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")

add_executable(Prova-intermedia-di-programmazione src/isbn/isbn.h src/isbn/isbn.cpp src/date/date.h src/date/date.cpp src/main.cpp src/book/book.cpp src/book/book.h)
