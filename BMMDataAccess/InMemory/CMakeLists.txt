# Declare cmake minimum required version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project name, version, language
project(BMMDataAccess VERSION 1.0.0 DESCRIPTION "In memory data access lib" LANGUAGES CXX)

#Make sure that custom modules like FindRapidJSON are found
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

##############################################
# Declare dependencies
find_package(BMMBusinessLogic REQUIRED)

##############################################
# Create target and set properties
add_library(BMMDataAccess
    src/MovieRepository.cpp
    src/ShowRepository.cpp
)

# Set VERSION property for the project
set_target_properties(BMMDataAccess PROPERTIES VERSION ${PROJECT_VERSION})

# Set SOVERSION to a major number of VERSION
set_target_properties(BMMDataAccess PROPERTIES SOVERSION 1)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(BMMDataAccess::BMMDataAccess ALIAS BMMDataAccess)

# Set target properties
target_include_directories(BMMDataAccess
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:$<$<BOOL:$<TARGET_PROPERTY:BMMDataAccess_PRIVATE>>:${CMAKE_CURRENT_SOURCE_DIR}/src>>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set_property(TARGET BMMDataAccess PROPERTY BMMDataAccess_PRIVATE 1)

# Let CMake pick the appropriate compiler flags for cxx standard
target_compile_features(BMMDataAccess PRIVATE cxx_std_11)

target_link_libraries(BMMDataAccess PUBLIC BMMBusinessLogic::BMMBusinessLogic)

##############################################
# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/BMMDataAccess)

# Declare files to install
install(TARGETS BMMDataAccess
    EXPORT BMMDataAccess-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


#This is required so that the exported target has the name BMMDataAccess
set_target_properties(BMMDataAccess PROPERTIES EXPORT_NAME BMMDataAccess)


install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Export the targets to a script
install(EXPORT BMMDataAccess-targets
    FILE
        BMMDataAccessTargets.cmake
    NAMESPACE
        BMMDataAccess::
    DESTINATION
        ${INSTALL_CONFIGDIR}
)

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/BMMDataAccess.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/BMMDataAccessConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/BMMDataAccessConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/BMMDataAccessConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/BMMDataAccessConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

##############################################
# Exporting from the build tree
export(EXPORT BMMDataAccess-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/BMMDataAccessTargets.cmake
    NAMESPACE BMMDataAccess::)

#Register package in user's package registry
export(PACKAGE BMMDataAccess)

##############################################
# Add tests
enable_testing()
add_subdirectory(tests)

##############################################
# Generate project documentation with Doxigen
add_subdirectory(docs)
