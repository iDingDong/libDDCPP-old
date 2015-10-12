//	DDCPP/standard/bits/DD_AddPointer.hpp
#ifndef DD_ADD_POINTER_HPP_INCLUDED_
#	define DD_ADD_POINTER_HPP_INCLUDED_ 1



#	include "DD_RemoveReference.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct AddPointer {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(RemoveReference, ObjectT_)*);


};



DD_TRAIT_MODIFIER(AddPointer)



DD_DETAIL_END_



DD_BEGIN_
using detail_::AddPointer;
DD_TRAIT_MODIFIER(AddPointer)



DD_END_



#endif
