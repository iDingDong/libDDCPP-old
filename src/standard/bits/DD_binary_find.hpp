//	DDCPP/standard/bits/DD_binary_find.hpp
#ifndef DD_BINARY_FIND_HPP_INCLUDED_
#	define DD_BINARY_FIND_HPP_INCLUDED_ 1



#	include "DD_middle.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename ValueT_, typename BinaryPredicateT_>
FreeAccessIteratorT_ binary_find(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) {
	for (FreeAccessIteratorT_ high__ = end__; begin__ < high__; ) {
		FreeAccessIteratorT_ current__ = middle(begin__, high__);
		if (less__(value__, *current__)) {
			high__ = current__;
		} else if (less__(*current__, value__)) {
			begin__ = current__ + 1;
		} else {
			return current__;
		}
	}
	return end__;
}

template <typename FreeAccessIteratorT_, typename ValueT_>
inline FreeAccessIteratorT_ binary_find(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<FreeAccessIteratorT_>(
	::DD::detail_::binary_find(begin__ DD_COMMA end__ DD_COMMA value__ DD_COMMA less_than)
)) {
	return ::DD::detail_::binary_find(begin__, end__, value__, less_than);
}

template <typename FreeAccessRangeT_, typename ValueT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_) binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_)>(
	::DD::detail_::binary_find(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA less__)
)) {
	return ::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__, less__);
}

template <typename FreeAccessRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_) binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_)>(
	::DD::detail_::binary_find(range__ DD_COMMA value__ DD_COMMA less_than)
)) {
	return ::DD::detail_::binary_find(range__, value__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::binary_find;



DD_END_



#endif
