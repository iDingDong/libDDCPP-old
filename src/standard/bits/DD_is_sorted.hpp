//	standard/bits/DD_is_sorted.hpp
#ifndef _DD_IS_SORTED_HPP_INCLUDED
#	define _DD_IS_SORTED_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN
template <ValidityType _is_free_access_iterator>
struct _IsSorted {
	template <typename _UndirectionalIteratorT_>
	static ValidityType _is_sorted(
		_UndirectionalIteratorT_ __begin_,
		_UndirectionalIteratorT_ const& __end_
	) DD_NOEXCEPT_AS(++__begin_ != __end_ && *__begin_ < *__begin_ DD_COMMA _UndirectionalIteratorT_(__begin_)) {
		if (__begin_ != __end_) {
			_UndirectionalIteratorT_ __front_(__begin_);
			for (; ++__begin_ != __end_; __front_ = __begin_) {
				if (*__begin_ < *__front_) {
					return false;
				}
			}
		}
		return true;
	}
	
	template <typename _UndirectionalIteratorT_, typename _BinaryPredicatorT_>
	static ValidityType _is_sorted(
		_UndirectionalIteratorT_ __begin_,
		_UndirectionalIteratorT_ const& __end_,
		_BinaryPredicatorT_ const& __less_
	) DD_NOEXCEPT_AS(++__begin_ != __end_ && __less_(*__begin_ DD_COMMA *__begin_) DD_COMMA _UndirectionalIteratorT_(__begin_)) {
		if (__begin_ != __end_) {
			_UndirectionalIteratorT_ __front_(__begin_);
			for (; ++__begin_ != __end_; __front_ = __begin_) {
				if (__less_(*__begin_, *__front_)) {
					return false;
				}
			}
		}
		return true;
	}
	
	
};



template <>
struct _IsSorted<true> {
	template <typename _FreeAccessIteratorT_>
	static ValidityType _is_sorted(
		_FreeAccessIteratorT_ __begin_,
		_FreeAccessIteratorT_ const& __end_
	) DD_NOEXCEPT_AS(++__begin_ < __end_ && *__begin_ < *(__begin_ - 1)) {
		while (++__begin_ < __end_) {
			if (*__begin_ < *(__begin_ - 1)) {
				return false;
			}
		}
		return true;
	}
	
	template <typename _FreeAccessIteratorT_, typename _BinaryPredicatorT_>
	static ValidityType _is_sorted(
		_FreeAccessIteratorT_ __begin_,
		_FreeAccessIteratorT_ const& __end_,
		_BinaryPredicatorT_ const& __less_
	) DD_NOEXCEPT_AS(++__begin_ < __end_ && __less_(*__begin_ DD_COMMA *(__begin_ - 1))) {
		while (++__begin_ < __end_) {
			if (__less_(*__begin_, *(__begin_ - 1))) {
				return false;
			}
		}
		return true;
	}
	
	
};



DD_DETAIL_END



DD_BEGIN
template <typename _UndirectionalIteratorT>
inline ValidityType is_sorted(
	_UndirectionalIteratorT const& __begin,
	_UndirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(detail::_IsSorted<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted(__begin DD_COMMA __end)) {
	return detail::_IsSorted<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted(__begin, __end);
}

template <typename _UndirectionalIteratorT, typename _BinaryPredicatorT>
inline ValidityType is_sorted(
	_UndirectionalIteratorT const& __begin,
	_UndirectionalIteratorT const& __end,
	_BinaryPredicatorT const& __less
) DD_NOEXCEPT_AS(detail::_IsSorted<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted(__begin DD_COMMA __end DD_COMMA __less)) {
	return detail::_IsSorted<IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_is_sorted(__begin, __end, __less);
}



DD_END



#endif 
