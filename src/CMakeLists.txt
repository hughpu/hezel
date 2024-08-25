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
    aux_source_directory("platform/linux" PLATFORM_SOURCE)
    set(PLATFORM_INCLUDE "platform/linux")
endif()

aux_source_directory(hezel HEZEL_SOURCE)
aux_source_directory(hezel/event EVENT_SOURCE)
aux_source_directory(hezel/imgui IMGUI_LAYER_SOURCE)

message("got system name: ${CMAKE_SYSTEM_NAME}")
target_sources(hezel 
    PRIVATE
    ${HEZEL_SOURCE}
    ${EVENT_SOURCE}
    ${PLATFORM_SOURCE}
    ${IMGUI_LAYER_SOURCE}
)

find_package(spdlog REQUIRED)
find_package(OpenGL REQUIRED)
# find_package(glfw3 3.3 REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW3 REQUIRED glfw3)


target_include_directories(hezel
    PUBLIC
        .
        ${GLFW3_INCLUDE_DIRS}
)
target_link_libraries(hezel
    PRIVATE
        ${CMAKE_DL_LIBS}
    PUBLIC
        spdlog::spdlog
        OpenGL::GL
        glad
        ${GLFW3_LIBRARIES}
        imgui
)
target_precompile_headers(hezel
    PUBLIC 
        "hezel/hzpch.h"
)
target_compile_definitions(hezel PUBLIC GLFW_INCLUDE_NONE ${GLFW3_CFLAGS_OTHER})