#include "parser.h"
#include <iostream>



Type* Parser::parseString(std::string str) throw()
{
	int equalCount = 0;
	int dotCount = 0;

	if (str.length() > 0)
	{
		if (str[0] == SPACE || str[0] == TAB)
		{
			throw(IndentationException());
		}

		Helper::trim(str);
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == EQUAL_SIGN)
				equalCount++;
			else if (str[i] == DOT)
				dotCount++;
		}

		if (getVariableValue(str) == nullptr && equalCount == 1)
		{
			Type* type = Parser::getType(str);
			if (type == nullptr)
			{
				if (makeAssignment(str))
				{
					Void* voidType = new Void();
					voidType->setIsTemp(true);
					return voidType;
				}
				else
					throw(SyntexException());
			}
			else
			{
				if (type->getIsTemp())
				{
					std::cout << type->toString() << std::endl;
				}
			}
		}
		else
		{
			if (dotCount == 1)
				functionsCheck(str);
			else
				print(str, str.length());
		}
			
	}

	return NULL;
}

Type* Parser::getType(std::string& str)
{
	Helper h;
	if (h.isBoolean(str))
	{
		bool boolValue;
		if (str == "True")
			boolValue = true;
		else
			boolValue = false;
		Boolean* booType = new Boolean(boolValue);
		booType->setIsTemp(true);

		return booType;
	}
	else if (h.isInteger(str))
	{
		Helper h;
		h.removeLeadingZeros(str);
		Integer* integerType = new Integer(std::stoi(str));
		integerType->setIsTemp(true);

		return integerType;
	}
	else if (h.isString(str))
	{
		String* stringType = new String(str);
		stringType->setIsTemp(true);

		return stringType;
	}
	else if (h.isList(str))
	{
		List* listType = new List(strToList(str));
		listType->setIsTemp(true);

		return listType;
	}
	else
		return nullptr;
}

bool Parser::isLegalVarName(const std::string& str)
{
	if (!Helper::isDigit(str[0]))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (!(Helper::isDigit(str[i]) || Helper::isLetter(str[i]) || Helper::isUnderscore(str[i])))
			{
				return false;
			}
		}

		return true;
	}
	else
		return false;
}

bool Parser::makeAssignment(const std::string& str)
{
	int i = 0;
	int count = 0;
	int equalSignPlace = 0;
	bool valueIsName = false;

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '=')
		{
			count++;
			equalSignPlace = i;
		}

		if (count > 1)
			return false;
	}

	if (count == 0)
		return false;
	
	std::string variableName = str.substr(0, equalSignPlace);
	Helper::trim(variableName);
	std::string value = str.substr(equalSignPlace + 1, -1);
	Helper::trim(value);
	
	if (!isLegalVarName(variableName))
		throw(NameErrorException(variableName));

	Type* newType = getType(value);

	if (newType == nullptr)
	{
		if (!isLegalVarName(value))
			throw(NameErrorException(value));

		for (auto j = _variables.begin(); j != _variables.end(); ++j)
		{
			if ((*j).first == value)
				valueIsName = true;
		}

		if (valueIsName)
		{
			if (Helper::isList(_variables[value]->toString()))
			{
				_variables[variableName] = _variables[value];
			}
			else
			{
				Type* valueOfExistedName = _variables[value];
				_variables[variableName] = valueOfExistedName;
			}
		}
		else
			throw(NameErrorException(value));
	}
	else
		_variables[variableName] = newType;

	return true;
}

Type* Parser::getVariableValue(const std::string& str)
{
	for (auto i = _variables.begin(); i != _variables.end(); ++i)
	{
		if ((*i).first == str)
			return (*i).second;
	}

	return nullptr;
}

std::list<Type*> Parser::strToList(std::string& s)
{
	int count = 0;
	int i = 0;
	int j = 0;
	std::string subStr = s.substr(1, s.size() - 2);
	std::string theOriginalStr = subStr;
	std::list<Type*> retList;
	if (s != "[]")
	{
		for (i = 1; i < s.size() - 1; i++)
		{
			if (s[i] == ',')
			{
				count++;
			}
		}
		for (i = 0; i <= count; i++)
		{
			j = subStr.find(',');
			subStr = subStr.substr(0, j);
			Helper::trim(subStr);

			retList.push_back(getType(subStr));

			theOriginalStr = theOriginalStr.substr(j + 1);
			subStr = theOriginalStr;
		}
	}

	return retList;
}

void Parser::functionsCheck(const std::string& str)
{
	int i = 0;
	int dotPlace = 0;
	int rBracketPlace = 0;

	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == DOT)
			dotPlace = i;
	}

	for (i = dotPlace; i < str.length(); i++)
	{
		if (str[i] == RIGHT_BRACKET)
		{
			rBracketPlace = i;
		}
	}

	if (rBracketPlace != 0 && str.back() == LEFT_BRACKET)
	{
		std::string function = str.substr(dotPlace + 1, rBracketPlace - dotPlace - 1);
		std::string var = str.substr(0, dotPlace);

		auto it = _variables.find(var);
		if (it != _variables.end())
		{
			if (function == APPEND)
				append(str, dotPlace, rBracketPlace);
			else if (function == TYPE)
				type(str, dotPlace);
			else if (function == PRINT)
				print(str, dotPlace);
			else
				throw(SyntexException());
		}
		else
			throw(NameErrorException(var));
	}
	else
		throw(SyntexException());
}

void Parser::append(const std::string& str, int dotPlace, int rBracketPlace)
{
	int valueInt = str.length() - rBracketPlace - 2;
	std::string value = str.substr(rBracketPlace + 1, valueInt);
	std::string var = str.substr(0, dotPlace);
	Type* type = getType(value);
	if (type != nullptr)
	{
		_variables[var]->addValue(type);
	}
	else
	{
		throw(SyntexException());
	}
}

void Parser::type(const std::string& str, int dotPlace)
{
	std::string var = str.substr(0, dotPlace);
	std::cout << "<type \'" << _variables[var]->getType() << "\'>" << std::endl;
}

void Parser::print(const std::string& str, int dotPlace)
{
	std::string variable = str.substr(0, dotPlace);
	for (auto it = _variables.begin(); it != _variables.end(); it++)
	{
		if ((*it).first == variable)
			std::cout << _variables[variable]->toString() << std::endl;
	}
}

void Parser::freeMemory()
{
	for (auto i = _variables.begin(); i != _variables.end(); ++i)
	{
		(*i).second = nullptr;
	}
}
