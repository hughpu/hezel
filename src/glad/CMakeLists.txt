add_library(glad
    ${CMAKE_CURRENT_LIST_DIR}/glad.c
    ${CMAKE_CURRENT_LIST_DIR}/include/glad/glad.h
)

target_include_directories(glad
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)