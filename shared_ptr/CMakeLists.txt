cmake_minimum_required(VERSION 3.10)
project(shared_ptr)

file (GLOB SHARED_PTR_SRC
	"./*.cpp"
	"./*.c")

add_executable(shared_ptr ${SHARED_PTR_SRC})
target_include_directories(shared_ptr PRIVATE "./include")
