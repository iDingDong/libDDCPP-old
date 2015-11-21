//	DDCPP/standard/bits/DD_find_if_not.hpp
#ifndef DD_FIND_IF_NOT_HPP_INCLUDED_
#	define DD_FIND_IF_NOT_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicateT_>
UndirectionalIteratorT_ find_if_not(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicateT_ predicate__
) DD_NOEXCEPT_AS(begin__ != end__ && predicate__(*++begin__)) {
	while (begin__ != end__ && predicate__(*begin__)) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalRangeT_, typename UnaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_if_not(
	UndirectionalRangeT_& range__,
	UnaryPredicateT_ predicate__
) DD_NOEXCEPT_AS(::DD::detail_::find_if_not(DD_SPLIT_RANGE(range__) DD_COMMA predicate__)) {
	return ::DD::detail_::find_if_not(DD_SPLIT_RANGE(range__), predicate__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_if_not;



DD_END_



#endif
