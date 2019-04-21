/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Logging target object template
*/

#ifndef GLOGTARGET_HPP_
    #define GLOGTARGET_HPP_

	#include "ILogTarget.hpp"

///
///@brief Namespace for Log library objects
///
///
namespace Log {

	///
	///@brief Target for message logging
	///
	///@class GLogTarget
	///Defines a target in which log messages for debug, informations,
	///warnings, errors and fatal erros can be written
	///@tparam ostream Defines the type of underlying stream of the target
	///
	template<class ostreamType> class GLogTarget : public ILogTarget {
		public:
			static_assert(std::is_convertible<ostreamType *, std::ostream *>::value,
			"LogTarget template argument must inherit from std::ostream");

			///
			///@brief Construct a new GLogTarget object
			///
			///@tparam Args Arguments types for underlying stream construction
			///@param lv Log level of the target
			///@param args Construction arguments to forward to underlying stream ref
			///
			template<typename... Args> GLogTarget(Level lv = All, Args&&... args):
				_stream(std::forward<Args>(args)...),
				_lv(lv)
			{}

			///
			///@brief Move Constructor for a GLogTarget object
			///
			///
			GLogTarget(GLogTarget &&) = default;

			///
			///@brief Copy Constructor for a GLogTarget object
			///
			///
			GLogTarget(const GLogTarget &) = default;

			///
			///@brief Destroy the GLogTarget object
			///
			///
			virtual ~GLogTarget() = default;

			///
			///@brief Move assignement operator
			///
			///@param right object to move
			///@return GLogTarget& the moved object
			///
			GLogTarget	&operator=(GLogTarget &&right) = default;

			///
			///@brief Writes message in the target.
			///If the Log level of the message is >= to the LogTarget's Log level,
			///writes message to the target, otherwise the message is ignored
			///@tparam stringType Type of string of message
			///@param message Message to be logged
			///@param lv Log level of the message
			///
			void	Log(const char *message, Level lv = All) override
			{
				if (lv >= _lv)
					_stream << '[' << lv << "] : " << message << std::endl;
			}

			///
			///@brief Set the Log Level of the object
			///
			///@param lv new Log level
			///
			void	SetLevel(Level lv) override
			{
				_lv = lv;
			}

			///
			///@brief Get the Log Level of the object
			///
			///@return Level current Level
			///
			Level	GetLevel() const override
			{
				return _lv;
			}

		protected:
			ostreamType	&_stream;
		private:

			Level		_lv;
	};
}

#endif /* !GLOGTARGET_HPP_ */
