/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Log Level definition
*/

#ifndef LOGLEVEL_HPP_
    #define LOGLEVEL_HPP_

	#include <ostream>
	#include <unordered_map>

namespace Log {

	///
	///@brief Log level
	///Defines the level of pertinence of a log message.
	///Log Targets can use it to filter out unwanted message
	///
	enum Level : uint8_t {
		All		= 0,
		Debug	= 1,
		Info	= 2,
		Warning	= 3,
		Error	= 4,
		Fatal	= 5
	};

	///
	///@brief Serialization mapping type
	///
	///
	using LevelStrings = std::unordered_map<Level, const char *>;

	///
	///@brief Serialization mapping of Log Level enum type
	///
	///
	extern const LevelStrings	Serialized;

	///
	///@brief Log Level Serializer
	///
	/// Obtain a C constant string corresponding to the log level given in lv
	///
	///@param lv Log level value to serialize
	///@return const char* Corresponding serialized Log level
	///
	const char	*to_string(Level lv);

	///
	///@brief Log level stream inserter
	///
	///@param left stream
	///@param right Log level value to insert
	///@return std::ostream& stream after insertion
	///
	std::ostream		&operator<<(std::ostream &left, Level right);

}

#endif /* !LOGLEVEL_HPP_ */
