#pragma once
#include <vector>
#include "../Lexer/Extras/Token.h"
#include "../Logger/Logger.h"
#include "../Functions/Functions.h"

namespace Analyzer
{
	void Analyze(std::vector<Token>& tokenList)
	{
		int i = 0;

		// skipp all the whitespaces in the starting
		while (true)
		{
			if (tokenList.at(i).type == Type::whiteSpace)
			{
				i++;
			}
			else
			{
				break;
			}
		}

		if (tokenList.at(i).value == "out")
		{
			functions::out(tokenList);
		}
		else if (tokenList.at(i).value == "end")
		{
			functions::end();
		}
		else if (tokenList.at(i).value == "wait")
		{
			functions::wait();
		}
		else
		{
			std::cout << "Unknown Syntax\n";
		}
	}
}