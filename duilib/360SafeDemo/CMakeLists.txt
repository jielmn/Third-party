#Cmake file for 360SafeDemo
#Author: Qi Gao(monkgau@gmail.com)
#Date: 2012/9/17

set(source_files 360safe.cpp stdafx.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB_RECURSE  ALL_H_FILE *.h )
add_executable(360safedemo ${source_files} ${ALL_H_FILE})

set_target_properties(360safedemo PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
add_dependencies(360safedemo duilib)

target_link_libraries( 360safedemo debug ${PROJECT_BINARY_DIR}/lib/debug/duilibd.lib)
target_link_libraries( 360safedemo optimized duilib)

add_custom_command(TARGET 360safedemo POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/bin/skin/360SafeRes.zip ${PROJECT_BINARY_DIR}/bin/Debug/skin/360SafeRes.zip COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/bin/skin/360SafeRes.zip ${PROJECT_BINARY_DIR}/bin/Release/skin/360SafeRes.zip )

#add_custom_command(TARGET 360safedemo POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${PROJECT_BINARY_DIR}/bin/360safedemo.exe ${PROJECT_SOURCE_DIR}/bin/360safedemo.exe)
