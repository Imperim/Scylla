cmake_minimum_required(VERSION 2.6)
project(Scylla)

# Enable debug symbols by default
# You can select a Release build from the command line using -DCMAKE_BUILD_TYPE=Release
if(CMAKE_BUILD_TYPE STREQUAL "")
	Set(CMAKE_BUILD_TYPE Debug)
endif()

# Installation paths
set(SCYLLA_BINARY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Bin)
set(SCYLLA_LIBRARY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Lib${LIB_SUFFIX})
set(SCYLLA_DATA_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Share/Scylla)
set(SCYLLA_CMAKE_MODULE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Share/CMake/Scylla)
set(SCYLLA_INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Include/Scylla)
set(SCYLLA_EXTERNAL_INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Include/ScyllaExternal)

set(SCYLLA_SOURCE_ROOT ${CMAKE_SOURCE_DIR}/Source/Scylla)
set(SCYLLA_DEPEND_ROOT ${CMAKE_SOURCE_DIR}/Source/ScyllaExternal)

# Access our source files
file(
	GLOB
	SCYLLA_SOURCE_FILES
	${SCYLLA_SOURCE_ROOT}/*
	${SCYLLA_SOURCE_ROOT}/Script/*
	${SCYLLA_SOURCE_ROOT}/Net/*
	${SCYLLA_SOURCE_ROOT}/Util/*
	${SCYLLA_SOURCE_ROOT}/Math/*
	${SCYLLA_SOURCE_ROOT}/Platform/*
	${SCYLLA_SOURCE_ROOT}/Graphics/*
)

# Access our depend source files
#file(
#	GLOB
#	SCYLLA_DEPEND_FILES
#	${SCYLLA_DEPEND_ROOT}/FastDelegate/*
#	${SCYLLA_DEPEND_ROOT}/GM/*
#	${SCYLLA_DEPEND_ROOT}/TinyThread/*
#	${SCYLLA_DEPEND_ROOT}/TinyXML2/*
#)

include_directories(
	# Scylla Source Directories
	${SCYLLA_SOURCE_ROOT}
	${SCYLLA_SOURCE_ROOT}/Script
	${SCYLLA_SOURCE_ROOT}/Net
	${SCYLLA_SOURCE_ROOT}/Util
	${SCYLLA_SOURCE_ROOT}/Math
	${SCYLLA_SOURCE_ROOT}/Platform
	${SCYLLA_SOURCE_ROOT}/Graphics

	# Scylla Dependency code
#	${SCYLLA_DEPEND_ROOT}/
#	${SCYLLA_DEPEND_ROOT}/FastDelegate
#	${SCYLLA_DEPEND_ROOT}/GM
#	${SCYLLA_DEPEND_ROOT}/TinyThread
#	${SCYLLA_DEPEND_ROOT}/TinyXML2
)

# Define sources and executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Bin)
add_executable(${PROJECT_NAME} ${SCYLLA_SOURCE_FILES}) #${SCYLLA_DEPEND_FILES})

# Detect and Add SDL2
# See FindSDL2.cmake for additional details and instructions
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/Modules)
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
	include_directories(${SDL2_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
endif()

# Install target
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/Bin)