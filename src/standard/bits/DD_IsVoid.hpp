//	DDCPP/standard/bits/DD_IsVoid.hpp
#ifndef DD_IS_VOID_HPP_INCLUDED_
#	define DD_IS_VOID_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN_
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsVoid_ : StdBoolConstant<std::is_void<ObjectT_>> {
#	else
struct IsVoid_ : FalseType {
#	endif
};



template <>
struct IsVoid_<void> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsVoid = AndType<detail_::IsVoid_<ObjectsT_>...>;
#	else
template <typename ObjectT_>
struct IsVoid : detail_::IsVoid_<ObjectT_> {
};
#	endif



DD_END_



#endif
