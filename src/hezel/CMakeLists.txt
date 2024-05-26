add_library(hezel SHARED)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions("HZ_ENABLE_ASSERTS")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions("HZ_PLATFORM_LINUX")
endif()

file(GLOB CUR_DIR_CPP "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB CUR_DIR_H "${CMAKE_CURRENT_LIST_DIR}/*.h")
file(GLOB EVENT_H "${CMAKE_CURRENT_LIST_DIR}/event/*.h")
file(GLOB PLATFORM_WINDOW_H "${CMAKE_CURRENT_LIST_DIR}/../platform/linux/*.h")
file(GLOB PLATFORM_WINDOW_CPP "${CMAKE_CURRENT_LIST_DIR}/../platform/linux/*.cpp")

target_sources(hezel 
    PRIVATE
        ${CUR_DIR_CPP}
        ${PLATFORM_WINDOW_CPP}
    PUBLIC
        ${CUR_DIR_H}
        ${EVENT_H}
        ${PLATFORM_WINDOW_H}
)

find_package(spdlog REQUIRED)

find_package(glfw3 3.3 REQUIRED)

find_package(OpenGL REQUIRED)

target_include_directories(hezel
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        "${CMAKE_CURRENT_LIST_DIR}/../platform/linux"
)
target_link_libraries(hezel
    PUBLIC
        spdlog::spdlog
        glfw
        OpenGL::GL
)
target_precompile_headers(hezel
    PUBLIC 
        "hzpch.h"
)