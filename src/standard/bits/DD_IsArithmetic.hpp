//	DDCPP/standard/bits/DD_IsArithmetic.hpp
#ifndef DD_IS_ARITHMETIC_HPP_INCLUDED_
#	define DD_IS_ARITHMETIC_HPP_INCLUDED_ 1



#	include "DD_IsIntegral.hpp"
#	include "DD_IsFloatingPoint.hpp"



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsArithmetic = AndType<OrType<IsIntegral<ObjectsT_>, IsFloatingPoint<ObjectsT_>, StdIntegralConstant<std::is_arithmetic<ObjectsT_>>>...>;
#	else
template <typename ObjectT_>
struct IsArithmetic : BoolConstant<IsIntegral<ObjectT_>::value || IsFloatingPoint<ObjectT_>::value> {
};
#	endif



DD_END_



#endif
