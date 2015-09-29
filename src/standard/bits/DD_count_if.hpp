//	DDCPP/standard/bits/DD_count_if.hpp
#ifndef DD_COUNT_IF_HPP_INCLUDED_
#	define DD_COUNT_IF_HPP_INCLUDED_ 1



#	include "DD_IteratorDifference.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicatorT_>
DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) count_if(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicatorT_ const& predicator__
) DD_NOEXCEPT_AS(++begin__ != end__ && predicator__(*begin__)) {
#	if __cplusplus >= 201103L
	auto result_ = DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) ResultType_;
	ResultType_ result_ = ResultType_();
#	endif
	for (; begin__ != end__; ++begin__) {
		if (predicator__(*begin__)) {
			++result_;
		}
	}
	return result_;
}



DD_END_



#endif
