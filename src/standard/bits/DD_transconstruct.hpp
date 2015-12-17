//	DDCPP/standard/bits/DD_transconstruct.hpp
#ifndef DD_TRANS_CONSTRUCT_HPP_INCLUDED_
#	define DD_TRANS_CONSTRUCT_HPP_INCLUDED_ 1



#	include <cstring>

#	include "DD_IsPointer.hpp"
#	include "DD_IsSame.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyMoveConstructible.hpp"
#	else
#		include "DD_IsNoexceptCopyConstructible.hpp"
#		include "DD_IsTriviallyCopyConstructible.hpp"
#	endif
#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_IteratorValue.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"



DD_DETAIL_BEGIN_

template <ValidityType can_trivially_operate_c_>
struct Transconstruct_ {
	template <ValidityType can_noexcept_move_construct_c__, int workaround__ = 0>
	struct Transconstruct__ {
		template <typename UndirectionalIteratorT1___, typename UndirectionalIteratorT2___>
		static UndirectionalIteratorT2___ transconstruct(
			UndirectionalIteratorT1___ begin____,
			UndirectionalIteratorT1___ end____,
			UndirectionalIteratorT2___ destination____
		) DD_NOEXCEPT_AS(::DD::construct(destination____ DD_COMMA move(*begin____))) {
			UndirectionalIteratorT2___ current____ = destination____;
			try {
				for (; begin____ < end____; ++begin____, ++current____) {
#	if __cplusplus >= 201103L
					::DD::construct(current____, move(*begin____));
#	else
					::DD::construct(current____, *begin____);
#	endif
				}
			} catch (...) {
#	if __cplusplus >= 201103L
				move(destination____, current____, begin____);
#	endif
				::DD::destruct(destination____, current____);
				throw;
			}
			return current____;
		}


	};


	template <int workaround>
	struct Transconstruct__<true, workaround> {
		template <typename UndirectionalIteratorT1___, typename UndirectionalIteratorT2___>
		static UndirectionalIteratorT2___ transconstruct(
			UndirectionalIteratorT1___ begin____,
			UndirectionalIteratorT1___ end____,
			UndirectionalIteratorT2___ destination____
		) DD_NOEXCEPT_AS(::DD::construct(destination____ DD_COMMA move(*begin____))) {
			for (; begin____ < end____; ++begin____, ++destination____) {
#	if __cplusplus >= 201103L
				::DD::construct(destination____, move(*begin____));
#	else
				::DD::construct(destination____, *begin____);
#	endif
			}
			return destination____;
		}


	};


	template <typename UndirectionalIteratorT1___, typename UndirectionalIteratorT2___>
	static UndirectionalIteratorT2___ transconstruct(
		UndirectionalIteratorT1___ begin___,
		UndirectionalIteratorT1___ end___,
		UndirectionalIteratorT2___ destination___
	) DD_NOEXCEPT_AS(Transconstruct__<
			noexcept(::DD::construct(destination___ DD_COMMA move(*begin___)))
	>::transconstruct(begin___ DD_COMMA end___ DD_COMMA destination___)) {
#	if __cplusplus >= 201103L
		return Transconstruct__<
			noexcept(::DD::construct(destination___, move(*begin___)))
		>::transconstruct(begin___, end___, destination___);
#	else
		return Transconstruct__<
			IsNoexceptCopyConstructible<typename IteratorValue<UndirectionalIteratorT2___>::Type>::value
		>::transconstruct(begin___, end___, destination___);
#	endif
	}


};



template <>
struct Transconstruct_<true> {
	template <typename ValueT__>
	static ValueT__* transconstruct(
		ValueT__* begin___,
		ValueT__* end___,
		ValueT__* destination___
	) {
		DD_MODIFY_TRAIT(IteratorDifference, ValueT__*) length_ = length_difference(begin___, end___);
		std::memcpy(begin___, destination___, sizeof(ValueT__) * length_);
		return destination___ + length_;
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
UndirectionalIteratorT2_ transconstruct(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UndirectionalIteratorT2_ destination__
) DD_NOEXCEPT_AS(
	Transconstruct_<AndType<
		IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_> DD_COMMA
		IsSame<IteratorValueType<UndirectionalIteratorT1_> DD_COMMA IteratorValueType<UndirectionalIteratorT2_>> DD_COMMA
		IsTriviallyMoveConstructible<IteratorValueType<UndirectionalIteratorT1_>>
	>::value>::transconstruct(begin__ DD_COMMA end__ DD_COMMA destination__)
) {
#	if __cplusplus >= 201103L
	return Transconstruct_<AndType<
		IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>,
		IsSame<IteratorValueType<UndirectionalIteratorT1_>, IteratorValueType<UndirectionalIteratorT2_>>,
		IsTriviallyMoveConstructible<IteratorValueType<UndirectionalIteratorT1_>>
	>::value>::transconstruct(begin__, end__, destination__);
#	else
	typedef typename IteratorValue<UndirectionalIteratorT1_>::Type ValueType;
	Transconstruct_<
		IsPointer<UndirectionalIteratorT1_>::value &&
		IsPointer<UndirectionalIteratorT2_>::value &&
		IsSame<ValueType, typename IteratorValue<UndirectionalIteratorT2_>::Type>::value &&
		IsTriviallyCopyConstructible<ValueType>::value
	>::transconstruct(begin__, end__, destination__);
#	endif
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transconstruct;



DD_END_



#endif
