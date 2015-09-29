//	DDCPP/standard/bits/DD_IsUnion.hpp
#ifndef DD_IS_UNION_HPP_INCLUDED_
#	define DD_IS_UNION_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsUnion'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



DD_BEGIN_
template <typename... ObjectsT_>
using IsUnion = AndType<StdIntegralConstant<std::is_union<ObjectsT_>>...>;



DD_END_



#endif
