//	DDCPP/standard/bits/DD_binary_find.hpp
#ifndef DD_BINARY_FIND_HPP_INCLUDED_
#	define DD_BINARY_FIND_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"
#	include "DD_IteratorDifference.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename ValueT_>
FreeAccessIteratorT_ binary_find(
	FreeAccessIteratorT_ const& begin__,
	FreeAccessIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(begin__[0] < value__) {
	DD_ALIAS(IndexType_, DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_));
	IndexType_ lower_bound__ = IndexType_();
	IndexType_ higher_bound__ = end__ - begin__;
	for (IndexType_ current__; lower_bound__ < higher_bound__; ) {
		current__ = (lower_bound__ + higher_bound__) / 2;
		if (begin__[current__] < value__) {
			lower_bound__ = current__ + 1;
		} else if (value__ < begin__[current__]) {
			higher_bound__ = current__;
		} else {
			return begin__ + current__;
		}
	}
	return end__;
}

template <typename FreeAccessIteratorT_, typename ValueT_, typename BinaryPredicateT_>
FreeAccessIteratorT_ binary_find(
	FreeAccessIteratorT_ const& begin__,
	FreeAccessIteratorT_ const& end__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) DD_NOEXCEPT_AS(less__(begin__[0], value__)) {
	DD_ALIAS(IndexType_, DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_));
	IndexType_ lower_bound__ = IndexType_();
	IndexType_ higher_bound__ = end__ - begin__;
	for (IndexType_ current__; lower_bound__ < higher_bound__; ) {
		current__ = (lower_bound__ + higher_bound__) / 2;
		if (less__(begin__[current__], value__)) {
			lower_bound__ = current__ + 1;
		} else if (less__(value__, begin__[current__])) {
			higher_bound__ = current__;
		} else {
			return begin__ + current__;
		}
	}
	return end__;
}

template <typename FreeAccessRangeT_, typename ValueT_>
#	if __cplusplus >= 201402L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__
) noexcept(noexcept(binary_find(DD_SPLIT_RANGE(range__), value__))) {
#	elif __cplusplus >= 201103L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__
) noexcept(
	noexcept(binary_find(DD_SPLIT_RANGE(range__), value__))
) -> decltype(binary_find(DD_SPLIT_RANGE(range__), value__)) {
#	else
inline DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_) binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__
) {
#	endif
	return binary_find(DD_SPLIT_RANGE(range__), value__);
}

template <typename FreeAccessRangeT_, typename ValueT_, typename BinaryPredicateT_>
#	if __cplusplus >= 201402L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) noexcept(noexcept(binary_find(DD_SPLIT_RANGE(range__), value__, less__))) {
#	elif __cplusplus >= 201103L
inline auto binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) noexcept(
	noexcept(binary_find(DD_SPLIT_RANGE(range__), value__, less__))
) -> decltype(binary_find(DD_SPLIT_RANGE(range__), value__, less__)) {
#	else
inline DD_MODIFY_TRAIT(Iterator, FreeAccessRangeT_) binary_find(
	FreeAccessRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ const& less__
) {
#	endif
	return binary_find(DD_SPLIT_RANGE(range__), value__, less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::binary_find;



DD_END_



#endif
