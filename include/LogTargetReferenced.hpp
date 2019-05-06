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

	///
	///@brief Single object insertion generic Log Target template
	///
	/// Log Target template defining a log template which logs
	/// by inserting in an ostream like device. Underlying object
	/// requires insertion operator capable of inserting:
	///	- char values,
	///	- char * a.k.a. C style string,
	///	- StringT template type object,
	///	- the <ostream> modifier std::endl.
	///
	/// underlying object is external to the object and only referenced in the target
	///
	/// (c++20 Concepts will have their place here when officialy released)
	///
	///@tparam ObjT Type of the underlying object
	///@tparam ClockT Clock type to be used for the log entries timestamps
	///@tparam StringT String type implementation
	///
	template<
		class ObjT,
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LogTargetReferenced : public LogTarget<ObjT &, ClockT, StringT> {
	public:

		///
		///@brief Construct a new Log Target Referenced object
		///
		///@param target Reference to the object to insert in the logs
		///@param lv Minimum log level
		///
		LogTargetReferenced(ObjT &target, Level lv = All):
			LogTarget<ObjT &, ClockT, StringT>(target, lv)
		{}

		///
		///@brief Destroy the Log Target Referenced object
		///
		///
		~LogTargetReferenced() = default;

	protected:
	private:
	};

}
#endif /* !LOGTARGETREFERENCED_HPP_ */
