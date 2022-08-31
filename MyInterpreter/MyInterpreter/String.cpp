#include "String.h"

String::String(std::string value)
{
	this->_stringValue = value;
}

void String::addValue(Type* type){}

const bool String::isPrintable()
{
	return true;
}

const std::string String::toString()
{
	return this->_stringValue;
}

std::string String::getType()
{
	return "string";
}
