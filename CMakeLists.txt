cmake_minimum_required(VERSION 3.10)
project(cplusplus VERSION 1.1)
#CMAKE defines <PROJECT_NAME>_VERSION_MAJOR and <PROJECT_NAME>_VERSION_MINOR
#[[ behind the scenes based on the values we give in the project() macro
and this is a multiline comment. See how it begins and ends ]]

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#[[ We're going to use a config_file which is a way to create a header file
generated from cmake and it's placed in the project's binary directory. The
idea is that we define the values in cmake or during build time and those
values will be defined in the header file which is generated in the project's
binary directory.

The following configure_file will take a look at the config directory's
cplusplus.config.in file and generate cplusplusconfig.h. We added the options
@ONLY to restrict variable substituion only for the types @VAR@ defined in the
config.in file and also set the newline style to be UNIX ]]

configure_file(./config/cplusplus.config.in cplusplusconfig.h @ONLY
		NEWLINE_STYLE UNIX)
#[[ options for this cmake file are same as in the config.in please see
that file on how these variables work]]

if(NOT DEFINED DEBUG_OUTPUT)
	set(DEBUG_OUTPUT 0)
endif()

if(NOT DEFINED COMPILE_VERSION)
	set(COMPILE_VERSION "undefined")
endif()
include_directories("./common/include")
include_directories("${PROJECT_BINARY_DIR}")


add_subdirectory("./vector")
