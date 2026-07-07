cmake_minimum_required(VERSION 3.15)
project(BitTest VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(BitTest INTERFACE)

target_include_directories(BitTest INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "Modo desarrollo: Compilando ejecutable de pruebas para BitTest")
    
    add_executable(run_tests 
        tests/main.cpp
    )
    target_link_libraries(run_tests PRIVATE BitTest)
endif()