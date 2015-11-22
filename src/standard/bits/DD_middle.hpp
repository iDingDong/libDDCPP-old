//	DDCPP/standard/bits/DD_middle.hpp
#ifndef DD_MIDDLE_HPP_INCLUDED_
#	define DD_MIDDLE_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_Range.hpp"
#	include "DD_next.hpp"
#	include "DD_length_difference.hpp"



DD_DETAIL_BEGIN_
template <IteratorCatagoryValue catagory_value_c_>
struct Middle_ {
	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ middle(
		UndirectionalIteratorT__ const& begin___,
		UndirectionalIteratorT__ const& end___
	) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT__>(
		::DD::next(begin___, length_difference(begin___, end___) / 2)
	)) {
		return ::DD::next(begin___, length_difference(begin___, end___) / 2);
	}


};



template <>
struct Middle_<IteratorCatagoryValue::bidirectional> {
	template <typename BidirectionalIteratorT__>
	static BidirectionalIteratorT__ middle(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(++begin___ != --end___) {
		while (begin___ != end___ && begin___ != --end___) {
			++begin___;
		}
		return begin___;
	}


};



template <typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ middle(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(
	Middle_<IteratorCatagory<UndirectionalIteratorT_>::value>::middle(begin__ DD_COMMA end__)
)) {
	return Middle_<IteratorCatagory<UndirectionalIteratorT_>::value>::middle(begin__, end__);
}

template <typename UndirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) middle(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::middle(DD_SPLIT_RANGE(range__))
)) {
	return ::DD::detail_::middle(DD_SPLIT_RANGE(range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::middle;



DD_END_



#endif
