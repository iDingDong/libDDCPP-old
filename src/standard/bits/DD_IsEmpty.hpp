//	DDCPP/standard/bits/DD_IsEmpty.hpp
#ifndef DD_IS_EMPTY_HPP_INCLUDED_
#	define DD_IS_EMPTY_HPP_INCLUDED_




#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsEmpty'.



#	endif
#	include <type_traits>

#	include "DD_Or.hpp"
#	include "DD_IsClass.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsEmptyHelper_ : ObjectT_ {
};



template <>
struct IsEmptyHelper_<void> {
};



template <typename ObjectT_, ValidityType is_class_c_>
struct IsEmpty_ : FalseType {
};



template <typename ObjectT_>
struct IsEmpty_<ObjectT_, true> : BoolConstant<sizeof(IsEmptyHelper_<ObjectT_>) == sizeof(IsEmptyHelper_<void>)> {
};



template <typename... ObjectsT_>
struct IsEmpty : AndType<IsEmpty<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsEmpty<ObjectT_> : OrType<IsEmpty_<ObjectT_, IsClass<ObjectT_>::value>, std::is_empty<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsEmpty;



DD_END_



#endif
