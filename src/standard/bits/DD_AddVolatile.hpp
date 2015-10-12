//	DDCPP/standard/bits/DD_AddVolatile.hpp
#ifndef DD_ADD_VOLATILE_HPP_INCLUDED_
#	define DD_ADD_VOLATILE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct AddVolatile {
#	if __cplusplus >= 201402L
	using Type = std::add_volatile_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::add_volatile<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



DD_TRAIT_MODIFIER(AddVolatile)



DD_DETAIL_END_



DD_BEGIN_
using detail_::AddVolatile;
DD_TRAIT_MODIFIER(AddVolatile)



DD_END_



#endif
