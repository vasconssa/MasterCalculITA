#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JKQTCommonLib" for configuration ""
set_property(TARGET JKQTCommonLib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(JKQTCommonLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libJKQTCommonLib_.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS JKQTCommonLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_JKQTCommonLib "${_IMPORT_PREFIX}/lib/libJKQTCommonLib_.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
