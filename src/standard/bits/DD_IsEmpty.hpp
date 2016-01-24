//	DDCPP/standard/bits/DD_IsEmpty.hpp
#ifndef DD_IS_EMPTY_HPP_INCLUDED_
#	define DD_IS_EMPTY_HPP_INCLUDED_




#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsEmpty'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsEmpty : AndType<IsEmpty<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsEmpty<ObjectT_> : StdBoolConstant<std::is_empty<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsEmpty : StdBoolConstant<std::is_empty<ObjectT_> > {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsEmpty;



DD_END_



#endif
