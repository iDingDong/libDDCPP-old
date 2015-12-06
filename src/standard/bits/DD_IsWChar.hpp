//	DDCPP/standard/bits/DD_IsWChar.hpp
#ifndef DD_IS_W_CHAR_HPP_INCLUDED_
#	define DD_IS_W_CHAR_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsWChar_ : FalseType {
};



template <>
struct IsWChar_<wchar_t> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsWChar : AndType<IsWChar<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsWChar<ObjectT_> : IsWChar_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsWChar : IsWChar_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsWChar;



DD_END_



#endif
