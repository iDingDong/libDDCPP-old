//	DDCPP/standard/bits/DD_IsCharactor.hpp
#ifndef _DD_IS_CHARACTOR_HPP_INCLUDED
#	define _DD_IS_CHARACTOR_HPP_INCLUDED 1


#	if __cplusplus >= 201103L
#		include "DD_Or.hpp"
#	endif
#	include "DD_IsChar.hpp"
#	include "DD_IsUnsignedChar.hpp"
#	include "DD_IsSignedChar.hpp"
#	include "DD_IsWChar.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsChar16.hpp"
#		include "DD_IsChar32.hpp"
#	endif



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <typename _ObjectT>
using _IsCharactor = OrType<
	IsChar<_ObjectT>,
	IsUnsignedChar<_ObjectT>,
	IsSignedChar<_ObjectT>,
	IsWChar<_ObjectT>,
	IsChar16<_ObjectT>,
	IsChar32<_ObjectT>
>;



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsCharactor = AndType<_detail::_IsCharactor<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsCharactor : BoolConstant<IsChar<_ObjectT>::value || IsUnsignedChar<_ObjectT>::value || IsSignedChar<_ObjectT>::value || IsWChar<_ObjectT>::value> {
};
#	endif



DD_END



#endif
