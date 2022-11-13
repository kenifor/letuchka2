cmake_minimum_required(VERSION 3.14)

project(let1)

set(CMAKE_CXX_STANDARD 17)

# флаг, который подключает тесты к проекту
set(ENABLE_UNIT_TESTS ON)

#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

set(FILES
    Header.h
    Source.cpp
    let_1.cpp
)

add_executable(${PROJECT_NAME} ${FILES})

if (ENABLE_UNIT_TESTS)

    #set(GTEST_INCLUDE_DIR lib/)
    #find_package(GTest REQUIRED)

    include(FetchContent)
    include(GoogleTest)
    enable_testing()
    #gtest_discover_tests(${TEST_PROJECT_NAME})

    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        release-1.12.1
    )

    FetchContent_MakeAvailable(googletest)

    set(TEST_SOURCES
        tests.cpp
        Header.h
        Source.cpp
    )

    set(TEST_PROJECT_NAME let1-test)

    add_executable(${TEST_PROJECT_NAME} ${TEST_SOURCES})

    target_link_libraries(${TEST_PROJECT_NAME}
        PRIVATE gtest_main)

    #gtest_discover_tests(${TEST_PROJECT_NAME} AUTO)

endif()
