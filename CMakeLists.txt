cmake_minimum_required(VERSION 3.19)
project(Cache)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(Cache
    src/decoder/AddressDecoder.h
    src/decoder/AddressDecoder.cpp
    src/settings/Settings.h
    src/system/cache/logic/line/Line.h
    src/system/cache/logic/line/Line.cpp
    src/system/cache/logic/set/Set.h
    src/system/cache/logic/set/Set.cpp
    src/system/cache/logic/Cache.h
    src/system/cache/logic/Cache.cpp
    src/system/cache/CacheController.h
    src/system/memory/DRAM.h
    src/system/shared/type/ElementType.h
    src/system/shared/Element.h
    src/system/shared/Element.cpp
    src/main.cpp
)