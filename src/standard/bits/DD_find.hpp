//	DDCPP/standard/bits/DD_find.hpp
#ifndef DD_FIND_HPP_INCLUDED_
#	define DD_FIND_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
UndirectionalIteratorT_ find(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(begin__ != end__ && *++begin__ != value__) {
	while (begin__ != end__ && *begin__ != value__) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicatorT_>
UndirectionalIteratorT_ find(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__,
	BinaryPredicatorT_ equal__
) DD_NOEXCEPT_AS(begin__ != end__ && equal__(*++begin__, value__)) {
	while (begin__ != end__ && !equal__(*begin__, value__)) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(find(DD_SPLIT_RANGE(range__) DD_COMMA value__)) {
	return find(DD_SPLIT_RANGE(range__), value__);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicatorT_ equal__
) DD_NOEXCEPT_AS(find(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA equal__)) {
	return find(DD_SPLIT_RANGE(range__), value__, equal__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find;



DD_END_



#endif
