//	DDCPP/standard/bits/DD_binary_find.hpp
#ifndef DD_BINARY_FIND_HPP_INCLUDED_
#	define DD_BINARY_FIND_HPP_INCLUDED_ 1



#	include "DD_middle.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename ValueT_>
FreeAccessIteratorT_ binary_find(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	ValueT_ const& value__
) {
	for (FreeAccessIteratorT_ high__ = end__; begin__ < high__; ) {
		FreeAccessIteratorT_ current__ = middle(begin__, high__);
		if (value__ < *current__) {
			high__ = current__;
		} else if (*current__ < value__) {
			begin__ = current__ + 1;
		} else {
			return current__;
		}
	}
	return end__;
}

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

template <typename FreeAccessRangeT_, typename ValueT_>
#	if __cplusplus >= 201402L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__
) noexcept(noexcept(::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__))) {
#	elif __cplusplus >= 201103L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__
) noexcept(
	noexcept(::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__))
) -> decltype(::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__)) {
#	else
inline DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_) binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__
) {
#	endif
	return ::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__);
}

template <typename FreeAccessRangeT_, typename ValueT_, typename BinaryPredicateT_>
#	if __cplusplus >= 201402L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) noexcept(noexcept(::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__, less__))) {
#	elif __cplusplus >= 201103L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) noexcept(
	noexcept(::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__, less__))
) -> decltype(::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__, less__)) {
#	else
inline DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_) binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) {
#	endif
	return ::DD::detail_::binary_find(DD_SPLIT_RANGE(range__), value__, less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::binary_find;



DD_END_



#endif
