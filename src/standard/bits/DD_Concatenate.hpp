//	DDCPP/standard/bits/DD_Concatenate.hpp
#ifndef DD_CONCATENATE_HPP_INCLUDED_
#	define DD_CONCATENATE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ConstantList'.



#	endif
#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ListT1_, typename ListT2_>
struct Concatenate {
	using Type = typename ListT1_::template Concatenate<ListT2_>;


};



template <typename ListT1_, typename ListT2_>
using ConcatenateType = typename Concatenate<ListT1_, ListT2_>::Type;



DD_DETAIL_END_



DD_BEGIN_
using detail_::Concatenate;
using detail_::ConcatenateType;



DD_END_



#endif
