//	DDCPP/standard/bits/DD_swap.hpp
#ifndef _DD_SWAP_HPP_INCLUDED
#	define _DD_SWAP_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_MemberFunctionCheck.hpp"
#		include "DD_IsNoexceptMoveConstructible.hpp"
#		include "DD_IsNoexceptMoveAssignable.hpp"
#		include "DD_move.hpp"
#	else
#		include "DD_global_definitions.hpp"
#	endif



DD_DETAIL_BEGIN
DD_MEMBER_FUNCTION_CHECK(_HasSwap, swap, ProcessType, _MACRO_ObjectT_&)



template <ValidityType _has_swap_c>
struct _Swap {
	template <typename _ObjectT_>
	static ProcessType _swap(
		_ObjectT_& __object_1_,
		_ObjectT_& __object_2_
	) DD_NOEXCEPT_AS(__object_1_ = move(__object_2_) DD_COMMA _ObjectT_(move(__object_1_))) {
#	if __cplusplus >= 201103L
		auto __temp_(move(__object_1_));
		__object_1_ = move(__object_2_);
		__object_2_ = move(__temp_);
#	else
		_ObjectT __temp_(__object_1_);
		__object_1_ = __object_2_;
		__object_2_ = __temp_;
#	endif
	}
	
	
};



template <>
struct _Swap<true> {
	template <typename _ObjectT_>
	static ProcessType _swap(
		_ObjectT_& __object_1_,
		_ObjectT_& __object_2_
	) DD_NOEXCEPT_AS(__object_1_.swap(__object_2_)) {
		__object_1_.swap(__object_2_);
	}
	
	
};



DD_DETAIL_END



DD_BEGIN
template <typename _ObjectT>
inline ProcessType swap(
	_ObjectT& __object_1,
	_ObjectT& __object_2
) DD_NOEXCEPT_AS(_detail::_Swap<_detail::_HasSwap<_ObjectT>::value>::_swap(__object_1 DD_COMMA __object_2)) {
	_detail::_Swap<_detail::_HasSwap<_ObjectT>::value>::_swap(__object_1, __object_2);
}



template <typename _ObjectT, LengthType _length_c>
#	if __cplusplus >= 201103L
inline ProcessType swap(ArrayType<_ObjectT, _length_c>& _array_1, ArrayType<_ObjectT, _length_c>& _array_2) noexcept(
	noexcept(swap(*_array_1, *_array_2))
) {
#	else
inline ProcessType swap(_ObjectT (&_array_1)[_length_c], _ObjectT (&_array_2)[_length_c]) {
#	endif
	for (LengthType i = 0; i < _length_c; ++i) {
		swap(_array_1[i], _array_2[i]);
	}
}



DD_END



#endif
