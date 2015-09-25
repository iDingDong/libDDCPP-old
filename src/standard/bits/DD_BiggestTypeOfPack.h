//	DDCPP/standard/bits/DD_BiggestTypeOfPack.hpp
#ifndef _DD_BIGGEST_TYPE_OF_PACK_HPP_INCLUDED
#	define _DD_BIGGEST_TYPE_OF_PACK_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::BiggestTypeOfPack'.



#	endif
#	include "DD_Nil.hpp"
#	include "DD_Conditional.hpp"



_DD_BEGIN
template <typename... _ObjectsT>
struct BiggestTypeOfPack {
	DD_ALIAS(Type, void);


};



template <typename _ObjectT1, typename _ObjectT2, typename... _ObjectsT>
struct BiggestTypeOfPack<_ObjectT1, _ObjectT2, _ObjectsT...> {
	DD_ALIAS(Type, typename BiggestTypeOfPack<BiggestTypeOfPack<_ObjectT1 DD_COMMA _ObjectT2> DD_COMMA _ObjectsT...>::Type);


};



template <typename _ObjectT1, typename _ObjectT2>
struct BiggestTypeOfPack<_ObjectT1, _ObjectT2> {
	DD_ALIAS(Type, typename Conditional<sizeof(_ObjectT1) < sizeof(_ObjectT2) DD_COMMA _ObjectT2 DD_COMMA _ObjectT1>::Type);


};



template <typename _ObjectT>
struct BiggestTypeOfPack<_ObjectT> {
	DD_ALIAS(Type, _ObjectT);


};



_DD_END



#endif
