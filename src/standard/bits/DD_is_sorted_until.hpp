//	DDCPP/standard/bits/DD_is_sorted_until.hpp
#ifndef _DD_IS_SORTED_UNTIL_HPP_INCLUDED
#	define _DD_IS_SORTED_UNTIL_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



_DD_DETAIL_BEGIN
template <ValidityType _is_free_access_iterator>
struct _IsSortedUntil {
	template <typename _UndirectionalIteratorT_>
	static _UndirectionalIteratorT_ _is_sorted_until(
		_UndirectionalIteratorT_ __begin_,
		_UndirectionalIteratorT_ const& __end_
	) DD_NOEXCEPT_AS(++__begin_ != __end_ && *__begin_ < *__begin_ DD_COMMA _UndirectionalIteratorT_(__begin_)) {
		if (__begin_ != __end_) {
			for (_UndirectionalIteratorT_ __front_(__begin_); ++__begin_ != __end_ && !(*__begin_ < *__front_); ) {
				__front_ = __begin_;
			}
		}
		return __begin_;
	}

	template <typename _UndirectionalIteratorT_, typename _BinaryPredicatorT_>
	static _UndirectionalIteratorT_ _is_sorted_until(
		_UndirectionalIteratorT_ __begin_,
		_UndirectionalIteratorT_ const& __end_,
		_BinaryPredicatorT_ const& __less_
	) DD_NOEXCEPT_AS(++__begin_ != __end_ && __less_(*__begin_ DD_COMMA *__begin_) DD_COMMA _UndirectionalIteratorT_(__begin_)) {
		if (__begin_ != __end_) {
			for (_UndirectionalIteratorT_ __front_(__begin_); ++__begin_ != __end_ && !__less_(*__begin_, *__front_); ) {
				__front_ = __begin_;
			}
		}
		return __begin_;
	}


};



template <>
struct _IsSortedUntil<true> {
	template <typename _FreeAccessIteratorT_>
	static _FreeAccessIteratorT_ _is_sorted_until(
		_FreeAccessIteratorT_ __begin_,
		_FreeAccessIteratorT_ const& __end_
	) DD_NOEXCEPT_AS(++__begin_ < __end_ && *__begin_ < *(__begin_ - 1)) {
		while (++__begin_ < __end_ && !(*__begin_ < *(__begin_ - 1))) {
		}
		return __begin_;
	}

	template <typename _FreeAccessIteratorT_, typename _BinaryPredicatorT_>
	static _FreeAccessIteratorT_ _is_sorted_until(
		_FreeAccessIteratorT_ __begin_,
		_FreeAccessIteratorT_ const& __end_,
		_BinaryPredicatorT_ const& __less_
	) DD_NOEXCEPT_AS(++__begin_ < __end_ && __less_(*__begin_ DD_COMMA *(__begin_ - 1))) {
		while (++__begin_ < __end_ && !__less_(*__begin_, *(__begin_ - 1))) {
		}
		return __begin_;
	}


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _UndirectionalIteratorT>
inline _UndirectionalIteratorT is_sorted_until(
	_UndirectionalIteratorT const& __begin,
	_UndirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(_detail::_IsSortedUntil<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted_until(__begin DD_COMMA __end)) {
	return _detail::_IsSortedUntil<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted_until(__begin, __end);
}

template <typename _UndirectionalIteratorT, typename _BinaryPredicatorT>
inline _UndirectionalIteratorT is_sorted_until(
	_UndirectionalIteratorT const& __begin,
	_UndirectionalIteratorT const& __end,
	_BinaryPredicatorT const& __less
) DD_NOEXCEPT_AS(_detail::_IsSortedUntil<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted_until(__begin DD_COMMA __end DD_COMMA __less)) {
	return _detail::_IsSortedUntil<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted_until(__begin, __end, __less);
}



_DD_END



#endif
