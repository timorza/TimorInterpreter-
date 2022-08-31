#pragma once
#include "type.h"

class Boolean : public Type
{
public:
	Boolean(bool value);

	virtual void addValue(Type* type);
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::string getType();

private:
	bool _isTemp;
	bool _boolValue;
};