//	DDCPP/standard/bits/DD_UniquePointer.hpp
#ifndef DD_UNIQUE_POINTER_HPP_INCLUDED_
#	define DD_UNIQUE_POINTER_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_Tags.hpp"
#	include "DD_Comparable.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_Allocator.hpp"
#	include "DD_swap.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, typename DeleterT_ = DefaultTag>
struct UniquePointer : Comparable<ValueT_, DeleterT_> {
	public:
	DD_ALIAS(ThisType, UniquePointer<ValueT_ DD_COMMA DeleterT_>);
	DD_ALIAS(DeleterType, DeleterT_);
	DD_VALUE_TYPE_NESTED(ValueT_)


	DD_ALIAS(DifferenceType, DD::DifferenceType);


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());
	DeleterType mutable m_deleter_ DD_IN_CLASS_INITIALIZE(DeleterType());


	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
#	else
	UniquePointer() DD_NOEXCEPT : m_pointer_(), m_deleter_() {
	}
#	endif

	DD_DELETE_COPY_CONSTRUCTOR(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer(ThisType&& origin_) noexcept : m_pointer_(origin_.release()), m_deleter_(forward<DeleterType>(origin_.m_deleter_)) {
	}

#	endif

	public:
	explicit DD_CONSTEXPR UniquePointer(PointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename DeleterT__>
	constexpr UniquePointer(DeleterT__&& deleter_) noexcept(
		noexcept(DeleterType(forward<DeleterT__>(deleter_)))
	) : m_deleter_(forward<DeleterT__>(deleter_)) {
	}

	public:
	template <typename DeleterT__>
	constexpr UniquePointer(PointerType pointer_, DeleterT__&& deleter_) noexcept(
		noexcept(DeleterType(forward<DeleterT__>(deleter_)))
	) : m_pointer_(pointer_), m_deleter_(forward<DeleterT__>(deleter_)) {
	}
#	else
	public:
	template <typename DeleterT__>
	UniquePointer(DeleterT__ const& deleter_) : m_pointer_(), m_deleter_(deleter_) {
	}

	public:
	template <typename DeleterT__>
	constexpr UniquePointer(PointerType pointer_, DeleterT__ const& deleter_) : m_pointer_(pointer_), m_deleter_(deleter_) {
	}
#	endif


	public:
	~UniquePointer() DD_NOEXCEPT {
		destruct();
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	DeleterType& get_deleter() const DD_NOEXCEPT {
		return m_deleter_;
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	ProcessType reset(PointerType pointer_ = PointerType()) DD_NOEXCEPT {
		destruct();
		m_pointer_ = pointer_;
	}


	public:
	PointerType release() DD_NOEXCEPT {
		PointerType temp_(get_pointer());
		m_pointer_ = PointerType();
		return temp_;
	}


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT {
		using DD::swap;
		swap(m_pointer_, target_.m_pointer_);
		swap(m_deleter_, target_.m_deleter_);
	}


	private:
	ProcessType destruct() const DD_NOEXCEPT {
		get_deleter(get_pointer());
	}


	DD_DELETE_COPY_ASSIGNMENT(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept(true) {
		swap(origin_);
	}

#	endif

	public:
	ThisType& operator =(PointerType pointer_) DD_NOEXCEPT {
		reset(pointer_);
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::UniquePointer::operator *' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::UniquePointer::operator ->' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename ValueT_>
struct UniquePointer<ValueT_, DefaultTag> : Comparable<ValueT_, DefaultTag> {
	public:
	DD_ALIAS(ThisType, UniquePointer<ValueT_ DD_COMMA DefaultTag>);
	DD_ALIAS(DeleterType, void);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(DifferenceType, DD::DifferenceType);


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
#	else
	UniquePointer() throw() : m_pointer_() {
	}
#	endif

	DD_DELETE_COPY_CONSTRUCTOR(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer(ThisType&& origin_) noexcept : m_pointer_(origin_.release()) {
	}

#	endif

	public:
	explicit DD_CONSTEXPR UniquePointer(PointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
	}


	public:
	~UniquePointer() DD_NOEXCEPT {
		destruct();
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
	ProcessType reset(PointerType pointer_ = PointerType()) DD_NOEXCEPT {
		destruct();
		m_pointer_ = pointer_;
	}


	public:
	PointerType release() DD_NOEXCEPT {
		PointerType temp(get_pointer());
		m_pointer_ = PointerType();
		return temp;
	}


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT {
		using DD::swap;
		swap(m_pointer_, target_.m_pointer_);
	}


	private:
	ProcessType destruct() const DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
		delete get_pointer();
	}


	DD_DELETE_COPY_ASSIGNMENT(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept(true) {
		swap(origin_);
	}

#	endif

	public:
	ThisType& operator =(PointerType pointer_) DD_NOEXCEPT {
		reset(pointer_);
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::UniquePointer::operator *' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::UniquePointer::operator ->' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename ValueT_>
struct UniquePointer<ValueT_[], DefaultTag> : Comparable<ValueT_[], DefaultTag> {
	public:
	DD_ALIAS(ThisType, UniquePointer<ValueT_ DD_COMMA void>);
	DD_ALIAS(DeleterType, void);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(DifferenceType, DD::DifferenceType);


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
#	else
	UniquePointer() throw() : m_pointer_() {
	}
#	endif

	DD_DELETE_COPY_CONSTRUCTOR(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer(ThisType&& origin_) noexcept : m_pointer_(origin_.release()) {
	}

#	endif

	public:
	DD_CONSTEXPR UniquePointer(PointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
	}


	public:
	~UniquePointer() DD_NOEXCEPT {
		destruct();
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
	ProcessType reset(PointerType target = PointerType()) DD_NOEXCEPT {
		destruct();
		m_pointer_ = target;
	}


	public:
	PointerType release() DD_NOEXCEPT {
		PointerType temp_(get_pointer());
		m_pointer_ = PointerType();
		return temp_;
	}


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT {
		using DD::swap;
		swap(m_pointer_, target_.m_pointer_);
	}


	private:
	ProcessType destruct() const DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
		delete[] get_pointer();
	}


	DD_DELETE_COPY_ASSIGNMENT(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept {
		swap(origin_);
	}

#	endif

	public:
	ThisType& operator =(PointerType pointer_) DD_NOEXCEPT {
		reset(pointer_);
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::UniquePointer::operator *' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		DD_ASSERT(is_valid(), "Invalid pointer dereferenced: 'DD::UniquePointer::operator ->' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



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
