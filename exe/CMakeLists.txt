cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

project(FormalLanguageFramework)

add_library(flexe SHARED # flexe = Formal Language EXE
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/Early/Early.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/Early/HelperEarly.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/Early/Situation.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/Early/Early.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/Early/HelperEarly.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/Early/Situation.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Grammar.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Rule.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Grammar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Rule.cpp
        )

target_compile_options(
        flexe PRIVATE
        -Wall -Wextra -pedantic -Werror
)
