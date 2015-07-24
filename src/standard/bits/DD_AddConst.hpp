//	standard/bits/DD_AddConst.hpp
#ifndef _DD_ADD_CONST_HPP_INCLUDED
#	define _DD_ADD_CONST_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT>
struct AddConst {
#	if __cplusplus >= 201402L
	using Type = std::add_const_t<_ObjectT>;
#	elif __cplusplus >= 201103L
	using Type = typename std::add_const<_ObjectT>::type;
#	else
	typedef _ObjectT Type;
#	endif
	
	
};



#	if __cplusplus >= 201103L
template <typename _ObjectT>
using AddConstType = typename AddConst<_ObjectT>::Type;



#	endif
DD_END



#endif
