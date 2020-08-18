# Declare cmake minimum required version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project name, version, language
project(BMMView VERSION 1.0.0 LANGUAGES CXX)

# Create target
add_executable(BMMView
    src/main.cpp
    src/ViewController.cpp
    src/ViewController.h)

# let CMake pick the appropriate compiler flags for cxx standard
target_compile_features(BMMView PRIVATE cxx_std_11)

find_package(BMMBusinessLogic REQUIRED)
find_package(BMMDataAccess REQUIRED)

target_link_libraries(BMMView PRIVATE BMMBusinessLogic::BMMBusinessLogic BMMDataAccess::BMMDataAccess)
