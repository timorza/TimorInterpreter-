#pragma once
#include "type.h"

class Sequence : public Type
{
public:
	Sequence();

	virtual void addValue(Type* type) = 0;
	virtual const bool isPrintable() = 0;
	virtual const std::string toString() = 0;
	virtual std::string getType() = 0;

private:
	bool _isTemp;
};