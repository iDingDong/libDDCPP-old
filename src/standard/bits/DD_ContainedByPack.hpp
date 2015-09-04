//	DDCPP/standard/bits/DD_ContainedByPack.hpp
#ifndef _DD_CONTAINED_BY_PACK_INCLUDED
#	define _DD_CONTAINED_BY_PACK_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ContainedByPack'.



#	endif
#	include "DD_Or.hpp"
#	include "DD_IsSame.hpp"



DD_BEGIN
template <typename _ObjectT, typename... _ListObjectsT>
struct ContainedByPack : FalseType {
};



template <typename _ObjectT, typename _ListObjectT, typename... _ListObjectsT>
struct ContainedByPack<_ObjectT, _ListObjectT, _ListObjectsT...> : OrType<
	IsSame<_ObjectT, _ListObjectT>,
	ContainedByPack<_ObjectT, _ListObjectsT...>
> {
};



DD_END



#endif
