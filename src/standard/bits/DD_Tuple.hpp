//	DDCPP/standard/bits/DD_Tuple.hpp
#ifndef DD_TUPLE_HPP_INCLUDED_
#	define DD_TUPLE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Tuple'.



#	endif
#	include "DD_Decay.hpp"
#	include "DD_fabricate.hpp"
#	include "DD_ReferenceWrapper.hpp"
#	include "DD_forward.hpp"
#	include "DD_TypeList.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct StripReferenceWrapper_ {
	using Type = ObjectT_;


};



template <typename ObjectT_>
struct StripReferenceWrapper_<ReferenceWrapper<ObjectT_>> {
	using Type = ObjectT_&;


};



template <typename ObjectT_>
struct DecayAndStrip_ {
	using Type = typename StripReferenceWrapper_<DecayType<ObjectT_>>::Type;


};



template <typename ObjectT_>
using DecayAndStripType_ = typename DecayAndStrip_<ObjectT_>::Type;



template <SubscriptType index_c_, typename... ValuesT_>
struct Tuple_;



template <SubscriptType index_c_, typename ValueT_>
inline ValueT_& get_value(Tuple_<index_c_, ValueT_>& tuple__);

template <SubscriptType index_c_, typename ValueT_>
inline ValueT_ const& get_value(Tuple_<index_c_, ValueT_> const& tuple__);

template <typename ValueT_, SubscriptType index_c_>
inline ValueT_& get_value(Tuple_<index_c_, ValueT_>& tuple__);

template <typename ValueT_, SubscriptType index_c_>
inline ValueT_ const& get_value(Tuple_<index_c_, ValueT_> const& tuple__);



template <SubscriptType index_c_, typename... ValuesT_>
struct Tuple_ {
	public:
	using ThisType = Tuple_<index_c_>;
	using StorageType = Tuple_<index_c_>;
	static SubscriptType constexpr index = index_c_;
	using TypeList = TypeList<ValuesT_...>;


};



template <SubscriptType index_c_, typename ValueT_, typename... ValuesT_>
struct Tuple_<index_c_, ValueT_, ValuesT_...> : Tuple_<index_c_, ValueT_>, Tuple_<index_c_ + 1, ValuesT_...> {
	public:
	using StorageType = Tuple_<index_c_, ValueT_>;
	using RestType = Tuple_<index_c_ + 1, ValuesT_...>;
	using ThisType = Tuple_<index_c_, ValueT_, ValuesT_...>;
	static SubscriptType constexpr index = index_c_;
	using TypeList = TypeList<ValueT_, ValuesT_...>;
	using ValueType = ValueT_;
	static LengthType constexpr length = RestType::length + 1;

	public:
	template <SubscriptType index_c__>
	using At = RemoveReferenceType<decltype(::DD::detail_::get_value<index_c__>(fabricate<ThisType>()))>;

	public:
	template <typename ValueT__>
	using Get = RemoveReferenceType<decltype(::DD::detail_::get_value<ValueT__>(fabricate<ThisType>()))>;


	public:
	constexpr Tuple_() = default;

	public:
	constexpr Tuple_(ThisType const& origin_) = default;

	public:
	constexpr Tuple_(ThisType&& origin_) = default;

	public:
	template <typename ValueT__, typename... ValuesT__>
	explicit constexpr Tuple_(ValueT__&& value___, ValuesT__&&... values___) noexcept(
		noexcept(StorageType(forward<ValueT__>(value___))) &&
		noexcept(RestType(forward<ValuesT__>(values___)...))
	) : StorageType(forward<ValueT__>(value___)), RestType(forward<ValuesT__>(values___)...) {
	}


	public:
	template <SubscriptType index_c__>
	At<index_c__>& at() noexcept {
		return ::DD::detail_::get_value<index_c__>(*this);
	}

	public:
	template <SubscriptType index_c__>
	At<index_c__> const& at() const noexcept {
		return ::DD::detail_::get_value<index_c__>(*this);
	}


	public:
	template <typename ValueT__>
	Get<ValueT__>& get() noexcept {
		return ::DD::detail_::get_value<ValueT__>(*this);
	}

	public:
	template <typename ValueT__>
	Get<ValueT__> const& get() const noexcept {
		return ::DD::detail_::get_value<ValueT__>(*this);
	}


	public:
	~Tuple_() = default;


	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


};



template <SubscriptType index_c_, typename ValueT_>
struct Tuple_<index_c_, ValueT_> {
	public:
	using ThisType = Tuple_<index_c_, ValueT_>;
	using StorageType = ThisType;
	using RestType = Tuple_<index_c_ + 1>;
	static SubscriptType constexpr index = index_c_;
	using TypeList = TypeList<ValueT_>;
	using ValueType = ValueT_;
	static LengthType constexpr length = 1;

	public:
	using ReferenceType = ValueType&;
	using ConstReferenceType = ValueType const&;
	using PointerType = ValueType*;
	using ConstPointerType = ValueType const*;

	public:
	template <SubscriptType index_c__>
	using At = RemoveReferenceType<decltype(::DD::detail_::get_value<index_c__>(fabricate<ThisType>()))>;

	public:
	template <typename ValueT__>
	using Get = RemoveReferenceType<decltype(::DD::detail_::get_value<ValueT__>(fabricate<ThisType>()))>;


