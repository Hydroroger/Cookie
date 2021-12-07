#pragma once

enum class Type
{
	EOL,
	unknown,
	str,
	num,
	graveAccent, // `
	swungDash, // ~
	exclamation, // !
	atTheRate, // @
	hash, // #
	dollar, // $
	percent, // %
	toThePowerOf, // ^
	ampersand, // &
	star, // *
	rPar, // (
	lPar, // )
	minus, // -
	underscore, // _
	equal, // =
	plus, // +
	rBracket, // [
	rCurly, // {
	lBracker, // ]
	lCurly, // }
	backSlash, // \ /
	pipe, // |
	semiColon, // ;
	colon, // :
	singleQuote, // '
	doubleQuote, // "
	comma, // ,
	lesserThan, // <
	fullStop, // .
	greaterThan, // >
	forwardSlash, // /
	questionMark, // ?
	whiteSpace,
};