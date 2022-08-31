#include "Boolean.h"

Boolean::Boolean(bool value)
{
	this->_boolValue = value;
}

void Boolean::addValue(Type* type){}

const bool Boolean::isPrintable()
{
	return true;
}

const std::string Boolean::toString()
{
	if (this->_boolValue)
		return "True";
	else
		return "False";
}

std::string Boolean::getType()
{
	return "boolean";
}
