//	DDCPP/standard/bits/DD_insert_sort.hpp
#ifndef _DD_INSERT_SORT_HPP_INCLUDED
#	define _DD_INSERT_SORT_HPP_INCLUDED


#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	else
#		include "DD_IteratorValue.hpp"
#	endif
#	include "DD_IsBidirectionalIterator.hpp"
#	include "DD_swap_target.hpp"



_DD_DETAIL_BEGIN
template <ValidityType _is_bidirectional_iterator_c>
struct _InsertSort {
	template <typename _UndirectionalIteratorT_>
	static ProcessType _insert_sort(
		_UndirectionalIteratorT_ const& __begin_,
		_UndirectionalIteratorT_ const& __end_
	) DD_NOEXCEPT_IF(
		noexcept(swap_target(__begin_, __end_)) &&
		noexcept(++const_cast<_UndirectionalIteratorT_&>(__begin_) != __end_) &&
		noexcept(*__begin_ < *__end_)
	) {
		if (__begin_ != __end_) {
			for (_UndirectionalIteratorT_ __current_(__begin_), __front_; ++__current_ != __end_; ) {
				__front_ = __begin_;
				do {
					if (*__current_ < *__front_) {
						do {
							swap_target(__front_, __current_);
						} while (++__front_ != __current_);
						break;
					}
				} while (++__front_ != __current_);
			}
		}
	}

	template <typename _UndirectionalIteratorT_, typename _BinaryPredicatorT_>
	static ProcessType _insert_sort(
		_UndirectionalIteratorT_ const& __begin_,
		_UndirectionalIteratorT_ const& __end_,
		_BinaryPredicatorT_ const& __less_
	) DD_NOEXCEPT_IF(
		noexcept(swap_target(__begin_, __end_)) &&
		noexcept(++const_cast<_UndirectionalIteratorT_&>(__begin_) != __end_) &&
		noexcept(__less_(*__begin_, *__end_))
	) {
		if (__begin_ != __end_) {
			for (_UndirectionalIteratorT_ __current_(__begin_), __front_; ++__current_ != __end_; ) {
				__front_ = __begin_;
				do {
					if (__less_(*__current_, *__front_)) {
						do {
							swap_target(__front_, __current_);
						} while (++__front_ != __current_);
						break;
					}
				} while (++__front_ != __current_);
			}
		}
	}


};



template <>
struct _InsertSort<true> {
	template <typename _BidirectionalIteratorT_>
	static ProcessType _insert_sort(
		_BidirectionalIteratorT_ const& __begin_,
		_BidirectionalIteratorT_ const& __end_
	) DD_NOEXCEPT_IF(
		noexcept(IteratorValueType<_BidirectionalIteratorT_>(move(*__begin_))) &&
		noexcept(++const_cast<_BidirectionalIteratorT_&>(__begin_) == __end_) &&
		noexcept(*__begin_ < *__end_)
	) {
		if (__begin_ != __end_) {
			for (_BidirectionalIteratorT_ __current_(__begin_), __front_; ++__current_ != __end_; ) {
				__front_ = __current_;
#	if __cplusplus >= 201103L
				auto _temp = move(*__front_);
				for (auto __previous_(__front_); _temp < *--__previous_; ) {
					*__front_ = move(*__previous_);
					--__front_;
					if (__front_ == __begin_) {
						break;
					}
				}
				*__front_ = move(_temp);
#	else
				typename IteratorValue<_BidirectionalIteratorT_>::Type _temp = *__current_;
				for (_BidirectionalIteratorT_ __previous_(__front_); _temp < *--__previous_; ) {
					*__front_ = *__previous_;
					--__front_;
					if (__previous_ == __begin_) {
						break;
					}
				}
				*__front_ = _temp;
#	endif
			}
		}
	}

	template <typename _BidirectionalIteratorT_, typename _BinaryPredicatorT_>
	static ProcessType _insert_sort(
		_BidirectionalIteratorT_ const& __begin_,
		_BidirectionalIteratorT_ const& __end_,
		_BinaryPredicatorT_ const& __less_
	) DD_NOEXCEPT_IF(
		noexcept(IteratorValueType<_BidirectionalIteratorT_>(move(*__begin_))) &&
		noexcept(++const_cast<_BidirectionalIteratorT_&>(__begin_) == __end_) &&
		noexcept(__less_(*__begin_, *__end_))
	) {
		if (__begin_ != __end_) {
			for (_BidirectionalIteratorT_ __current_(__begin_), __front_; ++__current_ != __end_; ) {
				__front_ = __current_;
#	if __cplusplus >= 201103L
				auto _temp = move(*__front_);
				for (auto __previous_(__front_); __less_(_temp, *--__previous_); ) {
					*__front_ = move(*__previous_);
					--__front_;
					if (__front_ == __begin_) {
						break;
					}
				}
				*__front_ = move(_temp);
#	else
				typename IteratorValue<_BidirectionalIteratorT_>::Type _temp = *__current_;
				for (_BidirectionalIteratorT_ __previous_(__front_); __less_(_temp, *--__previous_); ) {
					*__front_ = *__previous_;
					--__front_;
					if (__previous_ == __begin_) {
						break;
					}
				}
				*__front_ = _temp;
#	endif
			}
		}
	}


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _UndirectionalIteratorT>
inline ProcessType insert_sort(
	_UndirectionalIteratorT const& __begin,
	_UndirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(
	_detail::_InsertSort<
		IsBidirectionalIterator<_UndirectionalIteratorT>::value
	>::_insert_sort(__begin DD_COMMA __end)
) {
	_detail::_InsertSort<
		IsBidirectionalIterator<_UndirectionalIteratorT>::value
	>::_insert_sort(__begin, __end);
}

template <typename _UndirectionalIteratorT, typename _BinaryPredicatorT>
inline ProcessType insert_sort(
	_UndirectionalIteratorT const& __begin,
	_UndirectionalIteratorT const& __end,
	_BinaryPredicatorT const& __less
) DD_NOEXCEPT_AS(
	_detail::_InsertSort<
		IsBidirectionalIterator<_UndirectionalIteratorT>::value
	>::_insert_sort(__begin DD_COMMA __end DD_COMMA __less)
) {
	_detail::_InsertSort<
		IsBidirectionalIterator<_UndirectionalIteratorT>::value
	>::_insert_sort(__begin, __end, __less);
}

template <typename _UndirectionalRangeT>
inline ProcessType insert_sort(
	_UndirectionalRangeT& __range
) DD_NOEXCEPT_AS(DD_SPLIT_RANGE(__range)) {
	insert_sort(DD_SPLIT_RANGE(__range));
}

template <typename _UndirectionalRangeT, typename _BinaryPredicatorT>
inline ProcessType insert_sort(
	_UndirectionalRangeT& __range,
	_BinaryPredicatorT const& __less
) DD_NOEXCEPT_AS(DD_SPLIT_RANGE(__range) DD_COMMA __less) {
	insert_sort(DD_SPLIT_RANGE(__range), __less);
}



_DD_END



#endif
