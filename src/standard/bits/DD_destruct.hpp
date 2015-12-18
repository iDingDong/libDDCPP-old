//	DDCPP/standard/bits/DD_destruct.hpp
#ifndef DD_DESTRUCT_HPP_INCLUDED_
#	define DD_DESTRUCT_HPP_INCLUDED_ 1



#	include "DD_IsTriviallyDestructible.hpp"
#	include "DD_address_of.hpp"
#	include "DD_IteratorValue.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_trivially_destructible_>
struct Destruct_ {
	template <typename PointerT_>
	static ProcessType destruct(PointerT_ pointer__) DD_NOEXCEPT {
		DD_ALIAS(ValueType, DD_MODIFY_TRAIT(IteratorValue, PointerT_));
		pointer__->~ValueType();
	}

	template <typename UndirectionalIteratorT_>
	static ProcessType destruct(UndirectionalIteratorT_ begin__, UndirectionalIteratorT_ const& end__) DD_NOEXCEPT {
		for (; begin__ != end__; ++begin__) {
			destruct(begin__);
		}
	}


};



template <>
struct Destruct_<true> {
	template <typename PointerT_>
	static ProcessType destruct(PointerT_ const& pointer__) DD_NOEXCEPT {
	}

	template <typename UndirectionalIteratorT_>
	static ProcessType destruct(UndirectionalIteratorT_ const& begin__, UndirectionalIteratorT_ const& end__) DD_NOEXCEPT {
	}


};



template <typename PointerT_>
inline ProcessType destruct(PointerT_ pointer__) DD_NOEXCEPT {
	Destruct_<IsTriviallyDestructible<DD_MODIFY_TRAIT(IteratorValue, PointerT_)>::value>::destruct(pointer__);
}

template <typename UndirectionalIteratorT_>
inline ProcessType destruct(UndirectionalIteratorT_ begin__, UndirectionalIteratorT_ end__) DD_NOEXCEPT {
	Destruct_<IsTriviallyDestructible<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT_)>::value>::destruct(begin__, end__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::destruct;



DD_END_



#endif
