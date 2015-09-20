//	DDCPP/standard/bits/DD_equal.hpp
#ifndef _DD_EQUAL_HPP_INCLUDED
#	define _DD_EQUAL_HPP_INCLUDED 1



#	include <cstring>

#	if __cplusplus >= 201103L
#		include "DD_IsPod.hpp"
#	else
#		include "DD_IsArithmetic.hpp"
#	endif
#	include "DD_IsPointer.hpp"
#	include "DD_IsSame.hpp"
#	include "DD_IsRange.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_size_distance.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN
template <ValidityType _is_trivially_equal_predicatable_c>
struct _Equal {
	template <ValidityType _is_free_access_iterator_c_, int _workaround_c_ = 0>
	struct __Equal {
		template <typename _UndirectionalIteratorT1__, typename _UndirectionalIteratorT2__>
		static ValidityType _equal(
			_UndirectionalIteratorT1__ __begin_1__,
			_UndirectionalIteratorT1__ const& __end_1__,
			_UndirectionalIteratorT2__ __begin_2__,
			_UndirectionalIteratorT2__ const& __end_2__
		) DD_NOEXCEPT_AS(++__begin_1__ != __end_1__ && ++__begin_2__ == __end_2__ && *__begin_1__ != *__begin_2__) {
			for (; __begin_1__ != __end_1__; ++__begin_1__, ++__begin_2__) {
				if (__begin_2__ == __end_2__) {
					return false;
				} else if (*__begin_1__ != *__begin_2__) {
					return false;
				}
			}
			return __begin_2__ == __end_2__;
		}

		template <typename _UndirectionalIteratorT1__, typename _UndirectionalIteratorT2__, typename _BinaryPredicator__>
		static ValidityType _equal(
			_UndirectionalIteratorT1__ __begin_1__,
			_UndirectionalIteratorT1__ const& __end_1__,
			_UndirectionalIteratorT2__ __begin_2__,
			_UndirectionalIteratorT2__ const& __end_2__,
			_BinaryPredicator__ const& __equal__
		) DD_NOEXCEPT_AS(++__begin_1__ != __end_1__ && ++__begin_2__ == __end_2__ && __equal__(*__begin_1__, *__begin_2__)) {
			for (; __begin_1__ != __end_1__; ++__begin_1__, ++__begin_2__) {
				if (__begin_2__ == __end_2__) {
					return false;
				} else if (!__equal__(*__begin_1__, *__begin_2__)) {
					return false;
				}
			}
			return __begin_2__ == __end_2__;
		}


	};


	template <int _workaround_c_>
	struct __Equal<true, _workaround_c_> {
		template <typename _FreeAccessIteratorT1__, typename _FreeAccessIteratorT2__>
		static ValidityType _equal(
			_FreeAccessIteratorT1__ const& __begin_1__,
			_FreeAccessIteratorT1__ const& __end_1__,
			_FreeAccessIteratorT2__ const& __begin_2__,
			_FreeAccessIteratorT2__ const& __end_2__
		) DD_NOEXCEPT_AS(__begin_1__[length_difference(__begin_1__, __end_1__)] != __begin_2__[length_difference(__begin_2__, __end_2__)]) {
#	if __cplusplus >= 201103L
			auto _length = length_difference(__begin_1__, __end_1__);
#	else
			typename IteratorDifference<_FreeAccessIteratorT1_>::Type _length = length_difference(__begin_1__, __end_1__);
#	endif
			if (_length != length_difference(__begin_2__, __end_2__)) {
				return false;
			}
			while (_length--) {
				if (__begin_1__[_length] != __begin_2__[_length]) {
					return false;
				}
			}
			return true;
		}

		template <typename _FreeAccessIteratorT1__, typename _FreeAccessIteratorT2__, typename _BinaryPredicator__>
		static ValidityType _equal(
			_FreeAccessIteratorT1__ const& __begin_1__,
			_FreeAccessIteratorT1__ const& __end_1__,
			_FreeAccessIteratorT2__ const& __begin_2__,
			_FreeAccessIteratorT2__ const& __end_2__,
			_BinaryPredicator__ const& __equal__
		) DD_NOEXCEPT_AS(__equal__(__begin_1__[length_difference(__begin_1__, __end_1__)], __begin_2__[length_difference(__begin_2__, __end_2__)])) {
#	if __cplusplus >= 201103L
			auto _length = length_difference(__begin_1__, __end_1__);
#	else
			typename IteratorDifference<_FreeAccessIteratorT1_>::Type _length = length_difference(__begin_1__, __end_1__);
#	endif
			if (_length != length_difference(__begin_2__, __end_2__)) {
				return false;
			}
			while (_length--) {
				if (!__equal__(__begin_1__[_length], __begin_2__[_length])) {
					return false;
				}
			}
			return true;
		}


	};


