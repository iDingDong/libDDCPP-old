//	DDCPP/standard/bits/DD_EnableIf.hpp
#ifndef _DD_ENABLE_IF_HPP_INCLUDED
#	define _DD_ENABLE_IF_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <ValidityType _is_valid_c, typename _ObjectT>
struct EnableIf {
};



template <typename _ObjectT>
struct EnableIf<true, _ObjectT> {
	DD_ALIAS(Type, _ObjectT);


};



#	if __cplusplus >= 201103L
template <ValidityType _is_valid_c, typename _ObjectT>
using EnableIfType = typename EnableIf<_is_valid_c, _ObjectT>::Type;



#	endif
_DD_END



#endif
