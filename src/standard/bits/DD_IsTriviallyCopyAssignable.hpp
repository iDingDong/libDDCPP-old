//	DDCPP/standard/bits/DD_IsTriviallyCopyAssignable.hpp
#ifndef DD_IS_TRIVIALLY_COPY_ASSIGNABLE_HPP_INCLUDED_
#	define DD_IS_TRIVIALLY_COPY_ASSIGNABLE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IsArithmetic.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsTriviallyCopyAssignable : AndType<IsTriviallyCopyAssignable<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsTriviallyCopyAssignable<ObjectT_> : StdBoolConstant<std::is_trivially_copy_assignable<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsTriviallyCopyAssignable : IsArithmetic<ObjectT_> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyCopyAssignable;



DD_END_



#endif
