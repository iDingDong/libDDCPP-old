//	DDCPP/standard/bits/DD_IsNoexceptMoveAssignable.hpp
#ifndef DD_IS_NOEXCEPT_MOVE_ASSIGNABLE_HPP_INCLUDED_
#	define DD_IS_NOEXCEPT_MOVE_ASSIGNABLE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsNoexceptMoveAssignable'.



#	endif
#	include <type_traits>
#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsNoexceptMoveAssignable_ : StdBoolConstant<std::is_nothrow_move_assignable<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
template <typename... ObjectsT_>
using IsNoexceptMoveAssignable = AndType<detail_::IsNoexceptMoveAssignable_<ObjectsT_>...>;



DD_END_



#endif
