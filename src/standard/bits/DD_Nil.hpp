//	DDCPP/standard/bits/DD_Nil.hpp
#ifndef _DD_NIL_HPP_INCLUDED
#	define _DD_NIL_HPP_INCLUDED 1



#	include "DD_relationship_operators.hpp"



_DD_BEGIN
struct NilType {
};



struct NilPointerType {
#	if __cplusplus >= 201103L
	constexpr NilPointerType() noexcept(true) = default;

	constexpr NilPointerType(NilPointerType const& _origin) = default;

	constexpr NilPointerType(NilPointerType&& _origin) = default;


#	endif
	template <typename _ValueT>
	DD_CONSTEXPR operator _ValueT*() const DD_NOEXCEPT {
#	if __cplusplus >= 201103L
		return PointerType<_ValueT>();
#	else
		typedef _ValueT* PointerType;
		return PointerType();
#	endif
	}


};



inline ValidityType DD_CONSTEXPR operator ==(NilPointerType _nil_pointer_1, NilPointerType _nil_pointer_2) DD_NOEXCEPT {
	return true;
}



inline ValidityType DD_CONSTEXPR operator <(NilPointerType _nil_pointer_1, NilPointerType _nil_pointer_2) DD_NOEXCEPT {
	return false;
}



NilType DD_CONSTANT nil;

NilPointerType DD_CONSTANT nil_pointer;



_DD_END



#endif
