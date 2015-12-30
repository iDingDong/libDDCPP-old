//	DDCPP/standard/bits/DD_fill_construct_length.hpp
#ifndef DD_FILL_CONSTRUCT_LENGTH_HPP_INCLUDED_
#	define DD_FILL_CONSTRUCT_LENGTH_HPP_INCLUDED_ 1



#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename DifferenceT_, typename ValueT_>
UndirectionalIteratorT_ fill_construct_length(
	UndirectionalIteratorT_ begin__,
	DifferenceT_ length__,
	ValueT_ const& value__
) {
	UndirectionalIteratorT_ current__(begin__);
	try {
		for (; length__; ++current__, --length__) {
			::DD::construct(current__, value__);
		}
	} catch (...) {
		::DD::destruct(begin__, current__);
		throw;
	}
	return current__;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::fill_construct_length;



DD_END_



#endif
