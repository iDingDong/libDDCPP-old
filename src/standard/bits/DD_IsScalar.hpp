//	DDCPP/standard/bits/DD_IsScalar.hpp
#ifndef _DD_IS_SCALAR_HPP_INCLUDED
#	define _DD_IS_SCALAR_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsEnum'.



#	endif
#	include "DD_IsArithmetic.hpp"
#	include "DD_IsPointer.hpp"
#	include "DD_IsEnum.hpp"



DD_BEGIN
template <typename... _ObjectsT>
using IsScalar = AndType<OrType<IsArithmetic<_ObjectsT>, IsPointer<_ObjectsT>, IsEnum<_ObjectsT>>...>;



DD_END



#endif
