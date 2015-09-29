//	DDCPP/standard/bits/DD_IsUnsignedChar.hpp
#ifndef DD_IS_UNSIGNED_CHAR_HPP_INCLUDED_
#	define DD_IS_UNSIGNED_CHAR_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsUnsignedChar_ : FalseType {
};



template <>
struct IsUnsignedChar_<unsigned char> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsUnsignedChar = AndType<detail_::IsUnsignedChar_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsUnsignedChar : detail_::IsUnsignedChar_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
