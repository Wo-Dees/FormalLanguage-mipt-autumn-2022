cmake_minimum_required(VERSION 3.23)

project(exe)

set(CMAKE_CXX_STANDARD 20)

add_executable(grammar
        main.cpp
        exe/grammar/Rule.hpp
        exe/grammar/Rule.cpp
        exe/grammar/Grammar.hpp
        exe/grammar/Grammar.cpp
        exe/algorithms/Early/Early.hpp
        exe/algorithms/Early/Early.cpp
        exe/algorithms/Early/HelperEarly.hpp
        exe/algorithms/Early/HelperEarly.cpp
        exe/algorithms/Early/Situation.hpp
        exe/algorithms/Early/Situation.cpp
        )
