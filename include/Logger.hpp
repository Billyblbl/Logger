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

	///
	///@brief Log target collection
	///
	/// Log target containing several log targets.
	/// Logging an entry to this target logs it to all contained targets.
	///
	///@tparam ClockT Clock type to be used for the log entries timestamps
	///@tparam StringT String type implementation
	///
	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	class Logger : public ALogTarget<ClockT, StringT> {

		public:

			///
			///@brief Vector type containing all targets
			///
			///
			using TargetVector = std::vector<std::unique_ptr<ALogTarget<ClockT, StringT>>;

			///
			///@brief Construct a new Logger object
			///
			///@param lv minimum Log Level
			///
			Logger(Level lv = All): ALogTarget(lv)
			{}

			///
			///@brief Destroy the Logger object
			///
			///
			~Logger() = default;

			///
			///@brief Log function implementation
			///@sa ALogTarget
			///
			///@param entry Log Entry to be written
			///
			void	log(const LogEntryT &entry) override
			{
				if (entry.getLevel() < _lv)
					return;
				for (auto &target : _targets) {
					target->log(entry);
				}
			}

			///
			///@brief Removes target at index
			///
			///@param idx Index of the target to be removed
			///
			void	erase(std::size_t idx)
			{
				_targets.erase(idx);
			}

			///
			///@brief Removes all targets
			///
			///
			void	clear()
			{
				_targets.clear();
			}

			///
			///@brief Adds a target to the Logger
			///
			///@tparam targetType Type of target to be added
			///@tparam Args Types of Target construction arguments
			///@param args Target construction arguments
			///@return targetType& Reference to the newly added Target
			///
			template<class targetType, typename...Args>
			targetType	&add(Args&&... args)
			{
				static_assert(std::is_convertible<targetType *, ALogTarget *>::value,
							  "Can't add non-LogTarget object to Logger");
				return *_targets.push_back(std::make_unique<targetType>(std::forward(args)...));
			}

			///
			///@brief Target adding operator
			///
			/// Moves the target in place
			///
			///@tparam targetType Type of the target to be added
			///@param right rvalue of the target to be added
			///
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
