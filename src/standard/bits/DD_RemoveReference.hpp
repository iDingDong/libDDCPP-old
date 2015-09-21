//	DDCPP/standard/bits/DD_RemoveReference.hpp
#ifndef _DD_REMOVE_REFERENCE_HPP_INCLUDED
#	define _DD_REMOVE_REFERENCE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>
#	endif

#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ObjectT>
struct RemoveReference {
#	if __cplusplus >= 201402L
	using Type = std::remove_reference_t<_ObjectT>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_reference<_ObjectT>::type;
#	else
	typedef _ObjectT Type;
#	endif


};



template <typename _ValueT>
struct RemoveReference<_ValueT&> {
	DD_ALIAS(Type, _ValueT)


};



#	if __cplusplus >= 201103L
template <typename _ValueT>
struct RemoveReference<_ValueT&&> {
	using Type = _ValueT;


};



#	endif
DD_TRAIT_MODIFIER(RemoveReference)



_DD_END



#endif
