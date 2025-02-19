#!/bin/bash

# source .env file
source .env

# check if $PROJECT_NAME exist otherwise fail
if [ -z "$PROJECT_NAME" ]; then
    echo "PROJECT_NAME is not set. Please set the PROJECT_NAME environment variable."
    exit 1
fi

# export project name as environment variable
export CMAKE_PROJECT_NAME=$PROJECT_NAME
export CMAKE_BUILD_TYPE=$BUILD_TYPE

# Create and move into the build directory
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# Run CMake to generate build files
cmake .. -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE 

# Build the project using Make
make -j$(nproc)

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Build successful! Running the executable..."
    ./$PROJECT_NAME  
else
    echo "Build failed."
    exit 1
fi
