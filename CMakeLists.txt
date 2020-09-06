cmake_minimum_required(VERSION 3.18)
project(cpp-notes)

set(CMAKE_CXX_STANDARD 11)

# global root dir
set(SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#include(${PROJECT_SOURCE_DIR}/cpp11-new_features)

# project files for clion
FILE(GLOB_RECURSE NEW_FEATURES ${PROJECT_SOURCE_DIR}/cpp11-new_features/*/*.cpp)

# add dir to src files
message(STATUS "[INFO] Recurse all src files")
foreach(path ${NEW_FEATURES})
    string(REGEX MATCH "[^/]*.[(c)|(cc)|(cpp)]$" file_ext ${path})
    string(REGEX MATCH "^[^.]*" file ${file_ext})
    add_executable(${file} ${path})
    message(${file})
    message(STATUS "into foreach")
#    target_link_libraries()
endforeach()