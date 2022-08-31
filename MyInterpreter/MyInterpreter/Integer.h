#pragma once
#include "type.h"

class Integer : public Type
{
public:
	Integer(int value);

	virtual void addValue(Type* type);
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::string getType();

private:
	bool _isTemp;
	int _integerValue;
};