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
				Logger::LogToFile(std::to_string(i), "log.txt", Logger::logLevel::Trace);
				i++;
			}
			else
			{
				Logger::LogToFile(tokenList.at(i).value, "log.txt", Logger::logLevel::Trace);
				break;
			}
		}

		if (tokenList.at(i).value == "out")
		{
			functions::out(tokenList);
		}
		else
		{
			std::cout << "Unknown Syntax\n";
		}
	}
}