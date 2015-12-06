//	DDCPP/standard/bits/DD_IsScalar.hpp
#ifndef DD_IS_SCALAR_HPP_INCLUDED_
#	define DD_IS_SCALAR_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsScalar'.



#	endif
#	include "DD_IsArithmetic.hpp"
#	include "DD_IsPointer.hpp"
#	include "DD_IsEnum.hpp"



DD_BEGIN_
template <typename... ObjectsT_>
struct IsScalar : AndType<IsScalar<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsScalar<ObjectT_> : OrType<IsArithmetic<ObjectT_>, IsPointer<ObjectT_>, IsEnum<ObjectT_>> {
};



DD_END_



#endif
