#include "type.h"

Type::Type()
{
	this->_isTemp = false;
}

bool Type::getIsTemp()
{
	return this->_isTemp;
}

void Type::setIsTemp(bool temp)
{
	this->_isTemp = temp;
}
