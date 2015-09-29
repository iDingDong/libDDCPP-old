//	DDCPP/standard/bits/DD_EnableIf.hpp
#ifndef DD_ENABLE_IF_HPP_INCLUDED_
#	define DD_ENABLE_IF_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <ValidityType is_valid_c_, typename ObjectT_>
struct EnableIf {
};



template <typename ObjectT_>
struct EnableIf<true, ObjectT_> {
	DD_ALIAS(Type, ObjectT_);


};



#	if __cplusplus >= 201103L
template <ValidityType is_valid_c_, typename ObjectT_>
using EnableIfType = typename EnableIf<is_valid_c_, ObjectT_>::Type;



#	endif
DD_END_



#endif
