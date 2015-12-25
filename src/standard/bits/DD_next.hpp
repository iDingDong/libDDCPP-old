//	DDCPP/standard/bits/DD_next.hpp
#ifndef DD_NEXT_HPP_INCLUDED_
#	define DD_NEXT_HPP_INCLUDED_ 1



#	include "DD_advance.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ DD_UNCONSTRIANED_CONSTEXPR next(UndirectionalIteratorT_ iterator__) DD_NOEXCEPT_AS(advance(iterator__)) {
	advance(iterator__);
	return iterator__;
}

template <typename UndirectionalIteratorT_, typename DifferenceT_>
inline UndirectionalIteratorT_ DD_UNCONSTRIANED_CONSTEXPR next(
	UndirectionalIteratorT_ iterator__,
	DifferenceT_ const& step__
) DD_NOEXCEPT_AS(advance(iterator__, step__)) {
	advance(iterator__, step__);
	return iterator__;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::next;



DD_END_



#endif
