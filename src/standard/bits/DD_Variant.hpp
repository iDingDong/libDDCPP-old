//	DDCPP/standard/bits/DD_Variant.hpp
#ifndef DD_VARIANT_HPP_INCLUDED_
#	define DD_VARIANT_HPP_INCLUDED_ 1



#	include "DD_SpecificTypeNested.hpp"
#	include "DD_TypeInfo.hpp"
#	if __cplusplus >= 201103L
#		include "DD_Decay.hpp"
#		include "DD_forward.hpp"
#	endif
#	include "DD_release.hpp"
#	include "DD_Allocator.hpp"
//#	include "DD_StrictPointer.hpp"
#	include "DD_swap.hpp"



#	if !defined(DDCPP_VARIANT_ALLOCATOR)
#		define DDCPP_VARIANT_ALLOCATOR ::DD::Allocator<void>
#	endif
#	if !defined(DDCPP_VARIANT_IMPLICIT_CAST)
#		define DDCPP_VARIANT_IMPLICIT_CAST DD_OFF
#	endif

#	if __cplusplus < 201103L || DDCPP_VARIANT_IMPLICIT_CAST
#		define DD_VARIANT_CAST_OPERATOR_EXPLICIT_
#	else
#		define DD_VARIANT_CAST_OPERATOR_EXPLICIT_ explicit
#	endif



DD_DETAIL_BEGIN_
DD_ALIAS(VariantAllocator_, DDCPP_VARIANT_ALLOCATOR);



//struct VariantHolderBase_;



//inline ProcessType destroy_variant_holder_(VariantHolderBase_* pointer_) DD_NOEXCEPT;



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
	virtual SizeType get_size_() const DD_NOEXCEPT = 0;


	public:
	virtual ThisType* get_clone_() const = 0;


	public:
	virtual TypeInfo const& get_type_() const = 0;


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
	VariantHolder_(ValueT__&& value___) noexcept(noexcept(ValueType(value___))) : m_value_(::DD::forward<ValueT__>(value___)) {
	}
#	else
	VariantHolder_(ValueT__ const& value___) : m_value_(value___) {
	}
#	endif


	public:
	SizeType get_size_() const DD_NOEXCEPT override {
		return sizeof(ThisType);
	}


	public:
	SuperType* get_clone_() const {
		ThisType* new_holder_ = static_cast<ThisType*>(VariantAllocator_::allocate(sizeof(ThisType)));
		::DD::construct(new_holder_, ThisType(m_value_));
		return new_holder_;
	}


	public:
	TypeInfo const& get_type_() const DD_OVERRIDE {
		return typeid(m_value_);
	}


};



struct Variant {
	public:
	DD_ALIAS(ThisType, Variant);

	private:
	DD_SPECIFIC_TYPE_NESTED(Holder, VariantHolderBase_)


	private:
	HolderPointerType m_holder_ DD_IN_CLASS_INITIALIZE(HolderPointerType());


#	if __cplusplus >= 201103L
	public:
	constexpr Variant() = default;
#	else
	public:
	Variant() : m_holder_() {
	}
#	endif

	public:
	Variant(ThisType const& origin_) : m_holder_(origin_.m_holder_->get_clone_()) {
	}

#	if __cplusplus >= 201103L
	public:
	Variant(ThisType&& origin_) noexcept : m_holder_(::DD::release(origin_.m_holder_)) {
	}

#	endif
	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	Variant(ValueT__&& value___) : m_holder_(static_cast<HolderPointerType>(
		VariantAllocator_::Basic::allocate(sizeof(VariantHolder_<DecayType<ValueT__>>))
	)) {
		try {
			::DD::construct(static_cast<VariantHolder_<DecayType<ValueT__>>*>(m_holder_), forward<ValueT__>(value___));
		} catch (...) {
			VariantAllocator_::deallocate(m_holder_, sizeof(VariantHolder_<DecayType<ValueT__>>));
		}
	}
#	else
	Variant(ValueT__ const& value___) : m_holder_(static_cast<HolderPointerType>(
		VariantAllocator_::Basic::allocate(sizeof(VariantHolder_<DecayType<ValueT__>>))
	)) {
		try {
			::DD::construct(static_cast<VariantHolder_<DecayType<ValueT__>>*>(m_holder_), value___);
		} catch (...) {
			VariantAllocator_::deallocate(m_holder_, sizeof(VariantHolder_<DecayType<ValueT__>>));
		}
	}
#	endif


	public:
	~Variant() DD_NOEXCEPT {
		destruct();
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return m_holder_;
	}


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT {
		::DD::swap(m_holder_, target_.m_holder_);
	}


	public:
	template <typename ValueT__>
	ValueT__& to() DD_NOEXCEPT {
		DD_ASSERT(get_type() == typeid(ValueT__), "Invalid cast on DD::Variant.");
		return static_cast<VariantHolder_<ValueT__>&>(*m_holder_).m_value_;
	}

	public:
	template <typename ValueT__>
	ValueT__ const& to() const DD_NOEXCEPT {
		DD_ASSERT(get_type() == typeid(ValueT__), "Invalid cast on DD::Variant.");
		return static_cast<VariantHolder_<ValueT__> const&>(*m_holder_).m_value_;
	}


	public:
	TypeInfo const& get_type() const {
		return m_holder_->get_type_();
	}


	private:
	ProcessType destruct() DD_NOEXCEPT {
		if (is_valid()) {
			SizeType size_ = m_holder_->get_size_();
			::DD::destruct(m_holder_);
			VariantAllocator_::deallocate(m_holder_, size_);
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) {
		ThisType temp_(origin_);
		swap(temp_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) {
		swap(origin_);
		return *this;
	}

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


#	if __cplusplus >= 201103L || DDCPP_VARIANT_IMPLICIT_CAST
	public:
	template <typename ValueT__>
	DD_VARIANT_CAST_OPERATOR_EXPLICIT_ operator ValueT__() const DD_NOEXCEPT {
		return to<ValueT__>();
	}


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Variant;



DD_END_



#	undef DD_VARIANT_CAST_OPERATOR_EXPLICIT_



#endif
