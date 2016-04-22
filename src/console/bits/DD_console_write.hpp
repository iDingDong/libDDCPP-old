//	DDCPP/console/bits/DD_console_write.hpp
#ifndef DD_CONSOLE_WRITE_HPP_INCLUDED_
#	define DD_CONSOLE_WRITE_HPP_INCLUDED_ 1



#	include <standard/bits/DD_get_string_length.hpp>

#	include "DD_console_write_length.hpp"



DD_CONSOLE_DETAIL_BEGIN_
inline ProcessType write(CStringConstType begin_, CStringConstType end_) {
	::DD::console::write_length(begin_, end_ - begin_);
}

inline ProcessType write(CStringConstType cstring_) {
	::DD::console::write_length(cstring_, ::DD::get_string_length(cstring_));
}



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::write;



DD_CONSOLE_END_



#endif
