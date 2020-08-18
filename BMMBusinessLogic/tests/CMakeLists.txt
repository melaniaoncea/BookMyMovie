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

add_executable(MovieTestSuite
               src/MovieTest.cpp)
target_link_libraries(MovieTestSuite
   PUBLIC gtest_main gmock_main BMMBusinessLogic::BMMBusinessLogic
   PRIVATE Threads::Threads)
set_property(TARGET MovieTestSuite PROPERTY BMMBusinessLogic_PRIVATE 1)
add_test(NAME MovieTestSuite COMMAND MovieTestSuite)

add_executable(SeatTestSuite
               src/SeatTest.cpp)
target_link_libraries(SeatTestSuite
   PUBLIC gtest_main gmock_main BMMBusinessLogic::BMMBusinessLogic
   PRIVATE Threads::Threads)
set_property(TARGET SeatTestSuite PROPERTY BMMBusinessLogic_PRIVATE 1)
add_test(NAME SeatTestSuite COMMAND SeatTestSuite)

add_executable(TeatherTestSuite
               src/TheaterTest.cpp)
target_link_libraries(TeatherTestSuite
   PUBLIC gtest_main gmock_main BMMBusinessLogic::BMMBusinessLogic
   PRIVATE Threads::Threads)
set_property(TARGET TeatherTestSuite PROPERTY BMMBusinessLogic_PRIVATE 1)
add_test(NAME TeatherTestSuite COMMAND TeatherTestSuite)


add_executable(BookingTestSuite
               src/BookingTest.cpp)
target_link_libraries(BookingTestSuite
   PUBLIC gtest_main gmock_main BMMBusinessLogic::BMMBusinessLogic
   PRIVATE Threads::Threads)
set_property(TARGET BookingTestSuite PROPERTY BMMBusinessLogic_PRIVATE 1)
add_test(NAME BookingTestSuite COMMAND BookingTestSuite)

add_executable(ShowTestSuite
               src/ShowTest.cpp)
target_link_libraries(ShowTestSuite
   PUBLIC gtest_main gmock_main BMMBusinessLogic::BMMBusinessLogic
   PRIVATE Threads::Threads)
set_property(TARGET ShowTestSuite PROPERTY BMMBusinessLogic_PRIVATE 1)
add_test(NAME ShowTestSuite COMMAND ShowTestSuite)

add_executable(MoviesProviderTestSuite
               src/MoviesProviderTest.cpp
               src/MocMovieRepository.h)
target_link_libraries(MoviesProviderTestSuite
   PUBLIC gtest_main gmock_main BMMBusinessLogic::BMMBusinessLogic
   PRIVATE Threads::Threads)
set_property(TARGET MoviesProviderTestSuite PROPERTY BMMBusinessLogic_PRIVATE 1)
add_test(NAME MoviesProviderTestSuite COMMAND MoviesProviderTestSuite)
