//	DDCPP/standard/bits/DD_RemoveExtent.hpp
#ifndef DD_REMOVE_EXTENT_HPP_INCLUDED_
#	define DD_REMOVE_EXTENT_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct RemoveExtent {
#	if __cplusplus >= 201402L
	using Type = std::remove_extent_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_extent<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



template <typename ValueT_, LengthType length_c_>
struct RemoveExtent<ValueT_[length_c_]> {
	DD_ALIAS(Type, ValueT_);


};



template <typename ValueT_>
struct RemoveExtent<ValueT_[]> {
	DD_ALIAS(Type, ValueT_);


};



DD_TRAIT_MODIFIER(RemoveExtent)



DD_DETAIL_END_



DD_BEGIN_
using detail_::RemoveExtent;
DD_TRAIT_MODIFIER(RemoveExtent)



DD_END_



#endif
