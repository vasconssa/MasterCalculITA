#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JKQTPlotterLib" for configuration ""
set_property(TARGET JKQTPlotterLib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(JKQTPlotterLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libJKQTPlotterLib_.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS JKQTPlotterLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_JKQTPlotterLib "${_IMPORT_PREFIX}/lib/libJKQTPlotterLib_.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
