# Install script for directory: /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so.2019.6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so.2019.6")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so.2019.6"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/output/libJKQTCommonSharedLib_.so.2019.6")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so.2019.6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so.2019.6")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so.2019.6")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/output/libJKQTCommonSharedLib_.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJKQTCommonSharedLib_.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonSharedLibConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonSharedLibConfig.cmake"
         "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/Export/lib/cmake/JKQTCommonSharedLibConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonSharedLibConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonSharedLibConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/Export/lib/cmake/JKQTCommonSharedLibConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/Export/lib/cmake/JKQTCommonSharedLibConfig-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/JKQTCommonSharedLibVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/libJKQTCommonLib_.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonLibConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonLibConfig.cmake"
         "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/Export/lib/cmake/JKQTCommonLibConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonLibConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTCommonLibConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/Export/lib/cmake/JKQTCommonLibConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/Export/lib/cmake/JKQTCommonLibConfig-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/JKQTCommonLibVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtcommon" TYPE FILE FILES
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtcommon_imexport.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpdebuggingtools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpmathtools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpalgorithms.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstringtools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtplinalgtools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpcodestructuring.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpbasicimagetools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpdrawingtools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpenhancedpainter.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtphighrestimer.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpmathparser.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqttools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtparraytools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstatisticstools.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstatbasics.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstathistogram.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstatkde.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstatregression.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstatpoly.h"
    "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/jkqtpstatgrouped.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/JKQTCommonLib_Readme.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE RENAME "JKQTCommonLib_LICENSE.txt" FILES "/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/LICENSE")
endif()

