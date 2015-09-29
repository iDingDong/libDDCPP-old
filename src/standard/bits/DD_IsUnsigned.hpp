//	DDCPP/standard/bits/DD_IsUnsigned.hpp
#ifndef DD_IS_UNSIGNED_HPP_INCLUDED_
#	define DD_IS_UNSIGNED_HPP_INCLUDED_ 1



#	include "DD_IsArithmetic.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_, ValidityType is_arithmetic_c_>
#	if __cplusplus >= 201103L
struct IsUnsigned_ : StdBoolConstant<std::is_unsigned<ObjectT_>> {
#	else
struct IsUnsigned_ : FalseType {
#	endif
};



template <typename ObjectT_>
struct IsUnsigned_<ObjectT_, true> : BoolConstant<ObjectT_(0) < ObjectT_(-1)> {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsUnsigned = AndType<detail_::IsUnsigned_<ObjectsT_, IsArithmetic<ObjectsT_>::value>...>;
#	else
template <typename ObjectT_>
struct IsUnsigned : detail_::IsUnsigned_<ObjectT_, IsArithmetic<ObjectT_>::value> {
};
#	endif



DD_END_



#endif
