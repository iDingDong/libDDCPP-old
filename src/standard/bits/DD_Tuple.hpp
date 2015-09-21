//	DDCPP/standard/bits/DD_Tuple.hpp
#ifndef _DD_TUPLE_HPP_INCLUDED
#	define _DD_TUPLE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::Tuple'.



#	endif
#	include "DD_forward.hpp"
#	include "DD_TypeList.hpp"



_DD_DETAIL_BEGIN
template <SubscriptType _index_c, typename... _ValuesT>
struct _Tuple {
	public:
	using ThisType = _Tuple<_index_c>;
	using StorageType = _Tuple<_index_c>;
	static SubscriptType constexpr index = _index_c;
	using TypeList = TypeList<_ValuesT...>;


};



template <SubscriptType _index_c, typename _ValueT, typename... _ValuesT>
struct _Tuple<_index_c, _ValueT, _ValuesT...> : _Tuple<_index_c, _ValueT>, _Tuple<_index_c + 1, _ValuesT...> {
	public:
	using StorageType = _Tuple<_index_c, _ValueT>;
	using RestType = _Tuple<_index_c + 1, _ValuesT...>;
	using ThisType = _Tuple<_index_c, _ValueT, _ValuesT...>;
	static SubscriptType constexpr index = _index_c;
	using TypeList = TypeList<_ValueT, _ValuesT...>;
	using ValueType = _ValueT;

	public:
	static LengthType constexpr length_constant = sizeof...(_ValuesT) + 1;


	public:
	constexpr _Tuple() = default;

	public:
	constexpr _Tuple(ThisType const& _origin) = default;

	public:
	constexpr _Tuple(ThisType&& _origin) = default;

	public:
	template <typename _ValueT_, typename... _ValuesT_>
	explicit constexpr _Tuple(_ValueT_&& __value_, _ValuesT_&&... __values_) noexcept(
		noexcept(StorageType(forward<_ValueT_>(__value_))) &&
		noexcept(RestType(forward<_ValuesT_>(__values_)...))
	) : StorageType(forward<_ValueT_>(__value_)), RestType(forward<_ValuesT_>(__values_)...) {
	}


	public:
	~_Tuple() = default;


	public:
	ThisType& operator =(ThisType const& _origin) = default;

	public:
	ThisType& operator =(ThisType&& _origin) = default;


};



template <SubscriptType _index_c, typename _ValueT>
struct _Tuple<_index_c, _ValueT> {
	public:
	using ThisType = _Tuple<_index_c, _ValueT>;
	using StorageType = ThisType;
	using RestType = _Tuple<_index_c + 1>;
	static SubscriptType constexpr index = _index_c;
	using TypeList = TypeList<_ValueT>;
	using ValueType = _ValueT;

	public:
	using ReferenceType = ValueType&;
	using ConstReferenceType = ValueType const&;
	using PointerType = ValueType*;
	using ConstPointerType = ValueType const*;


	private:
	ValueType _m_value = ValueType();


	public:
	constexpr _Tuple() = default;

	public:
	constexpr _Tuple(ThisType const& _origin) = default;

	public:
	constexpr _Tuple(ThisType&& _origin) = default;

	public:
	template <typename _ValueT_>
	explicit constexpr _Tuple(_ValueT_&& __value_) noexcept(
		noexcept(ValueType(forward<_ValueT_>(__value_)))
	) : _m_value(forward<_ValueT_>(__value_)) {
	}


	public:
	~_Tuple() = default;


	public:
	ValueType& get_value() noexcept {
		return _m_value;
	}

	public:
	ValueType const& get_value() const noexcept {
		return _m_value;
	}


	public:
	ThisType& operator =(ThisType const& _origin) = default;

	public:
	ThisType& operator =(ThisType&& _origin) = default;


};



template <SubscriptType _index_c, typename _ValueT>
inline _ValueT& get_value(_Tuple<_index_c, _ValueT>& __tuple) {
	return __tuple.get_value();
}

template <SubscriptType _index_c, typename _ValueT>
inline _ValueT const& get_value(_Tuple<_index_c, _ValueT> const& __tuple) {
	return __tuple.get_value();
}

template <typename _ValueT, SubscriptType _index_c>
inline _ValueT& get_value(_Tuple<_index_c, _ValueT>& __tuple) {
	return __tuple.get_value();
}

template <typename _ValueT, SubscriptType _index_c>
inline _ValueT const& get_value(_Tuple<_index_c, _ValueT> const& __tuple) {
	return __tuple.get_value();
}


/*
template <SubscriptType _index_c, typename _ValueT1, typename _ValueT2>
inline ValidityType constexpr operator ==(
	_Tuple<_index_c, _ValueT1> const& _tuple_1,
	_Tuple<_index_c, _ValueT2> const& _tuple_2
) noexcept(noexcept(get_value<_index_c>(_tuple_1) == get_value<_index_c>(_tuple_2))) {
	return get_value<_index_c>(_tuple_1) == get_value<_index_c>(_tuple_2);
}

template <SubscriptType _index_c, typename _ValueT, typename..._ValuesT>
inline ValidityType constexpr operator ==(
	_Tuple<_index_c, _ValueT> const& _tuple_1,
	_Tuple<_index_c, _ValuesT...> const& _tuple_2
) noexcept {
	return false;
}

template <SubscriptType _index_c, typename _ValueT, typename..._ValuesT>
inline ValidityType constexpr operator ==(
	_Tuple<_index_c, _ValuesT...> const& _tuple_1,
	_Tuple<_index_c, _ValueT> const& _tuple_2
) noexcept {
	return false;
}

template <SubscriptType _index_c, typename... _ValuesT1, typename... _ValuesT2>
inline ValidityType constexpr operator ==(
	_Tuple<_index_c, _ValuesT1...> const& _tuple_1,
	_Tuple<_index_c, _ValuesT2...> const& _tuple_2
) noexcept(noexcept(static_cast<ValidityType>(
	get_value<_index_c>(_tuple_1) == get_value<_index_c>(_tuple_2) &&
	operator ==<_index_c + 1>(_tuple_1, _tuple_2)
))) {
	return _TupleEqual<0>::_equal(_tuple_1, _tuple_2);
}
*/



_DD_DETAIL_END



_DD_BEGIN
template <typename... _ValuesT>
using Tuple = _detail::_Tuple<0, _ValuesT...>;



using _detail::get_value;



_DD_END



#endif
