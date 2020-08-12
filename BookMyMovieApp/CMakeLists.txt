cmake_minimum_required(VERSION 3.11)

# Project name, version, language
project(BookMyMovieApp VERSION 1.0.0 LANGUAGES CXX)

# Include library for tests
#include(ctest)

# Useful CMake options
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run some settings automatically if needed
# tried to create shared libraries out of the modules
if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif(WIN32)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download GoogleTest as part of the build's configure step
# Declare content details
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

# Populate the content
FetchContent_MakeAvailable(googletest)



# Specify the output directory as an include directory
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR})

# Add the list of subdirectories
add_subdirectory(Tests/)
#add_subdirectory(DefModule/)

set(SOURCES main.cpp)

# Create executable
set(MyProjectBin_src ${PROJECT_SOURCE_DIR}/main.cpp)
add_executable(BookMyMovieApp ${MyProjectBin_src})
