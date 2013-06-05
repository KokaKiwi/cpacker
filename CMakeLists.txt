cmake_minimum_required(VERSION 2.8)

project(cpacker)

set(OFLAGS "-O2")

set(CMAKE_C_FLAGS "${OFLAGS}")
set(CMAKE_CXX_FLAGS "${OFLAGS} -std=c++11")

include_directories(include)
install(
    FILES
        include/cpacker.h
        include/cpacker-cpp.h
    DESTINATION include
)

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
    TARGETS cpacker
    DESTINATION lib
)

set(cpacker_cpp_SOURCES
    src/cpacker_cpp.cpp
    src/cpacker_cpp_put.cpp
    src/cpacker_cpp_pack.cpp
)
add_library(cpacker-cpp STATIC ${cpacker_SOURCES} ${cpacker_cpp_SOURCES})
install(
    TARGETS cpacker-cpp
    DESTINATION lib
)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOC_LANGUAGE "English" CACHE STRING "Documentation language")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif (DOXYGEN_FOUND)
