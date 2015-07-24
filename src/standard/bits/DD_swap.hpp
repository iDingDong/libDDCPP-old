//	standard/bits/DD_swap.hpp
#ifndef _DD_SWAP_HPP_INCLUDED
#	define _DD_SWAP_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_IsNoexceptMoveConstructible.hpp"
#		include "DD_IsNoexceptMoveAssignable.hpp"
#		include "DD_move.hpp"
#	else
#		include "DD_global_definitions.hpp"
#	endif



DD_BEGIN
template <typename _ObjectT>
inline ProcessType swap(_ObjectT& __object_1, _ObjectT& __object_2) DD_NOEXCEPT_IF(
	noexcept(_ObjectT(move(__object_1))) && noexcept(__object_1 = move(__object_2))
) {
#	if __cplusplus >= 201103L
	auto __temp(move(__object_1));
	__object_1 = move(__object_2);
	__object_2 = move(__temp);
#	else
	_ObjectT __temp(__object_1);
	__object_1 = __object_2;
	__object_2 = __temp;
#	endif
}



template <typename _ObjectT, LengthType _length_c>
#	if __cplusplus >= 201103L
inline ProcessType swap(ArrayType<_ObjectT, _length_c>& __array_1, ArrayType<_ObjectT, _length_c>& __array_2) noexcept(
	noexcept(swap(*__array_1, *__array_2))
) {
	for (auto i = 0_DD_Counter; i < _length_c; ++i) {
#	else
inline ProcessType swap(_ObjectT(&__array_1)[_length_c], _ObjectT(&__array_2)[_length_c]) {
	for (CounterType i = 0; i < _length_c; ++i) {
#	endif
		swap(__array_1[i], __array_2[i]);
	}
}



DD_END



#endif
