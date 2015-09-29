//	DDCPP/standard/bits/DD_replace.hpp
#ifndef DD_REPLACE_HPP_INCLUDED_
#	define DD_REPLACE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT1_, typename ValueT2_>
ProcessType replace(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT1_ const& old__,
	ValueT2_ value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__ && *begin__ == old__) {
	for (; begin__ != end__; ++begin__) {
		if (*begin__ == old__) {
			*begin__ = value__;
		}
	}
}

template <typename UndirectionalIteratorT_, typename ValueT1_, typename BinaryPredicatorT_, typename ValueT2_>
ProcessType replace(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT1_ old__,
	BinaryPredicatorT_ const& equal__,
	ValueT2_ value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__ && equal__(*begin__, old__)) {
	for (; begin__ != end__; ++begin__) {
		if (equal__(*begin__, old__)) {
			*begin__ = value__;
		}
	}
}



DD_END_



#endif