	template <typename _UndirectionalIteratorT1_, typename _UndirectionalIteratorT2_>
	static ValidityType _equal(
		_UndirectionalIteratorT1_ __begin_1_,
		_UndirectionalIteratorT1_ const& __end_1_,
		_UndirectionalIteratorT2_ __begin_2_
	) DD_NOEXCEPT_AS(__begin_1_ != __end_1_ && *++__begin_1_ != *++__begin_2_) {
		for (; __begin_1_ != __end_1_; ++__begin_1_, ++__begin_2_) {
			if (*__begin_1_ != *__begin_2_) {
				return false;
			}
		}
		return true;
	}

	template <typename _UndirectionalIteratorT1_, typename _UndirectionalIteratorT2_>
	static ValidityType _equal(
		_UndirectionalIteratorT1_ const& __begin_1_,
		_UndirectionalIteratorT1_ const& __end_1_,
		_UndirectionalIteratorT2_ const& __begin_2_,
		_UndirectionalIteratorT2_ const& __end_2_
	) DD_NOEXCEPT_AS(
		__Equal<
			IsFreeAccessIterator<_UndirectionalIteratorT1_ DD_COMMA _UndirectionalIteratorT2_>::value
		>::_equal(__begin_1_ DD_COMMA __end_1_ DD_COMMA __begin_2_ DD_COMMA __end_2_)
	) {
		return __Equal<
#	if __cplusplus >= 201103L
			IsFreeAccessIterator<_UndirectionalIteratorT1_, _UndirectionalIteratorT2_>::value
#	else
			IsFreeAccessIterator<_UndirectionalIteratorT1_>::value && IsFreeAccessIterator<_UndirectionalIteratorT2_>::value
#	endif
		>::_equal(__begin_1_, __end_1_, __begin_2_, __end_2_);
	}

	template <typename _UndirectionalIteratorT1_, typename _UndirectionalIteratorT2_, typename _BinaryPredicator_>
	static ValidityType _equal(
		_UndirectionalIteratorT1_ __begin_1_,
		_UndirectionalIteratorT1_ const& __end_1_,
		_UndirectionalIteratorT2_ __begin_2_,
		_BinaryPredicator_ const& __equal_
	) DD_NOEXCEPT_AS(__begin_1_ != __end_1_ && __equal_(*++__begin_1_, *++__begin_2_)) {
		for (; __begin_1_ != __end_1_; ++__begin_1_, ++__begin_2_) {
			if (!__equal_(*__begin_1_, *__begin_2_)) {
				return false;
			}
		}
		return true;
	}

	template <typename _UndirectionalIteratorT1_, typename _UndirectionalIteratorT2_, typename _BinaryPredicator_>
	static ValidityType _equal(
		_UndirectionalIteratorT1_ const& __begin_1_,
		_UndirectionalIteratorT1_ const& __end_1_,
		_UndirectionalIteratorT2_ const& __begin_2_,
		_UndirectionalIteratorT2_ const& __end_2_,
		_BinaryPredicator_ const& __equal_
	) DD_NOEXCEPT_AS(
		__Equal<
			IsFreeAccessIterator<_UndirectionalIteratorT1_ DD_COMMA _UndirectionalIteratorT2_>::value
		>::_equal(__begin_1_ DD_COMMA __end_1_ DD_COMMA __begin_2_ DD_COMMA __end_2_ DD_COMMA __equal_)
	) {
		return __Equal<
#	if __cplusplus >= 201103L
			IsFreeAccessIterator<_UndirectionalIteratorT1_, _UndirectionalIteratorT2_>::value
#	else
			IsFreeAccessIterator<_UndirectionalIteratorT1_>::value && IsFreeAccessIterator<_UndirectionalIteratorT2_>::value
#	endif
		>::_equal(__begin_1_, __end_1_, __begin_2_, __end_2_, __equal_);
	}


};



