//	DDCPP/standard/bits/DD_replace_if.hpp
#ifndef DD_REPLACE_IF_HPP_INCLUDED_
#	define DD_REPLACE_IF_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicateT_, typename ValueT_>
ProcessType replace_if(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	UnaryPredicateT_ predicate__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__ && predicate__(*begin__)) {
	for (; begin__ != end__; ++begin__) {
		if (predicate__(*begin__)) {
			*begin__ = value__;
		}
	}
}

template <typename UndirectionalRangeT_, typename UnaryPredicateT_, typename ValueT_>
inline ProcessType replace_if(
	UndirectionalRangeT_& range__,
	UnaryPredicateT_ predicate__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(::DD::detail_::replace_if(DD_SPLIT_RANGE(range__) DD_COMMA predicate__ DD_COMMA value__)) {
	::DD::detail_::replace_if(DD_SPLIT_RANGE(range__), predicate__, value__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::replace_if;



DD_END_



#endif
