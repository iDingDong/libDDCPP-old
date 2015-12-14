//	DDCPP/standard/bits/DD_IsIntegral.hpp
#ifndef DD_IS_INTEGRAL_HPP_INCLUDED_
#	define DD_IS_INTEGRAL_HPP_INCLUDED_ 1



#	if __cplusplus > 201103L
#		include <type_traits>

#	endif
#	include "DD_IsBool.hpp"

#	include "DD_IsCharactor.hpp"

#	include "DD_IsUnsignedShort.hpp"
#	include "DD_IsSignedShort.hpp"
#	include "DD_IsUnsignedInt.hpp"
#	include "DD_IsSignedInt.hpp"
#	include "DD_IsUnsignedLong.hpp"
#	include "DD_IsSignedLong.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsUnsignedLongLong.hpp"
#		include "DD_IsSignedLongLong.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsIntegral : AndType<IsIntegral<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsIntegral<ObjectT_> : OrType<
	IsBool<ObjectT_>,
	IsCharactor<ObjectT_>,
	IsUnsignedShort<ObjectT_>,
	IsSignedShort<ObjectT_>,
	IsUnsignedInt<ObjectT_>,
	IsSignedInt<ObjectT_>,
	IsUnsignedLong<ObjectT_>,
	IsSignedLong<ObjectT_>,
	IsUnsignedLongLong<ObjectT_>,
	IsSignedLongLong<ObjectT_>,
	StdBoolConstant<std::is_integral<ObjectT_>>
> {
};
#	else
template <typename ObjectT_>
struct IsIntegral : BoolConstant<
	IsBool<ObjectT_>::value ||
	IsCharactor<ObjectT_>::value ||
	IsUnsignedShort<ObjectT_>::value ||
	IsSignedShort<ObjectT_>::value ||
	IsUnsignedInt<ObjectT_>::value ||
	IsSignedInt<ObjectT_>::value ||
	IsUnsignedLong<ObjectT_>::value ||
	IsSignedLong<ObjectT_>::value
> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsIntegral;



DD_END_



#endif
