//	standard/bits/DD_RemoveVolatile.hpp
#ifndef _DD_REMOVE_VOLATILE_HPP_INCLUDED
#	define _DD_REMOVE_VOLATILE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>
#	endif

#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT>
struct RemoveVolatile {
#	if __cplusplus >= 201402L
	using Type = std::remove_volatile_t<_ObjectT>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_volatile<_ObjectT>::type;
#	else
	typedef _ObjectT Type;
#	endif
	
	
};



template <typename _ObjectT>
struct RemoveVolatile<_ObjectT volatile> {
	DD_ALIAS(Type, _ObjectT)
	
	
};



#	if __cplusplus >= 201103L
template <typename _ObjectT>
using RemoveVolatileType = typename RemoveVolatile<_ObjectT>::Type;



#	endif
DD_END



#endif
