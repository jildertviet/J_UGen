# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/build

# Include any dependencies generated for this target.
include CMakeFiles/JBufferSender_supernova.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/JBufferSender_supernova.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/JBufferSender_supernova.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JBufferSender_supernova.dir/flags.make

CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o: CMakeFiles/JBufferSender_supernova.dir/flags.make
CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o: /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/plugins/JBufferSender/JBufferSender.cpp
CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o: CMakeFiles/JBufferSender_supernova.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o -MF CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o.d -o CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o -c /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/plugins/JBufferSender/JBufferSender.cpp

CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/plugins/JBufferSender/JBufferSender.cpp > CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.i

CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/plugins/JBufferSender/JBufferSender.cpp -o CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.s

# Object files for target JBufferSender_supernova
JBufferSender_supernova_OBJECTS = \
"CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o"

# External object files for target JBufferSender_supernova
JBufferSender_supernova_EXTERNAL_OBJECTS =

JBufferSender_supernova.so: CMakeFiles/JBufferSender_supernova.dir/plugins/JBufferSender/JBufferSender.cpp.o
JBufferSender_supernova.so: CMakeFiles/JBufferSender_supernova.dir/build.make
JBufferSender_supernova.so: CMakeFiles/JBufferSender_supernova.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module JBufferSender_supernova.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JBufferSender_supernova.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JBufferSender_supernova.dir/build: JBufferSender_supernova.so
.PHONY : CMakeFiles/JBufferSender_supernova.dir/build

CMakeFiles/JBufferSender_supernova.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JBufferSender_supernova.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JBufferSender_supernova.dir/clean

CMakeFiles/JBufferSender_supernova.dir/depend:
	cd /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/build /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/build /home/jildert/.local/share/SuperCollider/Extensions/J_UGen/jbuffersender/build/CMakeFiles/JBufferSender_supernova.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JBufferSender_supernova.dir/depend

