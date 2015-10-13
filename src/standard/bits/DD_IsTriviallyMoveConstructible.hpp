//	DDCPP/standard/bits/DD_IsTriviallyCopyConstructible.hpp
#ifndef _DD_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_HPP_INCLUDED
#	define _DD_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsTriviallyMoveConstructible'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct IsTriviallyMoveConstructible : AndType<IsTriviallyMoveConstructible<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsTriviallyMoveConstructible<ObjectT_> : StdBoolConstant<std::is_trivially_move_constructible<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyMoveConstructible;



DD_END_



#endif

