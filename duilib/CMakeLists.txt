# CMake root file for duilib related apps
#Date 2012-09-16
#Author: Qi Gao(monkgau@gmail.com)
#
#  CMake files for duilib
#  file for each app is under the related sub-dir
#

cmake_minimum_required(VERSION 2.8)

project(dui)

message(STATUS," CMake project files for duilib")

# this line is for UNICODE release,which is required by DuiDesigner 
# add_definitions(-DUNICODE -D_UNICODE)

macro(source_group_by_dir source_files)
    if(MSVC)
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}//(.*/) //1 sgbd_fpath ${sgbd_file})
            string(REGEX REPLACE "/(.*/)/.*" //1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "//" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
                set(sgbd_group_name "//")
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
    endif(MSVC)
endmacro(source_group_by_dir)

# add each CMake file
add_subdirectory(duilib)
add_subdirectory(360SafeDemo)
#add_subdirectory(FlashDemo)
add_subdirectory(GameDemo)
add_subdirectory(ListDemo)
# add_subdirectory(MenuDemo) the sources in this project has error
add_subdirectory(QQDemo)
add_subdirectory(RichListDemo)
add_subdirectory(MenuDemo)
