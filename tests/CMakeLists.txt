# Include FetchContent module for downloading dependencies
include(FetchContent)

# Declare GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make available to the parent
FetchContent_MakeAvailable(googletest)

# Add the test executables
add_executable(circus_tower_tests
    test_tower_builder.cpp
    test_person.cpp
    test_file_data_parser.cpp
    ../src/tower_builder.cpp
    ../src/file_data_parser.cpp
)

# Link test executable against GoogleTest libraries and circus_tower_lib
target_link_libraries(circus_tower_tests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
    circus_tower_lib
)

# Discover and register tests
include(GoogleTest)
gtest_discover_tests(circus_tower_tests)