add_subdirectory(googletest)

add_executable(runTests src/Lexer.cpp src/StringStore.cpp)

target_include_directories(runTests PUBLIC ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests alb)
