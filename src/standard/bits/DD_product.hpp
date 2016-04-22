//	DDCPP/standard/bits/DD_product.hpp
#ifndef DD_PRODUCT_HPP_INCLUDED_
#	define DD_PRODUCT_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"
#	include "DD_MultiplyAssignWith.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryFunctionT_>
ValueT_ product(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ initial_value__,
	BinaryFunctionT_ multiply_assign__
) DD_NOEXCEPT_IF(noexcept(++begin__ != end__) && noexcept(multiply_assign__(initial_value__ DD_COMMA *begin__))) {
	for (; begin__ != end__; ++begin__) {
		multiply_assign__(initial_value__, *begin__);
	}
	return initial_value__;
}

template <typename UndirectionalIteratorT_, typename ValueT_>
inline ValueT_ product(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ initial_value__
) DD_NOEXCEPT_AS(static_cast<ValueT_>(
	::DD::detail_::product(begin__ DD_COMMA end__ DD_COMMA initial_value__ DD_COMMA multiply_assign_with)
)) {
	return ::DD::detail_::product(begin__, end__, initial_value__, multiply_assign_with);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryFunctionT_>
inline ValueT_ product(
	UndirectionalRangeT_& range__,
	ValueT_ initial_value__,
	BinaryFunctionT_ multiply_assign__
) DD_NOEXCEPT_AS(static_cast<ValueT_>(
	::DD::detail_::product(DD_SPLIT_RANGE(range__) DD_COMMA initial_value__ DD_COMMA multiply_assign__)
)) {
	return ::DD::detail_::product(DD_SPLIT_RANGE(range__), initial_value__, multiply_assign__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline ValueT_ product(
	UndirectionalRangeT_& range__,
	ValueT_ initial_value__
) DD_NOEXCEPT_AS(static_cast<ValueT_>(
	::DD::detail_::product(range__ DD_COMMA initial_value__ DD_COMMA multiply_assign_with)
)) {
	return ::DD::detail_::product(range__, initial_value__, multiply_assign_with);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::product;



DD_END_



#endif
