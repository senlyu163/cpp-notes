cmake_minimum_required(VERSION 3.18)
project(cpp-notes)

set(CMAKE_CXX_STANDARD 11)

# global root dir
set(SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#---------------------------------------------------------#
# =================== Options start ===================== #
#---------------------------------------------------------#
option(BUILD_NEW_FEATURES "[Optional] Build cpp11-new_features" ON)
option(BUILD_CONCURRENCY "[Optional] Build cpp-concurrency" ON)
option(BUILD_UTILS "[Optional] Build utils" ON)
#---------------------------------------------------------#
# =================== Options end  ====================== #
#---------------------------------------------------------#


# project files for cmake
if (BUILD_NEW_FEATURES)
    FILE(GLOB_RECURSE NEW_FEATURES ${PROJECT_SOURCE_DIR}/cpp11-new_features/test/*.cpp)
    include_directories(${SOLUTION_DIR}/cpp11-new_features/src)
else()
    message(STATUS "[Optional] Build cpp11-new_features: [OFF]")
endif ()

if (BUILD_CONCURRENCY)
    FILE(GLOB_RECURSE CONCURRENCY ${PROJECT_SOURCE_DIR}/cpp-concurrency/test/*.cpp)
    include_directories(${SOLUTION_DIR}/cpp-concurrency/src)
    find_package(Threads REQUIRED)
    target_link_libraries(${file} Threads::Threads)  # to link pthread
else()
    message(STATUS "[Optional] Build cpp-concurrency: [OFF]")
endif ()

if (BUILD_UTILS)
    FILE(GLOB_RECURSE UTILS ${PROJECT_SOURCE_DIR}/utils/test/*.cpp)
    include_directories(${SOLUTION_DIR}/utils/src)
else()
    message(STATUS "[Optional] Build utils: [OFF]")
endif ()


# add dir to src files
if (BUILD_NEW_FEATURES)
    foreach(path ${NEW_FEATURES})
        string(REGEX MATCH "[^/]*.[(c)|(cc)|(cpp)]$" file_ext ${path})
        string(REGEX MATCH "^[^.]*" file ${file_ext})
        add_executable(test_${file} ${path})
    endforeach()
else()
    message(STATUS "[Optional] Build cpp11-new_features: [OFF]")
endif ()

if (BUILD_CONCURRENCY)
    foreach(path ${CONCURRENCY})
        string(REGEX MATCH "[^/]*.[(c)|(cc)|(cpp)]$" file_ext ${path})
        string(REGEX MATCH "^[^.]*" file ${file_ext})
        add_executable(test_${file} ${path})
    endforeach()
else()
    message(STATUS "[Optional] Build cpp-concurrency: [OFF]")
endif ()

if (BUILD_UTILS)
    foreach(path ${CONCURRENCY})
        string(REGEX MATCH "[^/]*.[(c)|(cc)|(cpp)]$" file_ext ${path})
        string(REGEX MATCH "^[^.]*" file ${file_ext})
        add_executable(test_${file} ${path})
    endforeach()
else()
    message(STATUS "[Optional] Build utils: [OFF]")
endif ()

