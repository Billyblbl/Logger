/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Log level fuctions
*/

#include "LogLevel.hpp"

namespace Log {

	const LevelStrings	Serialized = {

		{All,		"All"},
		{Debug,		"Debug"},
		{Info,		"Info"},
		{Warning,	"Warning"},
		{Error,		"Error"},
		{Fatal,		"Fatal"}

	};

	const char	*to_string(Level lv)
	{
		return Serialized.at(lv);
	}

	std::ostream	&operator<<(std::ostream &left, Level right)
	{
		return left << to_string(right);
	}

}