//	DDCPP/standard/bits/DD_Optional.hpp
#ifndef DD_OPTIONAL_HPP_INCLUDED_
#	define DD_OPTIONAL_HPP_INCLUDED_



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Optional'.



#	endif
#	include "DD_Tags.hpp"
#	include "DD_ValueTypeNested.hpp"
#	include "DD_IsSame.hpp"
#	include "DD_IsTriviallyCopyable.hpp"
#	include "DD_Decay.hpp"
#	include "DD_Comparable.hpp"
#	include "DD_AccessDenied.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"
#	include "DD_SingleStorage.hpp"



DD_DETAIL_BEGIN_
struct NilOptional : Tag {
} DD_CONSTANT nil_optional;



struct OptionalAccessDenied : AccessDenied {
	public:
	using SuperType = AccessDenied;
	using ThisType = OptionalAccessDenied;


	public:
	constexpr OptionalAccessDenied() = default;

	public:
	constexpr OptionalAccessDenied(ThisType const& origin_) = default;

	public:
	constexpr OptionalAccessDenied(ThisType&& origin_) = default;

	public:
	constexpr OptionalAccessDenied(PromptType prompt_) noexcept : SuperType(prompt_) {
	}


	public:
	~OptionalAccessDenied() override = default;


	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


};



template <typename ValueT_>
struct Optional;



template <>
struct Optional<void> {
	protected:
	using ThisType = Optional<void>;


	private:
	ValidityType m_validity_ = false;


	protected:
	constexpr Optional() = default;

	protected:
	constexpr Optional(ThisType const& origin_) = default;

	protected:
	constexpr Optional(ThisType&& origin_) = default;

	protected:
	explicit constexpr Optional(ValidityType validity_) noexcept : m_validity_(validity_) {
	}

	protected:
	constexpr Optional(NilOptional tag_) {
	}


	protected:
	~Optional() = default;


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return m_validity_;
	}


	protected:
	ThisType& operator =(ThisType const& origin_) = default;

	protected:
	ThisType& operator =(ThisType&& origin_) = default;


};



