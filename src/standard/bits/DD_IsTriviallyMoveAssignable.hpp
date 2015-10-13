//	DDCPP/standard/bits/DD_IsTriviallyMoveAssignable.hpp
#ifndef DD_IS_TRIVIALLY_MOVE_ASSIGNABLE_HPP_INCLUDED_
#	define DD_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsTriviallyMoveAssignable'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct IsTriviallyMoveAssignable : AndType<IsTriviallyMoveAssignable<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsTriviallyMoveAssignable<ObjectT_> : StdBoolConstant<std::is_trivially_move_assignable<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyMoveAssignable;



DD_END_



#endif
