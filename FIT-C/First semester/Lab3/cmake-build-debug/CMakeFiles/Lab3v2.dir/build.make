# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Oleg\CLionProjects\Lab3v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Oleg\CLionProjects\Lab3v2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab3v2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab3v2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab3v2.dir/flags.make

CMakeFiles/Lab3v2.dir/main.c.obj: CMakeFiles/Lab3v2.dir/flags.make
CMakeFiles/Lab3v2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Oleg\CLionProjects\Lab3v2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab3v2.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Lab3v2.dir\main.c.obj   -c C:\Users\Oleg\CLionProjects\Lab3v2\main.c

CMakeFiles/Lab3v2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab3v2.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Oleg\CLionProjects\Lab3v2\main.c > CMakeFiles\Lab3v2.dir\main.c.i

CMakeFiles/Lab3v2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab3v2.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Oleg\CLionProjects\Lab3v2\main.c -o CMakeFiles\Lab3v2.dir\main.c.s

CMakeFiles/Lab3v2.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Lab3v2.dir/main.c.obj.requires

CMakeFiles/Lab3v2.dir/main.c.obj.provides: CMakeFiles/Lab3v2.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Lab3v2.dir\build.make CMakeFiles/Lab3v2.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Lab3v2.dir/main.c.obj.provides

CMakeFiles/Lab3v2.dir/main.c.obj.provides.build: CMakeFiles/Lab3v2.dir/main.c.obj


# Object files for target Lab3v2
Lab3v2_OBJECTS = \
"CMakeFiles/Lab3v2.dir/main.c.obj"

# External object files for target Lab3v2
Lab3v2_EXTERNAL_OBJECTS =

Lab3v2.exe: CMakeFiles/Lab3v2.dir/main.c.obj
Lab3v2.exe: CMakeFiles/Lab3v2.dir/build.make
Lab3v2.exe: CMakeFiles/Lab3v2.dir/linklibs.rsp
Lab3v2.exe: CMakeFiles/Lab3v2.dir/objects1.rsp
Lab3v2.exe: CMakeFiles/Lab3v2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Oleg\CLionProjects\Lab3v2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab3v2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab3v2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab3v2.dir/build: Lab3v2.exe

.PHONY : CMakeFiles/Lab3v2.dir/build

CMakeFiles/Lab3v2.dir/requires: CMakeFiles/Lab3v2.dir/main.c.obj.requires

.PHONY : CMakeFiles/Lab3v2.dir/requires

CMakeFiles/Lab3v2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab3v2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab3v2.dir/clean

CMakeFiles/Lab3v2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Oleg\CLionProjects\Lab3v2 C:\Users\Oleg\CLionProjects\Lab3v2 C:\Users\Oleg\CLionProjects\Lab3v2\cmake-build-debug C:\Users\Oleg\CLionProjects\Lab3v2\cmake-build-debug C:\Users\Oleg\CLionProjects\Lab3v2\cmake-build-debug\CMakeFiles\Lab3v2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab3v2.dir/depend