template <typename ValueT_>
struct Optional : Comparable<Optional<ValueT_>>, Optional<void> {
	public:
	using SuperType = Optional<void>;
	DD_ALIAS(ThisType, Optional<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	private:
	template <ValidityType is_trivially_operatable_c__, int workaround__ = 0>
	struct Reset_ {
		template <typename ValueT___>
		static ProcessType reset(ThisType* this_, ValueT___&& value____) {
			if (this_->is_valid()) {
				this_->unguarded_assign(::DD::forward<ValueT___>(value____));
			} else {
				this_->unguarded_emplace(::DD::forward<ValueT___>(value____));
			}
		}


	};


	private:
	template <int workaround_>
	struct Reset_<true, workaround_> {
		template <typename ValueT___>
		static ProcessType reset(ThisType* this_, ValueT___&& value____) {
			this_->unguarded_assign(::DD::forward<ValueT___>(value____));
			this_->m_validity_ = true;
		}


	};


	private:
	SingleStorage<ValueType> m_storage_;


	public:
	constexpr Optional() = default;

	public:
	Optional(ThisType const& origin_) noexcept(
		noexcept(emplace_(origin_.get_value_()))
	) : SuperType(origin_.is_valid()) {
		if (is_valid()) {
			emplace_(origin_.get_value_());
		}
	}

	public:
	Optional(ThisType&& origin_) noexcept(
		noexcept(emplace_(::DD::move(origin_.get_value_())))
	) : SuperType(origin_.is_valid()) {
		if (is_valid()) {
			emplace_(::DD::move(origin_.get_value_()));
		}
	}

	public:
	constexpr Optional(NilOptional tag_) DD_NOEXCEPT : SuperType(tag_) {
	}

	public:
	template <typename... ArgumentsT__>
	Optional(ValidityType validity_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(emplace_(::DD::forward<ArgumentsT__>(arguments___)...))
	) : SuperType(validity_) {
		if (is_valid()) {
			emplace_(::DD::forward<ArgumentsT__>(arguments___)...);
		}
	}

	public:
	template <typename... ArgumentsT__>
	Optional(ConstructTag tag_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(emplace_(::DD::forward<ArgumentsT__>(arguments___)...))
	) : SuperType(true) {
		emplace_(::DD::forward<ArgumentsT__>(arguments___)...);
	}


	public:
	~Optional() noexcept {
		if (is_valid()) {
			::DD::destruct(get_pointer());
		}
	}


	public:
	ReferenceType unguarded_get_reference() noexcept {
		return *unguarded_get_pointer();
	}

	public:
	ConstReferenceType constexpr unguarded_get_reference() const noexcept {
		return *unguarded_get_pointer();
	}


	public:
	ReferenceType get_reference() {
		if (is_valid()) {
			return unguarded_get_reference();
		}
		throw OptionalAccessDenied(
			"Failed to access reference from an invalid optional: 'DD::Optional::get_reference'"
		);
	}

	public:
	ConstReferenceType get_reference() const {
		if (is_valid()) {
			return unguarded_get_reference();
		}
		throw OptionalAccessDenied(
			"Failed to access reference from an invalid optional: 'DD::Optional::get_reference'"
		);
	}


	public:
	PointerType unguarded_get_pointer() noexcept {
		return m_storage_->get_pointer();
	}

	public:
	ConstPointerType constexpr unguarded_get_pointer() const noexcept {
		return m_storage_->get_pointer();
	}


	public:
	PointerType get_pointer() noexcept {
		return is_valid() ? unguarded_get_pointer() : PointerType();
	}

	public:
	ConstPointerType constexpr get_pointer() const noexcept {
		return is_valid() ? unguarded_get_pointer() : PointerType();
	}


	public:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace(ArgumentsT__&&... arguments___) noexcept(
		noexcept(::DD::construct(unguarded_get_pointer(), ::DD::forward<ArgumentsT__>(arguments___)...))
	) {
		::DD::construct(unguarded_get_pointer(), ::DD::forward<ArgumentsT__>(arguments___)...);
	}

	public:
	template <typename... ArgumentsT__>
	ProcessType emplace(ArgumentsT__&&... arguments___) {
		if (is_valid()) {
			throw OptionalAccessDenied("Failed to emplace on a valid optional: 'DD::Optional::emplace'");
		}
		unguarded_emplace(::DD::forward<ArgumentsT__>(arguments___)...);
		m_validity_ = true;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_assign(ValueT__&& value___) noexcept(
		noexcept(::DD::fabricate<ThisType>().unguarded_get_reference() = ::DD::forward<ValueT__>(value___))
	) {
		unguarded_get_reference() = ::DD::forward<ValueT__>(value___);
	}

	public:
	template <typename ValueT__>
	ProcessType assign(ValueT__&& value___) {
		if (!is_valid()) {
			throw OptionalAccessDenied("Failed to assign to an invalid optional: 'DD::Optional::assign'");
		}
		unguarded_assign(::DD::forward<value___>);
	}


	public:
	ProcessType reset() noexcept {
		if (is_valid()) {
			m_validity_ = false;
			::DD::destruct(get_pointer());
		}
	}

	public:
	ProcessType reset(NilOptional tag_) noexcept {
		reset();
	}

	public:
	template <typename ValueT__>
	ProcessType reset(ValueT__&& value___) noexcept(noexcept(Reset_<AndType<
		IsSame<RemoveReferenceType<ValueT__>, ValueType>,
		IsTriviallyCopyable<ValueType>
	>::value>::reset(::DD::fabricate<ThisType*>(), ::DD::forward<ValueT__>(value___)))) {
		Reset_<AndType<
			IsSame<RemoveReferenceType<ValueT__>, ValueType>,
			IsTriviallyCopyable<ValueType>
		>::value>::reset(this, ::DD::forward<ValueT__>(value___));
	}

	public:
	ProcessType reset(ThisType const& origin_) noexcept(
		noexcept(::DD::fabricate<ThisType>().reset(origin_.unguarded_get_reference()))
	) {
		if (origin_.is_valid()) {
			reset(origin_.unguarded_get_reference());
		} else {
			reset();
		}
	}

	public:
	ProcessType reset(ThisType&& origin_) noexcept(
		noexcept(::DD::fabricate<ThisType>().reset(::DD::move(origin_.unguarded_get_reference())))
	) {
		if (origin_.is_valid()) {
			reset(::DD::move(origin_.unguarded_get_reference()));
		} else {
			reset();
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) {
		reset(origin_);
		return *this;
	}

	public:
	ThisType& operator =(ThisType&& origin_) noexcept(
		noexcept(::DD::fabricate<ThisType>().reset(::DD::move(origin_)))
	) {
		reset(::DD::move(origin_));
		return *this;
	}

	public:
	template <typename ValueT__>
	ThisType& operator =(ValueT__&& value___) noexcept(
		noexcept(::DD::fabricate<ThisType>().reset(::DD::forward<ValueT__>(value___)))
	) {
		reset(::DD::forward<ValueT__>(value___));
		return *this;
	}


	public:
	explicit constexpr operator ValidityType() const noexcept {
		return is_valid();
	}


};



template <typename ValueT_>
Optional<DecayType<ValueT_>> make_optional(ValueT_&& value__) noexcept(
	noexcept(Optional<DecayType<ValueT_>>(::DD::forward<ValueT_>(value__)))
) {
	return Optional<DecayType<ValueT_>>(construct_tag, ::DD::forward<ValueT_>(value__));
}


template <typename ValueT_>
inline ValidityType constexpr operator ==(
	Optional<ValueT_> const& optional_1_, Optional<ValueT_> const& optional_2_
) noexcept(noexcept(static_cast<ValidityType>(optional_1_.get_reference() == optional_2_.get_reference()))) {
	return optional_1_.is_valid() && optional_2_.is_valid() ?
		optional_1_.get_reference() == optional_2_.get_reference() :
		optional_1_.is_valid() == optional_2_.is_valid()
	;
}

template <typename ValueT_>
inline ValidityType constexpr operator ==(NilOptional nil_optional_, Optional<ValueT_> const& optional_) noexcept {
	return !optional_.is_valid();
}

template <typename ValueT_>
inline ValidityType constexpr operator ==(Optional<ValueT_> const& optional_, NilOptional nil_optional_) noexcept {
	return nil_optional == optional_;
}


template <typename ValueT_>
inline ValidityType constexpr operator <(
	Optional<ValueT_> const& optional_1_, Optional<ValueT_> const& optional_2_
) noexcept(noexcept(static_cast<ValidityType>(optional_1_.get_reference() < optional_2_.get_reference()))) {
	return optional_2_.is_valid() ?
		(optional_1_.is_valid() ? optional_1_.get_value() < optional_2_.get_value() : true) : false
	;
}

template <typename ValueT_>
inline ValidityType constexpr operator <(NilOptional nil_optional_, Optional<ValueT_> const& optional_) {
	return optional_.is_valid();
}

template <typename ValueT_>
inline ValidityType constexpr operator <(Optional<ValueT_> const& optional_, NilOptional nil_optional_) {
	return false;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::NilOptional;
using detail_::OptionalAccessDenied;
using detail_::Optional;

using detail_::nil_optional;
using detail_::make_optional;



DD_END_



#endif
