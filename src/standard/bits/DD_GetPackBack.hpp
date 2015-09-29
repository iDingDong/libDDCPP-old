//	DDCPP/standard/bits/DD_GetPackBack.hpp
#ifndef DD_GET_PACK_BACK_HPP_INCLUDED_
#	define DD_GET_PACK_BACK_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::GetPackBack'.



#	endif
#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ObjectT_, typename... ObjectsT_>
struct GetPackBack : GetPackBack<ObjectsT_...> {
};



template <typename ObjectT_>
struct GetPackBack<ObjectT_> {
	using Type = ObjectT_;


};



template <typename ObjectT_, typename... ObjectsT_>
using GetPackBackType = typename GetPackBack<ObjectT_, ObjectsT_...>::Type;



DD_END_



#endif
