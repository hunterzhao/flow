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
include src/CMakeFiles/flow_framework_so.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/flow_framework_so.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/flow_framework_so.dir/flags.make

src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o: ../src/flow_loop.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_loop.cc.o -c /mnt/shared/flow/src/flow_loop.cc

src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_loop.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_loop.cc > CMakeFiles/flow_framework_so.dir/flow_loop.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_loop.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_loop.cc -o CMakeFiles/flow_framework_so.dir/flow_loop.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o: ../src/flow_message.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_message.cc.o -c /mnt/shared/flow/src/flow_message.cc

src/CMakeFiles/flow_framework_so.dir/flow_message.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_message.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_message.cc > CMakeFiles/flow_framework_so.dir/flow_message.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_message.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_message.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_message.cc -o CMakeFiles/flow_framework_so.dir/flow_message.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o: ../src/flow_tcp_handle.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o -c /mnt/shared/flow/src/flow_tcp_handle.cc

src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_tcp_handle.cc > CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_tcp_handle.cc -o CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o: ../src/flow_queue.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_queue.cc.o -c /mnt/shared/flow/src/flow_queue.cc

src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_queue.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_queue.cc > CMakeFiles/flow_framework_so.dir/flow_queue.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_queue.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_queue.cc -o CMakeFiles/flow_framework_so.dir/flow_queue.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o: ../src/flow_stage.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_stage.cc.o -c /mnt/shared/flow/src/flow_stage.cc

src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_stage.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_stage.cc > CMakeFiles/flow_framework_so.dir/flow_stage.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_stage.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_stage.cc -o CMakeFiles/flow_framework_so.dir/flow_stage.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o: ../src/flow_actor.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_actor.cc.o -c /mnt/shared/flow/src/flow_actor.cc

src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_actor.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_actor.cc > CMakeFiles/flow_framework_so.dir/flow_actor.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_actor.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_actor.cc -o CMakeFiles/flow_framework_so.dir/flow_actor.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o: ../src/flow_server.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_server.cc.o -c /mnt/shared/flow/src/flow_server.cc

src/CMakeFiles/flow_framework_so.dir/flow_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_server.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_server.cc > CMakeFiles/flow_framework_so.dir/flow_server.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_server.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_server.cc -o CMakeFiles/flow_framework_so.dir/flow_server.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o: ../src/flow_client.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_client.cc.o -c /mnt/shared/flow/src/flow_client.cc

src/CMakeFiles/flow_framework_so.dir/flow_client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_client.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_client.cc > CMakeFiles/flow_framework_so.dir/flow_client.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_client.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_client.cc -o CMakeFiles/flow_framework_so.dir/flow_client.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o: ../src/flow_session.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_session.cc.o -c /mnt/shared/flow/src/flow_session.cc

src/CMakeFiles/flow_framework_so.dir/flow_session.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_session.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_session.cc > CMakeFiles/flow_framework_so.dir/flow_session.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_session.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_session.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_session.cc -o CMakeFiles/flow_framework_so.dir/flow_session.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o: ../src/flow_log.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_log.cc.o -c /mnt/shared/flow/src/flow_log.cc

src/CMakeFiles/flow_framework_so.dir/flow_log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_log.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_log.cc > CMakeFiles/flow_framework_so.dir/flow_log.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_log.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_log.cc -o CMakeFiles/flow_framework_so.dir/flow_log.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o: ../src/flow_publisher.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o -c /mnt/shared/flow/src/flow_publisher.cc

src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_publisher.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_publisher.cc > CMakeFiles/flow_framework_so.dir/flow_publisher.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_publisher.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_publisher.cc -o CMakeFiles/flow_framework_so.dir/flow_publisher.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o

src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o: src/CMakeFiles/flow_framework_so.dir/flags.make
src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o: ../src/flow_manager.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/shared/flow/Debug/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flow_framework_so.dir/flow_manager.cc.o -c /mnt/shared/flow/src/flow_manager.cc

src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flow_framework_so.dir/flow_manager.cc.i"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/shared/flow/src/flow_manager.cc > CMakeFiles/flow_framework_so.dir/flow_manager.cc.i

src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flow_framework_so.dir/flow_manager.cc.s"
	cd /mnt/shared/flow/Debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/shared/flow/src/flow_manager.cc -o CMakeFiles/flow_framework_so.dir/flow_manager.cc.s

src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.requires:
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.requires

src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.provides: src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.requires
	$(MAKE) -f src/CMakeFiles/flow_framework_so.dir/build.make src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.provides.build
.PHONY : src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.provides

src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.provides.build: src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o

# Object files for target flow_framework_so
flow_framework_so_OBJECTS = \
"CMakeFiles/flow_framework_so.dir/flow_loop.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_message.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_queue.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_stage.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_actor.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_server.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_client.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_session.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_log.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o" \
"CMakeFiles/flow_framework_so.dir/flow_manager.cc.o"

# External object files for target flow_framework_so
flow_framework_so_EXTERNAL_OBJECTS =

../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/build.make
../lib/libflow_framework.so: src/CMakeFiles/flow_framework_so.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/libflow_framework.so"
	cd /mnt/shared/flow/Debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flow_framework_so.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/flow_framework_so.dir/build: ../lib/libflow_framework.so
.PHONY : src/CMakeFiles/flow_framework_so.dir/build

src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_loop.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_message.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_tcp_handle.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_queue.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_stage.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_actor.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_server.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_client.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_session.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_log.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_publisher.cc.o.requires
src/CMakeFiles/flow_framework_so.dir/requires: src/CMakeFiles/flow_framework_so.dir/flow_manager.cc.o.requires
.PHONY : src/CMakeFiles/flow_framework_so.dir/requires

src/CMakeFiles/flow_framework_so.dir/clean:
	cd /mnt/shared/flow/Debug/src && $(CMAKE_COMMAND) -P CMakeFiles/flow_framework_so.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/flow_framework_so.dir/clean

src/CMakeFiles/flow_framework_so.dir/depend:
	cd /mnt/shared/flow/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/shared/flow /mnt/shared/flow/src /mnt/shared/flow/Debug /mnt/shared/flow/Debug/src /mnt/shared/flow/Debug/src/CMakeFiles/flow_framework_so.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/flow_framework_so.dir/depend

