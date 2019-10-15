#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JKQTFastPlotterSharedLib" for configuration ""
set_property(TARGET JKQTFastPlotterSharedLib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(JKQTFastPlotterSharedLib PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libJKQTFastPlotterSharedLib_.so.2019.6"
  IMPORTED_SONAME_NOCONFIG "libJKQTFastPlotterSharedLib_.so.2019.6"
  )

list(APPEND _IMPORT_CHECK_TARGETS JKQTFastPlotterSharedLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_JKQTFastPlotterSharedLib "${_IMPORT_PREFIX}/lib/libJKQTFastPlotterSharedLib_.so.2019.6" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
