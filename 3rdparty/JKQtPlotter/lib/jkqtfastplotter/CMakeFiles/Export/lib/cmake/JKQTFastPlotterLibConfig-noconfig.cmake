#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JKQTFastPlotterLib" for configuration ""
set_property(TARGET JKQTFastPlotterLib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(JKQTFastPlotterLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libJKQTFastPlotterLib_.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS JKQTFastPlotterLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_JKQTFastPlotterLib "${_IMPORT_PREFIX}/lib/libJKQTFastPlotterLib_.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
