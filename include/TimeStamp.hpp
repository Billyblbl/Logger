/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Timestamp object template
*/

#ifndef TIMESTAMP_HPP_
    #define TIMESTAMP_HPP_

	#include <string>
	#include <chrono>
	#include <ctime>

namespace Log {

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class TimeStamp {
	public:

		using TimePoint = std::chrono::time_point<ClockT>;
		using SecondD = std::chrono::duration<double>;

		TimeStamp(const TimePoint &_time)
		{
			auto tt = ClockT::to_time_t(_time);
			auto tm = std::gmtime(&tt);
			_stamp += tm->tm_mon + 1 + '-';
			_stamp += tm->tm_mday + '-';
			_stamp += tm->tm_year + 1900 + ' ';
			if (tm->tm_hour <= 9)
				_stamp += '0';
			_stamp += tm->tm_hour + ':';
			if (tm->tm_min <= 9)
				_stamp += '0';
    		_stamp += tm->tm_min + ':';
			SecondD	sec = _time - ClockT::from_time_t(tt) +
						  std::chrono::seconds(tm->tm_sec);
			if (sec.count() < 10)
        		_stamp += '0';
			_stamp += sec.count() + ':';
		}

		~TimeStamp() = default;

		operator const StringT &() const
		{
			return _stamp;
		}

	protected:
	private:
		StringT	_stamp;
	};

}

#endif /* !TIMESTAMP_HPP_ */
