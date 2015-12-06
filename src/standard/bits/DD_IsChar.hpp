//	DDCPP/standard/bits/DD_IsChar.hpp
#ifndef DD_IS_CHAR_HPP_INCLUDED_
#	define DD_IS_CHAR_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsChar_ : FalseType {
};



template <>
struct IsChar_<char> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsChar : AndType<IsChar<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsChar<ObjectT_> : IsChar_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsChar : IsChar_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsChar;



DD_END_



#endif
