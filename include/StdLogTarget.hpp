/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Standard Log targets
*/

#ifndef STDLOGTARGET_HPP_
    #define STDLOGTARGET_HPP_

	#include "GLogTarget.hpp"

namespace Log {

	///
	///@brief Log target to STDOUT
	///
	///
	extern ILogTarget	&LogOut;

	///
	///@brief Log target to STDERR
	///
	///
	extern ILogTarget	&LogErr;

}

#endif /* !STDLOGTARGET_HPP_ */
