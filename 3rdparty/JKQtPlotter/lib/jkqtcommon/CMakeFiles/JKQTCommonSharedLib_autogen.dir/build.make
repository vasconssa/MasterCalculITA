# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter

# Utility rule file for JKQTCommonSharedLib_autogen.

# Include the progress variables for this target.
include lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/progress.make

lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target JKQTCommonSharedLib"
	cd /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon && /usr/bin/cmake -E cmake_autogen /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/AutogenInfo.cmake ""

JKQTCommonSharedLib_autogen: lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen
JKQTCommonSharedLib_autogen: lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/build.make

.PHONY : JKQTCommonSharedLib_autogen

# Rule to build all files generated by this target.
lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/build: JKQTCommonSharedLib_autogen

.PHONY : lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/build

lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/clean:
	cd /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon && $(CMAKE_COMMAND) -P CMakeFiles/JKQTCommonSharedLib_autogen.dir/cmake_clean.cmake
.PHONY : lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/clean

lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/depend:
	cd /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon /home/vasconssa/Documents/ITA/CES-28/JKQtPlotter/lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/jkqtcommon/CMakeFiles/JKQTCommonSharedLib_autogen.dir/depend

