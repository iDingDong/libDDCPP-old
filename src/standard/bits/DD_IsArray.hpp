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
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsArray : AndType<IsArray<ObjectsT_>...> {
};
#	endif



template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsArray<ObjectT_> : StdBoolConstant<std::is_array<ObjectT_>> {
#	else
struct IsArray : FalseType {
#	endif
};



template <typename ValueT_>
struct IsArray<ValueT_[]> : TrueType {
};



template <typename ValueT_, LengthType length_c_>
struct IsArray<ValueT_[length_c_]> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsArray;



DD_END_



#endif
