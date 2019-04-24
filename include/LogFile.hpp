/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** File type log target
*/

#ifndef LOGFILE_HPP_
    #define LOGFILE_HPP_

	#include <fstream>
	#include <cstring>
	#include <cerrno>
	#include "LogTarget.hpp"
	#include "LoggedExceptStd.hpp"

namespace Log {

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LogFile : public LogTarget<std::ofstream, ClockT, StringT> {
	public:

		LogFile(const StringT &path, std::ios_base::openmode mode = ios_base::out):
			LogTarget<std::ofstream, ClockT, StringT>(path, mode)
		{
			if (!_obj)
				throw Fs::FileSystemErr<ClockT, StringT>(StringT(__func__), path, errno);
		}

		LogFile(LogFile &&other): LogTarget<std::ofstream, ClockT, StringT>(std::move(other))
		{
			if (!_obj)
				throw RuntimeErr<ClockT, StringT>(StringT(__func__) + " : Invalid ofstream");
		}

		~LogFile() = default;

	protected:
	private:
	};

}

#endif /* !LOGFILE_HPP_ */
