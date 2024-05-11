add_library(event)

file(GLOB CUR_DIR_CPP "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB CUR_DIR_H "${CMAKE_CURRENT_LIST_DIR}/*.h")

target_sources(event 
    PRIVATE
        ${CUR_DIR_CPP}
    PUBLIC
        ${CUR_DIR_H}
)

target_include_directories(event PUBLIC ${CMAKE_CURRENT_LIST_DIR})

set_target_properties(event PROPERTIES
    CXX_STANDARD 17  # For C++11
    # Or for C:
    # C_STANDARD 99
)