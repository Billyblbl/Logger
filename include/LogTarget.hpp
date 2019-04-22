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

	template<
		class ObjT,
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class LogTarget : public ALogTarget<ClockT, StringT> {
	public:

		template<typename... Args>
		LogTarget(Args&&... args, Level lv = All):
			ALogTarget<ClockT, StringT>(lv),
			_obj(std::forward(args)...)
		{}

		LogTarget(ObjT &obj, Level lv = All):
			ALogTarget<ClockT, StringT>(lv),
			_obj(obj)
		{}

		LogTarget(LogTarget &&) = default;

		LogTarget(const LogTarget &) = default;

		virtual ~LogTarget() = default;

		LogTarget		&operator=(LogTarget &&right) = default;

		virtual void	log(const LogEntry<ClockT, StringT> &entry) override
		{
			if (entry.getLevel() < ALogTarget<ClockT, StringT>::_lv)
				return;
			_obj << '[' << to_string(entry.getLevel()) << ']'
				 << StringT(entry.getTimeStamp()) << " : "
				 << entry.getToken() << std::endl;
		}

		const ObjT	&getObj() const
		{
			return _obj;
		}

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
