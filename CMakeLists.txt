cmake_minimum_required(VERSION 3.20)
project(lua_wyhash C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")

include_directories(F:/conda/Library/include ./dep)
link_directories("F:\\conda\\Library\\lib" F:/conda/Library/bin)

#file(GLOB SOURCES  ./dep/src/*.c)
#message(${SOURCES})

add_library(wyhash SHARED src/lwyhash.c)
target_link_libraries(wyhash lua)

set_target_properties(wyhash PROPERTIES OUTPUT_NAME wyhash)

