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
CMAKE_COMMAND = C:/Users/Sxing/scoop/apps/cmake/3.20.3/bin/cmake.exe

# The command to remove a file.
RM = C:/Users/Sxing/scoop/apps/cmake/3.20.3/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:/Users/Sxing/OneDrive/2020_2/C/10#"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:/Users/Sxing/OneDrive/2020_2/C/10#/build"

# Include any dependencies generated for this target.
include CMakeFiles/10_.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/10_.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/10_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/10_.dir/flags.make

CMakeFiles/10_.dir/main.c.obj: CMakeFiles/10_.dir/flags.make
CMakeFiles/10_.dir/main.c.obj: ../main.c
CMakeFiles/10_.dir/main.c.obj: CMakeFiles/10_.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:/Users/Sxing/OneDrive/2020_2/C/10#/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/10_.dir/main.c.obj"
	C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/10_.dir/main.c.obj -MF CMakeFiles/10_.dir/main.c.obj.d -o CMakeFiles/10_.dir/main.c.obj -c "C:/Users/Sxing/OneDrive/2020_2/C/10#/main.c"

CMakeFiles/10_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/10_.dir/main.c.i"
	C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:/Users/Sxing/OneDrive/2020_2/C/10#/main.c" > CMakeFiles/10_.dir/main.c.i

CMakeFiles/10_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/10_.dir/main.c.s"
	C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:/Users/Sxing/OneDrive/2020_2/C/10#/main.c" -o CMakeFiles/10_.dir/main.c.s

# Object files for target 10_
10__OBJECTS = \
"CMakeFiles/10_.dir/main.c.obj"

# External object files for target 10_
10__EXTERNAL_OBJECTS =

10_.exe: CMakeFiles/10_.dir/main.c.obj
10_.exe: CMakeFiles/10_.dir/build.make
10_.exe: CMakeFiles/10_.dir/linklibs.rsp
10_.exe: CMakeFiles/10_.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:/Users/Sxing/OneDrive/2020_2/C/10#/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 10_.exe"
	C:/Users/Sxing/scoop/apps/cmake/3.20.3/bin/cmake.exe -E rm -f CMakeFiles/10_.dir/objects.a
	C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/ar.exe cr CMakeFiles/10_.dir/objects.a @CMakeFiles/10_.dir/objects1.rsp
	C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe -g -Wl,--whole-archive CMakeFiles/10_.dir/objects.a -Wl,--no-whole-archive -o 10_.exe -Wl,--out-implib,lib10_.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/10_.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/10_.dir/build: 10_.exe
.PHONY : CMakeFiles/10_.dir/build

CMakeFiles/10_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/10_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/10_.dir/clean

CMakeFiles/10_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "C:/Users/Sxing/OneDrive/2020_2/C/10#" "C:/Users/Sxing/OneDrive/2020_2/C/10#" "C:/Users/Sxing/OneDrive/2020_2/C/10#/build" "C:/Users/Sxing/OneDrive/2020_2/C/10#/build" "C:/Users/Sxing/OneDrive/2020_2/C/10#/build/CMakeFiles/10_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/10_.dir/depend

