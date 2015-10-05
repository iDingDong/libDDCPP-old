//	DDCPP/standard/bits/DD_StrictParasiticPointer.hpp
#ifndef DD_STRICT_PARASITIC_POINTER_HPP_INCLUDED_
#	define DD_STRICT_PARASITIC_POINTER_HPP_INCLUDED_ 1



#	include "DD_fabricate.hpp"
#	include "DD_Parasitifer.hpp"
#	include "DD_StrictPointer.hpp"
#	include "DD_Tags.hpp"
#	include "DD_address_of.hpp"
#	include "DD_release.hpp"
#	include "DD_Pair.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, ProcessType(&deleter_c_)(ParasitiferBase<ValueT_>*)>
ProcessType unrefer_parasitifer_(StrictParasitifer<ValueT_, deleter_c_>* parasitifer_) {
	if (parasitifer_) {
		parasitifer_->unrefered();
	}
}



template <
	typename ValueT_,
#	if __cplusplus >= 201103L
	ProcessType(&deleter_c_)(ParasitiferBase<ValueT_>*) = DefaultDeleter<ParasitiferBase<ValueT_>>::destroy
#	else
	ProcessType(&deleter_c_)(ParasitiferBase<ValueT_>*) = DefaultDeleter<ParasitiferBase<ValueT_> >::destroy
#	endif
>
struct StrictParasiticPointer : Comparable<StrictParasiticPointer<ValueT_, deleter_c_>> {
	public:
	DD_ALIAS(ThisType, StrictParasiticPointer<ValueT_ DD_COMMA deleter_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_);
	DD_ALIAS(DeleterType, ProcessType(&)(ParasitiferBase<ValueT_>*));
	static DeleterType DD_CONSTANT deleter = deleter_c_;

	public:
	DD_ALIAS(LengthType, ::DD::LengthType);
	DD_ALIAS(StrictParasitiferType, StrictParasitifer<ValueT_ DD_COMMA deleter_c_>);
	DD_ALIAS(StrictParasitiferReferenceType, StrictParasitiferType&);
	DD_ALIAS(StrictParasitiferConstReferenceType, StrictParasitiferType const&);
	DD_ALIAS(StrictParasitiferPointerType, StrictParasitiferType*);
	DD_ALIAS(StrictParasitiferConstPointerType, StrictParasitiferType const*);

	private:
	DD_ALIAS(HolderType, StrictPointer<StrictParasitiferType DD_COMMA unrefer_parasitifer_>);


	private:
	HolderType m_holder_;


#	if __cplusplus >= 201103L
	public:
	constexpr StrictParasiticPointer() = default;
#	else
	public:
	StrictParasiticPointer() throw() {
	}
#	endif

	public:
	DD_CONSTEXPR StrictParasiticPointer(ThisType const& origin_) DD_NOEXCEPT_AS(
		HolderType(origin_.is_valid() ? origin_.m_holder_->refered() DD_COMMA origin_.get_parasitifer() : HolderType())
	) : m_holder_(origin_.is_valid() ? origin_.m_holder_->refered(), origin_.get_parasitifer() : HolderType()) {
	}

#	if __cplusplus >= 201103L
	public:
	constexpr StrictParasiticPointer(ThisType&& origin_) = default;

#	endif
	public:
	DD_CONSTEXPR StrictParasiticPointer(StrictParasitiferPointerType pointer_) DD_NOEXCEPT_AS(
		HolderType(pointer_ ? pointer_->refered() DD_COMMA pointer_ : StrictParasitiferPointerType())
	) : m_holder_(pointer_ ? pointer_->refered(), pointer_ : StrictParasitiferPointerType()) {
	}


	public:
	StrictParasitiferPointerType DD_CONSTEXPR get_parasitifer() const DD_NOEXCEPT_AS(
		static_cast<StrictParasitiferPointerType>(fabricate<ThisType>().m_holder_.get_pointer())
	) {
		return m_holder_.get_pointer();
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT_AS(
		static_cast<PointerType>(address_of(fabricate<ThisType>().get_parasitifer()->get_value()))
	) {
		return is_valid() ? address_of(get_parasitifer()->get_value()) : PointerType();
	}


	public:
	LengthType DD_CONSTEXPR get_reference_count() const DD_NOEXCEPT_AS(
		static_cast<LengthType>(fabricate<ThisType>().get_parasitifer()->get_reference_count())
	) {
		return is_valid() ? get_parasitifer()->get_reference_count() : LengthType();
	}


	public:
	ValidityType DD_CONSTEXPR is_unique() const DD_NOEXCEPT_AS(
		static_cast<ValidityType>(fabricate<ThisType>().get_reference_count() == 1)
	) {
		return get_reference_count() == 1;
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT_AS(static_cast<ValidityType>(m_holder_.is_valid())) {
		return m_holder_.is_valid();
	}


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT_AS(fabricate<ThisType>().m_holder_.swap(target_.m_holder_)) {
		m_holder_.swap(target_.m_holder_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT_AS(m_holder_.reset()) {
		m_holder_.reset();
	}


	public:
	ProcessType reset(StrictParasitiferPointerType pointer_) DD_NOEXCEPT_IF(
		noexcept(ThisType(pointer_)) && noexcept(fabricate<ThisType>().swap(fabricate<ThisType>()))
	) {
		ThisType temp_(pointer_);
		swap(temp_);
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(fabricate<ThisType>().reset(origin_.get_parasitifer())) {
		reset(origin_.get_parasitifer());
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(fabricate<ThisType>().swap(origin_)) {
		swap(origin_);
		return *this;
	}

#	endif

	public:
	ReferenceType operator *() const DD_NOEXCEPT_AS(
		static_cast<ReferenceType>(fabricate<ThisType>().get_parasitifer()->get_value())
	) {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::StrictParasiticPointer::operator *' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		return get_parasitifer()->get_value();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT_AS(
		static_cast<PointerType>(address_of(fabricate<ThisType>().get_parasitifer()->get_value()))
	) {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::StrictParasiticPointer::operator ->' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		return address_of(get_parasitifer()->get_value());
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() DD_NOEXCEPT_AS(fabricate<ThisType>().is_valid()) {
		return is_valid();
	}


#	endif
};



template <typename ValueT_, ProcessType(&deleter_c_)(ParasitiferBase<ValueT_>*)>
inline ValidityType DD_CONSTEXPR operator ==(
	StrictParasiticPointer<ValueT_, deleter_c_> const& parasitic_pointer_1__,
	StrictParasiticPointer<ValueT_, deleter_c_> const& parasitic_pointer_2__
) noexcept(
	noexcept(static_cast<ValidityType>(parasitic_pointer_1__.get_parasitifer() == parasitic_pointer_2__.get_parasitifer()))
) {
	return parasitic_pointer_1__.get_parasitifer() == parasitic_pointer_2__.get_parasitifer();
}



template <typename ValueT_, ProcessType(&deleter_c_)(ParasitiferBase<ValueT_>*)>
inline ValidityType DD_CONSTEXPR operator <(
	StrictParasiticPointer<ValueT_, deleter_c_> const& parasitic_pointer_1__,
	StrictParasiticPointer<ValueT_, deleter_c_> const& parasitic_pointer_2__
) noexcept(
	noexcept(static_cast<ValidityType>(parasitic_pointer_1__.get_parasitifer() < parasitic_pointer_2__.get_parasitifer()))
) {
	return parasitic_pointer_1__.get_parasitifer() < parasitic_pointer_2__.get_parasitifer();
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::StrictParasiticPointer;



DD_END_



#endif
