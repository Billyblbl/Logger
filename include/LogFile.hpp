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

	///
	///@brief File logging log target template
	///
	/// Log Target of underlying object type std::ofstream,
	/// writes logs into a log file.
	///
	///@tparam ClockT Clock type to be used for the log entries timestamps
	///@tparam StringT String type implementation
	///
	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LogFile : public LogTarget<std::ofstream, ClockT, StringT> {
	public:

		///
		///@brief Construct a new Log File object
		///
		///@param path path to the file
		///@param mode io mode of the file stream
		///
		LogFile(const StringT &path, std::ios_base::openmode mode = ios_base::out):
			LogTarget<std::ofstream, ClockT, StringT>(path, mode)
		{
			if (!_obj)
				throw FileSystemErr<ClockT, StringT>(StringT(__func__), path, errno);
		}

		///
		///@brief Construct a new Log File object
		///
		/// Move constructor
		///
		///@param other Log File target to be moved into self
		///
		LogFile(LogFile &&other): LogTarget<std::ofstream, ClockT, StringT>(std::move(other))
		{
			if (!_obj)
				throw RuntimeErr<ClockT, StringT>(StringT(__func__) + " : Invalid ofstream");
		}

		///
		///@brief Destroy the Log File object
		///
		///
		~LogFile() = default;

	protected:
	private:
	};

}

#endif /* !LOGFILE_HPP_ */
