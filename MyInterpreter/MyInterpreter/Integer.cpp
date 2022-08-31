#include "Integer.h"

Integer::Integer(int value)
{
	this->_integerValue = value;
}

void Integer::addValue(Type* type){}

const bool Integer::isPrintable()
{
	return true;
}

const std::string Integer::toString()
{
	std::string str = std::to_string(this->_integerValue);
	Helper::removeLeadingZeros(str);
	return str;
}

std::string Integer::getType()
{
	return "int";
}
