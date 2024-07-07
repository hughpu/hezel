add_library(hezel SHARED)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MD")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Dist")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MD")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MDd")
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
        ${CMAKE_CURRENT_LIST_DIR}/../platform/linux
        ${CMAKE_CURRENT_LIST_DIR}/../glad/include
)
target_link_libraries(hezel
    PRIVATE
        ${CMAKE_DL_LIBS}
    PUBLIC
        spdlog::spdlog
        glfw
        OpenGL::GL
        glad
)
target_precompile_headers(hezel
    PUBLIC 
        "hzpch.h"
)
add_compile_definitions(GLFW_INCLUDE_NONE)