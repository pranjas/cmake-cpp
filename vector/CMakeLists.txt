cmake_minimum_required(VERSION 3.10)
project(vector)

file (GLOB VECTOR_SRC
	"./*.cpp"
	"./*.c")

add_executable(vector ${VECTOR_SRC})
target_include_directories(vector PRIVATE "./include")
