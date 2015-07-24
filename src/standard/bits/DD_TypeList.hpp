//	standard/bits/DD_TypeList.hpp
#ifndef _DD_TYPE_LIST_HPP_INCLUDED
#	define _DD_TYPE_LIST_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::TypeList'.



#	endif
#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename... _ObjectsT>
struct TypeList {
	static LengthType constexpr length = sizeof...(_ObjectsT);
	
	
};



DD_END



#endif
