# Install script for directory: /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so.2019.6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so.2019.6")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so.2019.6"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/output/libJKQTPlotterSharedLib_.so.2019.6")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so.2019.6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so.2019.6")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so.2019.6"
         OLD_RPATH "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/output:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so.2019.6")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/output/libJKQTPlotterSharedLib_.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so"
         OLD_RPATH "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/output:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTPlotterSharedLib_.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterSharedLibConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterSharedLibConfig.cmake"
         "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/CMakeFiles/Export/lib/cmake/JKQTPlotterSharedLibConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterSharedLibConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterSharedLibConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/CMakeFiles/Export/lib/cmake/JKQTPlotterSharedLibConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/CMakeFiles/Export/lib/cmake/JKQTPlotterSharedLibConfig-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/JKQTPlotterSharedLibVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/libJKQTPlotterLib_.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterLibConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterLibConfig.cmake"
         "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/CMakeFiles/Export/lib/cmake/JKQTPlotterLibConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterLibConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotterLibConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/CMakeFiles/Export/lib/cmake/JKQTPlotterLibConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/CMakeFiles/Export/lib/cmake/JKQTPlotterLibConfig-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/JKQTPlotterLibVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtplotter" TYPE FILE FILES
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtptools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpbaseelements.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpbaseplotter.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpdatastorage.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpoverlaysbase.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbase.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbaseerrors.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbasestylingmixins.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtplotter.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtplotterstyle.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpkeystyle.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpbaseplotterstyle.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpcoordinateaxes.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpcoordinateaxesstyle.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtpimagetools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/jkqtplotter_imexport.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtplotter/graphs" TYPE FILE FILES
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpboxplot.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpboxplotstylingmixins.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpevaluatedfunction.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpfilledcurve.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpgeometric.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimage.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimpulses.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpparsedfunction.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtppeakstream.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpsinglecolumnsymbols.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimageoverlays.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpcontour.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimagergb.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpviolinplot.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpviolinplotstylingmixins.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpstatisticsadaptors.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpscatter.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtprange.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpspecialline.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpbarchart.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtplotter/gui" TYPE FILE FILES
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/gui/jkqtpcomboboxes.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/gui/jkqtpenhancedspinboxes.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/gui/jkqtpenhancedtableview.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/gui/jkqtpgraphsmodel.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/gui/jkvanishqtoolbar.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtplotter/overlays" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/overlays/jkqtpbasicoverlays.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtplotter/JKQTPlotterLib_Readme.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE RENAME "JKQTPlotterLib_LICENSE.txt" FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/LICENSE")
endif()

