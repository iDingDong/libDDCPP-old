//	standard/bits/DD_Range.hpp
#ifndef _DD_RANGE_HPP_INCLUDED
#	define _DD_RANGE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_IteratorReverse.hpp"
#	include "DD_Pair.hpp"



DD_BEGIN
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



DD_END



#endif
