#Cmake file for QQDemo
#Author: Qi Gao(monkgau@gmail.com)
#Created: 2012/9/17

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})                           


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB_RECURSE  ALL_H_FILE *.h )
add_executable(QQDemo ${SRC} QQDemo.rc ${ALL_H_FILE})

set_target_properties(QQDemo PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(QQDemo duilib)

add_custom_command(TARGET QQDemo POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/bin/skin/360SafeRes.zip ${PROJECT_BINARY_DIR}/bin/Debug/skin/360SafeRes.zip COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/bin/skin/360SafeRes.zip ${PROJECT_BINARY_DIR}/bin/Release/skin/360SafeRes.zip )

#add_custom_command(TARGET QQDemo POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${PROJECT_BINARY_DIR}/bin/QQDemo.exe ${PROJECT_SOURCE_DIR}/bin/QQDemo.exe)
