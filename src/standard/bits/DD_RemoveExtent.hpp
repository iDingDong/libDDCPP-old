//	standard/bits/DD_RemoveExtent.hpp
#ifndef _DD_REMOVE_EXTENT_HPP_INCLUDED
#	define _DD_REMOVE_EXTENT_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT>
struct RemoveExtent {
#	if __cplusplus >= 201402L
	using Type = std::remove_extent_t<_ObjectT>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_extent<_ObjectT>::type;
#	else
	typedef _ObjectT Type;
#	endif
	
	
};



template <typename _ValueT, LengthType _length_c>
struct RemoveExtent<_ValueT[_length_c]> {
	DD_ALIAS(Type, _ValueT)
	
	
};



template <typename _ValueT>
struct RemoveExtent<_ValueT[]> {
	DD_ALIAS(Type, _ValueT)
	
	
};



#	if __cplusplus >= 201103L
template <typename _ObjectT>
using RemoveExtentType = typename RemoveExtent<_ObjectT>::Type;



#	endif
DD_END



#endif
