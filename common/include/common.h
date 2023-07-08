#ifndef COM_THEPKSBLOG_COMMON
#define COM_THEPKSBLOG_COMMON

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <chrono>
#include "cplusplusconfig.h"

static inline std::string getVersion() {
#ifndef COMPILE_VERSION
	return std::string("undefined");
#else
	return COMPILE_VERSION;
#endif
}

static inline bool isDebug() {
#ifndef DEBUG_OUTPUT
	return false;
#else
	return !!DEBUG_OUTPUT;
#endif
}
#endif //COM_THEPKSBLOG_COMMON
