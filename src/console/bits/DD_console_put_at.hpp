//	DDCPP/console/bits/DD_console_put_at.hpp
#ifndef DD_CONSOLE_PUT_AT_HPP_INCLUDED_
#	define DD_CONSOLE_PUT_AT_HPP_INCLUDED_ 1



#	include <standard/bits/DD_address_of.hpp>

#	include "DD_console_ConsoleFailure.hpp"



DD_CONSOLE_DETAIL_BEGIN_
inline ProcessType put_at(CharactorType charactor_, RealLengthType count_, Coord coord_) {
#	if DD_CONSOLE_IS_ON_WIN32
	RealLengthType workaround_;
	if (!FillConsoleOutputCharacter(
		GetStdHandle(STD_OUTPUT_HANDLE),
		charactor_,
		count_,
		COORD{ coord_.x, coord_.y },
		::DD::address_of(workaround_)
	)) {
		throw ConsoleFailure("Unable to print: 'DD::console::put_at'", GetLastError());
	}
#	endif
}

inline ProcessType put_at(CharactorType charactor_, RealLengthType count_, CoordValueType x_, CoordValueType y_) {
	put_at(charactor_, count_, Coord{ x_, y_ });
}



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::put_at;



DD_CONSOLE_END_



#endif

