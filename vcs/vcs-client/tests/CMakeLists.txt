cmake_minimum_required(VERSION 3.29)
project(vcs-client-tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(vcs-client-tests)
target_sources(vcs-client-tests
        PRIVATE test.cpp
)
target_link_libraries(
        vcs-client-tests PRIVATE
        GTest::gtest_main
        GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(vcs-client-tests)
