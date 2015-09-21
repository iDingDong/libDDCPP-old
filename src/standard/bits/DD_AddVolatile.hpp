//	DDCPP/standard/bits/DD_AddVolatile.hpp
#ifndef _DD_ADD_VOLATILE_HPP_INCLUDED
#	define _DD_ADD_VOLATILE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ObjectT>
struct AddVolatile {
#	if __cplusplus >= 201402L
	using Type = std::add_volatile_t<_ObjectT>;
#	elif __cplusplus >= 201103L
	using Type = typename std::add_volatile<_ObjectT>::type;
#	else
	typedef _ObjectT Type;
#	endif


};



#	if __cplusplus >= 201103L
template <typename _ObjectT>
using AddVolatileType = typename AddVolatile<_ObjectT>::Type;



#	endif
_DD_END



#endif
