cmake_minimum_required(VERSION 3.29)
project(vcs-tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../artefacts/${CMAKE_BUILD_TYPE}/vcs/tests/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../artefacts/${CMAKE_BUILD_TYPE}/vcs/tests/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../artefacts/${CMAKE_BUILD_TYPE}/vcs/tests/bin)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(tests "src/tests.cc")
target_link_libraries(
        tests PRIVATE
        GTest::gtest_main
        GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(tests)
