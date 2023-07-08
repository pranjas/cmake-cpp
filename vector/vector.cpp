#include "common.h"
#include <cstdlib>
int main(int argc, char *argv[])
{
	std::cout<<"This is debug build "<< isDebug()<<"\n";
	std::cout<<"Compiler Version = "<< getVersion()<<"\n";
	return EXIT_SUCCESS;
}
