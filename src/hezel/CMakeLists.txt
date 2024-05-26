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

target_sources(hezel 
    PRIVATE
        ${CUR_DIR_CPP}
    PUBLIC
        ${CUR_DIR_H}
        ${EVENT_H}
)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

if(NOT TARGET glfw3)
    find_package(glfw3 REQUIRED)
endif()

if(NOT TARGET OpenGL)
    find_package(OpenGL REQUIRED)
endif()

target_include_directories(hezel
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(hezel PUBLIC spdlog::spdlog glfw3 OpenGL::OpenGL)
target_precompile_headers(hezel
    PUBLIC 
        "hzpch.h"
)