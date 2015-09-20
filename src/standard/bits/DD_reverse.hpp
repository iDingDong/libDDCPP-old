//	DDCPP/standard/bits/DD_reverse.hpp
#ifndef _DD_REVERSE_HPP_INCLUDED
#	define _DD_REVERSE_HPP_INCLUDED 1



#	include "DD_swap_target.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN
template <ValidityType _is_free_access_iterator_c>
struct _Reverse {
	template <typename _BidirectionalIteratorT_>
	static ProcessType _reverse(
		_BidirectionalIteratorT_ __begin_,
		_BidirectionalIteratorT_ __end_
	) DD_NOEXCEPT_AS(swap_target(++__begin_, --__end_) DD_COMMA ValidityType(__begin_ != __end_)) {
		for (; __begin_ != __end_ && __begin_ != --__end_; ++__begin_) {
			swap_target(__begin_, __end_);
		}
	}


};



template <>
struct _Reverse<true> {
	template <typename _FreeAccessIteratorT_>
	static ProcessType _reverse(
		_FreeAccessIteratorT_ __begin_,
		_FreeAccessIteratorT_ __end_
	) DD_NOEXCEPT_AS(swap_target(++__begin_, --__end_) DD_COMMA ValidityType(__begin_ < __end_)) {
		for (; __begin_ < --__end_; ++__begin_) {
			swap_target(__begin_, __end_);
		}
	}


};



DD_DETAIL_END



DD_BEGIN
template <typename _BidirectionalIteratorT>
inline ProcessType reverse(
	_BidirectionalIteratorT const& __begin,
	_BidirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(_detail::_Reverse<IsFreeAccessIterator<_BidirectionalIteratorT>::value>::_reverse(__begin DD_COMMA __end)) {
	_detail::_Reverse<IsFreeAccessIterator<_BidirectionalIteratorT>::value>::_reverse(__begin, __end);
}



template <typename _BidirectionalRangeT>
inline ProcessType reverse(
	_BidirectionalRangeT& __range
) DD_NOEXCEPT_AS(reverse(DD_SPLIT_RANGE(__range))) {
	reverse(DD_SPLIT_RANGE(__range));
}



DD_END



#endif
