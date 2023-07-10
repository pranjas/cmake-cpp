#include "common.h"
#include "references.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
	int a = 10;
	int &&abc = 20;
	//int &&ac = a;
	std::cout <<updateArgument(a)<<"\n";
	std::cout <<updateArgument(20)<<"\n";
	return EXIT_SUCCESS;
}
