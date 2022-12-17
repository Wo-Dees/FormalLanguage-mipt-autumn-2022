cmake_minimum_required(VERSION 3.23)

project(play)

set(CMAKE_CXX_STANDARD 20)

add_executable(MainPlay main.cpp)

set_target_properties(
        MainPlay PROPERTIES
        CXX_STANDART 20
        CXX_STANDART_REQURED ON
)

target_include_directories(
        MainPlay
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(
        MainPlay
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../exe/algorithms/Early
)

target_link_libraries(MainPlay flexe)

target_compile_options(
        MainPlay PRIVATE
        -Wall -Wextra -pedantic -Werror
)
