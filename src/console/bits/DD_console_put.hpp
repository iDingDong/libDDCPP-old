//	DDCPP/console/bits/DD_console_put.hpp
#ifndef DD_CONSOLE_PUT_HPP_INCLUDED_
#	define DD_CONSOLE_PUT_HPP_INCLUDED_ 1



#	include <standard/bits/DD_address_of.hpp>

#	include "DD_console_Pixel.hpp"
#	include "DD_console_put_at.hpp"



DD_CONSOLE_DETAIL_BEGIN_
inline ProcessType put(Pixel const& pixel_, Coord coord_) {
#	if DD_CONSOLE_IS_ON_WIN32
	::DD::console::put_at(pixel_.charactor, 1U, coord_);
	WORD attribute_ = extract_text_attribute_value_(pixel_.attribute);
	RealLengthType workaround_;
	if (!WriteConsoleOutputAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		::DD::address_of(attribute_),
		1U,
		::DD::console::detail_::convert_coord_(coord_),
		::DD::address_of(workaround_)
	)) {
		throw ConsoleFailure("Unable to print: 'DD::console::put'", GetLastError());
	}
#	endif
}



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::put;



DD_CONSOLE_END_



#endif


