cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(DEBUG_ENABLE "Enable DEBUG" ON)
# if(DEBUG_ENABLE)
#   set(CMAKE_BUILD_TYPE Debug) 
#   set(DEBUG_STRING "foo")


configure_file(TutorialConfig.h.in TutorialConfig.h)


add_executable(Tutorial main.cpp)

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
