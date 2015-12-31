//	DDCPP/standard/bits/DD_dereference.hpp
#ifndef DD_DEREFERENCE_HPP_INCLUDED_
#	define DD_DEREFERENCE_HPP_INCLUDED_ 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_IteratorReference.hpp"
#	if DDCPP_GUARD_DESTROY
#		include "DD_IteratorPointer.hpp"
#	endif
#	include "DD_get_pointer.hpp"



DD_DETAIL_BEGIN_
template <typename PointerT_>
#	if DDCPP_GUARD_DESTROY
inline DD_MODIFY_TRAIT(IteratorReference, PointerT_) dereference(
	PointerT_ const& pointer__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorReference, PointerT_)>(*pointer__)) {
	DD_ASSERT(
		::DD::get_pointer(pointer__) != reinterpret_cast<DD_MODIFY_TRAIT(IteratorPointer, PointerT_)>(get_invalid_address_()),
		"Dangling pointer dereferenced: 'DD::dereference'"
	);
	return *pointer__;
}
#	else
inline DD_MODIFY_TRAIT(IteratorReference, PointerT_) DD_CONSTEXPR dereference(
	PointerT_ const& pointer__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorReference, PointerT_)>(*pointer__)) {
	return *pointer__;
}
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::dereference;



DD_END_



#endif
