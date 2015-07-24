//	standard/bits/DD_IsUnion.hpp
#ifndef _DD_IS_UNION_HPP_INCLUDED
#	define _DD_IS_UNION_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsUnion'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



DD_BEGIN
template <typename... _ObjectsT>
using IsUnion = AndType<StdIntegralConstant<std::is_union<_ObjectsT>>...>;



DD_END



#endif
