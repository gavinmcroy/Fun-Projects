# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-1/211.7628.27/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-1/211.7628.27/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project2.dir/flags.make

CMakeFiles/project2.dir/main.c.o: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project2.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project2.dir/main.c.o -c /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/main.c

CMakeFiles/project2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project2.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/main.c > CMakeFiles/project2.dir/main.c.i

CMakeFiles/project2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project2.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/main.c -o CMakeFiles/project2.dir/main.c.s

CMakeFiles/project2.dir/mythreads.c.o: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/mythreads.c.o: ../mythreads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/project2.dir/mythreads.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project2.dir/mythreads.c.o -c /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/mythreads.c

CMakeFiles/project2.dir/mythreads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project2.dir/mythreads.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/mythreads.c > CMakeFiles/project2.dir/mythreads.c.i

CMakeFiles/project2.dir/mythreads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project2.dir/mythreads.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/mythreads.c -o CMakeFiles/project2.dir/mythreads.c.s

CMakeFiles/project2.dir/helper.c.o: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/helper.c.o: ../helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/project2.dir/helper.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project2.dir/helper.c.o -c /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/helper.c

CMakeFiles/project2.dir/helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project2.dir/helper.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/helper.c > CMakeFiles/project2.dir/helper.c.i

CMakeFiles/project2.dir/helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project2.dir/helper.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/helper.c -o CMakeFiles/project2.dir/helper.c.s

# Object files for target project2
project2_OBJECTS = \
"CMakeFiles/project2.dir/main.c.o" \
"CMakeFiles/project2.dir/mythreads.c.o" \
"CMakeFiles/project2.dir/helper.c.o"

# External object files for target project2
project2_EXTERNAL_OBJECTS =

project2: CMakeFiles/project2.dir/main.c.o
project2: CMakeFiles/project2.dir/mythreads.c.o
project2: CMakeFiles/project2.dir/helper.c.o
project2: CMakeFiles/project2.dir/build.make
project2: CMakeFiles/project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable project2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project2.dir/build: project2

.PHONY : CMakeFiles/project2.dir/build

CMakeFiles/project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project2.dir/clean

CMakeFiles/project2.dir/depend:
	cd /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2 /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2 /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug /Users/gavintaylormcroy/Documents/GitHub/School-Rep/project2/cmake-build-debug/CMakeFiles/project2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project2.dir/depend
