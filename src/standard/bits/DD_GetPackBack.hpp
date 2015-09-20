//	DDCPP/standard/bits/DD_GetPackBack.hpp
#ifndef _DD_GET_PACK_BACK_HPP_INCLUDED
#	define _DD_GET_PACK_BACK_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::GetPackBack'.



#	endif
#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT, typename... _ObjectsT>
struct GetPackBack : GetPackBack<_ObjectsT...> {
};



template <typename _ObjectT>
struct GetPackBack<_ObjectT> {
	using Type = _ObjectT;


};



template <typename _ObjectT, typename... _ObjectsT>
using GetPackBackType = typename GetPackBack<_ObjectT, _ObjectsT...>::Type;



DD_END



#endif
