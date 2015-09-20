//	DDCPP/standard/bits/DD_AddPointer.hpp
#ifndef _DD_ADD_POINTER_HPP_INCLUDED
#	define _DD_ADD_POINTER_HPP_INCLUDED 1



#	include "DD_RemoveReference.hpp"



DD_BEGIN
template <typename _ObjectT>
struct AddPointer {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(RemoveReference, _ObjectT)*)


};



DD_TRAIT_MODIFIER(AddPointer)



DD_END



#endif
