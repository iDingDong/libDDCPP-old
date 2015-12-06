//	DDCPP/standard/bits/DD_IsChar32.hpp
#ifndef DD_IS_CHAR_32_HPP_INCLUDED_
#	define DD_IS_CHAR_32_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsChar32'.
#	endif



#	include "DD_And.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsChar32_ : FalseType {
};



template <>
struct IsChar32_<char32_t> : TrueType {
};



template <typename... ObjectsT_>
struct IsChar32 : AndType<IsChar32<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsChar32<ObjectT_> : IsChar32_<RemoveCVType<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsChar32;



DD_END_



#endif
