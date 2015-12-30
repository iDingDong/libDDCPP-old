//	DDCPP/standard/bits/DD_fill_length.hpp
#ifndef DD_FILL_LENGTH_HPP_INCLUDED_
#	define DD_FILL_LENGTH_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename DifferenceT_, typename ValueT_>
UndirectionalIteratorT_ fill_length(
	UndirectionalIteratorT_ begin__,
	DifferenceT_ length__,
	ValueT_ const& value__
) {
	for (; length__; ++begin__, --length__) {
		*++begin__ = value__;
	}
	return begin__;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::fill_length;



DD_END_



#endif
