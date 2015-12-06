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
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsVolatile : AndType<IsVolatile<ObjectsT_>...> {
};



#	endif
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsVolatile<ObjectT_> : StdBoolConstant<std::is_volatile<ObjectT_>> {
#	else
struct IsVolatile : FalseType {
#	endif
};



template <typename ObjectT_>
struct IsVolatile<ObjectT_ volatile> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsVolatile;



DD_END_



#endif
