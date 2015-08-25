//	DDCPP/standard/bits/DD_Tuple.hpp
#ifndef _DD_TUPLE_HPP_INCLUDED
#	define _DD_TUPLE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::Tuple'.



#	endif
#	include "DD_forward.hpp"
#	include "DD_UniquePointer.hpp"



DD_DETAIL_BEGIN
template <SubscriptType _index_c, typename... _ValuesT>
struct _Tuple;



template <SubscriptType _index_c, typename _ValueT, typename... _ValuesT>
struct _Tuple<_index_c, _ValueT, _ValuesT...> : _Tuple<_index_c, _ValueT>, _Tuple<_index_c + 1, _ValuesT...> {
	public:
	using ThisType = _Tuple<_index_c, _ValueT, _ValuesT...>;
	static SubscriptType constexpr index_constant = _index_c;
	using ValueType = _ValueT;
	
	static LengthType constexpr length_constant = sizeof...(_ValuesT) + 1;
	
	
	public:
	constexpr _Tuple() = default;
	
	public:
	constexpr _Tuple(ThisType const& _origin) = default;
	
	public:
	constexpr _Tuple(ThisType&& _origin) = default;
	
	public:
	template <typename _ValueT_, typename... _ValuesT_>
	constexpr _Tuple(_ValueT_&& __value_, _ValuesT_&&... __values_) noexcept(
		noexcept(_Tuple<_index_c, _ValueT>(forward<_ValueT_>(__value_))) &&
		noexcept(_Tuple<_index_c + 1, _ValuesT...>(forward<_ValuesT_>(__values_)...))
	) : _Tuple<_index_c, _ValueT>(forward<_ValueT_>(__value_)), _Tuple<_index_c + 1, _ValuesT...>(forward<_ValuesT_>(__values_)...) {
	}
	
	
};



template <SubscriptType _index_c, typename _ValueT>
struct _Tuple<_index_c, _ValueT> {
	public:
	using ThisType = _Tuple<_index_c, _ValueT>;
	static SubscriptType constexpr index_constant = _index_c;
	using ValueType = _ValueT;
	
	public:
	using ReferenceType = ValueType&;
	using ConstReferenceType = ValueType const&;
	using PointerType = ValueType*;
	using ConstPointerType = ValueType const*;
	
	
	private:
	UniquePointer<ValueType> _m_pointer = UniquePointer<ValueType>(new ValueType());
	
	
	public:
	constexpr _Tuple() = default;
	
	public:
	constexpr _Tuple(ThisType const& _origin) noexcept(false) : _m_pointer(new ValueType(*_origin._m_pointer)) {
	}
	
	public:
	constexpr _Tuple(ThisType&& _origin) = default;
	
	public:
	template <typename _ValueT_>
	constexpr _Tuple(_ValueT_&& __value_) noexcept(false) : _m_pointer(new ValueType(forward<_ValueT_>(__value_))) {
	}
	
	
	public:
	ValueType& get_value() noexcept {
		return *this->_m_pointer;
	}
	
	public:
	ValueType const& get_value() const noexcept {
		return *this->_m_pointer;
	}
	
	
};



template <>
struct _Tuple<0> {
	static SubscriptType constexpr index_constant = 0;
	
	
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ValuesT>
using Tuple = _detail::_Tuple<0, _ValuesT...>;



template <SubscriptType _index_c, typename _ValueT>
inline _ValueT& get_value(_detail::_Tuple<_index_c, _ValueT>& __tuple) {
	return __tuple.get_value();
}

template <SubscriptType _index_c, typename _ValueT>
inline _ValueT const& get_value(_detail::_Tuple<_index_c, _ValueT> const& __tuple) {
	return __tuple.get_value();
}

template <typename _ValueT, SubscriptType _index_c>
inline _ValueT& get_value(_detail::_Tuple<_index_c, _ValueT>& __tuple) {
	return __tuple.get_value();
}

template <typename _ValueT, SubscriptType _index_c>
inline _ValueT const& get_value(_detail::_Tuple<_index_c, _ValueT> const& __tuple) {
	return __tuple.get_value();
}



DD_END



#endif
