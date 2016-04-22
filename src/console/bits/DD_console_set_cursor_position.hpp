//	DDCPP/console/bits/DD_console_set_cursor_position.hpp
#ifndef DD_CONSOLE_SET_CURSOR_POSITION_HPP_INCLUDED_
#	define DD_CONSOLE_SET_CURSOR_POSITION_HPP_INCLUDED_ 1



#	include "DD_console_ConsoleFailure.hpp"



DD_CONSOLE_DETAIL_BEGIN_
inline ProcessType set_cursor_position(Coord coord_) {
#	if DD_CONSOLE_IS_ON_WIN32
	if (!SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		::DD::console::detail_::convert_coord_(coord_)
	)) {
		throw ConsoleFailure("Unable to print: 'DD::console::put_at'", GetLastError());
	}
#	endif
}

inline ProcessType set_cursor_position(CoordValueType x_, CoordValueType y_) {
	set_cursor_position(Coord{ x_, y_ });
}



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::set_cursor_position;



DD_CONSOLE_END_



#endif
