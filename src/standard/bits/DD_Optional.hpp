//	DDCPP/standard/bits/DD_Optional.hpp
#ifndef DD_OPTIONAL_HPP_INCLUDED_
#	define DD_OPTIONAL_HPP_INCLUDED_



#	include "DD_Tags.hpp"
#	include "DD_ValueTypeNested.hpp"
#	include "DD_IsSame.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsLvalueReference.hpp"
#		include "DD_IsRvalueReference.hpp"
#	endif
#	include "DD_IsTriviallyCopyable.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyMoveable.hpp"
#	endif
#	include "DD_Comparable.hpp"
#	include "DD_AccessDenied.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"
#	include "DD_SizeTrait.hpp"



DD_DETAIL_BEGIN_
struct NilOptional : Tag {
} DD_CONSTANT nil_optional;



struct Optional_ {
	protected:
	DD_ALIAS(ThisType, Optional_);


	private:
	ValidityType m_validity_ DD_IN_CLASS_INITIALIZE(false);


	protected:
#	if __cplusplus >= 201103L
	constexpr Optional_() = default;
#	else
	Optional_() : m_validity_(false) {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(Optional_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(Optional_)

	protected:
	explicit DD_CONSTEXPR Optional_(ValidityType validity_) DD_NOEXCEPT : m_validity_(validity_) {
	}


#	if __cplusplus >= 201103L
	protected:
	~Optional_() = default;


#	endif
	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return m_validity_;
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(Optional_)


};



template <typename ValueT_>
#	if __cplusplus >= 201103L
struct Optional : Comparable<Optional<ValueT_>>, Optional_ {
#	else
struct Optional : Comparable< Optional<ValueT_> >, Optional_ {
#	endif
	public:
	DD_ALIAS(SuperType, Optional_);
	DD_ALIAS(ThisType, Optional<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	static SizeType DD_CONSTANT value_size = sizeof(ValueT_);


	private:
	template <ValidityType is_trivially_operatable_c__, int workaround__ = 0>
	struct Reset_ {
		template <typename ValueT___>
#	if __cplusplus >= 201103L
		static ProcessType reset(ThisType* this_, ValueT___&& value____) {
			if (this_->is_valid()) {
				this_->get_value_() = forward<ValueT___>(value____);
			} else {
				this_->emplace(forward<ValueT___>(value____));
			}
			this_->m_validity_ = true;
		}
#	else
		static ProcessType reset(ThisType* this_, ValueT___ const& value____) {
			if (this_->is_valid()) {
				this_->get_value_() = value____;
			} else {
				this_->emplace(value____);
			}
			this_->m_validity_ = true;
		}
#	endif


	};


	private:
	template <int workaround_>
	struct Reset_<true, workaround_> {
		template <typename ValueT___>
#	if __cplusplus >= 201103L
		static ProcessType reset(ThisType* this_, ValueT___&& value____) {
			this_->m_validity_ = true;
			this_->get_value_() = forward<ValueT___>(value____);
		}
#	else
		static ProcessType reset(ThisType* this_, ValueT___ const& value____) {
			this_->m_validity_ = true;
			this_->get_value_() = value____;
		}
#	endif


	};


	private:
	SizeTrait<value_size> m_storage_;


	public:
	constexpr Optional() = default;

	public:
	Optional(ThisType const& origin_) DD_NOEXCEPT_AS(
		emplace(origin_.get_value_())
	) : SuperType(origin_.is_valid()) {
		if (is_valid()) {
			emplace(origin_.get_value_());
		}
	}

#	if __cplusplus >= 201103L
	public:
	Optional(ThisType&& origin_) noexcept(
		noexcept(emplace(move(origin_.get_value_())))
	) : SuperType(origin_.is_valid()) {
		if (is_valid()) {
			emplace(move(origin_.get_value_()));
		}
	}

	public:
	template <typename... ArgumentsT__>
	Optional(ValidityType validity_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(emplace(forward<ArgumentsT__>(arguments___)...))
	) : SuperType(validity_) {
		if (is_valid()) {
			emplace(forward<ArgumentsT__>(arguments___)...);
		}
	}
#	else
	public:
	template <typename ValueT__>
	Optional(ValidityType validity_, ValueT__ const& value___) : SuperType(validity_) {
		if (is_valid()) {
			emplace(value___);
		}
	}
#	endif

	public:
	~Optional() DD_NOEXCEPT {
		if (is_valid()) {
			destruct(get_pointer());
		}
	}


	private:
	ReferenceType get_value_() DD_NOEXCEPT {
		return reinterpret_cast<ReferenceType>(m_storage_);
	}

	private:
	ConstReferenceType get_value_() const DD_NOEXCEPT {
		return reinterpret_cast<ConstReferenceType>(m_storage_);
	}


	public:
	ReferenceType get_value() DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Failed to access invalid value: 'DD::Optional::get_value'");
		return get_value_();
	}

	public:
	ConstReferenceType get_value() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Failed to access invalid value: 'DD::Optional::get_value'");
		return get_value_();
	}


	public:
	ReferenceType fetch_value() DD_NOEXCEPT {
		if (is_valid()) {
			return get_value_();
		}
		throw AccessDenied("Failed to access invalid value: 'DD::Optional::fetch_value'");
	}

	public:
	ConstReferenceType fetch_value() const DD_NOEXCEPT {
		if (is_valid()) {
			return get_value_();
		}
		throw AccessDenied("Failed to access invalid value: 'DD::Optional::fetch_value'");
	}


	private:
	PointerType get_pointer_() DD_NOEXCEPT {
		return address_of(get_value());
	}

	private:
	ConstPointerType get_pointer_() const DD_NOEXCEPT {
		return address_of(get_value());
	}


	public:
	PointerType get_pointer() DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Failed to access invalid value: 'DD::Optional::get_pointer'");
		return get_pointer_();
	}

	public:
	ConstPointerType get_pointer() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Failed to access invalid value: 'DD::Optional::get_pointer'");
		return get_pointer_();
	}


