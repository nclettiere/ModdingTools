cmake_minimum_required(VERSION 3.14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(
    ModTools
    VERSION 0.1.5
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/functions.cmake)

add_executable(
    pz_symlink
    "src/symlink_mods.cpp"
)
add_executable(
    pz_fetch
    "src/fetch_defaults.cpp"
)

find_package(CURL REQUIRED)
target_link_libraries(pz_fetch PRIVATE CURL::libcurl)

Configure_Target(pz_symlink)
Configure_Target(pz_fetch)