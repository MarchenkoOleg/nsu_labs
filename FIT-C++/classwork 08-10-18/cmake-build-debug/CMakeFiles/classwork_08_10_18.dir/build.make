# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = C:\Users\march\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\183.2940.13\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\march\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\183.2940.13\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\march\CLionProjects\classwork 08-10-18"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\march\CLionProjects\classwork 08-10-18\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/classwork_08_10_18.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/classwork_08_10_18.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/classwork_08_10_18.dir/flags.make

CMakeFiles/classwork_08_10_18.dir/main.cpp.obj: CMakeFiles/classwork_08_10_18.dir/flags.make
CMakeFiles/classwork_08_10_18.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\march\CLionProjects\classwork 08-10-18\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/classwork_08_10_18.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\classwork_08_10_18.dir\main.cpp.obj -c "C:\Users\march\CLionProjects\classwork 08-10-18\main.cpp"

CMakeFiles/classwork_08_10_18.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/classwork_08_10_18.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\march\CLionProjects\classwork 08-10-18\main.cpp" > CMakeFiles\classwork_08_10_18.dir\main.cpp.i

CMakeFiles/classwork_08_10_18.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/classwork_08_10_18.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\march\CLionProjects\classwork 08-10-18\main.cpp" -o CMakeFiles\classwork_08_10_18.dir\main.cpp.s

# Object files for target classwork_08_10_18
classwork_08_10_18_OBJECTS = \
"CMakeFiles/classwork_08_10_18.dir/main.cpp.obj"

# External object files for target classwork_08_10_18
classwork_08_10_18_EXTERNAL_OBJECTS =

classwork_08_10_18.exe: CMakeFiles/classwork_08_10_18.dir/main.cpp.obj
classwork_08_10_18.exe: CMakeFiles/classwork_08_10_18.dir/build.make
classwork_08_10_18.exe: CMakeFiles/classwork_08_10_18.dir/linklibs.rsp
classwork_08_10_18.exe: CMakeFiles/classwork_08_10_18.dir/objects1.rsp
classwork_08_10_18.exe: CMakeFiles/classwork_08_10_18.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\march\CLionProjects\classwork 08-10-18\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable classwork_08_10_18.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\classwork_08_10_18.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/classwork_08_10_18.dir/build: classwork_08_10_18.exe

.PHONY : CMakeFiles/classwork_08_10_18.dir/build

CMakeFiles/classwork_08_10_18.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\classwork_08_10_18.dir\cmake_clean.cmake
.PHONY : CMakeFiles/classwork_08_10_18.dir/clean

CMakeFiles/classwork_08_10_18.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\march\CLionProjects\classwork 08-10-18" "C:\Users\march\CLionProjects\classwork 08-10-18" "C:\Users\march\CLionProjects\classwork 08-10-18\cmake-build-debug" "C:\Users\march\CLionProjects\classwork 08-10-18\cmake-build-debug" "C:\Users\march\CLionProjects\classwork 08-10-18\cmake-build-debug\CMakeFiles\classwork_08_10_18.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/classwork_08_10_18.dir/depend

