add_subdirectory(glad)

aux_source_directory(imgui IMGUI_SOURCE)
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(
        IMGUI_BACKEND
        "imgui/backends/imgui_impl_opengl3.h"
        "imgui/backends/imgui_impl_opengl3.cpp"
        "imgui/backends/imgui_impl_glfw.h"
        "imgui/backends/imgui_impl_glfw.cpp"
    )
endif()

add_library(imgui OBJECT ${IMGUI_SOURCE} ${IMGUI_BACKEND})

target_link_libraries(imgui PUBLIC glad)
target_include_directories(imgui PUBLIC "imgui" "imgui/backends")
set_property(TARGET imgui PROPERTY POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_CUSTOM)
target_precompile_headers(imgui
    PRIVATE 
        "glad/include/glad/glad.h"
)