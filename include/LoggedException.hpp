/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Logged exception objects
*/

#ifndef LOGGEDEXCEPTION_HPP_
    #define LOGGEDEXCEPTION_HPP_

	#include <exception>
	#include "LogLevel.hpp"
	#include "ALogTarget.hpp"
	#include "LogStdio.hpp"

namespace Log {

	template<
		class ExceptionT,
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LoggedException : public ExceptionT {
		public:

			using LTarget = ALogTarget<ClockT, StringT>;

			template<typename... Args>
			LoggedException(Args&&... args, LTarget &target = LogErr, Level lv = All):
				ExceptionT(std::forward(args)...),
				_entry(what(), lv)
			{
				target.Log(_entry);
			}

			template<typename... Args>
			LoggedException(Args&&... args, Level lv = All): LoggedException(std::forward(args)..., LogErr, lv)
			{}

			~LoggedException() = default;

			LoggedException	&operator=(const LoggedException &right) = default;

			const LogEntry<ClockT, StringT>	&getEntry() const
			{
				return _entry;
			}

		protected:
		private:
			LogEntry<ClockT, StringT>	_entry;
	};

}
#endif /* !LOGGEDEXCEPTION_HPP_ */
