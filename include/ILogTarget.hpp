/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Logging target object interface
*/

#ifndef ILOGTARGET_HPP_
    #define ILOGTARGET_HPP_

	#include <ostream>
	#include "LogLevel.hpp"

///
///@brief Namespace for Log library objects
///
///
namespace Log {

	///
	///@brief Target for message logging
	///
	///@class ILogTarget
	///Defines a target in which log messages for debug, informations,
	///warnings, errors and fatal erros can be written
	///
	class ILogTarget {
		public:

			///
			///@brief Destroy the ILogTarget object
			///
			///
			virtual ~ILogTarget() = default;

			///
			///@brief Writes message in the target.
			///If the Log level of the message is >= to the LogTarget's Log level,
			///writes message to the target, otherwise the message is ignored
			///@param message Message to be logged
			///@param lv Log level of the message
			///
			virtual void	Log(const char *message, Level lv = All) = 0;

			///
			///@brief Set the Log Level of the object
			///
			///@param lv new Log level
			///
			virtual	void	SetLevel(Level lv) = 0;

			///
			///@brief Get the Log Level of the object
			///
			///@return Level current Level
			///
			virtual Level	GetLevel() const = 0;

	};
}

#endif /* !ILOGTARGET_HPP_ */
