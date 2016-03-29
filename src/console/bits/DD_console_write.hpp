//	DDCPP/console/bits/DD_console_write_at.hpp
#ifndef DD_CONSOLE_WRITE_HPP_INCLUDED_
#	define DD_CONSOLE_WRITE_HPP_INCLUDED_ 1



#	include <standard/bits/DD_address_of.hpp>
#	include <standard/bits/DD_get_string_length.hpp>

#	include "DD_console_ConsoleFailure.hpp"



DD_CONSOLE_DETAIL_BEGIN_
inline ProcessType write(CStringConstType cstring_) {
#	if DD_CONSOLE_IS_ON_WIN32
	RealLengthType workaround_;
	if (!WriteConsole(
		GetStdHandle(STD_OUTPUT_HANDLE),
		cstring_,
		get_string_length(cstring_) * sizeof(CharactorType),
		::DD::address_of(workaround_),
		::DD::nil_pointer
	)) {
		throw ConsoleFailure("Unable to print: 'DD::console::write'", GetLastError());
	}
#	endif
}



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::write;



DD_CONSOLE_END_



#endif
