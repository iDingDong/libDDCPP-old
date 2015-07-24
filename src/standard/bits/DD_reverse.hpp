//	standard/bits/DD_reverse.hpp
#ifndef _DD_REVERSE_HPP_INCLUDED
#	define _DD_REVERSE_HPP_INCLUDED 1



#	include "DD_swap_target.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN
template <ValidityType _is_free_access_iterator_c>
struct _Reverse {
	template <typename _BidirectionalIteratorT_>
	static ProcessType reverse(
		_BidirectionalIteratorT_ __begin,
		_BidirectionalIteratorT_ __end
	) DD_NOEXCEPT_AS(swap_target(++__begin, --__end) DD_COMMA ValidityType(__begin != __end)) {
		for (; __begin != __end && __begin != --__end; ++__begin) {
			swap_target(__begin, __end);
		}
	}
	
	
};



template <>
struct _Reverse<true> {
	template <typename _FreeAccessIteratorT_>
	static ProcessType reverse(
		_FreeAccessIteratorT_ __begin,
		_FreeAccessIteratorT_ __end
	) DD_NOEXCEPT_AS(swap_target(++__begin, --__end) DD_COMMA ValidityType(__begin < __end)) {
		for (; __begin < --__end; ++__begin) {
			swap_target(__begin, __end);
		}
	}
	
	
}; 



DD_DETAIL_END 



DD_BEGIN
template <typename _BidirectionalIteratorT>
inline ProcessType reverse(
	_BidirectionalIteratorT const& __begin,
	_BidirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(detail::_Reverse<IsFreeAccessIterator<_BidirectionalIteratorT>::value>::reverse(__begin DD_COMMA __end)) {
	detail::_Reverse<IsFreeAccessIterator<_BidirectionalIteratorT>::value>::reverse(__begin, __end);
}



DD_END



#endif
