# Declare cmake minimum required version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Declare a project
project(BMMBusinessLogic VERSION 1.0.0 DESCRIPTION "Library to book movie tickets" LANGUAGES CXX)


#Make sure that custom modules are found
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create target and set properties
add_library(BMMBusinessLogic
    src/Booking.cpp
    src/Movie.cpp
    src/Seat.cpp
    src/Show.cpp
    src/Theater.cpp
    src/BusinessLogicController.cpp
    src/MoviesProvider.cpp
    src/ShowProvider.cpp
    src/BookableSeat
)

# Set VERSION property for the project
set_target_properties(BMMBusinessLogic PROPERTIES VERSION ${PROJECT_VERSION})

# Set SOVERSION to a major number of VERSION
set_target_properties(BMMBusinessLogic PROPERTIES SOVERSION 1)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(BMMBusinessLogic::BMMBusinessLogic ALIAS BMMBusinessLogic)

# Include other directories
target_include_directories(BMMBusinessLogic
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:$<$<BOOL:$<TARGET_PROPERTY:BMMBusinessLogic_PRIVATE>>:${CMAKE_CURRENT_SOURCE_DIR}/src>>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set_property(TARGET BMMBusinessLogic PROPERTY BMMBusinessLogic_PRIVATE 1)

# Create install rule
include(GNUInstallDirs)

set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/BMMBusinessLogic)

# Declare files to install
install(TARGETS BMMBusinessLogic
    EXPORT BMMBusinessLogic-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


#This is required so that the exported target has the name BMMBusinessLogic
set_target_properties(BMMBusinessLogic PROPERTIES EXPORT_NAME BMMBusinessLogic)


install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Export the targets to a script
install(EXPORT BMMBusinessLogic-targets
    FILE
        BMMBusinessLogicTargets.cmake
    NAMESPACE
        BMMBusinessLogic::
    DESTINATION
        ${INSTALL_CONFIGDIR}
)

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/BMMBusinessLogic.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/BMMBusinessLogicConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/BMMBusinessLogicConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/BMMBusinessLogicConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/BMMBusinessLogicConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

##############################################
## Exporting from the build tree
export(EXPORT BMMBusinessLogic-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/BMMBusinessLogicTargets.cmake
    NAMESPACE BMMBusinessLogic::)

#Register package in user's package registry
export(PACKAGE BMMBusinessLogic)

##############################################
# Add tests
enable_testing()
add_subdirectory(tests)

##############################################
# Generate project documentation with Doxigen
add_subdirectory(docs)
