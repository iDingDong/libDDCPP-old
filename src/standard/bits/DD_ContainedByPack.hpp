//	DDCPP/standard/bits/DD_ContainedByPack.hpp
#ifndef DD_CONTAINED_BY_PACK_INCLUDED_
#	define DD_CONTAINED_BY_PACK_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ContainedByPack'.



#	endif
#	include "DD_Or.hpp"
#	include "DD_IsSame.hpp"



DD_BEGIN_
template <typename ObjectT_, typename... ListObjectsT_>
struct ContainedByPack : FalseType {
};



template <typename ObjectT_, typename ListObjectT_, typename... ListObjectsT_>
struct ContainedByPack<ObjectT_, ListObjectT_, ListObjectsT_...> : OrType<
	IsSame<ObjectT_, ListObjectT_>,
	ContainedByPack<ObjectT_, ListObjectsT_...>
> {
};



DD_END_



#endif
