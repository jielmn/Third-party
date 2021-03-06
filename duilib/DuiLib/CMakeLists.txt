# cmake file for duilib
#Author Qi Gao(monkgau@gmail.com)
#Created: 2012/09/16

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} Root_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Control Control_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Core Core_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Layout Layout_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Utils Utils_src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Control)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Layout)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Utils)

file(GLOB_RECURSE  ALL_H_FILE *.h )

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(duilib  SHARED ${Control_src} ${Core_src} ${Layout_src} ${Utils_src} ${Root_src} ${ALL_H_FILE} )

add_definitions(-DUILIB_EXPORTS)
target_link_libraries(duilib comctl32)
set_target_properties(duilib PROPERTIES OUTPUT_NAME "duilib")
set_target_properties(duilib PROPERTIES DEBUG_OUTPUT_NAME "duilibd" ) 

set(DEBUG_LIBRARY   ${PROJECT_BINARY_DIR}/lib/Debug/duilibd.dll)
set(RELEASE_LIBRARY ${PROJECT_BINARY_DIR}/lib/Release/duilib.dll)

add_custom_command(TARGET duilib POST_BUILD COMMAND if exist ${DEBUG_LIBRARY} ${CMAKE_COMMAND} -E copy_if_different ${DEBUG_LIBRARY} ${PROJECT_BINARY_DIR}/bin/Debug/duilibd.dll COMMAND if exist ${RELEASE_LIBRARY} ${CMAKE_COMMAND} -E copy_if_different ${RELEASE_LIBRARY} ${PROJECT_BINARY_DIR}/bin/Release/duilib.dll )





#add_custom_command(TARGET duilib POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E copy_if_different
#  ${PROJECT_BINARY_DIR}/lib/\$\(TargetName\)/duilib.dll ${PROJECT_SOURCE_DIR}/bin/duilib.dll)
