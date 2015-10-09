//	DDCPP/standard/bits/DD_copy.hpp
#ifndef DD_COPY_HPP_INCLUDED_
#	define DD_COPY_HPP_INCLUDED_ 1



#	include <cstring>

#	include "DD_global_definitions.hpp"
#	include "DD_size_distance.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_memmoveable_c_>
struct Copy_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static UndirectionalIteratorT2__ copy(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT1__ const& end___,
		UndirectionalIteratorT2__ result_begin___
	) DD_NOEXCEPT_IF(noexcept(++begin___) && noexcept(++result_begin___) && noexcept(*result_begin___ = *begin___)) {
		for (; begin___ != end___; ++begin___, ++result_begin___) {
			*result_begin___ = *begin___;
		}
		return result_begin___;
	}


};



template <>
struct Copy_<true> {
	template <typename PointerT1__, typename PointerT2__>
	static PointerT2__ DD_CONSTEXPR copy(
		PointerT1__ const& begin___,
		PointerT1__ const& end___,
		PointerT2__ const& result_begin___
	) DD_NOEXCEPT_AS(std::memmove(result_begin___, begin___, size_distance(begin___, end___))) {
		return std::memmove(result_begin___, begin___, size_distance(begin___, end___)), result_begin___ + (end___ - begin___);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
UndirectionalIteratorT2_ DD_CONSTEXPR copy(
	UndirectionalIteratorT1_ const& begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_ const& result_end__
) {
	return Copy_<false>::copy(begin__, end__, result_end__);// Imperfect realization
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy;



DD_END_



#endif
