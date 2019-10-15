include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
include_directories(${EIGEN3_INCLUDE_DIR})

file(GLOB_RECURSE UIS *.ui)
file(GLOB_RECURSE HDRS *.h)
file(GLOB_RECURSE HPPDRS *.hpp)
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE C_SRCS *.c)
file(GLOB_RECURSE MAINS main*.cpp)
list(REMOVE_ITEM SRCS ${MAINS})


qt5_wrap_ui( UI_HEADERS ${UIS})
qt5_add_resources( QRCS resources.qrc )

add_executable(${PROJECT_NAME} "main.cpp" ${SRCS} ${C_SRCS} ${HDRS} ${HPPDRS} ${UI_HEADERS} ${QRCS})


target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)