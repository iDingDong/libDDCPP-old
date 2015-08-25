//	DDCPP/standard/bits/DD_IsFloatingPoint.hpp
#ifndef _DD_IS_FLOATING_POINT_HPP_INCLUDED
#	define _DD_IS_FLOATING_POINT_HPP_INCLUDED 1


#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_Or.hpp"
#	endif
#	include "DD_IsFloat.hpp"
#	include "DD_IsDouble.hpp"
#	include "DD_IsLongDouble.hpp"



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <typename _ObjectT>
using _IsFloatingPoint = OrType<IsFloat<_ObjectT>, IsDouble<_ObjectT>, IsLongDouble<_ObjectT>, StdBoolConstant<std::is_floating_point<_ObjectT>>>;



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsFloatingPoint = AndType<_detail::_IsFloatingPoint<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsFloatingPoint : BoolConstant<IsFloat<_ObjectT>::value || IsDouble<_ObjectT>::value || IsLongDouble<_ObjectT>::value> {
}; 
#	endif



DD_END



#endif
