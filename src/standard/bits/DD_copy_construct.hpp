//	DDCPP/standard/bits/DD_copy_construct.hpp
#ifndef DD_COPY_CONSTRUCT_INCLUDED_
#	define DD_COPY_CONSTRUCT_INCLUDED_ 1



#	include "DD_construct.hpp"
#	include "DD_copy.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct CopyConstruct_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static UndirectionalIteratorT2__ copy_construct(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT1__ const& end___,
		UndirectionalIteratorT2__ result_begin___
	) DD_NOEXCEPT_AS(construct(result_begin___ DD_COMMA *begin___) DD_COMMA ++begin___ != end___) {
		for (; begin___ != end___; ++begin___, ++result_begin___) {
			construct(result_begin___, *begin___);
		}
		return result_begin___;
	}


};



template <>
struct CopyConstruct_<true> {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static UndirectionalIteratorT2__ copy_construct(
		UndirectionalIteratorT1__ const& begin___,
		UndirectionalIteratorT1__ const& end___,
		UndirectionalIteratorT2__ const& result_begin___
	) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT2__>(copy(begin___ DD_COMMA end___ DD_COMMA result_begin___))) {
		return copy(begin___, end___, result_begin___);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline UndirectionalIteratorT2_ copy_construct(
	UndirectionalIteratorT1_ const& begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_ const& result_begin__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT2_>(CopyConstruct_<
	IsSame<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_), DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)>::value &&
	IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_>::value &&
	IsTriviallyCopyable<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)>::value
>::copy_construct(begin__ DD_COMMA end__ DD_COMMA result_begin__))) {
	return CopyConstruct_<
		IsSame<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_), DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)>::value &&
		IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>::value &&
		IsTriviallyCopyable<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)>::value
	>::copy_construct(begin__, end__, result_begin__);
}

template <typename UndirectionalRangeT_, typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ copy_construct(
	UndirectionalRangeT_& range__,
	UndirectionalIteratorT_ const& result_begin__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(copy_construct(DD_SPLIT_RANGE(range__) DD_COMMA result_begin__))) {
	return copy_construct(DD_SPLIT_RANGE(range__), result_begin__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy_construct;



DD_END_



#endif
