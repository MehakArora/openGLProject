# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mehak\CLionProjects\openGLProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug

# Include any dependencies generated for this target.
include glfw/examples/CMakeFiles/particles.dir/depend.make
# Include the progress variables for this target.
include glfw/examples/CMakeFiles/particles.dir/progress.make

# Include the compile flags for this target's objects.
include glfw/examples/CMakeFiles/particles.dir/flags.make

glfw/examples/CMakeFiles/particles.dir/particles.c.obj: glfw/examples/CMakeFiles/particles.dir/flags.make
glfw/examples/CMakeFiles/particles.dir/particles.c.obj: glfw/examples/CMakeFiles/particles.dir/includes_C.rsp
glfw/examples/CMakeFiles/particles.dir/particles.c.obj: ../glfw/examples/particles.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw/examples/CMakeFiles/particles.dir/particles.c.obj"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\particles.dir\particles.c.obj -c C:\Users\mehak\CLionProjects\openGLProject\glfw\examples\particles.c

glfw/examples/CMakeFiles/particles.dir/particles.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/particles.c.i"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mehak\CLionProjects\openGLProject\glfw\examples\particles.c > CMakeFiles\particles.dir\particles.c.i

glfw/examples/CMakeFiles/particles.dir/particles.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/particles.c.s"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mehak\CLionProjects\openGLProject\glfw\examples\particles.c -o CMakeFiles\particles.dir\particles.c.s

glfw/examples/CMakeFiles/particles.dir/glfw.rc.obj: glfw/examples/CMakeFiles/particles.dir/flags.make
glfw/examples/CMakeFiles/particles.dir/glfw.rc.obj: ../glfw/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object glfw/examples/CMakeFiles/particles.dir/glfw.rc.obj"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\mehak\CLionProjects\openGLProject\glfw\examples\glfw.rc CMakeFiles\particles.dir\glfw.rc.obj

glfw/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj: glfw/examples/CMakeFiles/particles.dir/flags.make
glfw/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj: glfw/examples/CMakeFiles/particles.dir/includes_C.rsp
glfw/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj: ../glfw/deps/tinycthread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object glfw/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\particles.dir\__\deps\tinycthread.c.obj -c C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\tinycthread.c

glfw/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/tinycthread.c.i"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\tinycthread.c > CMakeFiles\particles.dir\__\deps\tinycthread.c.i

glfw/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/tinycthread.c.s"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\tinycthread.c -o CMakeFiles\particles.dir\__\deps\tinycthread.c.s

glfw/examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj: glfw/examples/CMakeFiles/particles.dir/flags.make
glfw/examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj: glfw/examples/CMakeFiles/particles.dir/includes_C.rsp
glfw/examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj: ../glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object glfw/examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\particles.dir\__\deps\getopt.c.obj -c C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\getopt.c

glfw/examples/CMakeFiles/particles.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/getopt.c.i"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\getopt.c > CMakeFiles\particles.dir\__\deps\getopt.c.i

glfw/examples/CMakeFiles/particles.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/getopt.c.s"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\getopt.c -o CMakeFiles\particles.dir\__\deps\getopt.c.s

glfw/examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj: glfw/examples/CMakeFiles/particles.dir/flags.make
glfw/examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj: glfw/examples/CMakeFiles/particles.dir/includes_C.rsp
glfw/examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj: ../glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object glfw/examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\particles.dir\__\deps\glad_gl.c.obj -c C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\glad_gl.c

glfw/examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\glad_gl.c > CMakeFiles\particles.dir\__\deps\glad_gl.c.i

glfw/examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mehak\CLionProjects\openGLProject\glfw\deps\glad_gl.c -o CMakeFiles\particles.dir\__\deps\glad_gl.c.s

# Object files for target particles
particles_OBJECTS = \
"CMakeFiles/particles.dir/particles.c.obj" \
"CMakeFiles/particles.dir/glfw.rc.obj" \
"CMakeFiles/particles.dir/__/deps/tinycthread.c.obj" \
"CMakeFiles/particles.dir/__/deps/getopt.c.obj" \
"CMakeFiles/particles.dir/__/deps/glad_gl.c.obj"

# External object files for target particles
particles_EXTERNAL_OBJECTS =

glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/particles.c.obj
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/glfw.rc.obj
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.obj
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/__/deps/getopt.c.obj
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/__/deps/glad_gl.c.obj
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/build.make
glfw/examples/particles.exe: glfw/src/libglfw3.a
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/linklibs.rsp
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/objects1.rsp
glfw/examples/particles.exe: glfw/examples/CMakeFiles/particles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable particles.exe"
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\particles.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw/examples/CMakeFiles/particles.dir/build: glfw/examples/particles.exe
.PHONY : glfw/examples/CMakeFiles/particles.dir/build

glfw/examples/CMakeFiles/particles.dir/clean:
	cd /d C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples && $(CMAKE_COMMAND) -P CMakeFiles\particles.dir\cmake_clean.cmake
.PHONY : glfw/examples/CMakeFiles/particles.dir/clean

glfw/examples/CMakeFiles/particles.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mehak\CLionProjects\openGLProject C:\Users\mehak\CLionProjects\openGLProject\glfw\examples C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples C:\Users\mehak\CLionProjects\openGLProject\cmake-build-debug\glfw\examples\CMakeFiles\particles.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : glfw/examples/CMakeFiles/particles.dir/depend
