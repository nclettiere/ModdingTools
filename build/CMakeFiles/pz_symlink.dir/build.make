# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\Users\Poffinsky\scoop\apps\cmake\3.27.0\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Poffinsky\scoop\apps\cmake\3.27.0\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Poffinsky\dev\projects\ModdingTools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Poffinsky\dev\projects\ModdingTools\build

# Include any dependencies generated for this target.
include CMakeFiles/pz_symlink.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pz_symlink.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pz_symlink.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pz_symlink.dir/flags.make

CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj: CMakeFiles/pz_symlink.dir/flags.make
CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj: CMakeFiles/pz_symlink.dir/includes_CXX.rsp
CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj: C:/Users/Poffinsky/dev/projects/ModdingTools/src/symlink_mods.cpp
CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj: CMakeFiles/pz_symlink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Poffinsky\dev\projects\ModdingTools\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj"
	C:\Users\Poffinsky\dev\tools\llvm-mingw-20231114-ucrt-x86_64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj -MF CMakeFiles\pz_symlink.dir\src\symlink_mods.cpp.obj.d -o CMakeFiles\pz_symlink.dir\src\symlink_mods.cpp.obj -c C:\Users\Poffinsky\dev\projects\ModdingTools\src\symlink_mods.cpp

CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.i"
	C:\Users\Poffinsky\dev\tools\llvm-mingw-20231114-ucrt-x86_64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Poffinsky\dev\projects\ModdingTools\src\symlink_mods.cpp > CMakeFiles\pz_symlink.dir\src\symlink_mods.cpp.i

CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.s"
	C:\Users\Poffinsky\dev\tools\llvm-mingw-20231114-ucrt-x86_64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Poffinsky\dev\projects\ModdingTools\src\symlink_mods.cpp -o CMakeFiles\pz_symlink.dir\src\symlink_mods.cpp.s

# Object files for target pz_symlink
pz_symlink_OBJECTS = \
"CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj"

# External object files for target pz_symlink
pz_symlink_EXTERNAL_OBJECTS =

bin/pz_symlink.exe: CMakeFiles/pz_symlink.dir/src/symlink_mods.cpp.obj
bin/pz_symlink.exe: CMakeFiles/pz_symlink.dir/build.make
bin/pz_symlink.exe: CMakeFiles/pz_symlink.dir/linkLibs.rsp
bin/pz_symlink.exe: CMakeFiles/pz_symlink.dir/objects1.rsp
bin/pz_symlink.exe: CMakeFiles/pz_symlink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Poffinsky\dev\projects\ModdingTools\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\pz_symlink.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pz_symlink.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pz_symlink.dir/build: bin/pz_symlink.exe
.PHONY : CMakeFiles/pz_symlink.dir/build

CMakeFiles/pz_symlink.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pz_symlink.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pz_symlink.dir/clean

CMakeFiles/pz_symlink.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Poffinsky\dev\projects\ModdingTools C:\Users\Poffinsky\dev\projects\ModdingTools C:\Users\Poffinsky\dev\projects\ModdingTools\build C:\Users\Poffinsky\dev\projects\ModdingTools\build C:\Users\Poffinsky\dev\projects\ModdingTools\build\CMakeFiles\pz_symlink.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pz_symlink.dir/depend

