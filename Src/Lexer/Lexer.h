#pragma once

#include <string>
#include <vector>
#include "extras/Token.h"

class Lexer
{
public:

	void Lex(std::string input, std::vector<Token>& tokens);

	int TypeToInt(Type type);
};