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

	///
	///@brief Log Entry class template, contains some message to be logged
	///
	/// Log entries contain the log level of their message,
	/// the timestamp of their initialisation, and the message itself
	///
	///@tparam ClockT Clock time to be used for timestamps
	///@tparam StringT String type implementation
	///
	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LogEntry {
	public:

		///
		///@brief Construct a new Log Entry
		///
		///@param token Message to be logged
		///@param lv Log level of the message
		///
		LogEntry(const StringT &token, Level lv = Info):
			_lv(lv),
			_timeStamp(ClockT::now()),
			_token(token)
		{}

		///
		///@brief Destroy the Log Entry
		///
		///
		virtual ~LogEntry() = default;

		///
		///@brief Time Stamp type
		///
		///
		using TimeStampT = TimeStamp<ClockT, StringT>;

		///
		///@brief Get the Log Level
		///
		///@return Level Log level of the entry
		///
		Level			getLevel() const
		{
			return _lv;
		}

		///
		///@brief Get the Time Stamp object
		///
		///@return const TimeStampT& Timestamp of the entry
		///
		const TimeStampT	&getTimeStamp() const
		{
			return _timeStamp;
		}

		///
		///@brief Get the Token message
		///
		///@return const StringT& Token message string
		///
		const StringT	&getToken() const
		{
			return _token;
		}

	protected:
		Level		_lv;
		TimeStampT	_timeStamp;
		StringT		_token;
	private:
	};

}

#endif /* !LOGENTRY_HPP_ */
