//	DDCPP/standard/bits/DD_ConstantList.hpp
#ifndef _DD_CONSTANT_LIST_HPP_INCLUDED
#	define _DD_CONSTANT_LIST_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ConstantList'.



#	endif
#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ValueT, _ValuesT... __values_c>
struct ConstantList {
	public:
	using ThisType = ConstantList<_ValueT, __values_c...>;


	template <_ValuesT_... __values_c_>
	using PushFront = ConstantList<_ValueT, __values_c..., __values_c_...>;

	public:
	template <_ValuesT_... __values_c_>
	using PushBack = ConstantList<_ValueT, __values_c..., __values_c_...>;



};



template <>



template <typename _ValueT, _ValueT __value>
struct Generate



_DD_END



#endif
