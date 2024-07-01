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
    DESCRIPTION "Conaprole's Modding Tools"
    HOMEPAGE_URL "https://lactoservice.uk/"
    LANGUAGES C CXX
)

include(cmake/functions.cmake)


#set(WITH_WEBP OFF CACHE BOOL "" FORCE)
#set(WITH_OPENGL OFF CACHE BOOL "" FORCE)
#add_subdirectory(vendor/fox)

add_executable(
    pz_symlink
    "src/symlink_mods.cpp"
)
add_executable(
    pz_fetch
    "src/fetch_defaults.cpp"
)
#add_executable(
#    pz_launcher
#    "src/pz_launcher.cpp"
#    "src/launcher_ui.cpp"
#)
add_executable(
    pz_patcher
    "src/pz_patcher.cpp"
)

#find_package(CURL REQUIRED)
#find_package(ftxui CONFIG REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(FOX REQUIRED fox)
pkg_check_modules(CURL REQUIRED libcurl)


message(STATUS "FOX INCLUDES: ${FOX_INCLUDE_DIRS}")

#if(WIN32)
	target_include_directories(pz_fetch PRIVATE ${CURL_INCLUDE_DIRS})
    target_link_libraries(pz_fetch PRIVATE ${CURL_LIBRARIES})
    #target_link_libraries(pz_launcher PRIVATE CURL::libcurl ftxui::dom ftxui::screen ftxui::component)
	
	target_include_directories(pz_patcher PRIVATE ${FOX_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS})
    target_link_libraries(pz_patcher PRIVATE msimg32 winmm imm32 wsock32 gdi32 ${FOX_LIBRARIES} ${CURL_LIBRARIES})
	
##else()
#    target_link_libraries(pz_fetch PRIVATE ${CURL_LIBRARIES})
#endif()

Configure_Target(pz_symlink)
Configure_Target(pz_fetch)
#Configure_Target(pz_launcher)
#Configure_Target(pz_patcher)
