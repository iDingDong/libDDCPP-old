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



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ObjectT_>
using IsFloatingPoint_ = OrType<IsFloat<ObjectT_>, IsDouble<ObjectT_>, IsLongDouble<ObjectT_>, StdBoolConstant<std::is_floating_point<ObjectT_>>>;



template <typename... ObjectsT_>
struct IsFloatingPoint : AndType<IsFloatingPoint_<ObjectsT_>...> {
};
#	else
template <typename ObjectT_>
struct IsFloatingPoint : BoolConstant<IsFloat<ObjectT_>::value || IsDouble<ObjectT_>::value || IsLongDouble<ObjectT_>::value> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsFloatingPoint;



DD_END_



#endif
