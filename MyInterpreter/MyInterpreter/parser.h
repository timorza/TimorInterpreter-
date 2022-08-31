#ifndef PARSER_H
#define PARSER_H

#include "InterperterException.h"
#include "type.h"
#include "Boolean.h"
#include "Integer.h"
#include "Sequence.h"
#include "String.h"
#include "Void.h"
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "List.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#define APPEND "append"
#define TYPE "type"
#define PRINT "print"
#define SPACE ' '
#define TAB '	'
#define DOT '.'
#define RIGHT_BRACKET '('
#define LEFT_BRACKET ')'
#define EQUAL_SIGN '='

static std::unordered_map<std::string, Type*> _variables;

class Parser
{
public:
	static Type* parseString(std::string str) throw();
	static Type* getType(std::string& str);
	static void freeMemory();
private:
	
	static bool isLegalVarName(const std::string& str);
	static bool makeAssignment(const std::string& str);
	static Type* getVariableValue(const std::string& str);
	static std::list<Type*> strToList(std::string& s);
	static void functionsCheck(const std::string& str);
	static void append(const std::string& str, int dotPlace, int rBracketPlace);
	static void type(const std::string& str, int dotPlace);
	static void print(const std::string& str, int dotPlace);

};

#endif //PARSER_H
