add_executable(YerleyTests
        tests.cpp
        testsmain.cpp)

target_link_libraries(YerleyTests ${GTEST_LIBRARIES})

target_include_directories(
        YerleyTests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../exe/algorithms/Early
)

target_link_libraries(YerleyTests flexe)

target_compile_options(YerleyTests PRIVATE
        -Wall -Wextra -pedantic -Werror
)