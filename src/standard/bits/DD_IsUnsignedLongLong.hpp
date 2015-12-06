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



template <typename... ObjectsT_>
struct IsUnsignedLongLong : AndType<IsUnsignedLongLong<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsUnsignedLongLong<ObjectT_> : IsUnsignedLongLong_<RemoveCVType<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsUnsignedLongLong;



DD_END_



#endif
