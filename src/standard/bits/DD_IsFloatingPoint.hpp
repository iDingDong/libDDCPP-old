//	DDCPP/standard/bits/DD_IsFloatingPoint.hpp
#ifndef DD_IS_FLOATING_POINT_HPP_INCLUDED_
#	define DD_IS_FLOATING_POINT_HPP_INCLUDED_ 1


#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_Or.hpp"
#	endif
#	include "DD_IsFloat.hpp"
#	include "DD_IsDouble.hpp"
#	include "DD_IsLongDouble.hpp"



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN_
template <typename ObjectT_>
using IsFloatingPoint_ = OrType<IsFloat<ObjectT_>, IsDouble<ObjectT_>, IsLongDouble<ObjectT_>, StdBoolConstant<std::is_floating_point<ObjectT_>>>;



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsFloatingPoint = AndType<detail_::IsFloatingPoint_<ObjectsT_>...>;
#	else
template <typename ObjectT_>
struct IsFloatingPoint : BoolConstant<IsFloat<ObjectT_>::value || IsDouble<ObjectT_>::value || IsLongDouble<ObjectT_>::value> {
};
#	endif



DD_END_



#endif
