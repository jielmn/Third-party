#Cmake file for MenuDemo
#Author: Qi Gao(monkgau@gmail.com)
#Created: 2012/9/17

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})                           

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(MenuDemo ${SRC} MenuDemo.rc)
set_target_properties(MenuDemo PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(MenuDemo duilib)


#add_custom_command(TARGET MenuDemo POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${PROJECT_BINARY_DIR}/bin/MenuDemo.exe ${PROJECT_SOURCE_DIR}/bin/MenuDemo.exe)
