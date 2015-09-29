//	DDCPP/standard/bits/DD_IsTriviallyDestructible
#ifndef DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED_
#	define DD_IS_TRIVIALLY_DESTRUCTIBLE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsTriviallyDistructible'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



DD_BEGIN_
template <typename... ObjectsT_>
using IsTriviallyDestructible = AndType<StdBoolConstant<std::is_trivially_destructible<ObjectsT_>>...>;



DD_END_



#endif
