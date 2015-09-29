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



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsWChar = AndType<detail_::IsWChar_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsWChar : detail_::IsWChar_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