template <>
struct _Equal<true> {
	template <typename _PointerT1_, typename _PointerT2_>
	static ValidityType _equal(
		_PointerT1_ const& __begin_1_,
		_PointerT1_ const& __end_1_,
		_PointerT2_ const& __begin_2_
	) DD_NOEXCEPT {
		return !std::memcmp(get_pointer(__begin_1_), get_pointer(__begin_2_), size_distance(__begin_1_, __end_1_));
	}

	template <typename _PointerT1_, typename _PointerT2_>
	static ValidityType _equal(
		_PointerT1_ const& __begin_1_,
		_PointerT1_ const& __end_1_,
		_PointerT2_ const& __begin_2_,
		_PointerT2_ const& __end_2_
	) DD_NOEXCEPT {
		SizeType _size = size_distance(__begin_1_, __end_1_);
		return _size == size_distance(__begin_2_, __end_2_) && !std::memcmp(get_pointer(__begin_1_), get_pointer(__begin_2_), _size);
	}


};



template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2>
inline ValidityType _equal(
	_UndirectionalIteratorT1 const& __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 const& __begin_2
) DD_NOEXCEPT_AS(
	_detail::_Equal<
		AndType<
			IsPod<IteratorValueType<_UndirectionalIteratorT1>> DD_COMMA
			IsPointer<_UndirectionalIteratorT1 DD_COMMA _UndirectionalIteratorT2> DD_COMMA
			IsSame<
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT1>> DD_COMMA
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT2>>
			>
		>::value
	>::_equal(__begin_1 DD_COMMA __end_1 DD_COMMA __begin_2)
) {
	return _detail::_Equal<
#	if __cplusplus >= 201103L
		AndType<
			IsPod<IteratorValueType<_UndirectionalIteratorT1>>,
			IsPointer<_UndirectionalIteratorT1, _UndirectionalIteratorT2>,
			IsSame<
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT1>>,
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT2>>
			>
		>::value
#	else
		IsArithmetic<typename IteratorValue<_UndirectionalIteratorT1>::Type>::value && IsPointer<_UndirectionalIteratorT1>::value && IsPointer<_UndirectionalIteratorT2>::value && IsSame<
			typename RemoveCV<typename IteratorValue<_UndirectionalIteratorT1>::Type>::Type,
			typename RemoveCV<typename IteratorValue<_UndirectionalIteratorT2>::Type>::Type
		>::value
#	endif
	>::_equal(__begin_1, __end_1, __begin_2);
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2>
inline ValidityType equal(
	_UndirectionalIteratorT1 const& __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 const& __begin_2,
	_UndirectionalIteratorT2 const& __end_2
) DD_NOEXCEPT_AS(
	_detail::_Equal<
		AndType<
			IsPod<IteratorValueType<_UndirectionalIteratorT1>> DD_COMMA
			IsPointer<_UndirectionalIteratorT1 DD_COMMA _UndirectionalIteratorT2> DD_COMMA
			IsSame<
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT1>> DD_COMMA
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT2>>
			>
		>::value
	>::_equal(__begin_1 DD_COMMA __end_1 DD_COMMA __begin_2 DD_COMMA __end_2)
) {
	return _detail::_Equal<
#	if __cplusplus >= 201103L
		AndType<
			IsPod<IteratorValueType<_UndirectionalIteratorT1>>,
			IsPointer<_UndirectionalIteratorT1, _UndirectionalIteratorT2>,
			IsSame<
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT1>>,
				RemoveCVType<IteratorValueType<_UndirectionalIteratorT2>>
			>
		>::value
#	else
		IsArithmetic<typename IteratorValue<_UndirectionalIteratorT1>::Type>::value && IsPointer<_UndirectionalIteratorT1>::value && IsPointer<_UndirectionalIteratorT2>::value && IsSame<
			typename RemoveCV<typename IteratorValue<_UndirectionalIteratorT1>::Type>::Type,
			typename RemoveCV<typename IteratorValue<_UndirectionalIteratorT2>::Type>::Type
		>::value
#	endif
	>::_equal(__begin_1, __end_1, __begin_2, __end_2);
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2, typename _BinaryPredicatorT>
inline ValidityType _equal(
	_UndirectionalIteratorT1 const& __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 const& __begin_2,
	_BinaryPredicatorT const& __equal
) DD_NOEXCEPT_AS(_detail::_Equal<false>::_equal(__begin_1 DD_COMMA __end_1 DD_COMMA __begin_2 DD_COMMA __equal)) {
	return _detail::_Equal<false>::_equal(__begin_1, __end_1, __begin_2, __equal);
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2, typename _BinaryPredicatorT>
inline ValidityType equal(
	_UndirectionalIteratorT1 const& __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 const& __begin_2,
	_UndirectionalIteratorT2 const& __end_2,
	_BinaryPredicatorT const& __equal
) DD_NOEXCEPT_AS(_detail::_Equal<false>::_equal(__begin_1 DD_COMMA __end_1 DD_COMMA __begin_2 DD_COMMA __end_2 DD_COMMA __equal)) {
	return _detail::_Equal<false>::_equal(__begin_1, __end_1, __begin_2, __end_2, __equal);
}



template <ValidityType _is_range_c>
struct _EqualDispatcher {
	template <typename _UndirectionalIteratorT1_, typename _UndirectionalIteratorT2_>
	static ValidityType _equal(
		_UndirectionalIteratorT1_ const& __begin_1_,
		_UndirectionalIteratorT1_ const& __end_1_,
		_UndirectionalIteratorT2_ const& __begin_2_
	) DD_NOEXCEPT_AS(::DD::_detail::_equal(__begin_1_ DD_COMMA __end_1_ DD_COMMA __begin_2_)) {
		return ::DD::_detail::_equal(__begin_1_, __end_1_, __begin_2_);
	}


};



template <>
struct _EqualDispatcher<true> {
	template <typename _UndirectionalRangeT1_, typename _UndirectionalRangeT2_, typename _BinaryPredicatorT_>
	static ValidityType _equal(
		_UndirectionalRangeT1_ const& __range_1_,
		_UndirectionalRangeT2_ const& __range_2_,
		_BinaryPredicatorT_ const& __equal_
	) DD_NOEXCEPT_AS(::DD::_detail::_equal(DD_SPLIT_RANGE(__range_1_) DD_COMMA DD_SPLIT_RANGE(__range_2_) DD_COMMA __equal_)) {
		return ::DD::_detail::_equal(DD_SPLIT_RANGE(__range_1_), DD_SPLIT_RANGE(__range_2_), __equal_);
	}


};



DD_DETAIL_END



DD_BEGIN
template <typename _ObjectT1, typename _ObjectT2, typename _ObjectT3>
inline ValidityType equal(
	_ObjectT1 const& __object_1,
	_ObjectT2 const& __object_2,
	_ObjectT3 const& __object_3
) DD_NOEXCEPT_AS(_detail::_EqualDispatcher<IsRange<_ObjectT1>::value>::_equal(__object_1 DD_COMMA __object_2 DD_COMMA __object_3)) {
	return _detail::_EqualDispatcher<IsRange<_ObjectT1>::value>::_equal(__object_1, __object_2, __object_3);
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2>
inline ValidityType equal(
	_UndirectionalIteratorT1 const& __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 const& __begin_2,
	_UndirectionalIteratorT2 const& __end_2
) DD_NOEXCEPT_AS(_detail::_equal(__begin_1 DD_COMMA __end_1 DD_COMMA __begin_2 DD_COMMA __end_2)) {
	return _detail::_equal(__begin_1, __end_1, __begin_2, __end_2);
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2, typename _BinaryPredicatorT>
inline ValidityType equal(
	_UndirectionalIteratorT1 const& __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 const& __begin_2,
	_UndirectionalIteratorT2 const& __end_2,
	_BinaryPredicatorT const& __equal
) DD_NOEXCEPT_AS(_detail::_equal(__begin_1 DD_COMMA __end_1 DD_COMMA __begin_2 DD_COMMA __end_2 DD_COMMA __equal)) {
	return _detail::_equal(__begin_1, __end_1, __begin_2, __end_2, __equal);
}

template <typename _UndirectionalRangeT1, typename _UndirectionalRangeT2>
inline ValidityType equal(
	_UndirectionalRangeT1 const& __range_1,
	_UndirectionalRangeT2 const& __range_2
) DD_NOEXCEPT_AS(_detail::_equal(DD_SPLIT_RANGE(__range_1) DD_COMMA DD_SPLIT_RANGE(__range_2))) {
	return _detail::_equal(DD_SPLIT_RANGE(__range_1), DD_SPLIT_RANGE(__range_2));
}



DD_END



#endif
