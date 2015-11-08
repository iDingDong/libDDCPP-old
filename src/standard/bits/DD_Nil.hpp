//	DDCPP/standard/bits/DD_Nil.hpp
#ifndef DD_NIL_HPP_INCLUDED_
#	define DD_NIL_HPP_INCLUDED_ 1



#	include "DD_relationship_operators.hpp"



DD_DETAIL_BEGIN_
struct NilType {
};



struct NilPointerType {
#	if __cplusplus >= 201103L
	constexpr NilPointerType() noexcept(true) = default;

	constexpr NilPointerType(NilPointerType const& origin_) = default;

	constexpr NilPointerType(NilPointerType&& origin_) = default;


#	endif
	template <typename ValueT_>
	DD_CONSTEXPR operator ValueT_*() const DD_NOEXCEPT {
#	if __cplusplus >= 201103L
		return PointerType<ValueT_>();
#	else
		typedef ValueT_* PointerType;
		return PointerType();
#	endif
	}


};



inline ValidityType DD_CONSTEXPR operator ==(NilPointerType nil_pointer_1_, NilPointerType nil_pointer_2_) DD_NOEXCEPT {
	return true;
}



inline ValidityType DD_CONSTEXPR operator <(NilPointerType nil_pointer_1_, NilPointerType nil_pointer_2_) DD_NOEXCEPT {
	return false;
}



NilType DD_CONSTANT nil;

NilPointerType DD_CONSTANT nil_pointer;



DD_DETAIL_END_



DD_BEGIN_
using detail_::NilType;
using detail_::NilPointerType;
using detail_::nil;
using detail_::nil_pointer;



DD_END_



#endif
