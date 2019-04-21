/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** logger main object
*/

#ifndef LOGGER_HPP_
    #define LOGGER_HPP_

	#include <vector>
	#include <memory>
	#include "ILogTarget.hpp"

namespace Log {

	class Logger {

		public:

			Logger() = default;
			~Logger() = default;

			void		Log(const char *message, Level lv = All);

			using TargetVector = std::vector<std::unique_ptr<ILogTarget>>;
			using iterator = TargetVector::iterator;

			iterator	begin();
			iterator	end();

			void		Erase(const iterator it);

			void		Clear();

			template<class targetType, typename...Args>
			void	Add(Args&&... args)
			{
				static_assert(std::is_convertible<targetType *, ILogTarget *>::value,
							  "Can't add non-LogTarget object to Logger");
				_targets.push_back(std::make_unique<targetType>(args)...);
			}

			template<class targetType>
			void	operator+=(targetType &&right)
			{
				Add(right);
			}

			template<class targetType>
			void	operator-=(targetType &&right)
			{
				Erase(std::find(_targets.begin(), _targets.end(), &right));
			}

			template<typename stringType>
			void	operator<<(const stringType &right)
			{
				Log(right, _deflt);
			}

			void	operator<<(const std::string &right)
			{
				Log(right.c_str(), _deflt);
			}

		protected:
		private:
			TargetVector	_targets;
			Level			_deflt;

	};
}

#endif /* !LOGGER_HPP_ */
