//	DDCPP/standard/bits/DD_Variant.hpp
#ifndef _DD_VARIANT_HPP_INCLUDED
#	define _DD_VARIANT_HPP_INCLUDED 1



#	include "DD_TypeInfo.hpp"
#	if __cplusplus >= 201103L
#		include "DD_Decay.hpp"
#		include "DD_forward.hpp"
#	endif
#	include "DD_UniquePointer.hpp"
#	include "DD_swap.hpp"



_DD_DETAIL_BEGIN
struct _VariantHolderBase {
	public:
	DD_ALIAS(ThisType, _VariantHolderBase);


	public:
#	if __cplusplus >= 201103L
	virtual ~_VariantHolderBase() = default;
#	else
	virtual ~_VariantHolderBase() throw() {
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	virtual UniquePointer<ThisType> get_clone() const = 0;
#	else
	virtual ThisType* get_clone() const = 0;
#	endif

	public:
	virtual TypeInfo const& get_type() const = 0;


};



template <typename _ValueT>
struct _VariantHolder DD_FINAL : _VariantHolderBase {
	public:
	DD_ALIAS(ThisType, _VariantHolder<_ValueT>);
	DD_ALIAS(SuperType, _VariantHolderBase);
	DD_ALIAS(ValueType, _ValueT);


	public:
	ValueType m_value;


	public:
	template <typename _ValueT_>
#	if __cplusplus >= 201103L
	_VariantHolder(_ValueT_&& _value) noexcept(noexcept(ValueType(_value))) : m_value(forward<_ValueT_>(_value)) {
	}
#	else
	_VariantHolder(_ValueT_ const& _value) : m_value(_value) {
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	UniquePointer<SuperType> get_clone() const override {
		return UniquePointer<SuperType>(new ThisType(m_value));
	}
#	else
	SuperType* get_clone() const {
		return new ValueType(m_value);
	}
#	endif


	public:
	TypeInfo const& get_type() const DD_OVERRIDE {
		return typeid(m_value);
	}


};



_DD_DETAIL_END



_DD_BEGIN
struct Variant {
	public:
	DD_ALIAS(ThisType, Variant);


	private:
	UniquePointer<_detail::_VariantHolderBase> _m_holder_pointer;


#	if __cplusplus >= 201103L
	public:
	constexpr Variant() = default;
#	else
	public:
	Variant() : _m_holder_pointer() {
	}
#	endif

	public:
	Variant(ThisType const& _origin) : _m_holder_pointer(_origin._m_holder_pointer->get_clone()) {
	}

#	if __cplusplus >= 201103L
	public:
	constexpr Variant(ThisType&& _origin) = default;

#	endif
	public:
	template <typename _ValueT_>
#	if __cplusplus >= 201103L
	Variant(_ValueT_&& __value_) : _m_holder_pointer(new _detail::_VariantHolder<DecayType<_ValueT_>>(forward<_ValueT_>(__value_))) {
	}
#	else
	Variant(_ValueT_ const& __value_) : _m_holder_pointer(new _detail::_VariantHolder<_ValueT_>(__value_)) {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~Variant() = default;


#	endif
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_holder_pointer, _target._m_holder_pointer);
	}


	public:
	template <typename _ValueT_>
	_ValueT_& to() DD_NOEXCEPT {
		DD_ASSERT(_m_holder_pointer->get_type() == typeid(_ValueT_), "Invalid cast on DD::Variant.")
		return static_cast<_detail::_VariantHolder<_ValueT_>&>(*_m_holder_pointer).m_value;
	}

	public:
	template <typename _ValueT_>
	_ValueT_ const& to() const DD_NOEXCEPT {
		DD_ASSERT(_m_holder_pointer->get_type() == typeid(_ValueT_), "Invalid cast on DD::Variant.")
		return static_cast<_detail::_VariantHolder<_ValueT_> const&>(*_m_holder_pointer).m_value;
	}


	public:
	TypeInfo const& get_type() const {
		return _m_holder_pointer->get_type();
	}


	public:
	ThisType& operator =(ThisType const& _origin) {
		ThisType _temp(_origin);
		swap(_temp);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& _origin) = default;

#	endif
	public:
	template <typename _ValueT_>
#	if __cplusplus >= 201103L
	ThisType& operator =(_ValueT_&& __value_) {
		ThisType _temp(forward<_ValueT_>(__value_));
#	else
	ThisType& operator =(_ValueT_ const& __value_) {
		ThisType _temp(__value_);
#	endif
		swap(_temp);
		return *this;
	}


};



_DD_END



#endif
