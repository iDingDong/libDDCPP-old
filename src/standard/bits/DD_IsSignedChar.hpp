//	DDCPP/standard/bits/DD_IsSignedChar.hpp
#ifndef DD_IS_SIGNED_CHAR_HPP_INCLUDED_
#	define DD_IS_SIGNED_CHAR_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsSignedChar_ : FalseType {
};



template <>
struct IsSignedChar_<signed char> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsSignedChar = AndType<detail_::IsSignedChar_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsSignedChar : detail_::IsSignedChar_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
