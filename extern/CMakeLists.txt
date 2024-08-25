add_subdirectory(glad)

aux_source_directory(imgui IMGUI_SOURCE)
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(
        IMGUI_BACKEND
        "imgui/backends/imgui_impl_opengl3.h"
        "imgui/backends/imgui_impl_opengl3.cpp"
        "imgui/backends/imgui_impl_opengl3_loader.h"
        "imgui/backends/imgui_impl_glfw.h"
        "imgui/backends/imgui_impl_glfw.cpp"
    )
endif()

add_library(imgui SHARED ${IMGUI_SOURCE} ${IMGUI_BACKEND})
target_include_directories(imgui PUBLIC "imgui" "imgui/backends")