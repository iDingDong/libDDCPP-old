//	DDCPP/standard/bits/DD_UniquePointer.hpp
#ifndef DD_UNIQUE_POINTER_HPP_INCLUDED_
#	define DD_UNIQUE_POINTER_HPP_INCLUDED_ 1



#	include "DD_Tags.hpp"
#	include "DD_RemoveAllExtents.hpp"
#	include "DD_Comparable.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#		include "DD_move.hpp"
#	endif
#	include "DD_Agent.hpp"
#	include "DD_destroy.hpp"
#	include "DD_dereference.hpp"



DD_DETAIL_BEGIN_
template <
	typename ValueT_,
	typename DeleterT_ = DefaultDeleter<ValueT_>
>
struct UniquePointer :
	Agent<DeleterT_>,
#	if __cplusplus >= 201103L
	Comparable<UniquePointer<ValueT_, DeleterT_>>
#	else
	Comparable<UniquePointer<ValueT_, DeleterT_> >
#	endif
{
	public:
	DD_ALIAS(DestroyAgent, Agent<DeleterT_>);
	DD_ALIAS(ThisType, UniquePointer<ValueT_ DD_COMMA DeleterT_>);
	DD_VALUE_TYPE_NESTED(DD_MODIFY_TRAIT(RemoveAllExtents, ValueT_))
	DD_ALIAS(DeleterType, DeleterT_);

	public:
	DD_ALIAS(DifferenceType, ::DD::DifferenceType);


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
#	else
	UniquePointer() : m_pointer_() {
	}
#	endif

	public:
	DD_DELETE_COPY_CONSTRUCTOR(UniquePointer);

#	if __cplusplus >= 201103L
	public:
	UniquePointer(ThisType&& origin_) noexcept(noexcept(DestroyAgent(::DD::move(static_cast<DestroyAgent&>(origin_))))) :
		DestroyAgent(::DD::move(static_cast<DestroyAgent&>(origin_))), m_pointer_(origin_.m_pointer_)
	{
		origin_.m_pointer_ = PointerType();
	}

#	endif
	public:
	explicit DD_CONSTEXPR UniquePointer(DeleterType const& deleter_) DD_NOEXCEPT_AS(DestroyAgent(deleter_)) :
		DestroyAgent(deleter_), m_pointer_()
	{
	}

	public:
	DD_CONSTEXPR UniquePointer(PointerType pointer_) DD_NOEXCEPT_AS(DestroyAgent()) : m_pointer_(pointer_) {
	}

	public:
	DD_CONSTEXPR UniquePointer(DeleterType const& deleter_, PointerType pointer_) DD_NOEXCEPT_AS(DestroyAgent(deleter_)) :
		DestroyAgent(deleter_), m_pointer_(pointer_)
	{
	}


	public:
	~UniquePointer() DD_NOEXCEPT {
		destruct_();
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	ProcessType swap(ThisType& origin_) DD_NOEXCEPT_AS(
		::DD::swap(static_cast<DestroyAgent&>(::DD::fabricate<ThisType>()) DD_COMMA static_cast<DestroyAgent&>(origin_))
	) {
		::DD::swap(static_cast<DestroyAgent&>(*this), static_cast<DestroyAgent&>(origin_));
		::DD::swap(m_pointer_, origin_.m_pointer_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		destruct_();
		m_pointer_ = PointerType();
	}

	public:
	ProcessType reset(PointerType pointer_) DD_NOEXCEPT {
		destruct_();
		m_pointer_ = pointer_;
	}


	public:
	PointerType release() DD_NOEXCEPT {
		PointerType original_pointer_(get_pointer());
		m_pointer_ = PointerType();
		return original_pointer_;
	}


	public:
	PointerType substitute(PointerType pointer_) DD_NOEXCEPT {
		PointerType original_pointer_(get_pointer());
		m_pointer_ = pointer_;
		return original_pointer_;
	}


	private:
	ProcessType destruct_() const DD_NOEXCEPT {
		::DD::destroy(get_pointer(), DestroyAgent::get_instance());
	}


	public:
	DD_DELETE_COPY_ASSIGNMENT(UniquePointer);

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(
		static_cast<DestroyAgent&>(::DD::fabricate<ThisType>()) = ::DD::move(static_cast<DestroyAgent&>(origin_))
	) {
		static_cast<DestroyAgent&>(*this) = ::DD::move(static_cast<DestroyAgent&>(origin_));
		reset(origin_.release());
		return *this;
	}

#	endif
	public:
	ThisType& operator =(PointerType pointer_) DD_NOEXCEPT {
		reset(pointer_);
		return *this;
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return ::DD::dereference(get_pointer());
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	ReferenceType operator [](DifferenceType index_) const DD_NOEXCEPT {
		return ::DD::dereference(get_pointer() + index_);
	}


#	if __cplusplus >= 201103L
	public:
	explicit constexpr operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename... ArgumentsT_>
inline UniquePointer<ValueT_> make_unique(ArgumentsT_&&... arguments__) DD_NOEXCEPT_AS(
	UniquePointer<ValueT_>(new ValueT_(::DD::forward<ArgumentsT_>(arguments__)...))
) {
	return UniquePointer<ValueT_>(new ValueT_(::DD::forward<ArgumentsT_>(arguments__)...));
}


#	endif
template <typename ValueT_, typename DeleterT_>
inline ValidityType DD_CONSTEXPR operator ==(
	UniquePointer<ValueT_, DeleterT_> const& unique_pointer_1_,
	UniquePointer<ValueT_, DeleterT_> const& unique_pointer_2_
) DD_NOEXCEPT_AS(static_cast<ValidityType>(unique_pointer_1_.get_pointer() == unique_pointer_2_.get_pointer())) {
	return unique_pointer_1_.get_pointer() == unique_pointer_2_.get_pointer();
}


template <typename ValueT_, typename DeleterT_>
inline ValidityType DD_CONSTEXPR operator <(
	UniquePointer<ValueT_, DeleterT_> const& unique_pointer_1_,
	UniquePointer<ValueT_, DeleterT_> const& unique_pointer_2_
) DD_NOEXCEPT_AS(static_cast<ValidityType>(unique_pointer_1_.get_pointer() < unique_pointer_2_.get_pointer())) {
	return unique_pointer_1_.get_pointer() < unique_pointer_2_.get_pointer();
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::UniquePointer;



DD_END_



#endif
