#pragma once
#include "type.h"

class Void : public Type
{
public:
	Void();

	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual void addValue(Type* type);
	virtual std::string getType();

private:
	bool _isTemp;
};