	private:
	ValueType m_value_ = ValueType();


	public:
	constexpr Tuple_() = default;

	public:
	constexpr Tuple_(ThisType const& origin_) = default;

	public:
	constexpr Tuple_(ThisType&& origin_) = default;

	public:
	template <typename ValueT__>
	explicit constexpr Tuple_(ValueT__&& value___) noexcept(
		noexcept(ValueType(forward<ValueT__>(value___)))
	) : m_value_(forward<ValueT__>(value___)) {
	}


	public:
	~Tuple_() = default;


	public:
	ValueType& get_value() noexcept {
		return m_value_;
	}

	public:
	ValueType const& get_value() const noexcept {
		return m_value_;
	}


	public:
	template <SubscriptType index_c__>
	At<index_c__>& at() noexcept {
		return ::DD::detail_::get_value<index_c__>(*this);
	}

	public:
	template <SubscriptType index_c__>
	At<index_c__> const& at() const noexcept {
		return ::DD::detail_::get_value<index_c__>(*this);
	}


	public:
	template <typename ValueT__>
	Get<ValueT__>& get() noexcept {
		return ::DD::detail_::get_value<ValueT__>(*this);
	}

	public:
	template <typename ValueT__>
	Get<ValueT__> const& get() const noexcept {
		return ::DD::detail_::get_value<ValueT__>(*this);
	}


	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


};



template <typename... ValuesT_>
struct Tuple : Tuple_<0, ValuesT_...> {
	using SuperType = Tuple_<0, ValuesT_...>;
	using ThisType = Tuple<ValuesT_...>;


	public:
	DD_CONSTEXPR Tuple() = default;

	public:
	DD_CONSTEXPR Tuple(ThisType const& origin_) = default;

	public:
	DD_CONSTEXPR Tuple(ThisType&& origin_) = default;

	public:
	template <typename... ValuesT__>
	explicit constexpr Tuple(ValuesT__&&... values___) noexcept(
		noexcept(SuperType(forward<ValuesT__>(values___)...))
	) : SuperType(forward<ValuesT__>(values___)...) {
	}


	public:
	~Tuple() = default;


	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


};



template <typename... ValuesT_>
Tuple<DecayAndStripType_<ValuesT_>...> constexpr make_tuple(ValuesT_&&... elements__) noexcept(
	noexcept(Tuple<DecayAndStripType_<ValuesT_>...>(forward<ValuesT_>(elements__)...))
) {
	return Tuple<DecayAndStripType_<ValuesT_>...>(forward<ValuesT_>(elements__)...);
}


template <SubscriptType index_c_, typename ValueT_>
inline ValueT_& get_value(Tuple_<index_c_, ValueT_>& tuple__) {
	return tuple__.get_value();
}

template <SubscriptType index_c_, typename ValueT_>
inline ValueT_ const& get_value(Tuple_<index_c_, ValueT_> const& tuple__) {
	return tuple__.get_value();
}

template <typename ValueT_, SubscriptType index_c_>
inline ValueT_& get_value(Tuple_<index_c_, ValueT_>& tuple__) {
	return tuple__.get_value();
}

template <typename ValueT_, SubscriptType index_c_>
inline ValueT_ const& get_value(Tuple_<index_c_, ValueT_> const& tuple__) {
	return tuple__.get_value();
}


/*
template <SubscriptType index_c_, typename ValueT1_, typename ValueT2_>
inline ValidityType constexpr operator ==(
	Tuple_<index_c_, ValueT1_> const& tuple_1_,
	Tuple_<index_c_, ValueT2_> const& tuple_2_
) noexcept(noexcept(get_value<index_c_>(tuple_1_) == get_value<index_c_>(tuple_2_))) {
	return get_value<index_c_>(tuple_1_) == get_value<index_c_>(tuple_2_);
}

template <SubscriptType index_c_, typename ValueT_, typename...ValuesT_>
inline ValidityType constexpr operator ==(
	Tuple_<index_c_, ValueT_> const& tuple_1_,
	Tuple_<index_c_, ValuesT_...> const& tuple_2_
) noexcept {
	return false;
}

template <SubscriptType index_c_, typename ValueT_, typename...ValuesT_>
inline ValidityType constexpr operator ==(
	Tuple_<index_c_, ValuesT_...> const& tuple_1_,
	Tuple_<index_c_, ValueT_> const& tuple_2_
) noexcept {
	return false;
}

template <SubscriptType index_c_, typename... ValuesT1_, typename... ValuesT2_>
inline ValidityType constexpr operator ==(
	Tuple_<index_c_, ValuesT1_...> const& tuple_1_,
	Tuple_<index_c_, ValuesT2_...> const& tuple_2_
) noexcept(noexcept(static_cast<ValidityType>(
	get_value<index_c_>(tuple_1_) == get_value<index_c_>(tuple_2_) &&
	operator ==<index_c_ + 1>(tuple_1_, tuple_2_)
))) {
	return TupleEqual_<0>::equal_(tuple_1_, tuple_2_);
}
*/



DD_DETAIL_END_



DD_BEGIN_
using detail_::Tuple;

using detail_::get_value;
using detail_::make_tuple;



DD_END_



#endif
