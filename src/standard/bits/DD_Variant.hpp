//	DDCPP/standard/bits/DD_Variant.hpp
#ifndef DD_VARIANT_HPP_INCLUDED_
#	define DD_VARIANT_HPP_INCLUDED_ 1



#	include "DD_TypeInfo.hpp"
#	if __cplusplus >= 201103L
#		include "DD_Decay.hpp"
#		include "DD_forward.hpp"
#	endif
#	include "DD_Allocator.hpp"
#	include "DD_StrictPointer.hpp"
#	include "DD_swap.hpp"



#	if !defined(DDCPP_VARIANT_ALLOCATOR)
#		define DDCPP_VARIANT_ALLOCATOR ::DD::Allocator<void>
#	endif



DD_DETAIL_BEGIN_
DD_ALIAS(VariantAllocator_, DDCPP_VARIANT_ALLOCATOR);



struct VariantHolderBase_;



inline ProcessType destroy_variant_holder_(VariantHolderBase_* pointer_) DD_NOEXCEPT;



struct VariantHolderBase_ {
	public:
	DD_ALIAS(ThisType, VariantHolderBase_);


	public:
#	if __cplusplus >= 201103L
	virtual ~VariantHolderBase_() = default;
#	else
	virtual ~VariantHolderBase_() throw() {
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	virtual StrictPointer<ThisType, destroy_variant_holder_> get_clone_() const = 0;
#	else
	virtual ThisType* get_clone_() const = 0;
#	endif


	public:
	virtual ProcessType destroy_() DD_NOEXCEPT = 0;

	public:
	virtual TypeInfo const& get_type() const = 0;


};



template <typename ValueT_>
struct VariantHolder_ DD_FINAL : VariantHolderBase_ {
	public:
	DD_ALIAS(SuperType, VariantHolderBase_);
	DD_ALIAS(ThisType, VariantHolder_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	public:
	ValueType m_value_;


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	VariantHolder_(ValueT__&& value_) noexcept(noexcept(ValueType(value_))) try : m_value_(forward<ValueT__>(value_)) {
	} catch (...) {
		VariantAllocator_::deallocate(this, sizeof(ThisType));
		throw;
	}
#	else
	VariantHolder_(ValueT__ const& value_) try : m_value_(value_) {
	} catch (...) {
		VariantAllocator_::deallocate(this, sizeof(ThisType));
		throw;
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	StrictPointer<SuperType, destroy_variant_holder_> get_clone_() const override {
		return StrictPointer<SuperType, destroy_variant_holder_>(new (VariantAllocator_::allocate(sizeof(ThisType))) ThisType(m_value_));
	}
#	else
	SuperType* get_clone_() const {
		return new (VariantAllocator_::allocate(sizeof(ThisType))) ThisType(m_value_);
	}
#	endif


	public:
	TypeInfo const& get_type() const DD_OVERRIDE {
		return typeid(m_value_);
	}


	public:
	ProcessType destroy_() DD_NOEXCEPT DD_OVERRIDE {
		m_value_.~ValueType();
		VariantAllocator_::deallocate(this, sizeof(ThisType));
	}


};



inline ProcessType destroy_variant_holder_(VariantHolderBase_* pointer_) DD_NOEXCEPT {
	pointer_->destroy_();
}



struct Variant {
	public:
	DD_ALIAS(ThisType, Variant);


	private:
	StrictPointer<VariantHolderBase_, destroy_variant_holder_> m_holder_pointer_;


#	if __cplusplus >= 201103L
	public:
	constexpr Variant() = default;
#	else
	public:
	Variant() : m_holder_pointer_() {
	}
#	endif

	public:
	Variant(ThisType const& origin_) : m_holder_pointer_(origin_.m_holder_pointer_->get_clone_()) {
	}

#	if __cplusplus >= 201103L
	public:
	constexpr Variant(ThisType&& origin_) = default;

#	endif
	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	Variant(ValueT__&& value___) : m_holder_pointer_(
		new (
			VariantAllocator_::allocate(sizeof(VariantHolder_<DecayType<ValueT__>>))
		) VariantHolder_<DecayType<ValueT__>>(forward<ValueT__>(value___))
	) {
	}
#	else
	Variant(ValueT__ const& value___) : m_holder_pointer_(
		new (VariantAllocator_::allocate(sizeof(VariantHolder_<ValueT__>))) VariantHolder_<ValueT__>(value___)
	) {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~Variant() = default;
#	else
	public:
	~Variant() throw() {
		destroy_variant_holder_(m_holder_pointer_);
	}
#	endif


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT {
		using DD::swap;
		swap(m_holder_pointer_, target_.m_holder_pointer_);
	}


	public:
	template <typename ValueT__>
	ValueT__& to() DD_NOEXCEPT {
		DD_ASSERT(m_holder_pointer_->get_type() == typeid(ValueT__), "Invalid cast on DD::Variant.")
		return static_cast<VariantHolder_<ValueT__>&>(*m_holder_pointer_).m_value_;
	}

	public:
	template <typename ValueT__>
	ValueT__ const& to() const DD_NOEXCEPT {
		DD_ASSERT(m_holder_pointer_->get_type() == typeid(ValueT__), "Invalid cast on DD::Variant.")
		return static_cast<VariantHolder_<ValueT__> const&>(*m_holder_pointer_).m_value_;
	}


	public:
	TypeInfo const& get_type() const {
		return m_holder_pointer_->get_type();
	}


	public:
	ThisType& operator =(ThisType const& origin_) {
		ThisType temp_(origin_);
		swap(temp_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) = default;

#	endif
	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ThisType& operator =(ValueT__&& value___) {
		ThisType temp_(forward<ValueT__>(value___));
#	else
	ThisType& operator =(ValueT__ const& value___) {
		ThisType temp_(value___);
#	endif
		swap(temp_);
		return *this;
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Variant;



DD_END_



#endif
