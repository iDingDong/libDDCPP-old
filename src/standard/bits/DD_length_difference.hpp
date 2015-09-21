//	DDCPP/standard/bits/DD_length_difference.hpp
#ifndef _DD_LENGTH_DIFFERENCE_HPP_INCLUDED
#	define _DD_LENGTH_DIFFERENCE_HPP_INCLUDED 1



#	include "DD_IteratorDifference.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



_DD_DETAIL_BEGIN
template <typename _UndirectionalIteratorT, ValidityType _is_free_access_iterator>
struct _LengthDifference {
	static DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT) _length_difference(
		_UndirectionalIteratorT __begin,
		_UndirectionalIteratorT const& __end
	) DD_NOEXCEPT_IF(noexcept(__begin != __end) && noexcept(++__begin)) {
#	if __cplusplus >= 201103L
		auto _result = IteratorDifference<_UndirectionalIteratorT>();
#	else
		typedef typename IteratorDifference<_UndirectionalIteratorT>::Type _ResultType;
		ResultType _result = ResultType();
#	endif
		for (; __begin != __end; ++__begin) {
			++_result;
		}
		return _result;
	}


};



template <typename _FreeAccessIterator>
struct _LengthDifference<_FreeAccessIterator, true> {
#	if __cplusplus >= 201103L
	static auto _length_difference(_FreeAccessIterator const& __begin, _FreeAccessIterator const& __end) DD_NOEXCEPT_AS(__end - __begin) -> decltype(__end - __begin) {
#	else
	static typename IteratorDifference<_FreeAccessIteratorT>::Type _length_difference(_FreeAccessIterator const& __begin, _FreeAccessIterator const& __end) {
#	endif
		return __end - __begin;
	}


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _UndirectionalIteratorT>
#	if __cplusplus >= 201103L
inline auto length_difference(_UndirectionalIteratorT const& __begin, _UndirectionalIteratorT const& __end) noexcept(
	noexcept(_detail::_LengthDifference<_UndirectionalIteratorT, IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_length_difference(__begin, __end))
) -> decltype(_detail::_LengthDifference<_UndirectionalIteratorT, IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_length_difference(__begin, __end)) {
#	else
typename IteratorDifference<_UndirectionalIteratorT>::Type length_difference(_UndirectionalIteratorT const& __begin, _UndirectionalIteratorT const& __end) {
#	endif
	return _detail::_LengthDifference<_UndirectionalIteratorT, IsFreeAccessIterator<_UndirectionalIteratorT>::value>::_length_difference(__begin, __end);
}



_DD_END



#endif
