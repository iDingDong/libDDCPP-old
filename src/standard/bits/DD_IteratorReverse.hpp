//	DDCPP/standard/bits/DD_IteratorReverse.hpp
#ifndef DD_ITERATOR_REVERSE_HPP_INCLUDED_
#	define DD_ITERATOR_REVERSE_HPP_INCLUDED_



#	include "DD_CompatStlIterator.hpp"
#	include "DD_NestedTypeCheck.hpp"
#	include "DD_Or.hpp"
#	include "DD_IsSame.hpp"
#	include "DD_Comparable.hpp"
#	include "DD_BinaryOperators.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_relationship_operators.hpp"
#	include "DD_IteratorReference.hpp"
#	include "DD_IteratorPointer.hpp"
#	include "DD_IteratorDifference.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_address_of.hpp"



DD_DETAIL_BEGIN_
template <typename IteratorT_>
struct ReverseIterator_ :
#	if __cplusplus >= 201103L
	Comparable<ReverseIterator_<IteratorT_>>,
#	else
	Comparable<ReverseIterator_<IteratorT_> >,
#	endif
	Addable<ReverseIterator_<IteratorT_>, DD_MODIFY_TRAIT(IteratorDifference, IteratorT_)>,
	Subtractable<ReverseIterator_<IteratorT_>, DD_MODIFY_TRAIT(IteratorDifference, IteratorT_)>
{
	public:
	DD_ALIAS(ThisType, ReverseIterator_<IteratorT_>);
	DD_ALIAS(ReverseType, IteratorT_);

	public:
	DD_ALIAS(ValueType, typename IteratorValue<ReverseType>::Type);
	DD_ALIAS(ReferenceType, typename IteratorReference<ReverseType>::Type);
	DD_ALIAS(PointerType, typename IteratorPointer<ReverseType>::Type);
	DD_ALIAS(DifferenceType, typename IteratorDifference<ReverseType>::Type);
	DD_ALIAS(CatagoryType, typename IteratorCatagory<ReverseType>::Type);
	DD_COMPAT_STL_ITERATOR


	private:
#	if __cplusplus >= 201103L
	ReverseType m_iterator_ = ReverseType();
#	else
	ReverseType m_iterator_;
#	endif


	public:
#	if __cplusplus >= 201103L
	constexpr ReverseIterator_() noexcept(noexcept(ReverseType())) = default;

	public:
	constexpr ReverseIterator_(ThisType const& origin_) = default;

	public:
	constexpr ReverseIterator_(ThisType&& origin_) = default;
#	else
	ReverseIterator_() : m_iterator_() {
	}
#	endif

	public:
	DD_CONSTEXPR ReverseIterator_(ReverseType const& iterator_) DD_NOEXCEPT_AS(ReverseType(iterator_)) : m_iterator_(iterator_) {
	}

	public:
#	if __cplusplus >= 201103L
	template <typename... ArgumentsT_>
	constexpr ReverseIterator_(ArgumentsT_ const&... arguments__) noexcept(noexcept(ReverseType(arguments__...))) : m_iterator_(arguments__...) {
#	else
	template <typename ArgumentT_>
	ReverseIterator_(ArgumentT_ const& argument__) : m_iterator_(argument__) {
#	endif
	}// Global reference doesn't work here. See test2.cpp


#	if __cplusplus >= 201103L
	public:
	~ReverseIterator_() noexcept(noexcept(m_iterator_.~ReverseType())) = default;


#	endif
	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& target_) const DD_NOEXCEPT_AS(m_iterator_ == target_.m_iterator_) {
		return this->m_iterator_ == target_.m_iterator_;
	}


	public:
	ValidityType DD_CONSTEXPR less(ThisType const& target_) const DD_NOEXCEPT_AS(target_.m_iterator_ < m_iterator_) {
		return target_.m_iterator_ < this->m_iterator_;
	}


	public:
	DifferenceType DD_CONSTEXPR difference(ThisType const& target_) const DD_NOEXCEPT_AS(target_.m_iterator_ - m_iterator_) {
		return target_.m_iterator_ - this->m_iterator_;
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT_AS(address_of(*m_iterator_)) {
		return address_of(*this->m_iterator_);
	}


	public:
	ReverseType DD_CONSTEXPR reverse() const DD_NOEXCEPT_AS(ReverseType(m_iterator_)) {
		return m_iterator_;
	}



#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;

#	endif
	public:
	ThisType& operator =(ReverseType const& iterator_) DD_NOEXCEPT_AS(m_iterator_ = iterator_) {
		this->m_iterator_ = iterator_;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ReverseType&& iterator_) DD_NOEXCEPT_AS(m_iterator_ = move(iterator_)) {
		this->m_iterator_ = move(iterator_);
	}

#	endif
	public:
	template <typename ArgumentT_>
	ThisType& operator =(ArgumentT_ const& argument__) DD_NOEXCEPT_AS(m_iterator_ = argument__) {
		this->m_iterator_ = argument__;
	}// Global reference doesn't work here. See test2.cpp


	public:
	ThisType& operator ++() DD_NOEXCEPT_AS(--m_iterator_) {
		--this->m_iterator_;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_NOEXCEPT_AS(m_iterator_--) {
		return ThisType(m_iterator_--);
	}


	public:
	ThisType& operator --() DD_NOEXCEPT_AS(++m_iterator_) {
		++this->m_iterator_;
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT_AS(m_iterator_++) {
		return ThisType(m_iterator_++);
	}


	public:
	ThisType& operator +=(DifferenceType step_) DD_NOEXCEPT_AS(m_iterator_ -= step_) {
		this->m_iterator_ -= step_;
		return *this;
	}


	public:
	ThisType& operator -=(DifferenceType step_) DD_NOEXCEPT_AS(m_iterator_ += step_) {
		this->m_iterator_ += step_;
		return *this;
	}


	public:
	ReferenceType operator [](DifferenceType index_) const DD_NOEXCEPT_AS(m_iterator_[-index_]) {
		return this->m_iterator_[-index_];
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT_AS(*m_iterator_) {
		return *this->m_iterator_;
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT_AS(get_pointer()) {
		return this->get_pointer();
	}


};



template <typename IteratorT_>
inline ValidityType DD_CONSTEXPR operator ==(
	ReverseIterator_<IteratorT_> const& reverse_iterator_1__,
	ReverseIterator_<IteratorT_> const& reverse_iterator_2__
) DD_NOEXCEPT_AS(reverse_iterator_1__.equal(reverse_iterator_2__)) {
	return reverse_iterator_1__.equal(reverse_iterator_2__);
}


template <typename IteratorT_>
inline ValidityType DD_CONSTEXPR operator <(
	ReverseIterator_<IteratorT_> const& reverse_iterator_1__,
	ReverseIterator_<IteratorT_> const& reverse_iterator_2__
) DD_NOEXCEPT_AS(reverse_iterator_1__.less(reverse_iterator_2__)) {
	return reverse_iterator_1__.less(reverse_iterator_2__);
}


template <typename IteratorT_>
inline typename ReverseIterator_<IteratorT_>::DifferenceType operator -(
	ReverseIterator_<IteratorT_> const& reverse_iterator_1__,
	ReverseIterator_<IteratorT_> const& reverse_iterator_2__
) DD_NOEXCEPT_AS(static_cast<typename ReverseIterator_<IteratorT_>::DifferenceType>(
	reverse_iterator_2__.reverse() - reverse_iterator_1__.reverse()
)) {
	return reverse_iterator_2__.reverse() - reverse_iterator_1__.reverse();
}



DD_DETAIL_END_



DD_BEGIN_
DD_NESTED_TYPE_TRAIT(IteratorReverse, ReverseType, detail_::ReverseIterator_<MACRO_ObjectT_>)



#	if __cplusplus >= 201103L
template <typename IteratorT_>
using IteratorReverseType = typename IteratorReverse<IteratorT_>::Type;



#	endif
DD_END_



#endif
