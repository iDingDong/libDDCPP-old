//	DDCPP/standard/bits/DD_IsTriviallyCopyConstructible.hpp
#ifndef _DD_IS_TRIVIALLY_COPY_CONSTRUCTIBLE_HPP_INCLUDED
#	define _DD_IS_TRIVIALLY_COPY_CONSTRUCTIBLE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IsScalar.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsTriviallyCopyConstructible = AndType<StdBoolConstant<std::is_trivially_copy_constructible<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsTriviallyCopyConstructible : IsScalar<ObjectT_> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyCopyConstructible;



DD_END_



#endif
