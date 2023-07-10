#include "references.hpp"
#include "common.h"
#include <iostream>

int updateArgument(int &lvalRef) {
#ifdef DEBUG_OUTPUT
	std::cout<<"Calling function "<< __func__ << "at line " << __LINE__ <<"\n";
#endif
	return ++lvalRef;
}

int updateArgument(int &&rvalRef) {
#ifdef DEBUG_OUTPUT
	std::cout<<"Calling function "<< __func__ << "at line " << __LINE__ <<"\n";
#endif
	return ++rvalRef;
}

