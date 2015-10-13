//	DDCPP/standard/bits/DD_IsTriviallyMoveable.hpp
#ifndef DD_IS_TRIVIALLY_MOVEABLE_HPP_INCLUDED_
#	define DD_IS_TRIVIALLY_MOVEABLE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsTriviallyMoveable'.



#	endif
#	include "DD_IsTriviallyMoveConstructible.hpp"
#	include "DD_IsTriviallyMoveAssignable.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct IsTriviallyMoveable : AndType<IsTriviallyMoveConstructible<ObjectsT_...>, IsTriviallyMoveAssignable<ObjectsT_...>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyMoveable;



DD_END_



#endif
