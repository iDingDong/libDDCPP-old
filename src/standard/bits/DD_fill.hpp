//	DDCPP/standard/bits/DD_fill.hpp
#ifndef DD_FILL_HPP_INCLUDED_
#	define DD_FILL_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
ProcessType fill(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__) {
	for (; begin__ != end__; ++begin__) {
		*begin__ = value__;
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::fill;



DD_END_



#endif
