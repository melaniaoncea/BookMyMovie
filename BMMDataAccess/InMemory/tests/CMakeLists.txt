# Declare cmake minimum required version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

add_definitions(-DGTEST_LANGUAGE_CXX11)

# Find 3rd party dependencies
find_package(Threads REQUIRED)
find_package(GTest QUIET)

if(NOT GTEST_FOUND)
  # Download and unpack googletest at build time
  # but only if needed!
  configure_file(${CMAKE_SOURCE_DIR}/cmake/GoogleTest-CMakeLists.txt.in
    ${CMAKE_BINARY_DIR}/lib-googletest/googletest-download/CMakeLists.txt)
  execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/lib-googletest/googletest-download)
  if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
  endif()

  execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/lib-googletest/googletest-download)
  if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
  endif()

  # Add googletest directly to our build. This defines
  # the gtest and gtest_main targets.
  add_subdirectory(${CMAKE_BINARY_DIR}/lib-googletest/googletest-src
    ${CMAKE_BINARY_DIR}/lib-googletest/googletest-build
    EXCLUDE_FROM_ALL)
endif()

add_executable(MovieRepositoryTestSuite
               src/MovieRepositoryTest.cpp)
target_link_libraries(MovieRepositoryTestSuite
   PUBLIC gtest_main gmock_main BMMDataAccess::BMMDataAccess
   PRIVATE Threads::Threads)
set_property(TARGET MovieRepositoryTestSuite PROPERTY BMMDataAccess_PRIVATE 1)
add_test(NAME MovieRepositoryTestSuite COMMAND MovieRepositoryTestSuite)

