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



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ObjectT_>
using IsCharactor_ = OrType<
	IsChar<ObjectT_>,
	IsUnsignedChar<ObjectT_>,
	IsSignedChar<ObjectT_>,
	IsWChar<ObjectT_>,
	IsChar16<ObjectT_>,
	IsChar32<ObjectT_>
>;



template <typename... ObjectsT_>
struct IsCharactor : AndType<IsCharactor_<ObjectsT_>...> {
};
#	else
template <typename ObjectT_>
struct IsCharactor : BoolConstant<
	IsChar<ObjectT_>::value ||
	IsUnsignedChar<ObjectT_>::value ||
	IsSignedChar<ObjectT_>::value ||
	IsWChar<ObjectT_>::value
> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsCharactor;



DD_END_



#endif
