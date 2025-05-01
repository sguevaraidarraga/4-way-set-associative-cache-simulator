cmake_minimum_required(VERSION 3.19)
project(Cache)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cache
    src/cpu/CPU.cpp
    src/memory/cache/Line.cpp
    src/memory/cache/Set.cpp
    src/memory/cache/Cache.cpp
    src/memory/dram/DRAM.cpp
    src/memory/type/Element.cpp
    src/utils/AddressFieldsDecomposer.cpp
    src/utils/Constants.cpp
    src/utils/FileManager.cpp
    src/utils/Generator.cpp
    src/utils/Logger.cpp
    src/app.cpp
    src/main.cpp
)

target_include_directories(Cache PRIVATE ${CMAKE_SOURCE_DIR}/include)