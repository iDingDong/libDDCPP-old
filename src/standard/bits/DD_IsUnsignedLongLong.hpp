//	DDCPP/standard/bits/DD_IsUnsignedLongLong.hpp
#ifndef DD_IS_UNSIGNED_LONG_LONG_HPP_INCLUDED_
#	define DD_IS_UNSIGNED_LONG_LONG_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsUnsignedLongLong'.
#	endif



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsUnsignedLongLong_ : FalseType {
};



template <>
struct IsUnsignedLongLong_<unsigned long long> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
template <typename... ObjectsT_>
using IsUnsignedLongLong = AndType<detail_::IsUnsignedLongLong_<RemoveCVType<ObjectsT_>>...>;



DD_END_



#endif
