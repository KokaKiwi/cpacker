cmake_minimum_required(VERSION 2.8)

project(cpacker)

include_directories(include)

set(cpacker_SOURCES
    src/cpacker.c
    src/cpacker_put.c
    src/cpacker_get.c
    src/cpacker_read.c
    src/cpacker_pack.c
    src/cpacker_unpack.c
)

add_library(cpacker STATIC ${cpacker_SOURCES})

install(
    FILES include/cpacker.h
    DESTINATION include
)
install(
    TARGETS cpacker
    DESTINATION lib
)
