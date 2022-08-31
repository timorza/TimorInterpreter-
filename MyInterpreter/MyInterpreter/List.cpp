#include "List.h"

List::List(std::list<Type*> newList)
{
	this->_listOfTypes = newList;
}

void List::addValue(Type* type)
{
	this->_listOfTypes.push_back(type);
}

std::string List::getType()
{
	return "list";
}

const bool List::isPrintable()
{
	return true;
}

const std::string List::toString()
{
	std::string listRet = "[";
	for (auto it = this->_listOfTypes.begin(); it != this->_listOfTypes.end(); ++it)
	{
		listRet += (*it)->toString() + ", ";
	}
	listRet = listRet.substr(0, listRet.size() - 2);
	listRet += "]";

	return listRet;
}
