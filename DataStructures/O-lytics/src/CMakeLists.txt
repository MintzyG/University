cmake_minimum_required(VERSION 3.27)
project(Olytics VERSION 0.1.0)

set(CMAKE_C_STANDARD 99)

add_executable(olytics example.c exampleFunc.c)
add_subdirectory(modules)

add_compile_definitions(all)

target_include_directories(olytics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(olytics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/modules/helpers)
target_include_directories(olytics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/modules/obase)
target_include_directories(olytics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/modules/probe)
target_include_directories(olytics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/modules/olytics)
