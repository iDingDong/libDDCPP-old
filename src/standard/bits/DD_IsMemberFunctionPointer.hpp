//	DDCPP/standard/bits/DD_IsMemberFunctionPointer.hpp
#ifndef _DD_IS_MEMBER_FUNCION_POINTER_HPP_INCLUDED
#	define _DD_IS_MEMBER_FUNCION_POINTER_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsMemberFunctionPointer'.



#	endif
#	include <type_traits>

#	include "DD_IsFunction.hpp"
#	include "DD_RemoveCV.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsMemberFunctionPointer : StdBoolConstant<std::is_member_function_pointer<_ObjectT>> {
};



template <typename _FunctionT, typename _ClassT>
struct _IsMemberFunctionPointer<_FunctionT _ClassT::*> : IsFunction<_FunctionT> {
};



_DD_DETAIL_END



_DD_BEGIN
template <typename... _ObjectsT>
using IsMemberFunctionPointer = AndType<_detail::_IsMemberFunctionPointer<RemoveCVType<_ObjectsT>>...>;



_DD_END



#endif
