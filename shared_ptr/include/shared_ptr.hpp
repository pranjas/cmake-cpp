#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include <sys/types.h>
#include "buffer.hpp"

class File {
	private:
		std::shared_ptr<FILE> file_ptr;
	public:
		File(const char *fname);
		File(const std::string &fname);
		std::shared_ptr<FILE> getFILE() const;
		bool isValid() const;
		//This overloaded operator makes it a
		//functor, which takes no args.
		std::shared_ptr<FILE> operator () ();
		size_t read(Buffer<char> &buffer);
		~File();		
};
#endif //SHARED_PTR_H
