# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CoffeeBox.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CoffeeBox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CoffeeBox.dir/flags.make

CMakeFiles/CoffeeBox.dir/main.cpp.o: CMakeFiles/CoffeeBox.dir/flags.make
CMakeFiles/CoffeeBox.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CoffeeBox.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoffeeBox.dir/main.cpp.o -c /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/main.cpp

CMakeFiles/CoffeeBox.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoffeeBox.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/main.cpp > CMakeFiles/CoffeeBox.dir/main.cpp.i

CMakeFiles/CoffeeBox.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoffeeBox.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/main.cpp -o CMakeFiles/CoffeeBox.dir/main.cpp.s

# Object files for target CoffeeBox
CoffeeBox_OBJECTS = \
"CMakeFiles/CoffeeBox.dir/main.cpp.o"

# External object files for target CoffeeBox
CoffeeBox_EXTERNAL_OBJECTS =

CoffeeBox: CMakeFiles/CoffeeBox.dir/main.cpp.o
CoffeeBox: CMakeFiles/CoffeeBox.dir/build.make
CoffeeBox: CMakeFiles/CoffeeBox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CoffeeBox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CoffeeBox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CoffeeBox.dir/build: CoffeeBox
.PHONY : CMakeFiles/CoffeeBox.dir/build

CMakeFiles/CoffeeBox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CoffeeBox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CoffeeBox.dir/clean

CMakeFiles/CoffeeBox.dir/depend:
	cd /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/cmake-build-debug /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/cmake-build-debug /Users/ilyabenikov/CLionProjects/Projects/CoffeeBox/cmake-build-debug/CMakeFiles/CoffeeBox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CoffeeBox.dir/depend

