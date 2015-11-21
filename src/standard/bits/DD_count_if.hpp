//	DDCPP/standard/bits/DD_count_if.hpp
#ifndef DD_COUNT_IF_HPP_INCLUDED_
#	define DD_COUNT_IF_HPP_INCLUDED_ 1



#	include "DD_IteratorDifference.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicateT_>
DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) count_if(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicateT_ predicate__
) DD_NOEXCEPT_AS(++begin__ != end__ && predicate__(*begin__)) {
#	if __cplusplus >= 201103L
	auto result_ = DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) ResultType_;
	ResultType_ result_ = ResultType_();
#	endif
	for (; begin__ != end__; ++begin__) {
		if (predicate__(*begin__)) {
			++result_;
		}
	}
	return result_;
}

template <typename UndirectionalRangeT_, typename UnaryPredicateT_>
inline DD_MODIFY_TRAIT(IteratorDifference, DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)) count_if(
	UndirectionalRangeT_& range__,
	UnaryPredicateT_ predicate__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorDifference, DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_))>(
	::DD::detail_::count_if(DD_SPLIT_RANGE(range__) DD_COMMA predicate__)
)) {
	return ::DD::detail_::count_if(DD_SPLIT_RANGE(range__), predicate__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::count_if;



DD_END_



#endif
