//	DDCPP/standard/bits/DD_IsTriviallyCopyConstructible.hpp
#ifndef _DD_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_HPP_INCLUDED
#	define _DD_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_HPP_INCLUDED 1



#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
using IsTriviallyMoveConstructible = AndType<StdBoolConstant<std::is_trivially_move_constructible<ObjectsT_>>...>;



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyMoveConstructible;



DD_END_



#endif

