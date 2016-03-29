//	DDCPP/standard/bits/DD_Dynamic.hpp
#ifndef DD_DYNAMIC_HPP_INCLUDED_
#	define DD_DYNAMIC_HPP_INCLUDED_ 1



#	include "DD_SpecificTypeNested.hpp"
#	include "DD_TypeInfo.hpp"
#	if __cplusplus >= 201103L
#		include "DD_Decay.hpp"
#		include "DD_forward.hpp"
#	endif
#	include "DD_release.hpp"
#	include "DD_Allocateable.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"
#	include "DD_swap.hpp"



#	if !defined(DDCPP_DYNAMIC_IMPLICIT_CAST)
#		define DDCPP_DYNAMIC_IMPLICIT_CAST DD_OFF
#	endif

#	if __cplusplus < 201103L || DDCPP_DYNAMIC_IMPLICIT_CAST
#		define DD_CAST_DYNAMIC_OPERATOR_EXPLICIT_
#	else
#		define DD_CAST_DYNAMIC_OPERATOR_EXPLICIT_ explicit
#	endif



DD_DETAIL_BEGIN_
struct DynamicHolderBase_ {
	public:
	DD_ALIAS(ThisType, DynamicHolderBase_);


	public:
#	if __cplusplus >= 201103L
	virtual ~DynamicHolderBase_() = default;
#	else
	virtual ~DynamicHolderBase_() throw() {
	}
#	endif


	public:
	virtual SizeType get_size_() const DD_NOEXCEPT = 0;


	public:
	virtual TypeInfo const& get_type_() const = 0;


	public:
	virtual ProcessType clone_to_(ThisType* pointer_) const = 0;

};



template <typename ValueT_>
struct DynamicHolder_ DD_FINAL : DynamicHolderBase_ {
	public:
	DD_ALIAS(SuperType, DynamicHolderBase_);
	DD_ALIAS(ThisType, DynamicHolder_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	public:
	ValueType m_value_;


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	DynamicHolder_(ValueT__&& value___) noexcept(noexcept(ValueType(value___))) : m_value_(::DD::forward<ValueT__>(value___)) {
	}
#	else
	DynamicHolder_(ValueT__ const& value___) : m_value_(value___) {
	}
#	endif


	public:
	SizeType get_size_() const DD_NOEXCEPT override {
		return sizeof(ThisType);
	}


	public:
	TypeInfo const& get_type_() const DD_OVERRIDE {
		return typeid(m_value_);
	}


	public:
	ProcessType clone_to_(SuperType* pointer_) const DD_OVERRIDE {
		::DD::construct(static_cast<ThisType*>(pointer_), *this);
	}


};



#	if __cplusplus >= 201103L
template <typename AllocatorT_ = Allocator<void>>
#	else
template <typename AllocatorT_ = Allocator<void> >
#	endif
struct Dynamic : protected Allocateable<AllocatorT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(ThisType, Dynamic);
	DD_ALIAS(AllocatorType, AllocatorT_);

	private:
	DD_SPECIFIC_TYPE_NESTED(Holder, DynamicHolderBase_)


	private:
	HolderPointerType m_holder_ DD_IN_CLASS_INITIALIZE(HolderPointerType());


#	if __cplusplus >= 201103L
	public:
	constexpr Dynamic() = default;
#	else
	public:
	Dynamic() : m_holder_() {
	}
#	endif

	public:
	Dynamic(ThisType const& origin_) : m_holder_(static_cast<HolderPointerType>(
		AllocateAgent::basic_allocate(origin_.m_holder_->get_size_())
	)) {
		try {
			origin_.m_holder_->clone_to_(m_holder_);
		} catch (...) {
			AllocateAgent::basic_deallocate(m_holder_, origin_.m_holder_->get_size_());
			throw;
		}
	}

#	if __cplusplus >= 201103L
	public:
	Dynamic(ThisType&& origin_) noexcept : m_holder_(::DD::release(origin_.m_holder_)) {
	}

#	endif
	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	Dynamic(ValueT__&& value___) : m_holder_(make_holder_(::DD::forward<ValueT__>(value___))) {
	}
#	else
	Dynamic(ValueT__ const& value___) : m_holder_(make_holder_(value___)) {
	}
#	endif


	public:
	~Dynamic() DD_NOEXCEPT {
		destruct();
	}


	private:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	HolderPointerType make_holder_(ValueT__&& value___) {
		using ResultType_ = DynamicHolder_<DecayType<ValueT__>>;
#	else
	HolderPointerType make_holder_(ValueT__ const& value___) {
		typedef DynamicHolder_<ValueT__> ResultType_;
#	endif
		ResultType_* result_ = static_cast<ResultType_*>(AllocateAgent::basic_allocate(sizeof(ResultType_)));
		try {
#	if __cplusplus >= 201103L
			::DD::construct(result_, ::DD::forward<ValueT__>(value___));
#	else
			::DD::construct(result_, value___);
#	endif
		} catch (...) {
			AllocateAgent::basic_deallocate(result_, sizeof(ResultType_));
			throw;
		}
		return result_;
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return m_holder_;
	}


	public:
	AllocatorType& get_allocator() const DD_NOEXCEPT {
		return AllocateAgent::get_allocator;
	}


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT {
		::DD::swap(m_holder_, target_.m_holder_);
	}


	public:
	template <typename ValueT__>
	ValueT__& to() DD_NOEXCEPT {
		DD_ASSERT(get_type() == typeid(ValueT__), "Invalid cast on DD::Dynamic.");
		return static_cast<DynamicHolder_<ValueT__>&>(*m_holder_).m_value_;
	}

	public:
	template <typename ValueT__>
	ValueT__ const& to() const DD_NOEXCEPT {
		DD_ASSERT(get_type() == typeid(ValueT__), "Invalid cast on DD::Dynamic.");
		return static_cast<DynamicHolder_<ValueT__> const&>(*m_holder_).m_value_;
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
			AllocateAgent::basic_deallocate(m_holder_, size_);
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


#	if __cplusplus >= 201103L || DDCPP_DYNAMIC_IMPLICIT_CAST
	public:
	template <typename ValueT__>
	DD_CAST_DYNAMIC_OPERATOR_EXPLICIT_ operator ValueT__() const DD_NOEXCEPT {
		return to<ValueT__>();
	}


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Dynamic;



DD_END_



#	undef DD_CAST_DYNAMIC_OPERATOR_EXPLICIT_



#endif
