//	DDCPP/standard/bits/DD_IsUnsignedInt.hpp
#ifndef DD_IS_UNSIGNED_INT_HPP_INCLUDED_
#	define DD_IS_UNSIGNED_INT_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsUnsignedInt_ : FalseType {
};



template <>
struct IsUnsignedInt_<unsigned int> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsUnsignedInt : AndType<IsUnsignedInt<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsUnsignedInt<ObjectT_> : IsUnsignedInt_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsUnsignedInt : IsUnsignedInt_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsUnsignedInt;



DD_END_



#endif
