//	DDCPP/standard/bits/DD_IsConst.hpp
#ifndef DD_IS_CONST_HPP_INCLUDED_
#	define DD_IS_CONST_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsConst : AndType<IsConst<ObjectsT_>...> {
};



#	endif
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsConst<ObjectT_> : StdBoolConstant<std::is_const<ObjectT_>> {
#	else
struct IsConst : FalseType {
#	endif
};



template <typename ObjectT_>
struct IsConst<ObjectT_ const> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsConst;



DD_END_



#endif
