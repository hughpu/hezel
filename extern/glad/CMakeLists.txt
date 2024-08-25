aux_source_directory(. GLAD_CURRENT)
aux_source_directory(include/glad GLAD_INCLUDE)

add_library(glad
    SHARED
    ${GLAD_CURRENT}
    ${GLAD_INCLUDE}
)

target_include_directories(glad
    PUBLIC
        "include"
)