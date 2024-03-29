include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${EIGEN3_INCLUDE_DIR})

file(GLOB_RECURSE UIS *.ui)
file(GLOB_RECURSE HDRS *.h)
file(GLOB_RECURSE HPPDRS *.hpp)
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE C_SRCS *.c)
file(GLOB_RECURSE MAINS main*.cpp)
list(REMOVE_ITEM SRCS ${MAINS})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

qt5_wrap_ui( UI_HEADERS ${UIS})
qt5_add_resources( QRCS resources.qrc )

find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" ${SRCS} ${C_SRCS} ${HDRS} ${HPPDRS} ${UI_HEADERS} ${QRCS})


include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Sql jkqtcommon jkqtmathtext ${PYTHON_LIBRARIES})
