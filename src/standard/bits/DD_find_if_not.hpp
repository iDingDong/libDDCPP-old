//	DDCPP/standard/bits/DD_find_if_not.hpp
#ifndef DD_FIND_IF_NOT_HPP_INCLUDED_
#	define DD_FIND_IF_NOT_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicatorT_>
UndirectionalIteratorT_ find_if_not(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicatorT_ const& predicator__
) DD_NOEXCEPT_AS(begin__ != end__ && predicator__(*++begin__)) {
	while (begin__ != end__ && predicator__(*begin__)) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalRangeT_, typename UnaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_if_not(
	UndirectionalRangeT_& range__,
	UnaryPredicatorT_ const& predicator__
) DD_NOEXCEPT_AS(find_if_not(DD_SPLIT_RANGE(range__) DD_COMMA predicator__)) {
	return find_if_not(DD_SPLIT_RANGE(range__), predicator__);
}



DD_END_



#endif
