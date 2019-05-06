/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Log target object abstract class temlplate
*/

#ifndef ALOGTARGET_HPP_
    #define ALOGTARGET_HPP_

	#include <LogEntry.hpp>

namespace Log {

	///
	///@brief Generic Base Log Target template
	///
	///@tparam ClockT Clock type to be used for the log entries timestamps
	///@tparam StringT String type implementation
	///
	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class ALogTarget {
	public:

		///
		///@brief Log Entry type
		///
		///
		using LogEntryT = LogEntry<ClockT, StringT>;

		///
		///@brief Construct a new ALogTarget object
		///
		///@param lv Minimum Log level for the target
		///
		ALogTarget(Level lv = All):
			_lv(lv)
		{}

		///
		///@brief Destroy the ALogTarget object
		///
		///
		virtual ~ALogTarget() = default;

		///
		///@brief (Abstract member) Writes a log entry to the target
		///
		/// Writes a log entry to the Log Target object.
		/// Exact writing procedure is implementation dependent
		///
		///@param entry Log Entry to be written in the log
		///
		virtual void	log(const LogEntryT &entry) = 0;

		///
		///@brief Writes a log entry to the target
		///
		/// Generates a log entry from a token string & a log level and writes it to the Log Target.
		/// Effectively calls 'log(generated_entry)' where 'generated_entry' is a LogEntryT constructed
		/// from token & lv
		///
		///@param token Token message string
		///@param lv Log Level of the Log Entry
		///
		void	log(const StringT &token, Level lv = Info)
		{
			log(LogEntryT(token, lv));
		}

		///
		///@brief Set the minimum Log Level
		///
		///@param lv new minimum Log Level
		///
		void	setLevel(Level lv)
		{
			_lv = lv;
		}

		///
		///@brief Get the minimum Log Level
		///
		///@return Level minimum Log Level of the Log Target
		///
		Level	getLevel() const
		{
			return _lv;
		}

	protected:
		Level	_lv;
	};

}

#endif /* !ALOGTARGET_HPP_ */
