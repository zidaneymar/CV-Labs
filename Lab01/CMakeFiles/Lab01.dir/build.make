# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.2.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.2.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kangqi/Desktop/exp/Lab01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kangqi/Desktop/exp/Lab01

# Include any dependencies generated for this target.
include CMakeFiles/Lab01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab01.dir/flags.make

CMakeFiles/Lab01.dir/Lab01.cpp.o: CMakeFiles/Lab01.dir/flags.make
CMakeFiles/Lab01.dir/Lab01.cpp.o: Lab01.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kangqi/Desktop/exp/Lab01/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Lab01.dir/Lab01.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Lab01.dir/Lab01.cpp.o -c /Users/kangqi/Desktop/exp/Lab01/Lab01.cpp

CMakeFiles/Lab01.dir/Lab01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab01.dir/Lab01.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kangqi/Desktop/exp/Lab01/Lab01.cpp > CMakeFiles/Lab01.dir/Lab01.cpp.i

CMakeFiles/Lab01.dir/Lab01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab01.dir/Lab01.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kangqi/Desktop/exp/Lab01/Lab01.cpp -o CMakeFiles/Lab01.dir/Lab01.cpp.s

CMakeFiles/Lab01.dir/Lab01.cpp.o.requires:
.PHONY : CMakeFiles/Lab01.dir/Lab01.cpp.o.requires

CMakeFiles/Lab01.dir/Lab01.cpp.o.provides: CMakeFiles/Lab01.dir/Lab01.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab01.dir/build.make CMakeFiles/Lab01.dir/Lab01.cpp.o.provides.build
.PHONY : CMakeFiles/Lab01.dir/Lab01.cpp.o.provides

CMakeFiles/Lab01.dir/Lab01.cpp.o.provides.build: CMakeFiles/Lab01.dir/Lab01.cpp.o

# Object files for target Lab01
Lab01_OBJECTS = \
"CMakeFiles/Lab01.dir/Lab01.cpp.o"

# External object files for target Lab01
Lab01_EXTERNAL_OBJECTS =

Lab01: CMakeFiles/Lab01.dir/Lab01.cpp.o
Lab01: CMakeFiles/Lab01.dir/build.make
Lab01: /usr/local/lib/libopencv_videostab.a
Lab01: /usr/local/lib/libopencv_videoio.a
Lab01: /usr/local/lib/libopencv_video.a
Lab01: /usr/local/lib/libopencv_superres.a
Lab01: /usr/local/lib/libopencv_stitching.a
Lab01: /usr/local/lib/libopencv_shape.a
Lab01: /usr/local/lib/libopencv_photo.a
Lab01: /usr/local/lib/libopencv_objdetect.a
Lab01: /usr/local/lib/libopencv_ml.a
Lab01: /usr/local/lib/libopencv_imgproc.a
Lab01: /usr/local/lib/libopencv_imgcodecs.a
Lab01: /usr/local/lib/libopencv_highgui.a
Lab01: /usr/local/lib/libopencv_flann.a
Lab01: /usr/local/lib/libopencv_features2d.a
Lab01: /usr/local/lib/libopencv_core.a
Lab01: /usr/local/lib/libopencv_calib3d.a
Lab01: /Users/kangqi/Desktop/ChartDirector/lib/libchartdir.dylib
Lab01: /Users/kangqi/Desktop/ChartDirector/lib/libchartdir.6.dylib
Lab01: /usr/local/lib/libopencv_features2d.a
Lab01: /usr/local/lib/libopencv_ml.a
Lab01: /usr/local/lib/libopencv_highgui.a
Lab01: /usr/local/lib/libopencv_videoio.a
Lab01: /usr/local/lib/libopencv_imgcodecs.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/liblibjpeg.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/liblibwebp.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/liblibpng.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/liblibtiff.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/liblibjasper.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/libIlmImf.a
Lab01: /usr/local/lib/libopencv_flann.a
Lab01: /usr/local/lib/libopencv_video.a
Lab01: /usr/local/lib/libopencv_imgproc.a
Lab01: /usr/local/lib/libopencv_core.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/libzlib.a
Lab01: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
Lab01: CMakeFiles/Lab01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Lab01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab01.dir/build: Lab01
.PHONY : CMakeFiles/Lab01.dir/build

CMakeFiles/Lab01.dir/requires: CMakeFiles/Lab01.dir/Lab01.cpp.o.requires
.PHONY : CMakeFiles/Lab01.dir/requires

CMakeFiles/Lab01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab01.dir/clean

CMakeFiles/Lab01.dir/depend:
	cd /Users/kangqi/Desktop/exp/Lab01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kangqi/Desktop/exp/Lab01 /Users/kangqi/Desktop/exp/Lab01 /Users/kangqi/Desktop/exp/Lab01 /Users/kangqi/Desktop/exp/Lab01 /Users/kangqi/Desktop/exp/Lab01/CMakeFiles/Lab01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab01.dir/depend

