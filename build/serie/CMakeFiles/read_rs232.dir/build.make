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
include serie/CMakeFiles/read_rs232.dir/depend.make

# Include the progress variables for this target.
include serie/CMakeFiles/read_rs232.dir/progress.make

# Include the compile flags for this target's objects.
include serie/CMakeFiles/read_rs232.dir/flags.make

serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o: serie/CMakeFiles/read_rs232.dir/flags.make
serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o: /home/apolinario/catkin_ventsup_ws/src/serie/src/read_rs232.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apolinario/catkin_ventsup_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o"
	cd /home/apolinario/catkin_ventsup_ws/build/serie && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o -c /home/apolinario/catkin_ventsup_ws/src/serie/src/read_rs232.cpp

serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/read_rs232.dir/src/read_rs232.cpp.i"
	cd /home/apolinario/catkin_ventsup_ws/build/serie && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apolinario/catkin_ventsup_ws/src/serie/src/read_rs232.cpp > CMakeFiles/read_rs232.dir/src/read_rs232.cpp.i

serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/read_rs232.dir/src/read_rs232.cpp.s"
	cd /home/apolinario/catkin_ventsup_ws/build/serie && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apolinario/catkin_ventsup_ws/src/serie/src/read_rs232.cpp -o CMakeFiles/read_rs232.dir/src/read_rs232.cpp.s

serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.requires:

.PHONY : serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.requires

serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.provides: serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.requires
	$(MAKE) -f serie/CMakeFiles/read_rs232.dir/build.make serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.provides.build
.PHONY : serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.provides

serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.provides.build: serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o


# Object files for target read_rs232
read_rs232_OBJECTS = \
"CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o"

# External object files for target read_rs232
read_rs232_EXTERNAL_OBJECTS =

/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: serie/CMakeFiles/read_rs232.dir/build.make
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/libroscpp.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/librosconsole.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/librospack.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /home/apolinario/catkin_ventsup_ws/devel/lib/libserial.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/librt.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/librostime.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /opt/ros/melodic/lib/libcpp_common.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232: serie/CMakeFiles/read_rs232.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/apolinario/catkin_ventsup_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232"
	cd /home/apolinario/catkin_ventsup_ws/build/serie && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/read_rs232.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
serie/CMakeFiles/read_rs232.dir/build: /home/apolinario/catkin_ventsup_ws/devel/lib/serie/read_rs232

.PHONY : serie/CMakeFiles/read_rs232.dir/build

serie/CMakeFiles/read_rs232.dir/requires: serie/CMakeFiles/read_rs232.dir/src/read_rs232.cpp.o.requires

.PHONY : serie/CMakeFiles/read_rs232.dir/requires

serie/CMakeFiles/read_rs232.dir/clean:
	cd /home/apolinario/catkin_ventsup_ws/build/serie && $(CMAKE_COMMAND) -P CMakeFiles/read_rs232.dir/cmake_clean.cmake
.PHONY : serie/CMakeFiles/read_rs232.dir/clean

serie/CMakeFiles/read_rs232.dir/depend:
	cd /home/apolinario/catkin_ventsup_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/apolinario/catkin_ventsup_ws/src /home/apolinario/catkin_ventsup_ws/src/serie /home/apolinario/catkin_ventsup_ws/build /home/apolinario/catkin_ventsup_ws/build/serie /home/apolinario/catkin_ventsup_ws/build/serie/CMakeFiles/read_rs232.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serie/CMakeFiles/read_rs232.dir/depend

