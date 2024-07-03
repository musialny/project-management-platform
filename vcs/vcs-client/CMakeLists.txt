cmake_minimum_required(VERSION 3.29)
project(vcs-client CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/vcs-client/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/vcs-client/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/vcs-client/bin)

add_executable(vcs-client "src/main.cc")

add_subdirectory(tests)
