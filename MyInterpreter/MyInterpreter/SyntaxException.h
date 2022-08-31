#pragma once
#define SYNTAX_EXCEPTION_H
#include "InterperterException.h"

class SyntexException : public InterperterException
{
	virtual const char* what() const throw();
};