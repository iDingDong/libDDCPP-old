//	DDCPP/standard/bits/DD_ConstantList.hpp
#ifndef DD_CONSTANT_LIST_HPP_INCLUDED_
#	define DD_CONSTANT_LIST_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ConstantList'.



#	endif
#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ValueT_, ValuesT_... values_c__>
struct ConstantList {
	public:
	using ThisType = ConstantList<ValueT_, values_c__...>;


	template <ValuesT__... values_c___>
	using PushFront = ConstantList<ValueT_, values_c__..., values_c___...>;

	public:
	template <ValuesT__... values_c___>
	using PushBack = ConstantList<ValueT_, values_c__..., values_c___...>;



};



template <>



template <typename ValueT_, ValueT_ value__>
struct Generate



DD_END_



#endif
