//	DDCPP/standard/bits/DD_AddRvalueReference.hpp
#ifndef _DD_ADD_RVALUE_REFERENCE_HPP_INCLUDED
#	define _DD_ADD_RVALUE_REFERENCE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::AddRvalueReference'.



#	endif
#	include <type_traits>
#	include "DD_IsReferable.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT, ValidityType _is_referenceable_c>
struct _AddRvalueReference {
	DD_ALIAS(Type, _ObjectT)


};



template <typename _ObjectT>
struct _AddRvalueReference<_ObjectT, true> {
	DD_ALIAS(Type, _ObjectT&&)


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _ObjectT>
struct AddRvalueReference {
	DD_ALIAS(Type, typename _detail::_AddRvalueReference<_ObjectT DD_COMMA IsReferable<_ObjectT>::value>::Type)


};



DD_TRAIT_MODIFIER(AddRvalueReference)



_DD_END



#endif
