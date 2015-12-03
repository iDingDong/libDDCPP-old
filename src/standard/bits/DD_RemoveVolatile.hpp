//	DDCPP/standard/bits/DD_RemoveVolatile.hpp
#ifndef DD_REMOVE_VOLATILE_HPP_INCLUDED_
#	define DD_REMOVE_VOLATILE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>
#	endif

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct RemoveVolatile {
#	if __cplusplus >= 201402L
	using Type = std::remove_volatile_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_volatile<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



template <typename ObjectT_>
struct RemoveVolatile<ObjectT_ volatile> {
	DD_ALIAS(Type, ObjectT_);


};



DD_TRAIT_MODIFIER(RemoveVolatile);



DD_DETAIL_END_



DD_BEGIN_
using detail_::RemoveVolatile;
#	if __cplusplus >= 201103L
using detail_::RemoveVolatileType;
#	endif



DD_END_



#endif
