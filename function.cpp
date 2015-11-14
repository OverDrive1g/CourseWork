#include "function.h"
#include <sstream>

std::string intToString(int num){
	std::string value;
	std::stringstream ss;
	ss << num;
	ss >> value;
	return value;
}
