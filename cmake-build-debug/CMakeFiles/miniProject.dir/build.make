# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\projects\AP\miniProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\projects\AP\miniProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/miniProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/miniProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/miniProject.dir/flags.make

CMakeFiles/miniProject.dir/main.cpp.obj: CMakeFiles/miniProject.dir/flags.make
CMakeFiles/miniProject.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\AP\miniProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/miniProject.dir/main.cpp.obj"
	D:\ProgramFiles\minGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\miniProject.dir\main.cpp.obj -c D:\projects\AP\miniProject\main.cpp

CMakeFiles/miniProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/miniProject.dir/main.cpp.i"
	D:\ProgramFiles\minGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\AP\miniProject\main.cpp > CMakeFiles\miniProject.dir\main.cpp.i

CMakeFiles/miniProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/miniProject.dir/main.cpp.s"
	D:\ProgramFiles\minGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\projects\AP\miniProject\main.cpp -o CMakeFiles\miniProject.dir\main.cpp.s

# Object files for target miniProject
miniProject_OBJECTS = \
"CMakeFiles/miniProject.dir/main.cpp.obj"

# External object files for target miniProject
miniProject_EXTERNAL_OBJECTS =

miniProject.exe: CMakeFiles/miniProject.dir/main.cpp.obj
miniProject.exe: CMakeFiles/miniProject.dir/build.make
miniProject.exe: CMakeFiles/miniProject.dir/linklibs.rsp
miniProject.exe: CMakeFiles/miniProject.dir/objects1.rsp
miniProject.exe: CMakeFiles/miniProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\projects\AP\miniProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable miniProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\miniProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/miniProject.dir/build: miniProject.exe

.PHONY : CMakeFiles/miniProject.dir/build

CMakeFiles/miniProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\miniProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/miniProject.dir/clean

CMakeFiles/miniProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\projects\AP\miniProject D:\projects\AP\miniProject D:\projects\AP\miniProject\cmake-build-debug D:\projects\AP\miniProject\cmake-build-debug D:\projects\AP\miniProject\cmake-build-debug\CMakeFiles\miniProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/miniProject.dir/depend

