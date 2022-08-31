#include "Void.h"

Void::Void(){}

const bool Void::isPrintable()
{
	return false;
}

const std::string Void::toString()
{
	return "";
}

void Void::addValue(Type* type){}

std::string Void::getType()
{
	return std::string();
}
