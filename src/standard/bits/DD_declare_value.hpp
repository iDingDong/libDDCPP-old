//	DDCPP/standard/bits/DD_declare_value.hpp
#ifndef DD_DECLARE_VALUE_HPP_INCLUDED_
#	define DD_DECLARE_VALUE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::declare_value'.



#	endif
#	include "DD_AddRvalueReference.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct declare_value_protector_ {
	static constexpr ValidityType value = false;
	static AddRvalueReferenceType<ObjectT_> declare_value_() noexcept;


};



DD_DETAIL_END_



DD_BEGIN_
template <typename ObjectT_>
AddRvalueReferenceType<ObjectT_> declare_value() noexcept {
	static_assert(detail_::declare_value_protector_<ObjectT_>::value, "DD::declare_value is forbidden to be evaluated.");
	return detail_::declare_value_protector_<ObjectT_>::declare_value_();
}



DD_END_



#endif
