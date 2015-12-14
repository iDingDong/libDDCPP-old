//	DDCPP/standard/bits/DD_RemoveConst.hpp
#ifndef DD_REMOVE_CONST_HPP_INCLUDED_
#	define DD_REMOVE_CONST_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct RemoveConst {
#	if __cplusplus >= 201402L
	using Type = std::remove_const_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_const<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



template <typename ObjectT_>
struct RemoveConst<ObjectT_ const> {
	DD_ALIAS(Type, ObjectT_);


};



DD_TRAIT_MODIFIER(RemoveConst)



DD_DETAIL_END_



DD_BEGIN_
using detail_::RemoveConst;
#	if __cplusplus >= 201103L
using detail_::RemoveConstType;
#	endif



DD_END_



#endif
