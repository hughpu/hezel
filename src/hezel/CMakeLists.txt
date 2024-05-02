add_library(hezel SHARED)

file(GLOB CUR_DIR_CPP "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB CUR_DIR_H "${CMAKE_CURRENT_LIST_DIR}/*.h")

target_sources(hezel 
    PRIVATE
        ${CUR_DIR_CPP}
    PUBLIC
        ${CUR_DIR_H}
)

target_include_directories(hezel
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)