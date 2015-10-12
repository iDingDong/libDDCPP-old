//	DDCPP/standard/bits/DD_RemoveAllExtents.hpp
#ifndef DD_REMOVE_ALL_EXTENTS_HPP_INCLUDED_
#	define DD_REMOVE_ALL_EXTENTS_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct RemoveAllExtents {
#	if __cplusplus >= 201402L
	using Type = std::remove_all_extents_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_all_extents<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



template <typename ValueT_, LengthType length_c_>
struct RemoveAllExtents<ValueT_[length_c_]> {
	DD_ALIAS(Type, typename RemoveAllExtents<ValueT_>::Type);


};



template <typename ValueT_>
struct RemoveAllExtents<ValueT_[]> {
	DD_ALIAS(Type, typename RemoveAllExtents<ValueT_>::Type);


};



DD_TRAIT_MODIFIER(RemoveAllExtents)



DD_DETAIL_END_



DD_BEGIN_
using detail_::RemoveAllExtents;
DD_TRAIT_MODIFIER(RemoveAllExtents)



DD_END_



#endif
