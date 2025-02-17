cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)  
set(CMAKE_CXX_STANDARD_REQUIRED True)


# check if the CMAKE_PROJECT_NAME is set otherwise fail
if(NOT DEFINED CMAKE_PROJECT_NAME)
    message(FATAL_ERROR "CMAKE_PROJECT_NAME is not set")
    set(CMAKE_PROJECT_NAME "bichael_engine")
endif()

set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

project(${PROJECT_NAME} VERSION 0.0.0.0)

configure_file(version.h.in version.h)

find_package(SDL3 REQUIRED)

# Search for header files in src/ directory
include_directories(src)

# Search the src/ directory for .cpp and .c files and store paths in SOURCES
file(GLOB_RECURSE SOURCES "src/*.c*" main.cpp)

# Check if any source files were found
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in src/")
endif()



add_executable(${PROJECT_NAME} ${SOURCES})


# Target link libraries for sdl3  
target_link_libraries(${PROJECT_NAME} SDL3::SDL3)

target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}" "./" "/usr/local/include/*"
                           )

