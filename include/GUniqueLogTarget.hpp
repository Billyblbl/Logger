/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Unique ownership responsible log target
*/

#ifndef GUNIQUELOGTARGET_HPP_
    #define GUNIQUELOGTARGET_HPP_

	#include "GLogTarget.hpp"

template<class ostreamType> class GUniqueLogTarget : public GLogTarget<ostreamType> {
	public:

		template<typename... Args> GUniqueLogTarget(Level lv, Args&&... args):
			_unique(std::forward<Args>(args)),
			GLogTarget<ostreamType>(lv, _unique)
		{}

		~GUniqueLogTarget() = default;

	protected:
	private:
		ostreamType	_unique;
};

#endif /* !GUNIQUELOGTARGET_HPP_ */
