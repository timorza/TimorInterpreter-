#include "SyntaxException.h"

const char* SyntexException::what() const throw()
{
	return "SyntaxError: invalid syntax";
}
