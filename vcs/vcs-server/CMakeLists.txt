cmake_minimum_required(VERSION 3.29)
project(vcs-server CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/vcs-server/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/vcs-server/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/vcs-server/bin)

add_definitions(-DVCS_VERSION="${CMAKE_PROJECT_VERSION}")

add_executable(vcs-server)
target_sources(vcs-server
        PRIVATE
            src/main.cpp
        PRIVATE FILE_SET CXX_MODULES FILES
            src/commands/Version.cppm
            src/commands/Commands.cppm
)

target_link_libraries(vcs-server
        PRIVATE
            vcs-shared-cli-preprocessor
)

add_subdirectory(tests)
