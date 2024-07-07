cmake_minimum_required(VERSION 3.29)
project(vcs-shared-cli-preprocessor-tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(vcs-shared-cli-preprocessor-tests)
target_sources(vcs-shared-cli-preprocessor-tests
        PRIVATE
        CliCommandExecutorTests.cpp
)
target_link_libraries(vcs-shared-cli-preprocessor-tests
        PRIVATE
            GTest::gtest_main
            GTest::gmock
            vcs-shared-cli-preprocessor
)

include(GoogleTest)
gtest_discover_tests(vcs-shared-cli-preprocessor-tests)
