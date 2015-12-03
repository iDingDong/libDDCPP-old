//	DDCPP/standard/bits/DD_AddConst.hpp
#ifndef DD_ADD_CONST_HPP_INCLUDED_
#	define DD_ADD_CONST_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct AddConst {
#	if __cplusplus >= 201402L
	using Type = std::add_const_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::add_const<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



DD_TRAIT_MODIFIER(AddConst)



DD_DETAIL_END_



DD_BEGIN_
using detail_::AddConst;
#	if __cplusplus >= 201103L
using detail_::AddConstType;
#	endif



DD_END_



#endif
