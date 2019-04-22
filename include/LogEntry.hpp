/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Generic Log Entry template
*/

#ifndef LOGENTRY_HPP_
    #define LOGENTRY_HPP_

	#include <chrono>
	#include <string>
	#include "LogLevel.hpp"
	#include "TimeStamp.hpp"

namespace Log {

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LogEntry {
	public:

		LogEntry(const StringT &token, Level lv = Info):
			_lv(lv),
			_timeStamp(ClockT::now()),
			_token(token)
		{}

		~LogEntry() = default;

		using TimeStampT = TimeStamp<ClockT, StringT>;

		Level			getLevel() const
		{
			return _lv;
		}

		const TimeStampT	&getTimeStamp() const
		{
			return _timeStamp;
		}

		const StringT	&getToken() const
		{
			return _token;
		}

	protected:
	private:
		Level		_lv;
		TimeStampT	_timeStamp;
		StringT		_token;
	};

}

#endif /* !LOGENTRY_HPP_ */
