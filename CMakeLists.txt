cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)  
set(CMAKE_CXX_STANDARD_REQUIRED True)


# check if the CMAKE_PROJECT_NAME is set otherwise fail
if(NOT DEFINED CMAKE_PROJECT_NAME)
    message(FATAL_ERROR "CMAKE_PROJECT_NAME is not set")
endif()

set(project_name "ENV{PROJECT_NAME}")

project(${CMAKE_PROJECT_NAME} VERSION 0.0.0.0)

configure_file(version.h.in version.h)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}" "./"
                           )

