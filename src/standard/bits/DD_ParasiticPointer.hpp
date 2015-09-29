//	DDCPP/standard/bits/DD_ParasiticPointer.hpp
#ifndef DD_INTRUSIVE_POINTER_HPP_INCLUDED_
#	define DD_INTRUSIVE_POINTER_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_Tags.hpp"
#	include "DD_Comparable.hpp"
#	include "DD_address_of.hpp"
#	include "DD_release.hpp"
#	include "DD_Pair.hpp"



DD_BEGIN_
template <typename ValueT_, typename DeleterT_ = DefaultTag>
struct ParasiticPointer : Comparable<ParasiticPointer<ValueT_, DeleterT_>> {
};



template <typename ValueT_>
struct ParasiticPointer<ValueT_, DefaultTag> : Comparable<ParasiticPointer<ValueT_, DefaultTag>> {
	public:
	DD_ALIAS(ThisType, ParasiticPointer<ValueT_ DD_COMMA DefaultTag>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(DeleterType, void);

	public:
	DD_ALIAS(ParasitiferValueType, Pair<LengthType DD_COMMA ValueType>);
	DD_ALIAS(ParasitiferReferenceType, ParasitiferValueType&);
	DD_ALIAS(ParasitiferConstReferenceType, ParasitiferValueType const&);
	DD_ALIAS(ParasitiferPointerType, ParasitiferValueType*);
	DD_ALIAS(ParasitiferConstPointerType, ParasitiferValueType const*);


	private:
	ParasitiferPointerType m_pointer_ DD_IN_CLASS_INITIALIZE(ParasitiferPointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr ParasiticPointer() = default;
#	else
	ParasiticPointer() throw() : m_pointer_() {
	}
#	endif

	public:
	DD_CONSTEXPR ParasiticPointer(ThisType const& origin_) DD_NOEXCEPT : m_pointer_(
		origin_.is_valid() ? (++origin_.m_pointer_->first, origin_.m_pointer_) : ParasitiferPointerType()
	) {
	}

#	if __cplusplus >= 201103L
	public:
	ParasiticPointer(ThisType&& origin_) noexcept : m_pointer_(release(origin_.m_pointer_)) {
	}

#	endif
	public:
	explicit DD_CONSTEXPR ParasiticPointer(
		ParasitiferPointerType parasitifer_target_
	) DD_NOEXCEPT : m_pointer_(parasitifer_target_ ? (++parasitifer_target_->first, parasitifer_target_) : ParasitiferPointerType()) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	explicit constexpr ParasiticPointer(
		ConstructTag tag_,
		ArgumentsT__&&... arguments___
	) noexcept(
		noexcept(new ParasitiferValueType(1 DD_COMMA ValueType(arguments___...)))
	) : m_pointer_(new ParasitiferValueType(1, ValueType(arguments___...))) {
	};
#	else
	public:
	explicit ParasiticPointer(ConstructTag tag_) : m_pointer_(new ParasitiferValueType()) {
	}
#	endif


	public:
	~ParasiticPointer() DD_NOEXCEPT {
		unrefer();
	}


	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return m_pointer_ ? PointerType() : address_of(m_pointer_->second);
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return m_pointer_;
	}


	private:
	ProcessType unrefer() DD_NOEXCEPT {
		if (m_pointer_) {
			if (m_pointer_->first > 1) {
				--m_pointer_->first;
			} else {
				DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
				delete m_pointer_;
			}
		}
	}


	public:
	ProcessType swap(ThisType& target_) {
		using DD::swap;
		DD::swap(m_pointer_, target_.m_pointer_);
	}


	public:
	ParasitiferReferenceType get_parasitifer() DD_NOEXCEPT {
		return *m_pointer_;
	}


	public:
	ParasitiferConstReferenceType get_parasitifer() const DD_NOEXCEPT {
		return *m_pointer_;
	}


	public:
	LengthType get_reference_count() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::ParasiticPointer::get_reference_count' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return m_pointer_->first;
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT {
		ThisType temp_(origin_);
		swap(temp_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept {
		swap(origin_);
		return *this;
	}

#	endif

	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::ParasiticPointer::operator *' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::ParasiticPointer::operator ->' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return get_pointer();
	}


	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


};



template <typename ValueT_, typename DeleterT_>
inline ValidityType DD_CONSTEXPR operator ==(
	ParasiticPointer<ValueT_, DeleterT_> const& parasitic_pointer_1__,
	ParasiticPointer<ValueT_, DeleterT_> const& parasitic_pointer_2__
) noexcept(noexcept(static_cast<ValidityType>(parasitic_pointer_1__.get_pointer() == parasitic_pointer_2__.get_pointer()))) {
	return parasitic_pointer_1__.get_pointer() == parasitic_pointer_2__.get_pointer();
}



template <typename ValueT_, typename DeleterT_>
inline ValidityType DD_CONSTEXPR operator <(
	ParasiticPointer<ValueT_, DeleterT_> const& parasitic_pointer_1__,
	ParasiticPointer<ValueT_, DeleterT_> const& parasitic_pointer_2__
) noexcept(noexcept(static_cast<ValidityType>(parasitic_pointer_1__.get_pointer() < parasitic_pointer_2__.get_pointer()))) {
	return parasitic_pointer_1__.get_pointer() < parasitic_pointer_2__.get_pointer();
}



DD_END_



#endif
