//	DDCPP/standard/bits/DD_Range.hpp
#ifndef _DD_RANGE_HPP_INCLUDED
#	define _DD_RANGE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	else
#		include "DD_Iterator.hpp"
#	endif
#	include "DD_IteratorReverse.hpp"
#	include "DD_Pair.hpp"



#	if !defined(DDCPP_CONSIDER_CSTRING_AS_RANGE)
#		define DDCPP_CONSIDER_CSTRING_AS_RANGE DD_OFF
#	endif



#	if __cplusplus >= 201103L
#		define DD_SPLIT_RANGE(...) ::DD::begin(__VA_ARGS__), ::DD::end(__VA_ARGS__)
#	else
#		define DD_SPLIT_RANGE(_ARG_range) ::DD::begin(__range), ::DD::end(__range)
#	endif



_DD_BEGIN
template <typename _RangeT>
#	if __cplusplus >= 201402L
auto begin(_RangeT& __range) noexcept(noexcept(__range.begin())) {
#	elif __cplusplus >= 201103L
auto begin(_RangeT& __range) noexcept(noexcept(__range.begin())) ->decltype(__range.begin()) {
#	else
typename Iterator<_RangeT>::Type begin(_RangeT& __range) {
#	endif
	return __range.begin();
}

template <typename _RangeT>
#	if __cplusplus >= 201402L
auto begin(_RangeT const& __range) noexcept(noexcept(__range.begin())) {
#	elif __cplusplus >= 201103L
auto begin(_RangeT const& __range) noexcept(noexcept(__range.begin())) ->decltype(__range.begin()) {
#	else
typename Iterator<_RangeT>::Type begin(_RangeT const& __range) {
#	endif
	return __range.begin();
}

template <typename _ValueT, LengthType _length_c>
#	if __cplusplus >= 201103L
_ValueT constexpr* begin(ArrayType<_ValueT, _length_c>& _array) noexcept {
#	else
_ValueT* begin(_ValueT (&_array)[_length_c]) throw() {
#	endif
	return _array;
}


template <typename _RangeT>
#	if __cplusplus >= 201402L
auto end(_RangeT& __range) noexcept(noexcept(__range.end())) {
#	elif __cplusplus >= 201103L
auto end(_RangeT& __range) noexcept(noexcept(__range.end())) ->decltype(__range.end()) {
#	else
typename Iterator<_RangeT>::Type end(_RangeT& __range) {
#	endif
	return __range.end();
}

template <typename _RangeT>
#	if __cplusplus >= 201402L
auto end(_RangeT const& __range) noexcept(noexcept(__range.end())) {
#	elif __cplusplus >= 201103L
auto end(_RangeT const& __range) noexcept(noexcept(__range.end())) ->decltype(__range.end()) {
#	else
typename Iterator<_RangeT>::Type end(_RangeT const& __range) {
#	endif
	return __range.end();
}

template <typename _ValueT, LengthType _length_c>
#	if _cplusplus >= 201103L
_ValueT constexpr* end(ArrayType<_ValueT, _length_c>& _array) noexcept {
#	else
_ValueT* end(_ValueT (&_array)[_length_c]) throw() {
#	endif
	return _array + _length_c;
}



template <typename _IteratorT>
struct Range {
	public:
	DD_ALIAS(ThisType, Range<_IteratorT>)
	DD_ALIAS(Iterator, _IteratorT)

	DD_ALIAS(ReverseIterator, IteratorReverse<Iterator>)


	private:
	Pair<Iterator> _m_range;


#	if __cplusplus >= 201103L
	public:
	constexpr Range() = default;

	public:
	constexpr Range(ThisType const& _origin) = default;

	public:
	constexpr Range(ThisType&& _origin) = default;

	public:
	template <typename _IteratorT1_, typename _IteratorT2_>
	constexpr Range(_IteratorT1_&& __begin_, _IteratorT2_&& __end_) noexcept(
		noexcept(Iterator(__begin_)) && noexcept(Iterator(__end_))
	) : _m_range(forward<_IteratorT1_>(__begin_), forward<_IteratorT2_>(__end_)) {
	}
#	else
	public:
	Range() : _m_range() {
	}

	public:
	template <typename _IteratorT1_, typename _IteratorT2_>
	Range(_IteratorT1_ const& __begin_, _IteratorT2_ const& __end) : _m_range(__begin_, __end_) {
	}
#	endif

	public:
	template <typename _RangeT_>
	Range(_RangeT_ const& __range_) DD_NOEXCEPT_AS(
		Pair<Iterator>(DD_SPLIT_RANGE(__range_))
	) : _m_range(DD_SPLIT_RANGE(__range_)) {
	}


#	if __cplusplus >= 201103L
	public:
	~Range() = default;


#	endif
	public:
	Iterator const& begin() const DD_NOEXCEPT {
		return _m_range.first;
	}


	public:
	Iterator const& end() const DD_NOEXCEPT {
		return _m_range.second;
	}


	public:
	ReverseIterator rbegin() const DD_NOEXCEPT_AS(
		ReverseIterator(++const_cast<ReverseIterator&>(ReverseIterator(_m_range.second)))
	) {
		ReverseIterator _temp(_m_range.second);
		return ++_temp;
	}

	public:
	ReverseIterator rend() const DD_NOEXCEPT_AS(
		ReverseIterator(++const_cast<ReverseIterator&>(ReverseIterator(_m_range.first)))
	) {
		ReverseIterator _temp(_m_range.first);
		return ++_temp;
	}


};



_DD_END



#endif
