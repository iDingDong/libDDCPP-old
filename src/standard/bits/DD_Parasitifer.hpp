//	DDCPP/standard/bits/DD_Parasitifer.hpp
#ifndef DD_PARASITIFER_HPP_INCLUDED_
#	define DD_PARASITIFER_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_DefaultDeleter.hpp"
#	include "DD_Pair.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ParasitiferBase {
	public:
	DD_ALIAS(ThisType, ParasitiferBase<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(LengthType, ::DD::LengthType);

	private:
	DD_ALIAS(ParasitiferType_, Pair<LengthType DD_COMMA ValueType>);


	protected:
	ParasitiferType_ m_parasitifer_;


#	if __cplusplus >= 201103L
	public:
	constexpr ParasitiferBase() = default;
#	else
	public:
	ParasitiferBase() {
	}
#	endif

	public:
	DD_CONSTEXPR ParasitiferBase(ThisType const& origin_) DD_NOEXCEPT_AS(
		ParasitiferType_(LengthType() DD_COMMA origin_.get_value())
	) : m_parasitifer_(LengthType(), origin_.get_value()) {
	}

#	if __cplusplus >= 201103L
	public:
	constexpr ParasitiferBase(ThisType&& origin_) noexcept(
		noexcept(ParasitiferType_(LengthType(), move(origin_.get_value())))
	) : m_parasitifer_(LengthType(), move(origin_.m_parasitifer.get_value())) {
	}

	public:
	template <typename ValueT__>
	constexpr ParasitiferBase(ValueT__&& value___) noexcept(
		noexcept(ParasitiferType_(LengthType(), ValueType(forward<ValueT__>(value___))))
	) : m_parasitifer_(LengthType(), ValueType(forward<ValueT__>(value___))) {
	}
#	else
	public:
	template <typename ValueT__>
	ParasitiferBase(ValueT__ const& value___) : m_parasitifer_(LengthType(), ValueType(value___)) {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~ParasitiferBase() = default;


#	endif
	public:
	LengthType get_reference_count() const DD_NOEXCEPT {
		return m_parasitifer_.first;
	}


	public:
	ValidityType is_refered() const DD_NOEXCEPT {
		return get_reference_count();
	}


	public:
	ValidityType is_uniquely_refered() const DD_NOEXCEPT {
		return get_reference_count() == 1;
	}


	public:
	ReferenceType get_value() DD_NOEXCEPT {
		return m_parasitifer_.second;
	}

	public:
	ConstReferenceType get_value() const DD_NOEXCEPT {
		return m_parasitifer_.second;
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(get_value() = origin_.get_value()) {
		get_value() = origin_.get_value();
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(get_value() = move(origin_.get_value())) {
		get_value() = move(origin_.get_value());
		return *this;
	}

#	endif

};



template <
	typename ValueT_,
	ProcessType(&deleter_c_)(ParasitiferBase<ValueT_>*) DD_NOEXCEPT = DefaultDeleter<ParasitiferBase<ValueT_>>::destroy
>
struct StrictParasitifer : ParasitiferBase<ValueT_> {
	public:
	DD_ALIAS(ThisType, StrictParasitifer<ValueT_ DD_COMMA deleter_c_>);
	DD_ALIAS(SuperType, ParasitiferBase<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);
	DD_ALIAS(DeleterType, ProcessType(&)(ParasitiferBase<ValueT_>*));
	static DeleterType DD_CONSTANT deleter = deleter_c_;


#	if __cplusplus >= 201103L
	public:
	constexpr StrictParasitifer() = default;

	public:
	constexpr StrictParasitifer(ThisType const& origin_) = default;

	public:
	constexpr StrictParasitifer(ThisType&& origin_) = default;

	public:
	template <typename ValueT__>
	constexpr StrictParasitifer(ValueT__&& value___) noexcept(
		noexcept(SuperType(forward<ValueT__>(value___)))
	) : SuperType(forward<ValueT__>(value___)) {
	}
#	else
	public:
	StrictParasitifer() {
	}

	public:
	template <typename ValueT__>
	StrictParasitifer(ValueT__ const& value___) : SuperType(value___) {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~StrictParasitifer() = default;


#	endif
	public:
	ProcessType refered() DD_NOEXCEPT {
		++this->m_parasitifer_.first;
	}


	public:
	ProcessType unrefered() DD_NOEXCEPT {
		DD_ASSERT(this->get_reference_count() >= 1, "Attempt to unrefer a parasitifer never refered.");
		if (this->is_uniquely_refered()) {
			deleter(this);
		} else {
			--this->m_parasitifer_.first;
		}
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename ValueT_, typename DeleterT_ = DefaultTag>
struct Parasitifer : ParasitiferBase<ValueT_> {
	public:
	DD_ALIAS(ThisType, Parasitifer<ValueT_ DD_COMMA DeleterT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);
	DD_ALIAS(DeleterType, DeleterT_);


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::StrictParasitifer;
using detail_::Parasitifer;



DD_END_



#endif
