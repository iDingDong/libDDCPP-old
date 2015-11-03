//	DDCPP/standard/bits/DD_BiggestTypeOfPack.hpp
#ifndef DD_BIGGEST_TYPE_OF_PACK_HPP_INCLUDED_
#	define DD_BIGGEST_TYPE_OF_PACK_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::BiggestTypeOfPack'.



#	endif
#	include "DD_Nil.hpp"
#	include "DD_Conditional.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct BiggestTypeOfPack {
	DD_ALIAS(Type, void);


};



template <typename ObjectT1_, typename ObjectT2_, typename... ObjectsT_>
struct BiggestTypeOfPack<ObjectT1_, ObjectT2_, ObjectsT_...> {
	DD_ALIAS(Type, typename BiggestTypeOfPack<BiggestTypeOfPack<ObjectT1_ DD_COMMA ObjectT2_> DD_COMMA ObjectsT_...>::Type);


};



template <typename ObjectT1_, typename ObjectT2_>
struct BiggestTypeOfPack<ObjectT1_, ObjectT2_> {
	DD_ALIAS(Type, typename Conditional<sizeof(ObjectT1_) < sizeof(ObjectT2_) DD_COMMA ObjectT2_ DD_COMMA ObjectT1_>::Type);


};



template <typename ObjectT_>
struct BiggestTypeOfPack<ObjectT_> {
	DD_ALIAS(Type, ObjectT_);


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::BiggestTypeOfPack;



DD_END_



#endif
