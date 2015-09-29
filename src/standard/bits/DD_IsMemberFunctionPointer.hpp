//	DDCPP/standard/bits/DD_IsMemberFunctionPointer.hpp
#ifndef DD_IS_MEMBER_FUNCION_POINTER_HPP_INCLUDED_
#	define DD_IS_MEMBER_FUNCION_POINTER_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsMemberFunctionPointer'.



#	endif
#	include <type_traits>

#	include "DD_IsFunction.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsMemberFunctionPointer_ : StdBoolConstant<std::is_member_function_pointer<ObjectT_>> {
};



template <typename FunctionT_, typename ClassT_>
struct IsMemberFunctionPointer_<FunctionT_ ClassT_::*> : IsFunction<FunctionT_> {
};



DD_DETAIL_END_



DD_BEGIN_
template <typename... ObjectsT_>
using IsMemberFunctionPointer = AndType<detail_::IsMemberFunctionPointer_<RemoveCVType<ObjectsT_>>...>;



DD_END_



#endif
