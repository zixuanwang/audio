PROJECT(audio)

cmake_minimum_required(VERSION 2.8)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	SET(CMAKE_CXX_FLAGS "-std=c++11")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# using Visual Studio C++
endif()

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET( LIBRARY_OUTPUT_PATH ${audio_BINARY_DIR}/../lib CACHE PATH
     "Output directory for the audio library" )
SET( EXECUTABLE_OUTPUT_PATH 
     ${audio_BINARY_DIR}/../bin CACHE PATH
     "Output directory for the audio executables" )

SUBDIRS(audio/lib)
SUBDIRS(audio/exe)
