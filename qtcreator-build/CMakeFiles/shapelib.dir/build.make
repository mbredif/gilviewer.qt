# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_BINARY_DIR = /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build

# Include any dependencies generated for this target.
include CMakeFiles/shapelib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shapelib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shapelib.dir/flags.make

CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o: CMakeFiles/shapelib.dir/flags.make
CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o: ../extern/shapelib/shpopen.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@echo "Building C object CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o   -c /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/shpopen.c

CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.i: cmake_force
	@echo "Preprocessing C source to CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/shpopen.c > CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.i

CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.s: cmake_force
	@echo "Compiling C source to assembly CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/shpopen.c -o CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.s

CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.requires:
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.requires

CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.provides: CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.requires
	$(MAKE) -f CMakeFiles/shapelib.dir/build.make CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.provides.build
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.provides

CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.provides.build: CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.provides.build

CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o: CMakeFiles/shapelib.dir/flags.make
CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o: ../extern/shapelib/dbfopen.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build/CMakeFiles $(CMAKE_PROGRESS_2)
	@echo "Building C object CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o   -c /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/dbfopen.c

CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.i: cmake_force
	@echo "Preprocessing C source to CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/dbfopen.c > CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.i

CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.s: cmake_force
	@echo "Compiling C source to assembly CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/dbfopen.c -o CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.s

CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.requires:
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.requires

CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.provides: CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.requires
	$(MAKE) -f CMakeFiles/shapelib.dir/build.make CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.provides.build
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.provides

CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.provides.build: CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.provides.build

CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o: CMakeFiles/shapelib.dir/flags.make
CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o: ../extern/shapelib/shptree.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build/CMakeFiles $(CMAKE_PROGRESS_3)
	@echo "Building C object CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o   -c /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/shptree.c

CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.i: cmake_force
	@echo "Preprocessing C source to CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/shptree.c > CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.i

CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.s: cmake_force
	@echo "Compiling C source to assembly CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/extern/shapelib/shptree.c -o CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.s

CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.requires:
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.requires

CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.provides: CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.requires
	$(MAKE) -f CMakeFiles/shapelib.dir/build.make CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.provides.build
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.provides

CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.provides.build: CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o
.PHONY : CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.provides.build

# Object files for target shapelib
shapelib_OBJECTS = \
"CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o" \
"CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o" \
"CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o"

# External object files for target shapelib
shapelib_EXTERNAL_OBJECTS =

../lib/libshapelib.so: CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o
../lib/libshapelib.so: CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o
../lib/libshapelib.so: CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o
../lib/libshapelib.so: CMakeFiles/shapelib.dir/build.make
../lib/libshapelib.so: CMakeFiles/shapelib.dir/link.txt
	@echo "Linking C shared library ../lib/libshapelib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shapelib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shapelib.dir/build: ../lib/libshapelib.so
.PHONY : CMakeFiles/shapelib.dir/build

CMakeFiles/shapelib.dir/requires: CMakeFiles/shapelib.dir/extern/shapelib/shpopen.c.o.requires
CMakeFiles/shapelib.dir/requires: CMakeFiles/shapelib.dir/extern/shapelib/dbfopen.c.o.requires
CMakeFiles/shapelib.dir/requires: CMakeFiles/shapelib.dir/extern/shapelib/shptree.c.o.requires
.PHONY : CMakeFiles/shapelib.dir/requires

CMakeFiles/shapelib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shapelib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shapelib.dir/clean

CMakeFiles/shapelib.dir/depend:
	cd /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olivier/work/dev/lib/gilviewer.repo/branch-icons /home/olivier/work/dev/lib/gilviewer.repo/branch-icons /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build /home/olivier/work/dev/lib/gilviewer.repo/branch-icons/qtcreator-build/CMakeFiles/shapelib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shapelib.dir/depend

