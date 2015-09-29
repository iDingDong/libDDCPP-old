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



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN_
template <typename ObjectT_>
using IsIntegral_ = OrType<
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
>;



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsIntegral = AndType<detail_::IsIntegral_<ObjectsT_>...>;
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



DD_END_



#endif
