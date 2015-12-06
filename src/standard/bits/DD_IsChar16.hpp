//	DDCPP/standard/bits/DD_IsChar16.hpp
#ifndef DD_IS_CHAR_16_HPP_INCLUDED_
#	define DD_IS_CHAR_16_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsChar16'.



#	endif
#	include "DD_And.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsChar16_ : FalseType {
};



template <>
struct IsChar16_<char16_t> : TrueType {
};



template <typename... ObjectsT_>
struct IsChar16 : AndType<IsChar16<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsChar16<ObjectT_> : IsChar16_<RemoveCVType<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsChar16;



DD_END_



#endif
