//	DDCPP/standard/bits/DD_IsBool.hpp
#ifndef DD_IS_BOOL_HPP_INCLUDED_
#	define DD_IS_BOOL_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsBool_ : FalseType {
};



template <>
struct IsBool_<bool> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsBool : AndType<IsBool<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsBool<ObjectT_> : IsBool_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsBool : IsBool_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsBool;



DD_END_



#endif
