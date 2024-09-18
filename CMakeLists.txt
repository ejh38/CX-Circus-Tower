cmake_minimum_required(VERSION 3.14)
project(CircusTower)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Ensure Release build
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files
add_library(circus_tower_lib
    src/main.cpp
    src/file_data_parser.cpp
    src/tower_builder.cpp
    src/person.cpp
)

# Add main executable
add_executable(circus_tower src/main.cpp)
target_link_libraries(circus_tower PRIVATE circus_tower_lib)

enable_testing()
add_subdirectory(tests)

# Post-build message to indicate where the executable is located
add_custom_command(TARGET circus_tower POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Executable is located in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)