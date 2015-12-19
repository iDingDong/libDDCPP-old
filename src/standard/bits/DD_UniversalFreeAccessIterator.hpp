//	DDCPP/standard/bits/DD_UniversalFreeAccessIterator.hpp
#ifndef DD_UNIVERSAL_FREE_ACCESS_ITERATOR_HPP_HPP_
#	define DD_UNIVERSAL_FREE_ACCESS_ITERATOR_HPP_HPP_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_SpecificTypeNested.hpp"
#	include "DD_Conditional.hpp"
#	include "DD_Value.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_Comparable.hpp"
#	include "DD_BinaryOperators.hpp"
#	include "DD_address_of.hpp"



DD_DETAIL_BEGIN_
template <typename ContainerT_, ValidityType const_qualified_c_ = false>
struct UniversalFreeAccessIterator :
#	if __cplusplus >= 201103L
	Comparable<UniversalFreeAccessIterator<ContainerT_, const_qualified_c_>>,
#	else
	Comparable<UniversalFreeAccessIterator<ContainerT_, const_qualified_c_> >,
#	endif
	Addable<UniversalFreeAccessIterator<ContainerT_, const_qualified_c_>, DifferenceType>,
	Subtractable<UniversalFreeAccessIterator<ContainerT_, const_qualified_c_>, DifferenceType>
{
	public:
	DD_ALIAS(ThisType, UniversalFreeAccessIterator<ContainerT_ DD_COMMA const_qualified_c_>);
	private:
#	if __cplusplus >= 201103L
	DD_ALIAS(ContainerType_, ConditionalType<const_qualified_c_ DD_COMMA ContainerT_ const DD_COMMA ContainerT_>);
#	else
	DD_ALIAS(ContainerType_, typename Conditional<const_qualified_c_ DD_COMMA ContainerT_ const DD_COMMA ContainerT_>::Type);
#	endif
	public:
	DD_SPECIFIC_TYPE_NESTED(Container, ContainerType_)

	public:
	DD_VALUE_TYPE_NESTED(
#	if __cplusplus >= 201103L
		ConditionalType<const_qualified_c_ DD_COMMA DD_MODIFY_TRAIT(Value, ContainerType) const DD_COMMA DD_MODIFY_TRAIT(Value, ContainerType)>
#	else
		typename Conditional<const_qualified_c_ DD_COMMA DD_MODIFY_TRAIT(Value, ContainerType) const DD_COMMA DD_MODIFY_TRAIT(Value, ContainerType)>::Type
#	endif
	)

	public:
	DD_ALIAS(DifferenceType, ::DD::DifferenceType);
	DD_ALIAS(CatagoryType, FreeAccessIterator);


	private:
	ContainerPointerType m_target_ DD_IN_CLASS_INITIALIZE(ContainerPointerType());
	DifferenceType m_index_;


	public:
#	if __cplusplus >= 201103L
	constexpr UniversalFreeAccessIterator() = default;

	constexpr UniversalFreeAccessIterator(ThisType const& origin_) = default;

	constexpr UniversalFreeAccessIterator(ThisType&& origin_) = default;
#	else
	UniversalFreeAccessIterator() : m_target_() {
	}
#	endif

	public:
	template <typename ContainerT__>
	DD_CONSTEXPR UniversalFreeAccessIterator(
		UniversalFreeAccessIterator<ContainerT__, const_qualified_c_> const& origin_
	) : m_target_(::DD::address_of(static_cast<ContainerReferenceType>(origin_.get_container()))), m_index_(origin_.get_index()) {
	}

	public:
	DD_CONSTEXPR UniversalFreeAccessIterator(
		ContainerReferenceType container_,
		DifferenceType index_
	) DD_NOEXCEPT : m_target_(::DD::address_of(container_)), m_index_(index_) {
	}


	public:
	ContainerReferenceType DD_CONSTEXPR get_container() const DD_NOEXCEPT {
		return *m_target_;
	}


	public:
	DifferenceType DD_CONSTEXPR get_index() const DD_NOEXCEPT {
		return m_index_;
	}


	public:
	PointerType DD_CONSTEXPR unguarded_get_pointer() const DD_NOEXCEPT {
		return ::DD::address_of(get_container()[get_index()]);
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return is_valid() ? unguarded_get_pointer() : PointerType();
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return m_target_;
	}


	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& other_) const DD_NOEXCEPT {
		return get_index() == other_.get_index();
	}


	public:
	ValidityType DD_CONSTEXPR less(ThisType const& other_) const DD_NOEXCEPT {
		return get_index() < other_.get_index();
	}


	public:
	DifferenceType DD_CONSTEXPR difference(ThisType const& other_) const DD_NOEXCEPT {
		return other_.get_index() - get_index();
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
	public:
	ThisType& operator ++() DD_NOEXCEPT {
		++m_index_;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_NOEXCEPT {
		ThisType result_(*this);
		++*this;
		return result_;
	}


	public:
	ThisType& operator --() DD_NOEXCEPT {
		--m_index_;
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT {
		ThisType result_(*this);
		--*this;
		return result_;
	}


	public:
	ThisType& operator +=(DifferenceType step_) DD_NOEXCEPT {
		m_index_ += step_;
		return *this;
	}


	public:
	ThisType& operator -=(DifferenceType step_) DD_NOEXCEPT {
		m_index_ -= step_;
		return *this;
	}


	public:
	ReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return *unguarded_get_pointer();
	}


	public:
	PointerType DD_CONSTEXPR operator ->() const DD_NOEXCEPT {
		return unguarded_get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename ContainerT_, ValidityType const_qualified_c_>
inline ValidityType DD_CONSTEXPR operator ==(
	UniversalFreeAccessIterator<ContainerT_, const_qualified_c_> const& iterator_1_,
	UniversalFreeAccessIterator<ContainerT_, const_qualified_c_> const& iterator_2_
) {
	return iterator_1_.equal(iterator_2_);
}


template <typename ContainerT_, ValidityType const_qualified_c_>
inline ValidityType DD_CONSTEXPR operator <(
	UniversalFreeAccessIterator<ContainerT_, const_qualified_c_> const& iterator_1_,
	UniversalFreeAccessIterator<ContainerT_, const_qualified_c_> const& iterator_2_
) {
	return iterator_1_.less(iterator_2_);
}


template <typename ContainerT_, ValidityType const_qualified_c_>
inline typename UniversalFreeAccessIterator<ContainerT_>::DifferenceType DD_CONSTEXPR operator -(
	UniversalFreeAccessIterator<ContainerT_, const_qualified_c_> const& iterator_1_,
	UniversalFreeAccessIterator<ContainerT_, const_qualified_c_> const& iterator_2_
) {
	return iterator_2_.difference(iterator_1_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::UniversalFreeAccessIterator;



DD_END_



#endif
