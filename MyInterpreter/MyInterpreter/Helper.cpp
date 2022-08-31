#include "Helper.h"

bool Helper::isInteger(const std::string& s)
{
	int start = (s[0] == '-') ? 1 : 0;
	for (int i = start; i < s.size(); i++)
	{
		if (!isDigit(s[i]))
		{
			return false;
		}
	}

	return true;
}

bool Helper::isList(const std::string& s)
{
	if (s[0] == '[' && s[s.size() - 1] == ']')
	{
		for (int i = 1; i < s.size() - 1; i++)
		{
			if (s[i] == ']' || s[i] == '[')
				return false;
		}

		if (elementsInList(s))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Helper::isBoolean(const std::string& s)
{
	return (s == "True" || s == "False");
}


bool Helper::isString(const std::string& s)
{
	size_t end = s.size() - 1;

	if (s[0] == '\"' && end == s.find('\"', 1))
	{
		return true;
	}
	if (s[0] == '\'' && end == s.find('\'', 1))
	{
		return true;
	}

	return false;

}

bool Helper::isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

void Helper::trim(std::string& str)
{
	rtrim(str);
	ltrim(str);

}

void Helper::rtrim(std::string& str)
{
	size_t endpos = str.find_last_not_of(" \t");
	if (std::string::npos != endpos)
	{
		str = str.substr(0, endpos + 1);
	}
}

void Helper::ltrim(std::string& str)
{
	size_t startpos = str.find_first_not_of(" \t");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}

void Helper::removeLeadingZeros(std::string& str)
{
	size_t startpos = str.find_first_not_of("0");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}

bool Helper::isLowerLetter(char c)
{
	return (c >= 'a' && c <= 'z');
}

bool Helper::isUpperLetter(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool Helper::isLetter(char c)
{
	return (isLowerLetter(c) || isUpperLetter(c));
}

bool Helper::isUnderscore(char c)
{
	return ('_' == c);
}

bool Helper::elementsInList(const std::string& s)
{
	int count = 0;
	int i = 0;
	int j = 0;
	std::string subStr = s.substr(1, s.size() - 2);
	std::string theOriginalStr = subStr;

	for (i = 1; i < s.size() - 1; i++)
	{
		if (s[i] == ',')
		{
			count++;
		}
	}
	for (i = 0; i <= count ; i++)
	{
		j = subStr.find(',');
		subStr = subStr.substr(0, j);
		trim(subStr);

		if (!(isInteger(subStr) || isString(subStr) || isBoolean(subStr)))
		{
			return false;
		}

		theOriginalStr = theOriginalStr.substr(j + 1);
		subStr = theOriginalStr;
	}
	
	return true;
}