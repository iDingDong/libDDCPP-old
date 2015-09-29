//	DDCPP/standard/bits/DD_IsCharactor.hpp
#ifndef DD_IS_CHARACTOR_HPP_INCLUDED_
#	define DD_IS_CHARACTOR_HPP_INCLUDED_ 1


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
DD_DETAIL_BEGIN_
template <typename ObjectT_>
using IsCharactor_ = OrType<
	IsChar<ObjectT_>,
	IsUnsignedChar<ObjectT_>,
	IsSignedChar<ObjectT_>,
	IsWChar<ObjectT_>,
	IsChar16<ObjectT_>,
	IsChar32<ObjectT_>
>;



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsCharactor = AndType<detail_::IsCharactor_<ObjectsT_>...>;
#	else
template <typename ObjectT_>
struct IsCharactor : BoolConstant<IsChar<ObjectT_>::value || IsUnsignedChar<ObjectT_>::value || IsSignedChar<ObjectT_>::value || IsWChar<ObjectT_>::value> {
};
#	endif



DD_END_



#endif
