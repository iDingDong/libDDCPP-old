//	DDCPP/standard/bits/DD_Range.hpp
#ifndef DD_RANGE_HPP_INCLUDED_
#	define DD_RANGE_HPP_INCLUDED_ 1



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
#		define DD_SPLIT_RANGE(...) ::DD::detail_::begin(__VA_ARGS__), ::DD::detail_::end(__VA_ARGS__)
#	else
#		define DD_SPLIT_RANGE(ARG_range_) ::DD::begin(range__), ::DD::end(range__)
#	endif

#	define DD_RANGE_NESTED\
	ConstIterator cbegin() const DD_NOEXCEPT_AS(ThisType().begin()) {\
		return begin();\
	}\
	\
	\
	ConstIterator cend() const DD_NOEXCEPT_AS(ThisType().end()) {\
		return end();\
	}
#	define DD_REVERSE_RANGE_NESTED\
	ReverseIterator crbegin() const DD_NOEXCEPT_AS(ThisType().rbegin()) {\
		return rbegin();\
	}\
	\
	\
	ReverseIterator crend() const DD_NOEXCEPT_AS(ThisType().rend()) {\
		return rend();\
	}



DD_DETAIL_BEGIN_
template <typename RangeT_>
#	if __cplusplus >= 201402L
auto begin(RangeT_& range__) noexcept(noexcept(range__.begin())) {
#	elif __cplusplus >= 201103L
auto begin(RangeT_& range__) noexcept(noexcept(range__.begin())) ->decltype(range__.begin()) {
#	else
typename Iterator<RangeT_>::Type begin(RangeT_& range__) {
#	endif
	return range__.begin();
}

template <typename RangeT_>
#	if __cplusplus >= 201402L
auto begin(RangeT_ const& range__) noexcept(noexcept(range__.begin())) {
#	elif __cplusplus >= 201103L
auto begin(RangeT_ const& range__) noexcept(noexcept(range__.begin())) ->decltype(range__.begin()) {
#	else
typename Iterator<RangeT_>::Type begin(RangeT_ const& range__) {
#	endif
	return range__.begin();
}

template <typename ValueT_, LengthType length_c_>
#	if __cplusplus >= 201103L
ValueT_ constexpr* begin(ArrayType<ValueT_, length_c_>& array_) noexcept {
#	else
ValueT_* begin(ValueT_ (&array_)[length_c_]) throw() {
#	endif
	return array_;
}


template <typename RangeT_>
#	if __cplusplus >= 201402L
auto end(RangeT_& range__) noexcept(noexcept(range__.end())) {
#	elif __cplusplus >= 201103L
auto end(RangeT_& range__) noexcept(noexcept(range__.end())) ->decltype(range__.end()) {
#	else
typename Iterator<RangeT_>::Type end(RangeT_& range__) {
#	endif
	return range__.end();
}

template <typename RangeT_>
#	if __cplusplus >= 201402L
auto end(RangeT_ const& range__) noexcept(noexcept(range__.end())) {
#	elif __cplusplus >= 201103L
auto end(RangeT_ const& range__) noexcept(noexcept(range__.end())) ->decltype(range__.end()) {
#	else
typename Iterator<RangeT_>::Type end(RangeT_ const& range__) {
#	endif
	return range__.end();
}

template <typename ValueT_, LengthType length_c_>
#	if cplusplus_ >= 201103L
ValueT_ constexpr* end(ArrayType<ValueT_, length_c_>& array_) noexcept {
#	else
ValueT_* end(ValueT_ (&array_)[length_c_]) throw() {
#	endif
	return array_ + length_c_;
}



template <typename IteratorT_>
struct Range {
	public:
	DD_ALIAS(ThisType, Range<IteratorT_>);
	DD_ALIAS(Iterator, IteratorT_);

	DD_ALIAS(ReverseIterator, IteratorReverse<Iterator>);


	private:
	Pair<Iterator> m_range_;


#	if __cplusplus >= 201103L
	public:
	constexpr Range() = default;

	public:
	constexpr Range(ThisType const& origin_) = default;

	public:
	constexpr Range(ThisType&& origin_) = default;

	public:
	template <typename IteratorT1__, typename IteratorT2__>
	constexpr Range(IteratorT1__&& begin___, IteratorT2__&& end___) noexcept(
		noexcept(Iterator(begin___)) && noexcept(Iterator(end___))
	) : m_range_(forward<IteratorT1__>(begin___), forward<IteratorT2__>(end___)) {
	}
#	else
	public:
	Range() : m_range_() {
	}

	public:
	template <typename IteratorT1__, typename IteratorT2__>
	Range(IteratorT1__ const& begin___, IteratorT2__ const& end__) : m_range_(begin___, end___) {
	}
#	endif

	public:
	template <typename RangeT__>
	Range(RangeT__ const& range___) DD_NOEXCEPT_AS(
		Pair<Iterator>(DD_SPLIT_RANGE(range___))
	) : m_range_(DD_SPLIT_RANGE(range___)) {
	}


#	if __cplusplus >= 201103L
	public:
	~Range() = default;


#	endif
	public:
	Iterator const& begin() const DD_NOEXCEPT {
		return m_range_.first;
	}


	public:
	Iterator const& end() const DD_NOEXCEPT {
		return m_range_.second;
	}


	public:
	ReverseIterator rbegin() const DD_NOEXCEPT_AS(
		ReverseIterator(++const_cast<ReverseIterator&>(ReverseIterator(m_range_.second)))
	) {
		ReverseIterator temp_(m_range_.second);
		return ++temp_;
	}

	public:
	ReverseIterator rend() const DD_NOEXCEPT_AS(
		ReverseIterator(++const_cast<ReverseIterator&>(ReverseIterator(m_range_.first)))
	) {
		ReverseIterator temp_(m_range_.first);
		return ++temp_;
	}


};



template <typename IteratorT_>
Range<IteratorT_> make_range(IteratorT_ const& begin__, IteratorT_ const& end__) DD_NOEXCEPT_AS(Range<IteratorT_>(begin__, end__)) {
	return Range<IteratorT_>(begin__, end__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::Range;

using detail_::begin;
using detail_::end;
using detail_::make_range;



DD_END_



#endif
