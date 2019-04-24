/*
** EPITECH PROJECT, 2019
** Logger
** File description:
** Commonly used basic Logged exceptions 
*/

#ifndef LOGGEDEXCEPTSTD_HPP_
    #define LOGGEDEXCEPTSTD_HPP_

	#include "LoggedException.hpp"

namespace Log
{
	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using Exception = LoggedException<, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using LogicErr = LoggedException<std::logic_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using InvalidArg = LoggedException<std::invalid_argument, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using DomainErr = LoggedException<std::domain_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using LengthErr = LoggedException<std::length_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using OutofRange = LoggedException<std::out_of_range, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using FutureErr = LoggedException<std::future_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadOptAccess = LoggedException<std::bad_optional_access, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using RuntimeErr = LoggedException<std::runtime_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using RangeErr = LoggedException<std::range_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using OverflowErr = LoggedException<std::overflow_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using UnderflowErr = LoggedException<std::underflow_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using RegexErr = LoggedException<std::regex_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using NonexistantLocalTime = LoggedException<std::nonexistant_local_time, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using AmbiguousLocalTime = LoggedException<std::ambiguous_local_time, ClockT, StringT>;

	template<
		class T,
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using TXErr = LoggedException<std::tx_exception<T>, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using SystemErr = LoggedException<std::system_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using IOSFailure = LoggedException<std::ios_base::failure, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using FileSystemErr = LoggedException<std::filesystem::filesystem_error, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadCast = LoggedException<std::bad_cast, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadAnyCast = LoggedException<std::bad_any_cast, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadWeakPtr = LoggedException<std::bad_weak_ptr, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadFctCall = LoggedException<std::bad_function_call, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadAlloc = LoggedException<std::bad_alloc, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadArrNewLength = LoggedException<std::bad_array_new_length, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadException = LoggedException<std::bad_exception, ClockT, StringT>;

	template<
		class ClockT = std::chrono::system_clock,
		class StringT = std::string
	>
	using BadVariantAccess = LoggedException<std::bad_variant_access, ClockT, StringT>;

}

#endif /* !LOGGEDEXCEPTSTD_HPP_ */
