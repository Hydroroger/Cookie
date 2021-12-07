#pragma once

#include "../Type.h"

Type GetType(char i)
{
	if (i == 'a' || i == 'b' || i == 'c' || i == 'd' || i == 'e' || i == 'f' || i == 'g' ||
		i == 'h' || i == 'i' || i == 'j' || i == 'k' || i == 'l' || i == 'm' || i == 'n' ||
		i == 'o' || i == 'p' || i == 'q' || i == 'r' || i == 's' || i == 't' || i == 'u' ||
		i == 'v' || i == 'w' || i == 'x' || i == 'y' || i == 'z' || i == 'A' || i == 'B' ||
		i == 'C' || i == 'D' || i == 'E' || i == 'F' || i == 'G' || i == 'H' || i == 'I' ||
		i == 'J' || i == 'K' || i == 'L' || i == 'M' || i == 'N' || i == 'O' || i == 'P' ||
		i == 'Q' || i == 'R' || i == 'S' || i == 'T' || i == 'U' || i == 'V' || i == 'W' ||
		i == 'X' || i == 'Y' || i == 'Z')
		return Type::str;
	else if (i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' ||
		i == '8' || i == '9' || i == '0')
		return Type::num;
	else
		switch (i)
		{
		case '`':
			return Type::graveAccent;
		case '~':
			return Type::swungDash;
		case '!':
			return Type::exclamation;
		case '@':
			return Type::atTheRate;
		case '#':
			return Type::hash;
		case '$':
			return Type::dollar;
		case '%':
			return Type::percent;
		case '^':
			return Type::toThePowerOf;
		case '&':
			return Type::ampersand;
		case '*':
			return Type::ampersand;
		case '(':
			return Type::rPar;
		case ')':
			return Type::lPar;
		case '-':
			return Type::minus;
		case '_':
			return Type::underscore;
		case '=':
			return Type::equal;
		case '+':
			return Type::plus;
		case '[':
			return Type::rBracket;
		case '{':
			return Type::rCurly;
		case ']':
			return Type::lBracker;
		case '}':
			return Type::lCurly;
		case '\\':
			return Type::backSlash;
		case '|':
			return Type::pipe;
		case ';':
			return Type::semiColon;
		case ':':
			return Type::colon;
		case '\'':
			return Type::singleQuote;
		case '"':
			return Type::doubleQuote;
		case ',':
			return Type::comma;
		case '<':
			return Type::lesserThan;
		case '.':
			return Type::fullStop;
		case '>':
			return Type::greaterThan;
		case '/':
			return Type::forwardSlash;
		case '?':
			return Type::questionMark;
		case ' ':
			return Type::whiteSpace;
		case '\t':
			return Type::whiteSpace;
		case '\v':
			return Type::whiteSpace;
		case '\f':
			return Type::whiteSpace;
		case '\r':
			return Type::whiteSpace;
		default:
			return Type::unknown;
		}
}