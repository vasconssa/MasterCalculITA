cmake_minimum_required(VERSION 3.10)

project(MasterCalculITA VERSION 1.0 LANGUAGES CXX)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Xml PrintSupport OpenGL Svg)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(MSVC)
    add_compile_options(/EHsc)
    # To enable M_PI, M_E,...
    add_definitions(/D_USE_MATH_DEFINES)
    # To Prevent Errors with min() and max()
    add_definitions(/DNOMINMAX)
    # To fix error: C2338: va_start argument must not
    # have reference type and must not be parenthesized
    add_definitions(/D_CRT_NO_VA_START_VALIDATION)
	if(BUILD_INCLUDE_XITS_FONTS)
		add_definitions(/DAUTOLOAD_XITS_FONTS)
		add_definitions(/DUSE_XITS_FONTS )
	else()
		add_definitions(/DNO_XITS_FONTS )
	endif()
	set(CMAKE_MSVCIDE_RUN_PATH ${CMAKE_PREFIX_PATH};${Qt5_DIR}/bin)
else()
    add_compile_options(-fexceptions)
    if(BUILD_HIGH_COMPILE_WARNING_LEVEL)
        add_compile_options(-Wall -Wextra) # -Wimplicit-fallthrough -Wuninitialized -Wmaybe-uninitialized) # -Wmisleading-indentation -Weffc++)
    endif(BUILD_HIGH_COMPILE_WARNING_LEVEL)

	if(BUILD_INCLUDE_XITS_FONTS)
		add_definitions(-DAUTOLOAD_XITS_FONTS)
		add_definitions(-DUSE_XITS_FONTS )
	else()
		add_definitions(-DNO_XITS_FONTS )
	endif()
endif()


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Specification of standard output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# .a and .so files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)

set(BUILD_EXAMPLES OFF)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/3rdparty/JKQtPlotter)

set(3RD_PARTY_DIR ${CMAKE_SOURCE_DIR}/3rdparty)
include_directories(${3RD_PARTY_DIR}/JKQtPlotter/lib)
# jkqtcommon

# Set up source files
set(JKQTCOMMON_SOURCES
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpdebuggingtools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpmathtools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpalgorithms.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstringtools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtplinalgtools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpcodestructuring.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpbasicimagetools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpdrawingtools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpenhancedpainter.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtphighrestimer.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpmathparser.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqttools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtparraytools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatbasics.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstathistogram.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatkde.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatregression.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatpoly.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatgrouped.cpp
)

set(JKQTCOMMON_HEADERS
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtcommon_imexport.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpdebuggingtools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpmathtools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpalgorithms.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstringtools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtplinalgtools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpcodestructuring.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpbasicimagetools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpdrawingtools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpenhancedpainter.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtphighrestimer.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpmathparser.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqttools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtparraytools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatisticstools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatbasics.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstathistogram.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatkde.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatregression.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatpoly.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtcommon/jkqtpstatgrouped.h
)

add_library(jkqtcommon STATIC  ${JKQTCOMMON_SOURCES} ${JKQTCOMMON_HEADERS})
target_link_libraries(jkqtcommon Qt5::Core Qt5::Gui Qt5::Xml Qt5::Widgets Qt5::PrintSupport)

# jkqtmathtext
## Set up source files
set(SOURCES
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtmathtext/jkqtmathtext.cpp
)

set(HEADERS
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtmathtext/jkqtmathtext.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtmathtext/jkqtmathtext_imexport.h
)

set(RESOURCES
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtmathtext/resources/xits.qrc
)
qt5_add_resources( RCS ${RESOURCES})

add_library(jkqtmathtext STATIC  ${SOURCES} ${HEADERS} ${RCS})
target_link_libraries(jkqtmathtext Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport jkqtcommon)

#jkqtfastplotter
# Set up source files
set(SOURCES
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtfastplotter/jkqtfastplotter.cpp
)

set(HEADERS
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtfastplotter/jkqtfastplotter.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtfastplotter/jkqtfastplotter_imexport.h
)

add_library(jkqtfastplotter STATIC  ${SOURCES} ${HEADERS} ${RESOURCES})
target_link_libraries(jkqtfastplotter Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport Qt5::OpenGL jkqtcommon)


#jkqtplotter

# Set up source files
set(SOURCES
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtptools.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpbaseelements.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpbaseplotter.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpdatastorage.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpoverlaysbase.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbase.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbaseerrors.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbasestylingmixins.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtplotter.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtplotterstyle.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpkeystyle.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpbaseplotterstyle.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpcoordinateaxes.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpcoordinateaxesstyle.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpimagetools.cpp
    )
set(SOURCES_GRAPHS
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpscatter.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtprange.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpspecialline.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpbarchart.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpboxplot.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpboxplotstylingmixins.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpevaluatedfunction.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpfilledcurve.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpgeometric.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimage.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimpulses.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpparsedfunction.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtppeakstream.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpsinglecolumnsymbols.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimageoverlays.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpcontour.cpp 
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimagergb.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpviolinplot.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpviolinplotstylingmixins.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpstatisticsadaptors.cpp 
    )
set(SOURCES_OVERLAYS
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/overlays/jkqtpbasicoverlays.cpp
)
set(SOURCES_GUI
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpcomboboxes.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpenhancedspinboxes.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpenhancedtableview.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpgraphsmodel.cpp
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkvanishqtoolbar.cpp
)


set(HEADERS
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtptools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpbaseelements.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpbaseplotter.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpdatastorage.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpoverlaysbase.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbase.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbaseerrors.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpgraphsbasestylingmixins.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtplotter.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtplotterstyle.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpkeystyle.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpbaseplotterstyle.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpcoordinateaxes.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpcoordinateaxesstyle.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtpimagetools.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/jkqtplotter_imexport.h
)
set(HEADERS_GRAPHS
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpboxplot.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpboxplotstylingmixins.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpevaluatedfunction.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpfilledcurve.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpgeometric.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimage.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimpulses.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpparsedfunction.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtppeakstream.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpsinglecolumnsymbols.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimageoverlays.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpcontour.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpimagergb.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpviolinplot.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpviolinplotstylingmixins.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpstatisticsadaptors.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpscatter.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtprange.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpspecialline.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/graphs/jkqtpbarchart.h
)
set(HEADERS_OVERLAY
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/overlays/jkqtpbasicoverlays.h
)
set(HEADERS_GUI
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpcomboboxes.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpenhancedspinboxes.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpenhancedtableview.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkqtpgraphsmodel.h
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/gui/jkvanishqtoolbar.h
)

set(RESOURCES
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/resources/jkqtpbaseplotter.qrc
    ${3RD_PARTY_DIR}/JKQtPlotter/lib/jkqtplotter/resources/jkqtpstyles.qrc
)

    add_library(jkqtplotter STATIC   ${SOURCES} ${SOURCES_GRAPHS} ${SOURCES_GUI} ${SOURCES_OVERLAYS} ${HEADERS} ${HEADERS_GRAPHS} ${HEADERS_GUI} ${HEADERS_OVERLAYS} ${RESOURCES})
    target_link_libraries(jkqtplotter Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport Qt5::Svg Qt5::Xml jkqtcommon jkqtmathtext)


add_subdirectory(src)
