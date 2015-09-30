//	DDCPP/standard/bits/DD_IsTriviallyDestructible
#ifndef DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED_
#	define DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_IntegralConstant.hpp"
#	else
#		include "DD_IsScalar.hpp"
#	endif



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsTriviallyDestructible = AndType<StdBoolConstant<std::is_trivially_destructible<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsTriviallyDestructible : IsScalar<ObjectT_> {
};
#	endif



DD_END_



#endif