	public:
	PointerType fetch_pointer() DD_NOEXCEPT {
		if (is_valid()) {
			return get_pointer_();
		}
		throw AccessDenied("Failed to access invalid value: 'DD::Optional::fetch_pointer'");
	}

	public:
	ConstPointerType fetch_pointer() const DD_NOEXCEPT {
		if (is_valid()) {
			return get_pointer_();
		}
		throw AccessDenied("Failed to access invalid value: 'DD::Optional::fetch_pointer'");
	}


	public:
	PointerType try_pointer() DD_NOEXCEPT {
		return is_valid() ? get_pointer_() : PointerType();
	}

	public:
	ConstPointerType try_pointer() const DD_NOEXCEPT {
		return is_valid() ? get_pointer_() : ConstPointerType();
	}


	public:
#	if __cplusplus >= 201103L
	template <typename... ArgumentsT__>
	ProcessType emplace(ArgumentsT__&&... arguments___) noexcept(
		noexcept(construct(get_pointer(), forward<ArgumentsT__>(arguments___)...))
	) {
		DD_ASSERT(!is_valid(), "Failed to construct over other instance: 'DD::Optional::emplace'");
		construct(get_pointer_(), forward<ArgumentsT__>(arguments___)...);
	}
#	else
	template <typename ValueT__>
	ProcessType emplace(ValueT__ const& value___) {
		DD_ASSERT(!is_valid(), "Failed to construct over other instance: 'DD::Optional::emplace'");
		construct(get_pointer_(), forward<ArgumentsT>(arguments___)...);
	}
#	endif


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ProcessType assign(ValueT__&& value___) noexcept(noexcept(get_value() = forward<ValueT__>(value___))) {
		DD_ASSERT(is_valid(), "Failed to access invalid value: 'DD::Optional::get_pointer'");
		get_value_() = forward<ValueT__>(value___);
	}
#	else
	ProcessType assign(ValueT__&& value___) {
		DD_ASSERT(is_valid(), "Failed to access invalid value: 'DD::Optional::get_pointer'");
		get_value_() = value___;
	}
#	endif


	public:
	ProcessType reset() DD_NOEXCEPT {
		if (is_valid()) {
			m_validity_ = false;
			destruct(get_pointer());
		}
	}

	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ProcessType reset(ValueT__&& value___) noexcept(
		noexcept(Reset_<AndType<
			IsSame<RemoveReferenceType<ValueT__>, ValueType>,
			OrType<
				AndType<IsLvalueReference<ValueT__>, IsTriviallyCopyable<ValueType>>,
				AndType<IsRvalueReference<ValueT__>, IsTriviallyMoveable<ValueType>>
			>
		>::value>::reset(nil_pointer, move<ValueT__>(value___)))
	) {
		Reset_<AndType<
			IsSame<RemoveReferenceType<ValueT__>, ValueType>,
			OrType<
				AndType<IsLvalueReference<ValueT__>, IsTriviallyCopyable<ValueType>>,
				AndType<IsRvalueReference<ValueT__>, IsTriviallyMoveable<ValueType>>
			>
		>::value>::reset(this, move<ValueT__>(value___));
	}
#	else
	ProcessType reset(ValueT__ const& value___) {
		Reset_<typename And<
			IsSame<RemoveReferenceType<ValueT__>, ValueType>,
			IsTriviallyCopyable<ValueType>
		>::Type::value>::reset(this, value___);
	}
#	endif


	public:
	ThisType& operator =(ThisType const& origin_) {
		if (origin_.is_valid()) {
			reset(origin_.get_value_());
		} else {
			reset();
		}
		return *this;
	}

	public:
	ThisType& operator =(ThisType&& origin_) {
		if (origin_.is_valid()) {
			reset(move(origin_.get_value_()));
		} else {
			reset();
		}
		return *this;
	}

	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ThisType& operator =(ValueT__&& value___) DD_NOEXCEPT_AS(reset(forward<ValueT__>(value___))) {
		reset(forward<ValueT__>(value___));
		return *this;
	}
#	else
	ThisType& operator =(ValueT__ const& value___) {
		reset(value___);
		return *this;
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	explicit constexpr operator ValidityType() const noexcept {
		return is_valid();
	}


#	endif
};



template <typename ValueT_>
inline ValidityType operator ==(Optional<ValueT_> const& optional_1_, Optional<ValueT_> const& optional_2_) {
	if (optional_1_.is_valid() && optional_2_.is_valid()) {
		return optional_1_.get_value() == optional_2_.get_value();
	} else {
		return optional_1_.is_valid() == optional_2_.is_valid();
	}
}


template <typename ValueT_>
inline ValidityType operator <(Optional<ValueT_> const& optional_1_, Optional<ValueT_> const& optional_2_) {
	if (!optional_1_.is_valid()) {
		return optional_2_.is_valid();
	} else if (!optional_2_.is_valid()) {
		return false;
	} else {
		return optional_1_.get_value() < optional_2_.get_value();
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::Optional;



DD_END_



#endif
