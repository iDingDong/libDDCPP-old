//	DDCPP/standard/bits/DD_IsTriviallyDestructible
#ifndef _DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED
#	define _DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsTriviallyDistructible'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



_DD_BEGIN
template <typename... _ObjectsT>
using IsTriviallyDestructible = AndType<StdBoolConstant<std::is_trivially_destructible<_ObjectsT>>...>;



_DD_END



#endif
