//	DDCPP/standard/bits/DD_StrictPointer.hpp
#ifndef DD_STRICT_POINTER_HPP_INCLUDED_
#	define DD_STRICT_POINTER_HPP_INCLUDED_ 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_ValueTypeNested.hpp"
#	include "DD_DefaultDeleter.hpp"
#	include "DD_swap.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, ProcessType(&deleter_c_)(ValueT_*) DD_NOEXCEPT = DefaultDeleter<ValueT_>::operate>
struct StrictPointer : Comparable<StrictPointer<ValueT_ DD_COMMA deleter_c_>> {
	public:
	DD_ALIAS(ThisType, StrictPointer<ValueT_ DD_COMMA deleter_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_);
	DD_ALIAS(DeleterType, ProcessType(&)(ValueT_*));
	static DeleterType DD_CONSTANT deleter = deleter_c_;


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr StrictPointer() = default;
#	else
	StrictPointer() throw() : m_pointer_() {
	}
#	endif

	DD_DELETE_COPY_CONSTRUCTOR(StrictPointer)

#	if __cplusplus >= 201103L
	public:
	constexpr StrictPointer(ThisType&& origin_) noexcept : m_pointer_(origin_.release()) {
	}

#	endif

	public:
	explicit DD_CONSTEXPR StrictPointer(PointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
	}


	public:
	~StrictPointer() DD_NOEXCEPT {
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
	ProcessType reset() DD_NOEXCEPT {
		destruct();
		m_pointer_ = PointerType();
	}

	public:
	ProcessType reset(PointerType pointer_) DD_NOEXCEPT {
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
		using ::DD::swap;
		swap(m_pointer_, target_.m_pointer_);
	}


	private:
	ProcessType destruct() const DD_NOEXCEPT {
		deleter(get_pointer());
	}


	DD_DELETE_COPY_ASSIGNMENT(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept {
		swap(origin_);
		return *this;
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



DD_DETAIL_END_



DD_BEGIN_
using detail_::StrictPointer;



DD_END_



#endif