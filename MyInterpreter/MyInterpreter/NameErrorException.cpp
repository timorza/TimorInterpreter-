#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name)
{
	this->_name = name;
}

const char* NameErrorException::what() const throw()
{
	std::string str =  "NameError : name ‘" + this->_name + "’ is not defined";

	return str.c_str();
}
