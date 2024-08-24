aux_source_directory(. GLAD_CURRENT)
aux_source_directory(include/glad GLAD_INCLUDE)

add_library(glad
    OBJECT
    ${GLAD_CURRENT}
    ${GLAD_INCLUDE}
)

target_include_directories(glad
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)
set_property(
    TARGET glad
    PROPERTY POSITION_INDEPENDENT_CODE ON
)