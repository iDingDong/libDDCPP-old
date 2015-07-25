//	DDCPP/standard/bits/DD_IsNoexceptMoveAssignable.hpp
#ifndef _DD_IS_NOEXCEPT_MOVE_ASSIGNABLE_HPP_INCLUDED
#	define _DD_IS_NOEXCEPT_MOVE_ASSIGNABLE_HPP_INCLUDED 1


#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsNoexceptMoveAssignable'.



#	endif
#	include <type_traits>
#	include "DD_And.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsNoexceptMoveAssignable : StdBoolConstant<std::is_nothrow_move_assignable<_ObjectT>> {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsNoexceptMoveAssignable = AndType<detail::_IsNoexceptMoveAssignable<_ObjectsT>...>;



DD_END



#endif
