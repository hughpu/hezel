add_executable(sandbox sandbox_app.cpp)

target_link_libraries(sandbox hezel)

add_test(
    NAME sandbox
    COMMAND sandbox
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)