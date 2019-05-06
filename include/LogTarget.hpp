/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Log target object template
*/

#ifndef LOGTARGET_HPP_
    #define LOGTARGET_HPP_

	#include "ALogTarget.hpp"

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
	class LogTarget : public ALogTarget<ClockT, StringT> {
	public:

		///
		///@brief Construct a new Log Target object
		///
		/// Construct underlying object from arguments
		///
		///@tparam Args Types of underlying objects' construction arguments
		///@param args Underlying objects' construction arguments
		///@param lv Minimum log Level
		///
		template<typename... Args>
		LogTarget(Args&&... args, Level lv = All):
			ALogTarget<ClockT, StringT>(lv),
			_obj(std::forward(args)...)
		{}

		///
		///@brief Construct a new Log Target object
		///
		/// Copy construct underlying object from obj
		///
		///@param obj Object to be copied as the underlying object
		///@param lv Minimum log level
		///
		LogTarget(ObjT &obj, Level lv = All):
			ALogTarget<ClockT, StringT>(lv),
			_obj(obj)
		{}

		///
		///@brief Construct a Log Target object
		///
		/// Move constructor
		///
		LogTarget(LogTarget &&) = default;

		///
		///@brief Construct a Log Target object
		///
		/// Copy constructor
		///
		LogTarget(const LogTarget &) = default;

		///
		///@brief Destroy the Log Target object
		///
		///
		virtual ~LogTarget() = default;

		///
		///@brief Assignement move operator
		///
		/// Moves right into self
		///
		///@param right Log Target to be moved
		///@return LogTarget& Reference to self after move assignement
		///
		LogTarget		&operator=(LogTarget &&right) = default;

		///
		///@brief Log function implementation
		///@sa ALogTarget
		///
		///@param entry Log Entry to be written
		///
		virtual void	log(const LogEntry<ClockT, StringT> &entry) override
		{
			if (entry.getLevel() < ALogTarget<ClockT, StringT>::_lv)
				return;
			_obj << '[' << to_string(entry.getLevel()) << ']'
				 << StringT(entry.getTimeStamp()) << " : "
				 << entry.getToken() << std::endl;
		}

		///
		///@brief Get the Underlying object
		///
		///@return const ObjT&
		///
		const ObjT	&getObj() const
		{
			return _obj;
		}

		///
		///@brief Get the Underlying object
		///
		///@return ObjT&
		///
		ObjT	&getObj()
		{
			return _obj;
		}

	protected:
		ObjT	_obj;
	private:
	};

}
#endif /* !LOGTARGET_HPP_ */
