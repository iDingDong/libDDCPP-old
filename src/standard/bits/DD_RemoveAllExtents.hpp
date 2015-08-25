//	DDCPP/standard/bits/DD_RemoveAllExtents.hpp
#ifndef _DD_REMOVE_ALL_EXTENTS_HPP_INCLUDED
#	define _DD_REMOVE_ALL_EXTENTS_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT>
struct RemoveAllExtents {
#	if __cplusplus >= 201402L
	using Type = std::remove_all_extents_t<_ObjectT>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_all_extents<_ObjectT>::type;
#	else
	typedef _ObjectT Type;
#	endif
	
	
};



template <typename _ValueT, LengthType _length_c>
struct RemoveAllExtents<_ValueT[_length_c]> {
	DD_ALIAS(Type, typename RemoveAllExtents<_ValueT>::Type)
	
	
};



template <typename _ValueT>
struct RemoveAllExtents<_ValueT[]> {
	DD_ALIAS(Type, typename RemoveAllExtents<_ValueT>::Type)
	
	
};



DD_TRAIT_MODIFIER(RemoveAllExtents)



DD_END



#endif
