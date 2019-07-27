add_executable(alb-exe main.cpp)
target_include_directories(alb-exe PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(alb-exe alb)
