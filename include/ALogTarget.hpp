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

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class ALogTarget {
	public:

		using LogEntryT = LogEntry<ClockT, StringT>;

		ALogTarget(Level lv = All):
			_lv(lv)
		{}

		virtual ~ALogTarget() = default;

		virtual void	log(const LogEntryT &entry) = 0;

		void	log(const StringT &token, Level lv = Info)
		{
			log(LogEntryT(token, lv));
		}

		void	setLevel(Level lv)
		{
			_lv = lv;
		}

		Level	getLevel() const
		{
			return _lv;
		}

	protected:
		Level	_lv;
	};

}

#endif /* !ALOGTARGET_HPP_ */
