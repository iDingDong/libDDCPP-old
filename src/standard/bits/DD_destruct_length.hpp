//	DDCPP/standard/bits/DD_destruct_length.hpp
#ifndef DD_DESTRUCT_LENGTH_HPP_INCLUDED_
#	define DD_DESTRUCT_LENGTH_HPP_INCLUDED_ 1



#	include "DD_destruct.hpp"
#	include "DD_next.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_trivially_destructible_c_>
struct DestructLength_ {
	template <typename UndirectionalIteratorT__>
	static ProcessType noreturn_destruct_length(UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT {
		for (; length_; --length_) {
			::DD::destruct(begin___);
		}
	}


	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ destruct_length(UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT {
		for (; length_; --length_, ++begin___) {
			::DD::destruct(begin___);
		}
		return begin___;
	}


};



template <>
struct DestructLength_<true> {
	template <typename UndirectionalIteratorT__>
	static ProcessType noreturn_destruct_length(UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT {
	}


	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ destruct_length(UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT {
		return ::DD::next(begin___, length_);
	}


};



template <typename UndirectionalIteratorT_>
inline ProcessType noreturn_destruct_length(UndirectionalIteratorT_ begin__, LengthType length_) DD_NOEXCEPT {
	DestructLength_<
		IsTriviallyDestructible<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT_)>::value
	>::noreturn_destruct_length(begin__, length_);
}


template <typename UndirectionalIteratorT_>
inline ProcessType destruct_length(UndirectionalIteratorT_ begin__, LengthType length_) DD_NOEXCEPT {
	DestructLength_<
		IsTriviallyDestructible<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT_)>::value
	>::destruct_length(begin__, length_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::noreturn_destruct_length;
using detail_::destruct_length;



DD_END_



#endif
