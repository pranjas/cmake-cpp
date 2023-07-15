#include "shared_ptr.hpp"
#include <cstdio>
#include <iostream>
#include <memory>
#include "buffered.hpp"

//This function is created so we can see
//the message being printed when the file is closed.
static void freeFilePointer(FILE *fptr)
{
	std::cout<<"Calling fclose\n";
	if (fptr != nullptr)
		::fclose(fptr);
}

//Setup the shared file_pointer.
File::File(const char *fname) {
	FILE *fptr = fopen(fname, "r");
	file_ptr = std::shared_ptr<FILE>(fptr, freeFilePointer);
}

File::File(const std::string &fname) : File(fname.c_str()){
}

std::shared_ptr<FILE> File::getFILE() const {
	return file_ptr;
}

bool File::isValid() const{
	return file_ptr != nullptr;
}

File::~File() {
	std::cout<<"Calling Destructor for File\n";
}

std::shared_ptr<FILE> File::operator() () {
	return file_ptr;
}

size_t File::read(Buffer<char> &buffer) {
	size_t bytes_read = 0;
	if (isValid()) {
		if (!feof(file_ptr.get())) {
			bytes_read = fread(static_cast<void*>(buffer.get()), 
					sizeof(char), buffer.size(), file_ptr.get());
		}
	}
	if (bytes_read != buffer.size())
		buffer.resize(bytes_read);
	return bytes_read;
}
