//	DDCPP/standard/bits/DD_IsNoexceptCopyConstructible.hpp
#ifndef DD_IS_NOEXCEPT_COPY_CONSTRUCTIBLE_HPP_INCLUDED_
#	define DD_IS_NOEXCEPT_COPY_CONSTRUCTIBLE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IsArithmetic.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsNoexceptCopyConstructible : AndType<IsNoexceptCopyConstructible<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsNoexceptCopyConstructible<ObjectT_> : StdBoolConstant<std::is_nothrow_copy_constructible<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsNoexceptCopyConstructible : IsArithmetic<ObjectT_> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsNoexceptCopyConstructible;



DD_END_



#endif

