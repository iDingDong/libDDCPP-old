//	DDCPP/standard/bits/DD_Multidimention.hpp
#ifndef DD_MULTIDIMENTION_HPP_INCLUDED_
#	define DD_MULTIDIMENTION_HPP_INCLUDED_



#	include "DD_SpecificTypeNested.hpp"
#	include "DD_ConstIterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_Array.hpp"
#	include "DD_Vessel.hpp"
#	include "DD_product.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ValueT_, LengthType dimentions_c_ = 2U, typename ContainerT_ = Vessel<ValueT_>>
#	else
template <typename ValueT_, LengthType dimentions_c_ = 2U, typename ContainerT_ = Vessel<ValueT_>>
#	endif
struct Multidimention {
	public:
	DD_ALIAS(ThisType, Multidimention<ValueT_ DD_COMMA dimentions_c_ DD_COMMA ContainerT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	static LengthType DD_CONSTANT dimentions = dimentions_c_;
	DD_ALIAS(ContainerType, ContainerT_);

	public:
	DD_ALIAS(Iterator, DD_MODIFY_TRAIT(Iterator, ContainerType));
	DD_ALIAS(ConstIterator, DD_MODIFY_TRAIT(ConstIterator, ContainerType));
	DD_ITERATOR_NESTED

	private:
	DD_ALIAS(SideLengthStorageType, Array<LengthType DD_COMMA dimentions - 1U>);


	private:
	SideLengthStorageType m_dimention_offsets_ DD_IN_CLASS_INITIALIZE(SideLengthStorageType());
	ContainerType m_container_;


	public:
	template <LengthType current_dimention_c__>
	struct AccessProxy;


#	if __cplusplus >= 201103L
	public:
	constexpr Multidimention() = default;

	public:
	constexpr Multidimention(ThisType const& origin_) = default;

	public:
	constexpr Multidimention(ThisType&& origin_) = default;
#	else
	public:
	Multidimention() : m_dimention_offsets_() {
	}
#	endif

	public:
	template <typename UndirectionalIteratorT__>
	Multidimention(
		UndirectionalIteratorT__ side_lengths_begin___,
		UndirectionalIteratorT__ side_lengths_end___
	) DD_NOEXCEPT_AS(
		ContainerType(::DD::product(side_lengths_begin___, side_lengths_end___))
	) : m_container_(ContainerType(::DD::product(side_lengths_begin___, side_lengths_end___))) {
		typename SideLengthStorageType::Iterator dimention_offsets_begin__(
			::DD::begin(m_dimention_offsets_)
		);
		*dimention_offsets_begin__ = get_length() / *side_lengths_begin___;
		while (++dimention_offsets_begin__ != ::DD::end(m_dimention_offsets_)) {
			*dimention_offsets_begin__ ==
				*::DD::previous(dimention_offsets_begin__) / *++side_lengths_begin___
			;
		}
	}

#	if __cplusplus >= 201103L
	public:
	template <typename UndirectionalIteratorT__>
	Multidimention(InitializerList<LengthType> initializer_) noexcept(
		noexcept(ThisType(::DD::begin(initializer_), ::DD::end(initializer_)))
	) : Multidimention(::DD::begin(initializer_), ::DD::end(initializer_)) {
	}

#	endif


#	if __cplusplus >= 201103L
	public:
	~Multidimention() = default;


#	endif
	public:
	LengthType DD_CONSTEXPR get_length() const DD_NOEXCEPT {
		return m_container_.get_length();
	}


	private:
	LengthType DD_CONSTEXPR get_dimention_offset_(LengthType dimention_) const DD_NOEXCEPT {
		return dimention_ ?
			(dimention_ < dimentions ? m_dimention_offsets_[dimention_ - 1] : 1U) :
			get_length()
		;
	}


    public:
	LengthType DD_CONSTEXPR get_dimention_length(LengthType dimention_) const DD_NOEXCEPT {
		return get_length() / get_dimention_offset_(dimention_);
	}


};



template <typename ValueT_, typename ContainerT_>
struct Multidimention<ValueT_, 1U, ContainerT_> {
};



template <typename ValueT_, typename ContainerT_>
struct Multidimention<ValueT_, 0U, ContainerT_> {
};



template <typename ValueT_, LengthType dimentions_c_, typename ContainerT_>
template <LengthType current_dimention_c_>
struct Multidimention<ValueT_, dimentions_c_, ContainerT_>::AccessProxy {
	public:
	DD_ALIAS(ThisType, Multidimention<
		ValueT_ DD_COMMA dimentions_c_ DD_COMMA ContainerT_
	>::AccessProxy<current_dimention_c_>);
	DD_SPECIFIC_TYPE_NESTED(
		Multidimention,
		Multidimention<ValueT_ DD_COMMA dimentions_c_ DD_COMMA ContainerT_>
	);
	DD_SPECIFIC_TYPE_NESTED(Position, typename Multidimention::Iterator)

	public:
	DD_ALIAS(NextDimentionProxy, Multidimention<
		ValueT_ DD_COMMA dimentions_c_ DD_COMMA ContainerT_
	>::AccessProxy<current_dimention_c_ + 1U>);


	private:
	MultidimentionPointerType const m_pointer_;
	PositionType const m_position_;


	public:
	DD_CONSTEXPR AccessProxy(
		MultidimentionPointerType pointer_, PositionType current_index_
	) DD_NOEXCEPT : m_pointer_(pointer_), m_position_(current_index_) {
	}


    public:
	NextDimentionProxy DD_CONSTEXPR operator [](LengthType index_c_) const DD_NOEXCEPT {
		return NextDimentionProxy(
			m_pointer_,
			m_position_ + index_c_ * m_pointer_->get_dimention_offset_(current_dimention_c_)
		);
	}


};



template <typename ValueT_, LengthType dimentions_c_, typename ContainerT_>
template <>
struct Multidimention<ValueT_, dimentions_c_, ContainerT_>::AccessProxy<dimentions_c_ - 1U> {
	public:
	DD_ALIAS(ThisType, Multidimention<
		ValueT_ DD_COMMA dimentions_c_ DD_COMMA ContainerT_
	>::AccessProxy<current_dimention_c_>);
	DD_SPECIFIC_TYPE_NESTED(
		Multidimention,
		Multidimention<ValueT_ DD_COMMA dimentions_c_ DD_COMMA ContainerT_>
	);
	DD_SPECIFIC_TYPE_NESTED(Position, typename MultidimentionType::Iterator);

	public:
	DD_VALUE_TYPE_NESTED(ValueT_)


	private:
	MultidimentionPointerType const m_pointer_;
	PositionType const m_position_;


	public:
	DD_CONSTEXPR AccessProxy(
		MultidimentionPointerType pointer_, PositionType current_index_
	) DD_NOEXCEPT : m_pointer_(pointer_), m_position_(current_index_) {
	}


    public:
	ReferenceType DD_CONSTEXPR operator [](LengthType index_c_) const DD_NOEXCEPT {
		return *(m_position_ + index_c_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Multidimention;



DD_END_



#endif
