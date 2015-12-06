//	DDCPP/standard/bits/ DD_IsSame.hpp
#ifndef DD_IS_SAME_HPP_INCLUDED_
#	define DD_IS_SAME_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsSame : TrueType {
};



template <typename ObjectT1_, typename ObjectT2_, typename... ObjectsT_>
struct IsSame<ObjectT1_, ObjectT2_, ObjectsT_...> : AndType<IsSame<ObjectT1_, ObjectT2_>, IsSame<ObjectT2_, ObjectsT_...>> {
};



template <typename ObjectT1_, typename ObjectT2_>
struct IsSame<ObjectT1_, ObjectT2_> : StdBoolConstant<std::is_same<ObjectT1_, ObjectT2_>> {
};
#	else
template <typename ObjectT1_, typename ObjectT2_>
struct IsSame : FalseType {
};
#	endif



template <typename ObjectT_>
struct IsSame<ObjectT_, ObjectT_> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsSame;



DD_END_



#endif
