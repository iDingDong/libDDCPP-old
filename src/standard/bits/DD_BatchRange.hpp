//	DDCPP/standard/bits/DD_BatchRange.hpp
#ifndef DD_BATCH_RANGE_HPP_INCLUDED_
#	define DD_BATCH_RANGE_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_RemoveConst.hpp"
#	include "DD_Comparable.hpp"
#	include "DD_BinaryOperators.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_address_of.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct BatchIterator :
#	if __cplusplus >= 201103L
	Comparable<BatchIterator<ValueT_>>,
#	else
	Comparable<BatchIterator<ValueT_> >,
#	endif
	Addable<BatchIterator<ValueT_>, DifferenceType>,
	Subtractable<BatchIterator<ValueT_>, DifferenceType>
{
	public:
	DD_ALIAS(ThisType, BatchIterator<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(DifferenceType, ::DD::DifferenceType);
	DD_ALIAS(CatagoryType, FreeAccessIterator);


	private:
	PointerType m_target_ DD_IN_CLASS_INITIALIZE(PointerType());
	DifferenceType m_offset_ DD_IN_CLASS_INITIALIZE(DifferenceType());


#	if __cplusplus >= 201103L
	public:
	constexpr BatchIterator() = default;

	public:
	constexpr BatchIterator(ThisType const& origin_) = default;

	public:
	constexpr BatchIterator(ThisType&& origin_) = default;
#	else
	public:
	BatchIterator() {
	}
#	endif

	public:
	DD_CONSTEXPR BatchIterator(
		ReferenceType target_,
		DifferenceType offset_ = DifferenceType()
	) DD_NOEXCEPT : m_target_(::DD::address_of(target_)), m_offset_(offset_) {
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return m_target_;
	}


	public:
	DifferenceType DD_CONSTEXPR get_offset() const DD_NOEXCEPT {
		return m_offset_;
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& other_) const DD_NOEXCEPT {
		return get_offset() == other_.get_offset();
	}


	public:
	ValidityType DD_CONSTEXPR less(ThisType const& other_) const DD_NOEXCEPT {
		return get_offset() < other_.get_offset();
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
	public:
	ThisType& operator ++() DD_NOEXCEPT {
		++m_offset_;
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
		--m_offset_;
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT {
		ThisType result_(*this);
		--*this;
		return result_;
	}


	public:
	ReferenceType operator *() DD_NOEXCEPT {
		return *get_pointer();
	}


	public:
	PointerType operator ->() DD_NOEXCEPT {
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit constexpr operator ValidityType() const noexcept {
		return is_valid();
	}


#	endif
};



template <typename ValueT_>
struct BatchRange {
	public:
	DD_ALIAS(ThisType, BatchRange<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, ::DD::LengthType);

	public:
	DD_ALIAS(Iterator, BatchIterator<ValueType>);
	DD_ALIAS(ConstIterator, BatchIterator<ValueConstType>);
	DD_ITERATOR_NESTED


	public:
	ValueType value;
	LengthType length;


	public:
	Iterator DD_CONSTEXPR begin() DD_NOEXCEPT_AS(Iterator(value)) {
		return Iterator(value);
	}

	public:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT_AS(Iterator(value)) {
		return ConstIterator(value);
	}


	public:
	Iterator DD_CONSTEXPR end() DD_NOEXCEPT_AS(Iterator(value, length)) {
		return Iterator(value, length);
	}

	public:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT_AS(Iterator(value, length)) {
		return ConstIterator(value, length);
	}


};



template <typename ValueT_>
ValidityType DD_CONSTEXPR operator ==(
	BatchIterator<ValueT_> const& iterator_1_,
	BatchIterator<ValueT_> const& iterator_2_
) DD_NOEXCEPT_AS(static_cast<ValidityType>(iterator_1_.equal(iterator_2_))) {
	return iterator_1_.equal(iterator_2_);
}


template <typename ValueT_>
ValidityType DD_CONSTEXPR operator <(
	BatchIterator<ValueT_> const& iterator_1_,
	BatchIterator<ValueT_> const& iterator_2_
) DD_NOEXCEPT_AS(static_cast<ValidityType>(iterator_1_.less(iterator_2_))) {
	return iterator_1_.less(iterator_2_);
}



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
