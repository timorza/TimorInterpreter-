#pragma once
#include "Sequence.h"
#include <list>

class List : public Sequence
{
public:
	List(std::list<Type*> newList);
	virtual void addValue(Type* type);
	virtual std::string getType();

	virtual const bool isPrintable();
	virtual const std::string toString();

private:
	bool _isTemp;
	std::list<Type*> _listOfTypes;
};