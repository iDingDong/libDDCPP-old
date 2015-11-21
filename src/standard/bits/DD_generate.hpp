//	DDCPP/standard/bits/DD_generate.hpp
#ifndef DD_GENERATE_HPP_INCLUDED_
#	define DD_GENERATE_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename Generator_>
ProcessType generate(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	Generator_ generator__
) DD_NOEXCEPT_AS(*++begin__ = generator__() DD_COMMA begin__ != end__) {
	for (; begin__ != end__; ++begin__) {
		*begin__ = generator__();
	}
}

template <typename UndirectionalRangeT_, typename Generator_>
ProcessType generate(
	UndirectionalRangeT_& range__,
	Generator_ generator__
) DD_NOEXCEPT_AS(::DD::detail_::generate(DD_SPLIT_RANGE(range__) DD_COMMA generator__)) {
	::DD::detail_::generate(DD_SPLIT_RANGE(range__), generator__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::generate;



DD_END_



#endif
