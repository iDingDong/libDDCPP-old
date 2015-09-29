//	DDCPP/standard/bits/DD_IsArray.hpp
#ifndef DD_IS_ARRAY_HPP_INCLUDED_
#	define DD_IS_ARRAY_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_Nil.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsArray_ : StdBoolConstant<std::is_array<ObjectT_>> {
#	else
struct IsArray_ : FalseType {
#	endif
};



template <typename ValueT_>
struct IsArray_<ValueT_[]> : TrueType {
};



template <typename ValueT_, LengthType length_c_>
struct IsArray_<ValueT_[length_c_]> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsArray = AndType<detail_::IsArray_<ObjectsT_>...>;
#	else
template <typename ObjectT_>
struct IsArray : detail_::IsArray_<ObjectT_> {
};
#	endif



DD_END_



#endif
