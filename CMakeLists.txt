cmake_minimum_required(VERSION 3.23)
project(exe)

set(CMAKE_CXX_STANDARD 20)

add_executable(automations play/main.cpp exe/automation/NonDeterministicAutomaton.cpp exe/automation/NonDeterministicAutomaton.h exe/automation/DeterministicAutomation.cpp exe/automation/DeterministicAutomation.h exe/regular/RegularExpression.cpp exe/regular/RegularExpression.h)
