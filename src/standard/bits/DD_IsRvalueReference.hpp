//	DDCPP/standard/bits/DD_IsRvalueReference.hpp
#ifndef DD_IS_RVALUE_REFERENCE_HPP_INCLUDED_
#	define DD_IS_RVALUE_REFERENCE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsRvalueReference'.
#	endif



#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsRvalueReference_ : StdBoolConstant<std::is_rvalue_reference<ObjectT_>> {
};



template <typename ObjectT_>
struct IsRvalueReference_<ObjectT_&&> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
template <typename... ObjectsT_>
using IsRvalueReference = AndType<detail_::IsRvalueReference_<ObjectsT_>...>;



DD_END_



#endif
