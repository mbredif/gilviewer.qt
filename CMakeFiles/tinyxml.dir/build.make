# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/olivier/work/dev/lib/gilviewer.repo/branch-icons

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olivier/work/dev/lib/gilviewer.repo/branch-icons

# Include any dependencies generated for this target.
include CMakeFiles/tinyxml.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tinyxml.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tinyxml.dir/flags.make

CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o: CMakeFiles/tinyxml.dir/flags.make
CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o: extern/tinyxml/tinystr.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o -c /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinystr.cpp

CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinystr.cpp > CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.i

CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinystr.cpp -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.s

CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.requires:
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.requires

CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.provides: CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.requires
	$(MAKE) -f CMakeFiles/tinyxml.dir/build.make CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.provides.build
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.provides

CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.provides.build: CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.provides.build

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o: CMakeFiles/tinyxml.dir/flags.make
CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o: extern/tinyxml/tinyxml.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o -c /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxml.cpp

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxml.cpp > CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.i

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxml.cpp -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.s

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.requires:
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.requires

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.provides: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.requires
	$(MAKE) -f CMakeFiles/tinyxml.dir/build.make CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.provides.build
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.provides

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.provides.build: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.provides.build

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o: CMakeFiles/tinyxml.dir/flags.make
CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o: extern/tinyxml/tinyxmlerror.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o -c /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxmlerror.cpp

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxmlerror.cpp > CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.i

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxmlerror.cpp -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.s

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.requires:
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.requires

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.provides: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.requires
	$(MAKE) -f CMakeFiles/tinyxml.dir/build.make CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.provides.build
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.provides

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.provides.build: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.provides.build

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o: CMakeFiles/tinyxml.dir/flags.make
CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o: extern/tinyxml/tinyxmlparser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o -c /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxmlparser.cpp

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxmlparser.cpp > CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.i

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/tinyxml/tinyxmlparser.cpp -o CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.s

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.requires:
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.requires

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.provides: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.requires
	$(MAKE) -f CMakeFiles/tinyxml.dir/build.make CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.provides.build
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.provides

CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.provides.build: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o
.PHONY : CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.provides.build

# Object files for target tinyxml
tinyxml_OBJECTS = \
"CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o" \
"CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o" \
"CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o" \
"CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o"

# External object files for target tinyxml
tinyxml_EXTERNAL_OBJECTS =

lib/libtinyxml.so: CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o
lib/libtinyxml.so: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o
lib/libtinyxml.so: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o
lib/libtinyxml.so: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o
lib/libtinyxml.so: CMakeFiles/tinyxml.dir/build.make
lib/libtinyxml.so: CMakeFiles/tinyxml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library lib/libtinyxml.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tinyxml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tinyxml.dir/build: lib/libtinyxml.so
.PHONY : CMakeFiles/tinyxml.dir/build

CMakeFiles/tinyxml.dir/requires: CMakeFiles/tinyxml.dir/extern/tinyxml/tinystr.cpp.o.requires
CMakeFiles/tinyxml.dir/requires: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxml.cpp.o.requires
CMakeFiles/tinyxml.dir/requires: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlerror.cpp.o.requires
CMakeFiles/tinyxml.dir/requires: CMakeFiles/tinyxml.dir/extern/tinyxml/tinyxmlparser.cpp.o.requires
.PHONY : CMakeFiles/tinyxml.dir/requires

CMakeFiles/tinyxml.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tinyxml.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tinyxml.dir/clean

CMakeFiles/tinyxml.dir/depend:
	cd /home/olivier/work/dev/lib/gilviewer.repo/branch-icons && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olivier/work/dev/lib/gilviewer.repo/branch-icons /home/olivier/work/dev/lib/gilviewer.repo/branch-icons /home/olivier/work/dev/lib/gilviewer.repo/branch-icons /home/olivier/work/dev/lib/gilviewer.repo/branch-icons /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/CMakeFiles/tinyxml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tinyxml.dir/depend

