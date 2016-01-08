//	DDCPP/standard/bits/DD_accumulate.hpp
#ifndef DD_ACCUMULATE_HPP_INCLUDED_
#	define DD_ACCUMULATE_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"
#	include "DD_AddAssignWith.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryFunctionT_>
ValueT_ accumulate(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ initial_value__,
	BinaryFunctionT_ add_assign__
) DD_NOEXCEPT_IF(noexcept(++begin__ != end__) && noexcept(add_assign__(initial_value__ DD_COMMA *begin__))) {
	for (; begin__ != end__; ++begin__) {
		add_assign__(initial_value__, *begin__);
	}
	return initial_value__;
}

template <typename UndirectionalIteratorT_, typename ValueT_>
inline ValueT_ accumulate(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ initial_value__
) DD_NOEXCEPT_AS(static_cast<ValueT_>(
	::DD::detail_::accumulate(begin__ DD_COMMA end__ DD_COMMA initial_value__ DD_COMMA AddAssignWith<>())
)) {
	return ::DD::detail_::accumulate(begin__, end__, initial_value__, AddAssignWith<>());
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryFunctionT_>
inline ValueT_ accumulate(
	UndirectionalRangeT_& range__,
	ValueT_ initial_value__,
	BinaryFunctionT_ add_assign__
) DD_NOEXCEPT_AS(static_cast<ValueT_>(
	::DD::detail_::accumulate(DD_SPLIT_RANGE(range__) DD_COMMA initial_value__ DD_COMMA add_assign__)
)) {
	return ::DD::detail_::accumulate(DD_SPLIT_RANGE(range__), initial_value__, add_assign__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline ValueT_ accumulate(
	UndirectionalRangeT_& range__,
	ValueT_ initial_value__
) DD_NOEXCEPT_AS(static_cast<ValueT_>(
	::DD::detail_::accumulate(range__ DD_COMMA initial_value__ DD_COMMA AddAssignWith<>())
)) {
	return ::DD::detail_::accumulate(range__, initial_value__, AddAssignWith<>());
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::accumulate;



DD_END_



#endif
