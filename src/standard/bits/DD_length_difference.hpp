//	DDCPP/standard/bits/DD_length_difference.hpp
#ifndef DD_LENGTH_DIFFERENCE_HPP_INCLUDED_
#	define DD_LENGTH_DIFFERENCE_HPP_INCLUDED_ 1



#	include "DD_IteratorDifference.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, ValidityType is_free_access_iterator_>
struct LengthDifference_ {
	static DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) length_difference_(
		UndirectionalIteratorT_ begin__,
		UndirectionalIteratorT_ const& end__
	) DD_NOEXCEPT_IF(noexcept(begin__ != end__) && noexcept(++begin__)) {
#	if __cplusplus >= 201103L
		auto result_ = IteratorDifference<UndirectionalIteratorT_>();
#	else
		typedef typename IteratorDifference<UndirectionalIteratorT_>::Type ResultType_;
		ResultType result_ = ResultType();
#	endif
		for (; begin__ != end__; ++begin__) {
			++result_;
		}
		return result_;
	}


};



template <typename FreeAccessIterator_>
struct LengthDifference_<FreeAccessIterator_, true> {
#	if __cplusplus >= 201103L
	static auto length_difference_(FreeAccessIterator_ const& begin__, FreeAccessIterator_ const& end__) DD_NOEXCEPT_AS(end__ - begin__) -> decltype(end__ - begin__) {
#	else
	static typename IteratorDifference<FreeAccessIteratorT_>::Type length_difference_(FreeAccessIterator_ const& begin__, FreeAccessIterator_ const& end__) {
#	endif
		return end__ - begin__;
	}


};



DD_DETAIL_END_



DD_BEGIN_
template <typename UndirectionalIteratorT_>
#	if __cplusplus >= 201103L
inline auto length_difference(UndirectionalIteratorT_ const& begin__, UndirectionalIteratorT_ const& end__) noexcept(
	noexcept(detail_::LengthDifference_<UndirectionalIteratorT_, IsFreeAccessIterator<UndirectionalIteratorT_>::value>::length_difference_(begin__, end__))
) -> decltype(detail_::LengthDifference_<UndirectionalIteratorT_, IsFreeAccessIterator<UndirectionalIteratorT_>::value>::length_difference_(begin__, end__)) {
#	else
typename IteratorDifference<UndirectionalIteratorT_>::Type length_difference(UndirectionalIteratorT_ const& begin__, UndirectionalIteratorT_ const& end__) {
#	endif
	return detail_::LengthDifference_<UndirectionalIteratorT_, IsFreeAccessIterator<UndirectionalIteratorT_>::value>::length_difference_(begin__, end__);
}



DD_END_



#endif
