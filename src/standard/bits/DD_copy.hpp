//	DDCPP/standard/bits/DD_copy.hpp
#ifndef _DD_COPY_HPP_INCLUDED
#	define _DD_COPY_HPP_INCLUDED 1



#	include <cstring>

#	include "DD_global_definitions.hpp"
#	include "DD_size_distance.hpp"



_DD_DETAIL_BEGIN
template <ValidityType _is_memmoveable_c>
struct _Copy {
	template <typename _UndirectionalIteratorT1_, typename _UndirectionalIteratorT2_>
	static _UndirectionalIteratorT2_ _copy(
		_UndirectionalIteratorT1_ __begin_,
		_UndirectionalIteratorT1_ const& __end_,
		_UndirectionalIteratorT2_ __result_begin_
	) DD_NOEXCEPT_IF(noexcept(++__begin_) && noexcept(++__result_begin_) && noexcept(*__result_begin_ = *__begin_)) {
		for (; __begin_ != __end_; ++__begin_, ++__result_begin_) {
			*__result_begin_ = *__begin_;
		}
		return __result_begin_;
	}


};



template <>
struct _Copy<true> {
	template <typename _PointerT1_, typename _PointerT2_>
	static _PointerT2_ DD_CONSTEXPR _copy(
		_PointerT1_ const& __begin_,
		_PointerT1_ const& __end_,
		_PointerT2_ const& __result_begin_
	) DD_NOEXCEPT_AS(std::memmove(__result_begin_, __begin_, size_distance(__begin_, __end_))) {
		return std::memmove(__result_begin_, __begin_, size_distance(__begin_, __end_)), __result_begin_ + (__end_ - __begin_);
	}


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2>
_UndirectionalIteratorT2 DD_CONSTEXPR copy(
	_UndirectionalIteratorT1 const& __begin,
	_UndirectionalIteratorT1 const& __end,
	_UndirectionalIteratorT2 const& __result_end
) {
	return _detail::_Copy<false>::_copy(__begin, __end, __result_end);// Imperfect realization
}



_DD_END



#endif
