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

	extern ALogTarget<>	&LogOut;
	extern ALogTarget<>	&LogErr;

}

#endif /* !LOGSTDIO_HPP_ */
