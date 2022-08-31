#include "type.h"
#include "InterperterException.h"
#include "parser.h"
#include <iostream>

#define WELCOME "Welcome to The Python Interperter by "
#define YOUR_NAME "Timor"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// prasing command
		try
		{
			Parser::parseString(input_string);
		}
		catch (InterperterException &e)
		{
			std::cout << e.what() << std::endl;
		}


		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	Parser::freeMemory();

	return 0;
}