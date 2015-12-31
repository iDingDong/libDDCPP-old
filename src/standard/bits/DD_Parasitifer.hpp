//	DDCPP/standard/bits/DD_Parasitifer.hpp
#ifndef DD_PARASITIFER_HPP_INCLUDED_
#	define DD_PARASITIFER_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_Agent.hpp"
#	include "DD_UniversalDeleter.hpp"
#	include "DD_destroy.hpp"
#	include "DD_Pair.hpp"



DD_DETAIL_BEGIN_
template <
	typename ValueT_,
	typename DeleterT_ = UniversalDeleter
>
struct Parasitifer : Agent<DeleterT_> {
	public:
	DD_ALIAS(DestroyAgent, Agent<DeleterT_>);
	DD_ALIAS(ThisType, Parasitifer<ValueT_ DD_COMMA DeleterT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);
	DD_DELETER_


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Parasitifer;



DD_END_



#endif
