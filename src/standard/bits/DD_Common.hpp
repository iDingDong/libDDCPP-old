//	DDCPP/standard/bits/DD_COMMON_HPP
#ifndef DD_COMMON_HPP_INCLUDED_
#	define DD_COMMON_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::CommonType'.



#	endif
#	include "DD_declare_value.hpp"
#	include "DD_Decay.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct Common {
	using Type = void;


};



template <typename ObjectT_>
struct Common<ObjectT_> {
	using Type = DecayType<ObjectT_>;


};



template <typename ObjectT1_, typename ObjectT2_>
struct Common<ObjectT1_, ObjectT2_> {
	using Type = DecayType<decltype(true ? declare_value<ObjectT1_> : declare_value<ObjectT2_>)>;


};



template <typename ObjectT1_, typename ObjectT2_, typename... ObjectsT_>
struct Common<ObjectT1_, ObjectT2_, ObjectsT_...> {
	using Type = typename Common<ObjectT1_, typename Common<ObjectT2_, ObjectsT_...>::Type>::Type;


};



template <typename... ObjectsT_>
using CommonType = typename Common<ObjectsT_...>::Type;



DD_DETAIL_END_



DD_BEGIN_
using detail_::Common;
using detail_::CommonType;



DD_END_



#endif
