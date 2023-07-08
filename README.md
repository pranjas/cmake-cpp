#This is a simple introduction to CMAKE

### Introduction
cmake is nice tool to automate makefile generation given a set of dependencies
and targets. This project is a simple introduction on how to use cmake and
then add some code to it as well.

### Build instruction
Create a directory `mkdir -p build` and move into it `cd build`. You can then
use `cmake ..` to configure the project.

cmake variables used by project which are available as `#define` macros in the
code are
* DEBUG_OUTPUT
* COMPILE_VERSION
