//	DDCPP/standard/bits/DD_IsUnsignedInt.hpp
#ifndef _DD_IS_UNSIGNED_INT_HPP_INCLUDED
#	define _DD_IS_UNSIGNED_INT_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsUnsignedInt : FalseType {
};



template <>
struct _IsUnsignedInt<unsigned int> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsUnsignedInt = AndType<_detail::_IsUnsignedInt<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsUnsignedInt : _detail::_IsUnsignedInt<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
