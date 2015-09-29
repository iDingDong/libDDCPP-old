//	DDCPP/standard/bits/DD_IsSignedLongLong.hpp
#ifndef DD_IS_SIGNED_LONG_LONG_HPP_INCLUDED_
#	define DD_IS_SIGNED_LONG_LONG_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsLongLong'.
#	endif



#	include "DD_And.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsSignedLongLong_ : FalseType {
};



template <>
struct IsSignedLongLong_<signed long long> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
template <typename... ObjectsT_>
using IsSignedLongLong = AndType<detail_::IsSignedLongLong_<RemoveCVType<ObjectsT_>>...>;



DD_END_



#endif
