/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Log target by reference
*/

#ifndef LOGTARGETREFERENCED_HPP_
    #define LOGTARGETREFERENCED_HPP_

	#include "LogTarget.hpp"

namespace Log {

	template<
		class ObjT,
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LogTargetReferenced : public LogTarget<ObjT &, ClockT, StringT> {
	public:

		LogTargetReferenced(ObjT &target, Level lv = All):
			LogTarget<ObjT &, ClockT, StringT>(target, lv)
		{}

		~LogTargetReferenced() = default;

	protected:
	private:
	};

}
#endif /* !LOGTARGETREFERENCED_HPP_ */
