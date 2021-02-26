cmake_minimum_required(VERSION 3.12)

target_sources(main
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/servo.cpp
)

target_include_directories(main
    PUBLIC
        ${PROJECT_SOURCE_DIR}/Incpp
)
