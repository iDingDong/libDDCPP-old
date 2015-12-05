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
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsConst_ : StdBoolConstant<std::is_const<ObjectT_>> {
#	else
struct IsConst_ : FalseType {
#	endif
};



template <typename ObjectT_>
struct IsConst_<ObjectT_ const> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsConst : AndType<IsConst_<ObjectsT_>...> {
};
#	else
template <typename ObjectT_>
struct IsConst : IsConst_<ObjectT_> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsConst;



DD_END_



#endif
