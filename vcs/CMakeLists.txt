cmake_minimum_required(VERSION 3.29)
project(vcs C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../artefacts/${CMAKE_BUILD_TYPE}/vcs/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../artefacts/${CMAKE_BUILD_TYPE}/vcs/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../artefacts/${CMAKE_BUILD_TYPE}/vcs/bin)

add_subdirectory(tests)

set(CMAKE_C_STANDARD 23)

add_executable(vcs "src/main.c")
