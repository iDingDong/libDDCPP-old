//	DDCPP/standard/bits/DD_memory_move.hpp
#ifndef DD_MEMORY_MOVE_HPP_INCLUDED_
#	define DD_MEMORY_MOVE_HPP_INCLUDED_ 1



#	include <cstring>

#	include "DD_size_distance.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
inline memory_move(ValueT_* begin_, ValueT_* end_, ValueT_* result_begin_) {
	return std::memmove(begin_, result_begin_, ::DD::size_distance(begin_, end_));
}



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
