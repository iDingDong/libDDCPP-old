//	standard/bits/DD_RemovePointer.hpp
#ifndef _DD_REMOVE_POINTER_HPP_INCLUDED
#	define _DD_REMOVE_POINTER_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>
#	endif

#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT>
struct RemovePointer {
#	if __cplusplus >= 201402L
	using Type = std::remove_pointer_t<_ObjectT>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_pointer<_ObjectT>::type;
#	else
	typedef _ObjectT Type;
#	endif
	
	
};



template <typename _ValueT>
struct RemovePointer<_ValueT*> {
	DD_ALIAS(Type, _ValueT)
	
	
};



template <typename _ValueT>
struct RemovePointer<_ValueT* const> {
	DD_ALIAS(Type, _ValueT)
	
	
};



template <typename _ValueT>
struct RemovePointer<_ValueT* volatile> {
	DD_ALIAS(Type, _ValueT)
	
	
};



template <typename _ValueT>
struct RemovePointer<_ValueT* const volatile> {
	DD_ALIAS(Type, _ValueT)
	
	
};



#	if __cplusplus >= 201103L
template <typename _ValueT>
using RemovePointerType = typename RemovePointer<_ValueT>::Type;



#	endif
DD_END



#endif
