//	DDCPP/standard/bits/DD_IsTriviallyCopyable.hpp
#ifndef DD_IS_TRIVIALLY_COPYABLE_HPP_INCLUDED_
#	define DD_IS_TRIVIALLY_COPYABLE_HPP_INCLUDED_ 1



#	include "DD_IsTriviallyCopyConstructible.hpp"
#	include "DD_IsTriviallyCopyAssignable.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyMoveable.hpp"
#	else
#		include "DD_And.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsTriviallyCopyable : AndType<IsTriviallyCopyConstructible<ObjectsT_...>, IsTriviallyCopyAssignable<ObjectsT_...>, IsTriviallyMoveable<ObjectsT_...>> {
};
#	else
template <typename ObjectT_>
struct IsTriviallyCopyable : typename And<IsTriviallyCopyConstructible<ObjectT_>, IsTriviallyCopyAssignable<ObjectT_> >::Type {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyCopyable;



DD_END_



#endif
