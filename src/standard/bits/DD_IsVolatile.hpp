//	DDCPP/standard/bits/DD_IsVolatile.hpp
#ifndef DD_IS_Volatile_HPP_INCLUDED_
#	define DD_IS_Volatile_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN_
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsVolatile_ : StdBoolConstant<std::is_volatile<ObjectT_>> {
#	else
struct IsVolatile_ : FalseType {
#	endif
};



template <typename ObjectT_>
struct IsVolatile_<ObjectT_ volatile> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsVolatile = AndType<detail_::IsVolatile_<ObjectsT_>...>;
#	else
template <typename ObjectT_>
struct IsVolatile : detail_::IsVolatile_<ObjectT_> {
};
#	endif



DD_END_



#endif
