# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /mnt/shared/flow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/shared/flow/Debug

# Include any dependencies generated for this target.
include server/CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/server.dir/flags.make

server/CMakeFiles/server.dir/main.cc.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/main.cc.o: ../server/main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/server.dir/main.cc.o"
	cd /mnt/shared/flow/Debug/server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/main.cc.o -c /mnt/shared/flow/server/main.cc

server/CMakeFiles/server.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/main.cc.i"
	cd /mnt/shared/flow/Debug/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/server/main.cc > CMakeFiles/server.dir/main.cc.i

server/CMakeFiles/server.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/main.cc.s"
	cd /mnt/shared/flow/Debug/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/server/main.cc -o CMakeFiles/server.dir/main.cc.s

server/CMakeFiles/server.dir/main.cc.o.requires:
.PHONY : server/CMakeFiles/server.dir/main.cc.o.requires

server/CMakeFiles/server.dir/main.cc.o.provides: server/CMakeFiles/server.dir/main.cc.o.requires
	$(MAKE) -f server/CMakeFiles/server.dir/build.make server/CMakeFiles/server.dir/main.cc.o.provides.build
.PHONY : server/CMakeFiles/server.dir/main.cc.o.provides

server/CMakeFiles/server.dir/main.cc.o.provides.build: server/CMakeFiles/server.dir/main.cc.o

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/main.cc.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

../bin/server: server/CMakeFiles/server.dir/main.cc.o
../bin/server: server/CMakeFiles/server.dir/build.make
../bin/server: ../lib/libflow_framework.a
../bin/server: server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/server"
	cd /mnt/shared/flow/Debug/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/CMakeFiles/server.dir/build: ../bin/server
.PHONY : server/CMakeFiles/server.dir/build

server/CMakeFiles/server.dir/requires: server/CMakeFiles/server.dir/main.cc.o.requires
.PHONY : server/CMakeFiles/server.dir/requires

server/CMakeFiles/server.dir/clean:
	cd /mnt/shared/flow/Debug/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : server/CMakeFiles/server.dir/clean

server/CMakeFiles/server.dir/depend:
	cd /mnt/shared/flow/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/shared/flow /mnt/shared/flow/server /mnt/shared/flow/Debug /mnt/shared/flow/Debug/server /mnt/shared/flow/Debug/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/CMakeFiles/server.dir/depend
