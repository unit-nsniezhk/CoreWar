# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Users/dderevyn/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/dderevyn/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dderevyn/CLionProjects/corewar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dderevyn/CLionProjects/corewar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/corewar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/corewar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/corewar.dir/flags.make

CMakeFiles/corewar.dir/srcs/corewar.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/srcs/corewar.c.o: ../srcs/corewar.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dderevyn/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/corewar.dir/srcs/corewar.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/srcs/corewar.c.o   -c /Users/dderevyn/CLionProjects/corewar/srcs/corewar.c

CMakeFiles/corewar.dir/srcs/corewar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/srcs/corewar.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dderevyn/CLionProjects/corewar/srcs/corewar.c > CMakeFiles/corewar.dir/srcs/corewar.c.i

CMakeFiles/corewar.dir/srcs/corewar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/srcs/corewar.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dderevyn/CLionProjects/corewar/srcs/corewar.c -o CMakeFiles/corewar.dir/srcs/corewar.c.s

CMakeFiles/corewar.dir/srcs/parse.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/srcs/parse.c.o: ../srcs/parse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dderevyn/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/corewar.dir/srcs/parse.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/srcs/parse.c.o   -c /Users/dderevyn/CLionProjects/corewar/srcs/parse.c

CMakeFiles/corewar.dir/srcs/parse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/srcs/parse.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dderevyn/CLionProjects/corewar/srcs/parse.c > CMakeFiles/corewar.dir/srcs/parse.c.i

CMakeFiles/corewar.dir/srcs/parse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/srcs/parse.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dderevyn/CLionProjects/corewar/srcs/parse.c -o CMakeFiles/corewar.dir/srcs/parse.c.s

CMakeFiles/corewar.dir/srcs/parse_champion.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/srcs/parse_champion.c.o: ../srcs/parse_champion.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dderevyn/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/corewar.dir/srcs/parse_champion.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/srcs/parse_champion.c.o   -c /Users/dderevyn/CLionProjects/corewar/srcs/parse_champion.c

CMakeFiles/corewar.dir/srcs/parse_champion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/srcs/parse_champion.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dderevyn/CLionProjects/corewar/srcs/parse_champion.c > CMakeFiles/corewar.dir/srcs/parse_champion.c.i

CMakeFiles/corewar.dir/srcs/parse_champion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/srcs/parse_champion.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dderevyn/CLionProjects/corewar/srcs/parse_champion.c -o CMakeFiles/corewar.dir/srcs/parse_champion.c.s

CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.o: ../srcs/parse_champion_loop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dderevyn/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.o   -c /Users/dderevyn/CLionProjects/corewar/srcs/parse_champion_loop.c

CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dderevyn/CLionProjects/corewar/srcs/parse_champion_loop.c > CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.i

CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dderevyn/CLionProjects/corewar/srcs/parse_champion_loop.c -o CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.s

# Object files for target corewar
corewar_OBJECTS = \
"CMakeFiles/corewar.dir/srcs/corewar.c.o" \
"CMakeFiles/corewar.dir/srcs/parse.c.o" \
"CMakeFiles/corewar.dir/srcs/parse_champion.c.o" \
"CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.o"

# External object files for target corewar
corewar_EXTERNAL_OBJECTS =

corewar: CMakeFiles/corewar.dir/srcs/corewar.c.o
corewar: CMakeFiles/corewar.dir/srcs/parse.c.o
corewar: CMakeFiles/corewar.dir/srcs/parse_champion.c.o
corewar: CMakeFiles/corewar.dir/srcs/parse_champion_loop.c.o
corewar: CMakeFiles/corewar.dir/build.make
corewar: CMakeFiles/corewar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dderevyn/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable corewar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/corewar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/corewar.dir/build: corewar

.PHONY : CMakeFiles/corewar.dir/build

CMakeFiles/corewar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/corewar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/corewar.dir/clean

CMakeFiles/corewar.dir/depend:
	cd /Users/dderevyn/CLionProjects/corewar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dderevyn/CLionProjects/corewar /Users/dderevyn/CLionProjects/corewar /Users/dderevyn/CLionProjects/corewar/cmake-build-debug /Users/dderevyn/CLionProjects/corewar/cmake-build-debug /Users/dderevyn/CLionProjects/corewar/cmake-build-debug/CMakeFiles/corewar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/corewar.dir/depend
