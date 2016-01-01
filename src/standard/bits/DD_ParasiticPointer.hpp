//	DDCPP/standard/bits/DD_ParasiticPointer.hpp
#ifndef DD_PARASITIC_POINTER_HPP_INCLUDED_
#	define DD_PARASITIC_POINTER_HPP_INCLUDED_



#	include "DD_Tags.hpp"
#	include "DD_SpecificTypeNested.hpp"
#	include "DD_fabricate.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#		include "DD_forward.hpp"
#	endif
#	include "DD_Agent.hpp"
#	include "DD_address_of.hpp"
#	include "DD_UniversalDeleter.hpp"
#	include "DD_destroy.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, typename DeleterT_ = UniversalDeleter>
struct ParasiticPointer;



template <typename ValueT_, typename DeleterT_ = UniversalDeleter>
struct Parasitifer : Agent<DeleterT_> {
	public:
	DD_ALIAS(DestroyAgent, Agent<DeleterT_>);
	DD_ALIAS(ThisType, Parasitifer<ValueT_ DD_COMMA DeleterT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);
	DD_ALIAS(DeleterType, DeleterT_);

	public:
	DD_ALIAS(LengthType, ::DD::LengthType);


	private:
	ValueType m_value_ DD_IN_CLASS_INITIALIZE(ValueType());
	LengthType m_reference_count_ DD_IN_CLASS_INITIALIZE(LengthType());


	public:
#	if __cplusplus >= 201103L
	constexpr Parasitifer() = default;
#	else
	Parasitifer() : m_value_(), m_reference_count_() {
	}
#	endif

	public:
	DD_DELETE_COPY_CONSTRUCTOR(Parasitifer)

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(Parasitifer)

#	if __cplusplus >= 201103L
	public:
	constexpr Parasitifer(DeleterType const& deleter_) DD_NOEXCEPT_IF(
		noexcept(DestroyAgent(deleter_)) && noexcept(ValueType())
	) : DestroyAgent(deleter_) {
	}

	public:
	template <typename... ArgumentsT__>
	constexpr Parasitifer(ConstructTag tag_, ArgumentsT__&&... arguments___) DD_NOEXCEPT_IF(
		noexcept(DestroyAgent()) && noexcept(ValueType(::DD::forward<ArgumentsT__>(arguments___)...))
	) : m_value_(::DD::forward<ArgumentsT__>(arguments___)...) {
	}

