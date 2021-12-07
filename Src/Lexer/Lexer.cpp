#include "Lexer.h"
#include <vector>
#include "Extras/ExtraFuncs/GetType.h"

void Lexer::Lex(std::string input, std::vector<Token>& tokens)
{
	std::vector<char> charList;
	std::vector<Token> tokenList;

	tokens.clear();

	/*
	|-------------------------|
	| START OF DIVIDING CHARS |
	|-------------------------|
	*/

	for (auto i : input)
		charList.emplace_back(i);

	/*
	|-----------------------|
	| END OF DIVIDING CHARS |
	|-----------------------|
	*/

	/*
	|-----------------------------------|
	| START OF GETTING EACH CHAR'S TYPE |
	|-----------------------------------|
	*/

	for (auto i : charList)
	{
		Token tempToken;
		tempToken.value = i;
		tempToken.type = GetType(i);
		tokenList.emplace_back(tempToken);
	}

	/*
	|---------------------------------|
	| END OF GETTING EACH CHAR'S TYPE |
	|---------------------------------|
	*/

	/*
	|-------------------------|
	| START OF JOINING CHAR'S |
	|-------------------------|
	*/

	bool foundString = false;
	bool foundInt = false;

	std::vector<Token> tempTokenList;
	std::string current;

	for (int i = 0; i < tokenList.size(); i++)
	{
		if (tokenList.at(i).type == Type::str)
		{
			if (foundInt)
			{
				Token tempToken;
				tempToken.type = Type::num;
				tempToken.value = current;

				foundInt = false;
				tempTokenList.emplace_back(tempToken);
				current.clear();
			}
			foundString = true;
			current += tokenList.at(i).value;
		}
		else if (tokenList.at(i).type == Type::num)
		{
			if (foundString)
			{
				Token tempToken;
				tempToken.type = Type::str;
				tempToken.value = current;

				foundString = false;
				tempTokenList.emplace_back(tempToken);
				current.clear();
			}

			foundInt = true;
			current += tokenList.at(i).value;
		}
		else
		{
			if (foundString)
			{
				Token tempToken;
				tempToken.type = Type::str;
				tempToken.value = current;

				foundString = false;
				tempTokenList.emplace_back(tempToken);
				current.clear();
			}
			else if (foundInt)
			{
				Token tempToken;
				tempToken.type = Type::num;
				tempToken.value = current;

				foundInt = false;
				tempTokenList.emplace_back(tempToken);
				current.clear();
			}

			current += tokenList.at(i).value;
			Token tempToken;
			tempToken.type = GetType(current[0]);
			tempToken.value = current;
			tempTokenList.emplace_back(tempToken);
			current.clear();
		}
	}

	if (foundInt)
	{
		Token tempToken;
		tempToken.type = Type::num;
		tempToken.value = current;

		foundInt = false;
		tempTokenList.emplace_back(tempToken);
		current.clear();
	}
	else if (foundString)
	{
		Token tempToken;
		tempToken.type = Type::str;
		tempToken.value = current;

		foundString = false;
		tempTokenList.emplace_back(tempToken);
		current.clear();
	}

	tokenList.clear();
	for (auto i : tempTokenList)
	{
		tokenList.emplace_back(i);
	}

	/*
	|-----------------------|
	| END OF JOINING CHAR'S |
	|-----------------------|
	*/

	/*
	|--------------------------------------------------------|
	| START OF PUTTING ELEMENTS OF "tokenList" INTO "tokens" |
	|--------------------------------------------------------|
	*/

	for (auto i : tokenList)
	{
		tokens.emplace_back(i);
	}

	{
		Token tempToken;
		tempToken.type = Type::EOL;
		tempToken.value = "EOL";
		tokens.emplace_back(tempToken);
	}
	/*
	|------------------------------------------------------|
	| END OF PUTTING ELEMENTS OF "tokenList" INTO "tokens" |
	|------------------------------------------------------|
	*/
}

int Lexer::TypeToInt(Type type)
{
	switch (type)
	{
	case Type::EOL:
		return 0;
	case Type::unknown:
		return 1;
	case Type::str:
		return 2;
	case Type::num:
		return 3;
	case Type::graveAccent:
		return 4;
	case Type::swungDash:
		return 5;
	case Type::exclamation:
		return 6;
	case Type::atTheRate:
		return 7;
	case Type::hash:
		return 8;
	case Type::dollar:
		return 9;
	case Type::percent:
		return 10;
	case Type::toThePowerOf:
		return 11;
	case Type::ampersand:
		return 12;
	case Type::star:
		return 13;
	case Type::rPar:
		return 14;
	case Type::lPar:
		return 15;
	case Type::minus:
		return 16;
	case Type::underscore:
		return 17;
	case Type::equal:
		return 18;
	case Type::plus:
		return 19;
	case Type::rBracket:
		return 20;
	case Type::rCurly:
		return 21;
	case Type::lBracker:
		return 22;
	case Type::lCurly:
		return 23;
	case Type::backSlash:
		return 24;
	case Type::pipe:
		return 25;
	case Type::semiColon:
		return 26;
	case Type::colon:
		return 27;
	case Type::singleQuote:
		return 28;
	case Type::doubleQuote:
		return 29;
	case Type::comma:
		return 30;
	case Type::lesserThan:
		return 31;
	case Type::fullStop:
		return 32;
	case Type::greaterThan:
		return 33;
	case Type::forwardSlash:
		return 34;
	case Type::questionMark:
		return 35;
	case Type::whiteSpace:
		return 36;
	default:
		return 1;
	}
}