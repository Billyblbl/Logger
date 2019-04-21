/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Standard Log targets
*/

#include <iostream>
#include "StdLogTarget.hpp"

namespace Log {

	static GLogTarget<std::ostream>	_LogOut(All, std::cout);
	static GLogTarget<std::ostream>	_LogErr(Warning, std::cerr);
	ILogTarget						&LogOut = _LogOut;
	ILogTarget						&LogErr = _LogErr;

}
