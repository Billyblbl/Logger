/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Log targets for standard channels
*/

#ifndef LOGSTDIO_HPP_
    #define LOGSTDIO_HPP_

	#include "ALogTarget.hpp"

namespace Log {

	///
	///@brief Log target to standard stream std::cout
	///
	///
	extern ALogTarget<>	&LogOut;

	///
	///@brief Log target to standard strem std::cerr
	///
	///
	extern ALogTarget<>	&LogErr;

}

#endif /* !LOGSTDIO_HPP_ */
