# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/apolinario/catkin_ventsup_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/apolinario/catkin_ventsup_ws/build

# Include any dependencies generated for this target.
include ethernet/CMakeFiles/socket_server.dir/depend.make

# Include the progress variables for this target.
include ethernet/CMakeFiles/socket_server.dir/progress.make

# Include the compile flags for this target's objects.
include ethernet/CMakeFiles/socket_server.dir/flags.make

ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o: ethernet/CMakeFiles/socket_server.dir/flags.make
ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o: /home/apolinario/catkin_ventsup_ws/src/ethernet/src/socket_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apolinario/catkin_ventsup_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o"
	cd /home/apolinario/catkin_ventsup_ws/build/ethernet && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket_server.dir/src/socket_server.cpp.o -c /home/apolinario/catkin_ventsup_ws/src/ethernet/src/socket_server.cpp

ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket_server.dir/src/socket_server.cpp.i"
	cd /home/apolinario/catkin_ventsup_ws/build/ethernet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apolinario/catkin_ventsup_ws/src/ethernet/src/socket_server.cpp > CMakeFiles/socket_server.dir/src/socket_server.cpp.i

ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket_server.dir/src/socket_server.cpp.s"
	cd /home/apolinario/catkin_ventsup_ws/build/ethernet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apolinario/catkin_ventsup_ws/src/ethernet/src/socket_server.cpp -o CMakeFiles/socket_server.dir/src/socket_server.cpp.s

ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.requires:

.PHONY : ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.requires

ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.provides: ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.requires
	$(MAKE) -f ethernet/CMakeFiles/socket_server.dir/build.make ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.provides.build
.PHONY : ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.provides

ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.provides.build: ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o


# Object files for target socket_server
socket_server_OBJECTS = \
"CMakeFiles/socket_server.dir/src/socket_server.cpp.o"

# External object files for target socket_server
socket_server_EXTERNAL_OBJECTS =

/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: ethernet/CMakeFiles/socket_server.dir/build.make
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/libroscpp.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/librosconsole.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/libroslib.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/librospack.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /home/apolinario/catkin_ventsup_ws/devel/lib/libserial.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/librt.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/librostime.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /opt/ros/melodic/lib/libcpp_common.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server: ethernet/CMakeFiles/socket_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/apolinario/catkin_ventsup_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server"
	cd /home/apolinario/catkin_ventsup_ws/build/ethernet && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/socket_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ethernet/CMakeFiles/socket_server.dir/build: /home/apolinario/catkin_ventsup_ws/devel/lib/ethernet/socket_server

.PHONY : ethernet/CMakeFiles/socket_server.dir/build

ethernet/CMakeFiles/socket_server.dir/requires: ethernet/CMakeFiles/socket_server.dir/src/socket_server.cpp.o.requires

.PHONY : ethernet/CMakeFiles/socket_server.dir/requires

ethernet/CMakeFiles/socket_server.dir/clean:
	cd /home/apolinario/catkin_ventsup_ws/build/ethernet && $(CMAKE_COMMAND) -P CMakeFiles/socket_server.dir/cmake_clean.cmake
.PHONY : ethernet/CMakeFiles/socket_server.dir/clean

ethernet/CMakeFiles/socket_server.dir/depend:
	cd /home/apolinario/catkin_ventsup_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/apolinario/catkin_ventsup_ws/src /home/apolinario/catkin_ventsup_ws/src/ethernet /home/apolinario/catkin_ventsup_ws/build /home/apolinario/catkin_ventsup_ws/build/ethernet /home/apolinario/catkin_ventsup_ws/build/ethernet/CMakeFiles/socket_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ethernet/CMakeFiles/socket_server.dir/depend

