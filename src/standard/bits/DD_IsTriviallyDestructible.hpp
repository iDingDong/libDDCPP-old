//	DDCPP/standard/bits/DD_IsTriviallyDestructible
#ifndef DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED_
#	define DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#		include "DD_And.hpp"
#	if __cplusplus < 201103L
#		include "DD_IsArithmetic.hpp"
#		include "DD_IsPointer.hpp"
#	endif



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsTriviallyDestructible : AndType<IsTriviallyDestructible<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsTriviallyDestructible<ObjectT_> : StdBoolConstant<std::is_trivially_destructible<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsTriviallyDestructible : And<IsArithmetic<ObjectT_>, IsPointer<ObjectT_> >::Type {
};
#	endif



DD_END_



#endif
