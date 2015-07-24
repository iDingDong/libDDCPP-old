//	standard/bits/DD_IsArithmetic.hpp
#ifndef _DD_IS_ARITHMETIC_HPP_INCLUDED
#	define _DD_IS_ARITHMETIC_HPP_INCLUDED 1



#	include "DD_IsIntegral.hpp"
#	include "DD_IsFloatingPoint.hpp"



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsArithmetic = AndType<OrType<IsIntegral<_ObjectsT>, IsFloatingPoint<_ObjectsT>, StdIntegralConstant<std::is_arithmetic<_ObjectsT>>>...>;
#	else
template <typename _ObjectT>
struct IsArithmetic : BoolConstant<IsIntegral<_ObjectT>::value || IsFloatingPoint<_ObjectT>::value> {
};
#	endif



DD_END



#endif
