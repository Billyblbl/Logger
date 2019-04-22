/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Log targets for standard channels definition
*/

#include <iostream>
#include "LogStdio.hpp"
#include "LogTargetReferenced.hpp"

namespace Log {

	LogTargetReferenced	_LogOut(std::cout, All);
	LogTargetReferenced	_LogErr(std::cerr, Warning);

	ALogTarget<>	&LogOut = _LogOut;
	ALogTarget<>	&LogErr = _LogErr;

}