#include "Lexer/Lexer.h"
#include <iostream>
#include "SyntaxAnalyzer/SyntaxAnalyzer.h"

#define INTERPRETER 0
#define FILE 1

#define MODE INTERPRETER

int main()
{
	std::vector<Token> tokenList;
	Lexer lexer;
	std::string input;

	while (true)
	{
		std::getline(std::cin, input);
		lexer.Lex(input, tokenList);
		for (auto i : tokenList)
		{
			std::cout << "value: '" << i.value << "' type: '" << lexer.TypeToInt(i.type) << "'\n";
		}
		Analyzer::Analyze(tokenList);
	}

	system("pause");
	return 0;
}