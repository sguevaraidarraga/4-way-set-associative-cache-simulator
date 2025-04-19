cmake_minimum_required(VERSION 3.19)
project(Cache)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

add_executable(Cache
    src/Settings.h
    src/Line.h
    src/Line.cpp
    src/Set.h
    src/Set.cpp
    src/Cache.h
    src/Cache.cpp
    src/main.cpp
)