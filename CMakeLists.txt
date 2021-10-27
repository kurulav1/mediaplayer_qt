project(media-player LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)

include(ExternalProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

ExternalProject_Add(
    taglib
    PREFIX ${CMAKE_BINARY_DIR}/vendor
    URL https://taglib.org/releases/taglib-1.11.1.tar.gz
    INSTALL_COMMAND make DESTDIR=${CMAKE_BINARY_DIR} install
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=
)

include_directories(BEFORE ./include)
link_directories(BEFORE ./lib)

add_subdirectory(src)
