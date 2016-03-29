//	DDCPP/console/bits/DD_console_clear_screen.hpp
#ifndef DD_CONSOLE_CLEAR_SCREEN_HPP_INCLUDED_
#	define DD_CONSOLE_CLEAR_SCREEN_HPP_INCLUDED_ 1



#	include "DD_console_definitions.hpp"



#	if DD_CONSOLE_IS_ON_WIN32
#		include <cstdlib>



#	endif
DD_CONSOLE_DETAIL_BEGIN_
inline ProcessType clear_screen() noexcept {
#	if DD_CONSOLE_IS_ON_WIN32
	system("cls");
#	endif
}



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::clear_screen;



DD_CONSOLE_END_



#endif
