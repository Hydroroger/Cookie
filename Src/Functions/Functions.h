#pragma once
#include "../Lexer/Extras/Token.h"
#include <vector>

namespace functions
{
	void out(std::vector<Token>& tokenList)
	{
		int i = 0;
		i += 2;

		while (tokenList.at(i).type != Type::EOL)
		{
			std::cout << tokenList.at(i).value; i++;
		}

		std::cout << "\n";
	}
}