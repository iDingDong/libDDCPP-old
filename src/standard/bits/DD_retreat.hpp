//	DDCPP/standard/bits/DD_retreat.hpp
#ifndef DD_RETREAT_HPP_INCLUDED_
#	define DD_RETREAT_HPP_INCLUDED_



#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN_
template <typename BidirectionalIteratorT_>
inline ProcessType retreat(BidirectionalIteratorT_& iterator__) DD_NOEXCEPT_AS(--iterator__) {
	--iterator__;
}



template <ValidityType is_free_access_iterator_c_>
struct Retreat_ {
	template <typename BidirectionalIteratorT_, typename DifferenceT__>
	static ProcessType retreat(BidirectionalIteratorT_& iterator___, DifferenceT__ step___) DD_NOEXCEPT_IF(
		noexcept(static_cast<bool>(step___)) &&
		noexcept(--step___) &&
		noexcept(retreat(iterator___))
	) {
		for (; step___; --step___) {
			retreat(iterator___);
		}
	}


};



template <>
struct Retreat_<true> {
	template <typename FreeAccessIteratorT__, typename DifferenceT__>
	static ProcessType retreat(FreeAccessIteratorT__& iterator___, DifferenceT__ step___) DD_NOEXCEPT_AS(iterator___ -= step___) {
		iterator___ -= step___;
	}


};



template <typename BidirectionalIteratorT_, typename DifferenceT_>
inline ProcessType retreat(BidirectionalIteratorT_& iterator__, DifferenceT_ const& step__) DD_NOEXCEPT_AS(
	Retreat_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::retreat(iterator__ DD_COMMA step__)
) {
	return Retreat_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::retreat(iterator__, step__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::retreat;



DD_END_



#endif
