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
	#include "ALogTarget.hpp"

namespace Log {

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class Logger : public ALogTarget<ClockT, StringT> {

		public:

			using TargetVector = std::vector<std::unique_ptr<ALogTarget<ClockT, StringT>>;

			Logger(Level lv = All): ALogTarget(lv)
			{}

			~Logger() = default;

			void	log(const LogEntryT &entry) override
			{
				if (entry.getLevel() < _lv)
					return;
				for (auto &target : _targets) {
					target->log(entry);
				}
			}

			void	erase(std::size_t idx)
			{
				_targets.erase(idx);
			}

			void	clear()
			{
				_targets.clear();
			}

			template<class targetType, typename...Args>
			targetType	&add(Args&&... args)
			{
				static_assert(std::is_convertible<targetType *, ALogTarget *>::value,
							  "Can't add non-LogTarget object to Logger");
				return *_targets.push_back(std::make_unique<targetType>(std::forward(args)...));
			}

			template<class targetType>
			void	operator+=(targetType &&right)
			{
				add(std::move(right));
			}

		protected:
		private:
			TargetVector	_targets;
	};
}

#endif /* !LOGGER_HPP_ */
