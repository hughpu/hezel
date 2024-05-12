add_library(hezel SHARED)

file(GLOB CUR_DIR_CPP "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB CUR_DIR_H "${CMAKE_CURRENT_LIST_DIR}/*.h")
file(GLOB EVENT_H "${CMAKE_CURRENT_LIST_DIR}/event/*.h")

target_sources(hezel 
    PRIVATE
        ${CUR_DIR_CPP}
    PUBLIC
        ${CUR_DIR_H}
        ${EVENT_H}
)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

target_include_directories(hezel
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(hezel PUBLIC spdlog::spdlog)