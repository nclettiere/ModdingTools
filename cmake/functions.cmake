function(Configure_Target TARGET_NAME)
    set_target_properties(
        ${TARGET_NAME} PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES
        VERSION "${PROJECT_VERSION}"
        SOVERSION "${PROJECT_VERSION_MAJOR}"
        EXPORT_NAME ${TARGET_NAME}
        OUTPUT_NAME ${TARGET_NAME}
        DEBUG_POSTFIX "d"
        USE_FOLDERS ON

        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib

        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib

        RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR}/lib
        ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR}/lib
    )

    target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        "include"
    )
    if(WIN32)
        target_link_libraries(${TARGET_NAME} PUBLIC -static)
    else()
        if(NOT ${TARGET_NAME} STREQUAL "pz_fetch")
            target_link_libraries(${TARGET_NAME} PUBLIC -static)
        endif()
    endif()
    target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)
endfunction()