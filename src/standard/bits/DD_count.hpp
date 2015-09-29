//	DDCPP/standard/bits/DD_count.hpp
#ifndef DD_COUNT_HPP_INCLUDED_
#	define DD_COUNT_HPP_INCLUDED_ 1



#	include "DD_IteratorDifference.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) count(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ == value__) {
#	if __cplusplus >= 201103L
	auto result_ = DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) ResultType_;
	ResultType_ result_ = ResultType_();
#	endif
	for (; begin__ != end__; ++begin__) {
		if (*begin__ == value__) {
			++result_;
		}
	}
	return result_;
}

template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicatorT_>
DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) count(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__,
	BinaryPredicatorT_ const& equal__
) DD_NOEXCEPT_AS(++begin__ != end__ && equal__(*begin__, value__)) {
#	if __cplusplus >= 201103L
	auto result_ = DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) ResultType_;
	ResultType_ result_ = ResultType_();
#	endif
	for (; begin__ != end__; ++begin__) {
		if (equal__(*begin__, value__)) {
			++result_;
		}
	}
	return result_;
}



DD_END_



#endif
