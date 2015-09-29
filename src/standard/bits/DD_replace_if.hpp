//	DDCPP/standard/bits/DD_replace_if.hpp
#ifndef DD_REPLACE_IF_HPP_INCLUDED_
#	define DD_REPLACE_IF_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicatorT_, typename ValueT_>
ProcessType replace_if(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicatorT_ predicator__,
	ValueT_ value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__ && predicator__(*begin__)) {
	for (; begin__ != end__; ++begin__) {
		if (predicator__(*begin__)) {
			*begin__ = value__;
		}
	}
}



DD_END_



#endif
