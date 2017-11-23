#Cmake file for GameDemo
#Author: Qi Gao(monkgau@gmail.com)
#Created: 2012/9/17

set(source_files GameDemo.cpp MiniDumper.cpp stdAfx.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB_RECURSE  ALL_H_FILE *.h )
add_executable(GameDemo ${source_files} ${ALL_H_FILE})

add_dependencies(GameDemo duilib)
target_link_libraries(GameDemo duilib)
set_target_properties(GameDemo PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

add_custom_command(TARGET GameDemo POST_BUILD COMMAND xcopy /EIY \"${PROJECT_SOURCE_DIR}/bin/skin/GameRes\" \"${PROJECT_BINARY_DIR}/bin/Debug/skin/GameRes\" COMMAND xcopy /EIY \"${PROJECT_SOURCE_DIR}/bin/skin/GameRes\" \"${PROJECT_BINARY_DIR}/bin/Release/skin/GameRes\" )

#add_custom_command(TARGET GameDemo POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${PROJECT_BINARY_DIR}/bin/GameDemo.exe ${PROJECT_SOURCE_DIR}/bin/GameDemo.exe)
