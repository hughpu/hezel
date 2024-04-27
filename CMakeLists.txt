cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Hezel LANGUAGES CXX)

# if(WIN32)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/debug/win)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/release/win)
# elseif(APPLE)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/debug/macos)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/release/macos)
# else()
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/debug/linux)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/release/linux)
# endif()
    
# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check for 64-bit system and x86 architecture
# if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
#     message(FATAL_ERROR "Only 64-bit systems are supported.")
# endif()
# if(NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
#     message(FATAL_ERROR "Only x86 architecture is supported.")
# endif()

# Set options for building dynamic link architecture
set(BUILD_SHARED_LIBS ON)

# Add your source files here
add_library(${PROJECT_NAME} SHARED src/test.cpp src/test.h)
# target_compile_definitions(hezel PUBLIC HEZEL_EXPORT)
target_include_directories(${PROJECT_NAME} PRIVATE src)

file(COPY src/test.h DESTINATION ${CMAKE_BINARY_DIR}/include)
file(COPY ${CMAKE_BINARY_DIR}/libHezel.so DESTINATION ${CMAKE_BINARY_DIR}/lib)
# Add any additional libraries or dependencies here
# target_link_libraries(H YourAdditionalLibraries)
