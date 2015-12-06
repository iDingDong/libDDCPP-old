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



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsUnsignedChar : AndType<IsUnsignedChar<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsUnsignedChar<ObjectT_> : IsUnsignedChar_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsUnsignedChar : IsUnsignedChar_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsUnsignedChar;



DD_END_



#endif