	public:
	template <typename... ArgumentsT__>
	constexpr Parasitifer(DeleterType const& deleter_, ConstructTag tag_, ArgumentsT__&&... arguments___) DD_NOEXCEPT_IF(
		noexcept(DestroyAgent(deleter_)) && noexcept(ValueType(::DD::forward<ArgumentsT__>(arguments___)...))
	) : DestroyAgent(deleter_), m_value_(::DD::forward<ArgumentsT__>(arguments___)...) {
	}
#	else
	public:
	template <typename ValueT__>
	Parasitifer(ValueT__ const& value___) : m_value_(value___) {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~Parasitifer() = default;


#	endif
	public:
	DeleterType& get_deleter() const DD_NOEXCEPT {
		return DestroyAgent::get_instance();
	}


	public:
	ReferenceType get_value() DD_NOEXCEPT {
		return m_value_;
	}

	public:
	ConstReferenceType get_value() const DD_NOEXCEPT {
		return m_value_;
	}


	public:
	LengthType get_reference_count() const DD_NOEXCEPT {
		return m_reference_count_;
	}


	public:
	ProcessType refered() DD_NOEXCEPT {
		++m_reference_count_;
	}


	public:
	ProcessType released() DD_NOEXCEPT {
		DD_ASSERT(get_reference_count() >= 1, "Unable to release a parasitifer never refered: DD::Parasitifer::released");
		if (get_reference_count() == 1) {
			destroy_();
		} else {
			--m_reference_count_;
		}
	}


	public:
	ParasiticPointer<ValueType, DeleterType> get_parasitic_pointer() DD_NOEXCEPT;


	private:
	ProcessType destroy_() DD_NOEXCEPT {
		::DD::destroy(this, get_deleter());
	}


	public:
	DD_DELETE_ALL_ASSIGNMENTS(Parasitifer)


	public:
	ParasiticPointer<ValueType, DeleterType> operator &() DD_NOEXCEPT {
		return get_parasitic_pointer();
	}


};



template <typename ValueT_, typename DeleterT_>
struct ParasiticPointer {
	public:
	DD_ALIAS(ThisType, ParasiticPointer<ValueT_ DD_COMMA DeleterT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(DeleterType, DeleterT_);

	private:
	DD_ALIAS(HolderType_, Parasitifer<ValueType DD_COMMA DeleterType>);

	public:
	DD_SPECIFIC_TYPE_NESTED(Parasitifer, HolderType_)


	private:
	ParasitiferPointerType m_pointer_ DD_IN_CLASS_INITIALIZE(ParasitiferPointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr ParasiticPointer() = default;
#	else
	ParasiticPointer() throw() : m_pointer_() {
	}
#	endif

	public:
	ParasiticPointer(ThisType const& origin_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().process_after_refer_()
	) : m_pointer_(origin_.get_parasitifer_pointer()) {
		process_after_refer_();
	}

#	if __cplusplus >= 201103L
	public:
	ParasiticPointer(ThisType&& origin_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().process_after_refer_()
	) : m_pointer_(origin_.get_parasitifer_pointer()) {
		origin_.m_pointer_ = ParasitiferPointerType();
	}

#	endif
	public:
	ParasiticPointer(ParasitiferPointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
		process_after_refer_();
	}

	public:
	~ParasiticPointer() DD_NOEXCEPT {
		destruct_();
	}


	public:
	ParasitiferPointerType DD_CONSTEXPR get_parasitifer_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	PointerType DD_CONSTEXPR unguarded_get_pointer() const DD_NOEXCEPT {
		return ::DD::address_of(get_parasitifer_pointer()->get_value());
	}

	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return is_valid() ? unguarded_get_pointer() : PointerType();
	}


	public:
	LengthType DD_CONSTEXPR get_reference_count() const DD_NOEXCEPT {
		return is_valid() ? get_parasitifer_pointer()->get_reference_count() : LengthType();
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return get_parasitifer_pointer();
	}


	private:
	ProcessType process_after_refer_() DD_NOEXCEPT_AS(::DD::fabricate<ParasitiferPointerType>()->refered()) {
		if (is_valid()) {
			get_parasitifer_pointer()->refered();
		}
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(m_pointer_, other_.m_pointer_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		destruct_();
		m_pointer_ = ParasitiferPointerType();
	}

	public:
	ProcessType reset(ParasitiferPointerType pointer_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().process_after_refer_()) {
		destruct_();
		m_pointer_ = pointer_;
		process_after_refer_();
	}

	public:
	ProcessType reset(ThisType const& origin_) DD_NOEXCEPT_AS(ThisType(origin_)) {
		ThisType temp_(origin_);
		swap(temp_);
	}

#	if __cplusplus >= 201103L
	public:
	ProcessType reset(ThisType&& origin_) DD_NOEXCEPT {
		swap(origin_);
	}

#	endif

	public:
	ProcessType destruct_() DD_NOEXCEPT {
		if (is_valid()) {
			get_parasitifer_pointer()->released();
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().reset(origin_)) {
		reset(origin_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().reset(::DD::move(origin_))) {
		reset(::DD::move(origin_));
		return *this;
	}

#	endif

	public:
	ReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return *unguarded_get_pointer();
	}


	public:
	PointerType DD_CONSTEXPR operator ->() const DD_NOEXCEPT {
		return unguarded_get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit constexpr operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename ValueT_, typename DeleterT_>
inline ParasiticPointer<ValueT_, DeleterT_> Parasitifer<ValueT_, DeleterT_>::get_parasitic_pointer() DD_NOEXCEPT {
	return ParasiticPointer<ValueT_, DeleterT_>(this);
}



#	if __cplusplus >= 201103L
template <typename ValueT_, typename... ArgumentsT_>
ParasiticPointer<ValueT_> make_parasitic(ArgumentsT_&&... arguments__) DD_NOEXCEPT_AS(
	ParasiticPointer<ValueT_>(new Parasitifer<ValueT_>(::DD::forward<ArgumentsT_>(arguments__)...))
) {
	return ParasiticPointer<ValueT_>(new Parasitifer<ValueT_>(::DD::forward<ArgumentsT_>(arguments__)...));
}



#	endif
DD_DETAIL_END_



DD_BEGIN_
using detail_::Parasitifer;
using detail_::ParasiticPointer;

#	if __cplusplus >= 201103L
using detail_::make_parasitic;

#	endif


DD_END_



#endif