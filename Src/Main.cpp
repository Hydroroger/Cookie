#include "Lexer/Lexer.h"
#include <iostream>
#include "SyntaxAnalyzer/SyntaxAnalyzer.h"
#include <fstream>
#include "GlobalVars.h"

int main(int argc, char const* argv[])
{
	if (argc == 1)
	{
		std::vector<Token> tokenList;
		Lexer lexer;
		std::string input;

		while (!Gvars::close)
		{
			std::cout << "-> ";
			std::getline(std::cin, input);
			lexer.Lex(input, tokenList);
			Analyzer::Analyze(tokenList);
		}

		return 0;
	}
	else
	{
		std::fstream fs;
		fs.open(argv[1], std::fstream::in);

		std::vector<Token> tokenList;
		Lexer lexer;
		std::string input;

		while (!Gvars::close)
		{
			std::getline(fs, input);
			lexer.Lex(input, tokenList);
			Analyzer::Analyze(tokenList);
		}

		fs.close();
		return 0;
	}
}