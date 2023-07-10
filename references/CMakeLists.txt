project(references)

file(GLOB REFERENCES_SRC
	"./*.cpp"
	"./*.c")
add_executable( references ${REFERENCES_SRC})
target_include_directories( references PRIVATE "./include")
