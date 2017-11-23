#Cmake file for RichListDemo
#Author: Qi Gao(monkgau@gmail.com)
#Created: 2012/9/17

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})                           


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB_RECURSE  ALL_H_FILE *.h )
add_executable(RichListDemo ${SRC_LIST} RichListDemo.rc ${ALL_H_FILE})

set_target_properties(RichListDemo PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(RichListDemo duilib)

add_custom_command(TARGET RichListDemo POST_BUILD COMMAND xcopy /EIY \"${PROJECT_SOURCE_DIR}/bin/skin/RichListRes\" \"${PROJECT_BINARY_DIR}/bin/Debug/skin/RichListRes\" COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/bin/skin/RichListRes.zip ${PROJECT_BINARY_DIR}/bin/Release/skin/RichListRes.zip )

#add_custom_command(TARGET RichListDemo POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${PROJECT_BINARY_DIR}/bin/RichListDemo.exe ${PROJECT_SOURCE_DIR}/bin/RichListDemo.exe)
