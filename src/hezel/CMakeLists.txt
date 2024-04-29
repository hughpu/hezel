add_library(hezel SHARED)

target_sources(hezel 
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/*.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/*.h
)

target_include_directories(hezel
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)