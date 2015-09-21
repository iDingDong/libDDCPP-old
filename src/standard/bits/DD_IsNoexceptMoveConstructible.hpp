//	DDCPP/standard/bits/DD_IsNoexceptMoveConstructible.hpp
#ifndef _DD_IS_NOEXCEPT_MOVE_CONSTRUCTIBLE_HPP_INCLUDED
#	define _DD_IS_NOEXCEPT_MOVE_CONSTRUCTIBLE_HPP_INCLUDED 1


#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsNoexceptMoveConstructible'.



#	endif
#	include <type_traits>
#	include "DD_Or.hpp"
#	include "DD_And.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsNoexceptMoveConstructible : OrType<StdBoolConstant<std::is_nothrow_move_constructible<_ObjectT>>> {
};



_DD_DETAIL_END



_DD_BEGIN
template <typename... _ObjectsT>
using IsNoexceptMoveConstructible = AndType<_detail::_IsNoexceptMoveConstructible<_ObjectsT>...>;



_DD_END



#endif
