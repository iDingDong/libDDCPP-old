//	DDCPP/standard/bits/DD_AddLvalueReference.hpp
#ifndef DD_ADD_LVALUE_REFERENCE_HPP_INCLUDED_
#	define DD_ADD_LVALUE_REFERENCE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_IsReferable.hpp"
#	else
#		include "DD_global_definitions.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ObjectT_, ValidityType is_referable_c_>
struct AddLvalueReference_ {
	using Type = ObjectT_;


};



template <typename ObjectT_>
struct AddLvalueReference_<ObjectT_, true> {
	using Type = ObjectT_&;


};



template <typename ObjectT_>
struct AddLvalueReference : AddLvalueReference_<ObjectT_, IsReferable<ObjectT_>::value> {
};
#	else
template <typename ObjectT_>
struct AddLvalueReference {
	typedef ObjectT_& Type;


};



template <>
struct AddLvalueReference<void> {
	typedef void Type;


};
#	endif



DD_TRAIT_MODIFIER(AddLvalueReference)



DD_DETAIL_END_



DD_BEGIN_
using detail_::AddLvalueReference;
#	if __cplusplus >= 201103L
using detail_::AddLvalueReferenceType;
#	endif



DD_END_



#endif
