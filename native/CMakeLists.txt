cmake_minimum_required(VERSION 2.8)
project(plugin)

set(plugin_VERSION_MAJOR 1)
set(plugin_VERSION_MINOR 0)

# Allow relative file paths for link_directory(...)
cmake_policy(SET CMP0015 NEW)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY cpp/target)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY cpp/target)

set(PLUGIN_LIBRARY plugin)
set(PLUGIN_RUNTEST runtest)

set(PLUGIN_DIR .)

include_directories(${PLUGIN_DIR}/cpp/src)

file(GLOB_RECURSE src_files cpp/src/*)
file(GLOB_RECURSE tst_files cpp/test/*)

add_library(${PLUGIN_LIBRARY} SHARED ${src_files})
add_executable(${PLUGIN_RUNTEST} ${tst_files})

target_link_libraries(${PLUGIN_RUNTEST} ${PLUGIN_LIBRARY})

