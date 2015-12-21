//	DDCPP/standard/bits/DD_advance.hpp
#ifndef DD_ADVANCE_HPP_INCLUDED_
#	define DD_ADVANCE_HPP_INCLUDED_



#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
inline ProcessType advance(UndirectionalIteratorT_& iterator__) DD_NOEXCEPT_AS(++iterator__) {
	++iterator__;
}



template <ValidityType is_free_access_iterator_c_>
struct Advance_ {
	template <typename UndirectionalIteratorT__, typename DifferenceT__>
	static ProcessType advance(UndirectionalIteratorT__& iterator___, DifferenceT__ step___) DD_NOEXCEPT_IF(
		noexcept(static_cast<bool>(step___)) &&
		noexcept(--step___) &&
		noexcept(::DD::detail_::advance(iterator___))
	) {
		for (; step___; --step___) {
			::DD::detail_::advance(iterator___);
		}
	}


};



template <>
struct Advance_<true> {
	template <typename FreeAccessIteratorT__, typename DifferenceT__>
	static ProcessType advance(FreeAccessIteratorT__& iterator___, DifferenceT__ step___) DD_NOEXCEPT_AS(iterator___ += step___) {
		iterator___ += step___;
	}


};



template <typename UndirectionalIteratorT_, typename DifferenceT_>
inline ProcessType advance(UndirectionalIteratorT_& iterator__, DifferenceT_ const& step__) DD_NOEXCEPT_AS(
	Advance_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::advance(iterator__ DD_COMMA step__)
) {
	return Advance_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::advance(iterator__, step__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::advance;



DD_END_



#endif
