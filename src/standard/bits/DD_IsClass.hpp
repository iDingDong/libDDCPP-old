//	DDCPP/standard/bits/DD_IsClass.hpp
#ifndef DD_IS_CLASS_HPP_INCLUDED_
#	define DD_IS_CLASS_HPP_INCLUDED_ 1


#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsClass'.



#	endif
#	include "DD_Nil.hpp"
#	include "DD_IsUnion.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsClass_ {
	template <typename ObjectT__>
	static ValidityType constexpr match_(int ObjectT__::*) noexcept {
		return true;
	}

	template <typename ObjectT__>
	static ValidityType constexpr match_(...) noexcept {
		return false;
	}


	static ValidityType constexpr value = (IsClass_<ObjectT_>::match_<ObjectT_>(nil_pointer) && !IsUnion<ObjectT_>::value ) || std::is_class<ObjectT_>::value;


};



DD_DETAIL_END_



DD_BEGIN_
template <typename... ObjectsT_>
using IsClass = AndType<BoolConstant<detail_::IsClass_<ObjectsT_>::value>...>;



DD_END_



#endif
