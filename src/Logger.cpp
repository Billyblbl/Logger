/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** logger main object
*/

#include "Logger.hpp"

namespace Log {

	void	Logger::Log(const char *message, Level lv)
	{
		Level	_lv = (lv > _deflt ? lv : _deflt);
		for (auto &target : _targets) {
			target->Log(message, _lv);
		}
	}

	Logger::iterator	Logger::begin()
	{
		return _targets.begin();
	}

	Logger::iterator	Logger::end()
	{
		return _targets.end();
	}

	void				Logger::Erase(const Logger::iterator it)
	{
		_targets.erase(it);
	}

	void				Logger::Clear()
	{
		_targets.clear();
	}


}
