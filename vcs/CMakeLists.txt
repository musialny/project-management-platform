cmake_minimum_required(VERSION 3.29)
project(vcs VERSION 0.1.0)

set(VCS_OUTPUT_DIRECTORY_BASE ${PROJECT_SOURCE_DIR}/../artefacts/${CMAKE_BUILD_TYPE})

add_subdirectory(vcs-client)
add_subdirectory(vcs-server)

add_subdirectory(shared/cli-preprocessor)
