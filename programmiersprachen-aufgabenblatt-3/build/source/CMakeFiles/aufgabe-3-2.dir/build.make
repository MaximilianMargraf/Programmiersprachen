# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build

# Include any dependencies generated for this target.
include source/CMakeFiles/aufgabe-3-2.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/aufgabe-3-2.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/aufgabe-3-2.dir/flags.make

source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o: source/CMakeFiles/aufgabe-3-2.dir/flags.make
source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o: ../source/aufgabe-3-2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o"
	cd /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/source && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o -c /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/source/aufgabe-3-2.cpp

source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.i"
	cd /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/source/aufgabe-3-2.cpp > CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.i

source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.s"
	cd /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/source/aufgabe-3-2.cpp -o CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.s

source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.requires:

.PHONY : source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.requires

source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.provides: source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/aufgabe-3-2.dir/build.make source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.provides.build
.PHONY : source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.provides

source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.provides.build: source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o


# Object files for target aufgabe-3-2
aufgabe__3__2_OBJECTS = \
"CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o"

# External object files for target aufgabe-3-2
aufgabe__3__2_EXTERNAL_OBJECTS =

source/aufgabe-3-2: source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o
source/aufgabe-3-2: source/CMakeFiles/aufgabe-3-2.dir/build.make
source/aufgabe-3-2: source/CMakeFiles/aufgabe-3-2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aufgabe-3-2"
	cd /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aufgabe-3-2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/aufgabe-3-2.dir/build: source/aufgabe-3-2

.PHONY : source/CMakeFiles/aufgabe-3-2.dir/build

source/CMakeFiles/aufgabe-3-2.dir/requires: source/CMakeFiles/aufgabe-3-2.dir/aufgabe-3-2.cpp.o.requires

.PHONY : source/CMakeFiles/aufgabe-3-2.dir/requires

source/CMakeFiles/aufgabe-3-2.dir/clean:
	cd /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/source && $(CMAKE_COMMAND) -P CMakeFiles/aufgabe-3-2.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/aufgabe-3-2.dir/clean

source/CMakeFiles/aufgabe-3-2.dir/depend:
	cd /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3 /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/source /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/source /home/lyrrok/Documents/Programmiersprachen/programmiersprachen-aufgabenblatt-3/build/source/CMakeFiles/aufgabe-3-2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/aufgabe-3-2.dir/depend

