#include <cstdlib>
#include <unistd.h>
#include <memory>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "shared_ptr.hpp"
#include "buffered.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout<<"Usage "<<argv[0]<<" <file_to_open>";
		return EXIT_FAILURE;
	}

	File fobj(argv[1]);
	long page_size = sysconf(_SC_PAGESIZE);
	Buffer<char> buffer(page_size);
	auto bytes_read = fobj.read(buffer);

	std::cout << "Bytes read = "<<bytes_read<<"\n";
	std::cout<<"Putting buffer, buffer size =  "<<buffer.size()<<"\n";
	for(int i = 0; i < buffer.size(); i += 1) {
		std::cout<<buffer[i];
	}
	return EXIT_SUCCESS;
}
