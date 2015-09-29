//	DDCPP/standard/bits/DD_IsLvalueReference.hpp
#ifndef DD_IS_LVALUE_REFERENCE_HPP_INCLUDED_
#	define DD_IS_LVALUE_REFERENCE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsLvalueReference'.
#	endif



#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsLvalueReference_ : StdBoolConstant<std::is_lvalue_reference<ObjectT_>> {
};



template <typename ObjectT_>
struct IsLvalueReference_<ObjectT_&> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
template <typename... ObjectsT_>
using IsLvalueReference = AndType<detail_::IsLvalueReference_<ObjectsT_>...>;



DD_END_



#endif
