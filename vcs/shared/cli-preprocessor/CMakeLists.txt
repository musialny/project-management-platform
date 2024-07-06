cmake_minimum_required(VERSION 3.29)
project(vcs-shared-cli-preprocessor CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/shared/cli-preprocessor/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/shared/cli-preprocessor/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${VCS_OUTPUT_DIRECTORY_BASE}/vcs/shared/cli-preprocessor/bin)

add_library(vcs-shared-cli-preprocessor STATIC)
target_compile_features(vcs-shared-cli-preprocessor PUBLIC cxx_std_20)
target_sources(vcs-shared-cli-preprocessor
        PUBLIC FILE_SET CXX_MODULES FILES
            src/CliPreprocessor.cppm
            src/CliCommandExecutor.cppm
            src/CliActionsContainer.cppm
)

add_subdirectory(tests)
