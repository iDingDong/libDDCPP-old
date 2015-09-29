//	DDCPP/standard/bits/DD_IsPod.hpp
#ifndef DD_IS_POD_HPP_INCLUDED_
#	define DD_IS_POD_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsPod'.



#	endif
#	include <type_traits>
#	include "DD_And.hpp"



DD_BEGIN_
template <typename... ObjectsT_>
using IsPod = AndType<StdBoolConstant<std::is_pod<ObjectsT_>>...>;



DD_END_



#endif
