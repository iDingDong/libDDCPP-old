//	DDCPP/standard/bits/DD_COMMON_HPP
#ifndef _DD_COMMON_HPP_INCLUDED
#	define _DD_COMMON_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::CommonType'.



#	endif
#	include "DD_declare_value.hpp"
#	include "DD_Decay.hpp"



_DD_BEGIN
template <typename... _ObjectsT>
struct Common {
	using Type = void;


};



template <typename _ObjectT>
struct Common<_ObjectT> {
	using Type = DecayType<_ObjectT>;


};



template <typename _ObjectT1, typename _ObjectT2>
struct Common<_ObjectT1, _ObjectT2> {
	using Type = DecayType<decltype(true ? declare_value<_ObjectT1> : declare_value<_ObjectT2>)>;


};



template <typename _ObjectT1, typename _ObjectT2, typename... _ObjectsT>
struct Common<_ObjectT1, _ObjectT2, _ObjectsT...> {
	using Type = typename Common<_ObjectT1, typename Common<_ObjectT2, _ObjectsT...>::Type>::Type;


};



template <typename... _ObjectsT>
using CommonType = typename Common<_ObjectsT...>::Type;



_DD_END



#endif
