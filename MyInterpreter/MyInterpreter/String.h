#pragma once
#include "Sequence.h"

class String : public Sequence
{
public:
	String(std::string value);

	virtual void addValue(Type* type);
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::string getType();

private:
	bool _isTemp;
	std::string _stringValue;
};