# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Gavin T McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Gavin T McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/project2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project2.dir/flags.make

CMakeFiles/project2.dir/main.c.obj: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/main.c.obj: ../main.c
CMakeFiles/project2.dir/main.c.obj: CMakeFiles/project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project2.dir/main.c.obj"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/project2.dir/main.c.obj -MF CMakeFiles\project2.dir\main.c.obj.d -o CMakeFiles\project2.dir\main.c.obj -c "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\main.c"

CMakeFiles/project2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project2.dir/main.c.i"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\main.c" > CMakeFiles\project2.dir\main.c.i

CMakeFiles/project2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project2.dir/main.c.s"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\main.c" -o CMakeFiles\project2.dir\main.c.s

CMakeFiles/project2.dir/mythreads.c.obj: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/mythreads.c.obj: ../mythreads.c
CMakeFiles/project2.dir/mythreads.c.obj: CMakeFiles/project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/project2.dir/mythreads.c.obj"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/project2.dir/mythreads.c.obj -MF CMakeFiles\project2.dir\mythreads.c.obj.d -o CMakeFiles\project2.dir\mythreads.c.obj -c "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\mythreads.c"

CMakeFiles/project2.dir/mythreads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project2.dir/mythreads.c.i"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\mythreads.c" > CMakeFiles\project2.dir\mythreads.c.i

CMakeFiles/project2.dir/mythreads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project2.dir/mythreads.c.s"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\mythreads.c" -o CMakeFiles\project2.dir\mythreads.c.s

CMakeFiles/project2.dir/helper.c.obj: CMakeFiles/project2.dir/flags.make
CMakeFiles/project2.dir/helper.c.obj: ../helper.c
CMakeFiles/project2.dir/helper.c.obj: CMakeFiles/project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/project2.dir/helper.c.obj"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/project2.dir/helper.c.obj -MF CMakeFiles\project2.dir\helper.c.obj.d -o CMakeFiles\project2.dir\helper.c.obj -c "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\helper.c"

CMakeFiles/project2.dir/helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project2.dir/helper.c.i"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\helper.c" > CMakeFiles\project2.dir\helper.c.i

CMakeFiles/project2.dir/helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project2.dir/helper.c.s"
	C:\Users\GAVINT~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\222434~1.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\helper.c" -o CMakeFiles\project2.dir\helper.c.s

# Object files for target project2
project2_OBJECTS = \
"CMakeFiles/project2.dir/main.c.obj" \
"CMakeFiles/project2.dir/mythreads.c.obj" \
"CMakeFiles/project2.dir/helper.c.obj"

# External object files for target project2
project2_EXTERNAL_OBJECTS =

project2.exe: CMakeFiles/project2.dir/main.c.obj
project2.exe: CMakeFiles/project2.dir/mythreads.c.obj
project2.exe: CMakeFiles/project2.dir/helper.c.obj
project2.exe: CMakeFiles/project2.dir/build.make
project2.exe: CMakeFiles/project2.dir/linklibs.rsp
project2.exe: CMakeFiles/project2.dir/objects1.rsp
project2.exe: CMakeFiles/project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable project2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project2.dir/build: project2.exe
.PHONY : CMakeFiles/project2.dir/build

CMakeFiles/project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project2.dir/clean

CMakeFiles/project2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library" "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library" "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug" "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug" "C:\Users\Gavin T McRoy\Documents\GitHub\Fun-Projects\PThread-Library\cmake-build-debug\CMakeFiles\project2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/project2.dir/depend

