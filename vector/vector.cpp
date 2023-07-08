#include "common.h"
#include <cstdlib>
#include "vectorobject.hpp"

int main(int argc, char *argv[])
{
	std::cout<<"This is debug build "<< isDebug()<<"\n";
	std::cout<<"Compiler Version = "<< getVersion()<<"\n";
	std::vector<VectorObject> vectorObjectList;
	int count = 100;
	//let's provide the number of objects we
	//want as a parameter. Note that this is not
	//a named parameter. This is a positional parameter
	//so it has to be the 1st argument.
	//The first argument is always the binary name, i.e.
	//how it's executed
	if (argc == 2) {
		count = stoi(std::string(argv[1]), 0, 10);
	}
	//emplace_back creates a new object if it's not
	//already there, so this is kind of like a new
	//operation
	for (int i = 0; i < count; i += 1) {
		if ( i % 3 == 0)
			vectorObjectList.emplace_back(i , "from 3");
		else if (i % 5 == 0)
			vectorObjectList.emplace_back(i, "from 5");
		else if (i % 7 == 0)
			vectorObjectList.emplace_back(i, "from 7");
		else 
			vectorObjectList.emplace_back();
	}
	//C++14 allows for auto in lambdas but not
	//C++11 which is why we've to explicitly tell the type
	//of object expected.
	std::for_each(vectorObjectList.begin(), vectorObjectList.end(), [](VectorObject &obj)->void {
			std::cout<<"Vector Object is " <<obj <<"at " << &obj<<"\n";
			});
	return EXIT_SUCCESS;
}

