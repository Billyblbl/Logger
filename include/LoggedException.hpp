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
		class ExceptionT = std::exception,
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LoggedException : public ExceptionT {
		public:

			static_assert(std::is_convertible<ExceptionT *, std::exception *>(
				"Can't make a Logged Exception out of a non-exception object type"));

			using LTarget = ALogTarget<ClockT, StringT>;
			using LogEntryT = LogEntry<ClockT, StringT>;

			template<typename... Args>
			LoggedException(Args&&... args, LTarget &target = LogErr, Level lv = Warning):
				ExceptionT(std::forward(args)...),
				_entry(what(), lv)
			{
				target.Log(_entry);
			}

			template<typename... Args>
			LoggedException(Args&&... args, Level lv = Warning):
				LoggedException(std::forward(args)..., , lv)
			{}

			virtual ~LoggedException() = default;

			LoggedException	&operator=(const LoggedException &right) = default;

			const LogEntryT				&getEntry() const
			{
				return _entry;
			}

			const Level					getLevel() const
			{
				return _entry.getLevel();
			}

			const LogEntryT::TimeStampT	&getTimeStamp() const
			{
				return _entry.getTimeStamp();
			}

		protected:
			LogEntry<ClockT, StringT>	_entry;
		private:
	};

}
#endif /* !LOGGEDEXCEPTION_HPP_ */
