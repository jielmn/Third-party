#Cmake file for ListDemo
#Author: Qi Gao(monkgau@gmail.com)
#Created: 2012/9/17

set(source_files Main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB_RECURSE  ALL_H_FILE *.h )
add_executable(ListDemo ${source_files} ${ALL_H_FILE})

add_dependencies(ListDemo duilib)
target_link_libraries(ListDemo duilib)
set_target_properties(ListDemo PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

add_custom_command(TARGET ListDemo POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/bin/skin/ListRes.zip ${PROJECT_BINARY_DIR}/bin/Debug/skin/ListRes.zip COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/bin/skin/ListRes.zip ${PROJECT_BINARY_DIR}/bin/Release/skin/ListRes.zip )

#add_custom_command(TARGET ListDemo POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${PROJECT_BINARY_DIR}/bin/ListDemo.exe ${PROJECT_SOURCE_DIR}/bin/ListDemo.exe)
