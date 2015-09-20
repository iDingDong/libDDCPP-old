//	DDCPP/standard/bits/DD_bind.hpp
#ifndef _DD_BIND_HPP_INCLUDED
#	define DD_BINARY_FIND_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::bind'.



#	endif
#	include "DD_Decay.hpp"
#	include "DD_Tuple.hpp"
#	include "DD_Functor.hpp"



#	define DD_PLACE_HOLDER_BEGIN DD_BEGIN namespace place_holder {
#	define DD_PLACE_HOLDER_END } DD_END

#	define DD_GENERATE_PLACE_HOLDER(_ARG_index) DD_PLACE_HOLDER_BEGIN static PlaceHolder<_ARG_index> constexpr _##_ARG_index; DD_PLACE_HOLDER_END



DD_DETAIL_BEGIN
template <SubscriptType... _subscripts_c>
struct _Indexs {
};



template <SubscriptType _subscript_c, SubscriptType... subscripts_c>
struct _MakeIndexs : _MakeIndexs<_subscript_c - 1, _subscript_c - 1, subscripts_c...> {
};



template <SubscriptType... _subscripts_c>
struct _MakeIndexs<0, _subscripts_c...> {
	using Type = _Indexs<_subscripts_c...>;


};



template <SubscriptType _subscript_c>
struct _PlaceHolder {
};




template <typename _FunctionT>
struct _ResultOf : _ResultOf<decltype(&_FunctionT::operator())> {
};



template <typename _FunctionT>
struct _ResultOf<_FunctionT*> : _ResultOf<_FunctionT> {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _ResultOf<_ResultT(*)(_ArgumentsT...)> {
	using Type = _ResultT;


};



template <typename _ResultT, typename _ClassT, typename... _ArgumentsT>
struct _ResultOf<_ResultT(_ClassT::*)(_ArgumentsT...)> {
	using Type = _ResultT;


};



template <typename _ArgumentT, typename... _ArgumentsT>
inline _ArgumentT&& select(_ArgumentT&& __argument, Tuple<_ArgumentsT...>& _arguments_pack) noexcept {
	return forward<_ArgumentT>(__argument);
}

template <SubscriptType _index_c, typename... _ArgumentsT>
inline auto select(
	_PlaceHolder<_index_c> __place_holder,
	Tuple<_ArgumentsT...>& _arguments_pack
) noexcept(noexcept(get_value<_index_c>(_arguments_pack))) -> decltype(get_value<_index_c>(_arguments_pack)) {
	return get_value<_index_c>(_arguments_pack);
}



template <typename _FunctionT, typename... _ArgumentsT>
struct _BindFunctor : Functor<typename _ResultOf<_FunctionT>::Type, _ArgumentsT...> {
	public:
	using FunctionType = DecayType<_FunctionT>;
	using ArgumentsList = TypeList<_ArgumentsT...>;

	public:
	using ResultType = typename _ResultOf<_FunctionT>::Type;
	using ArgumentsPack = Tuple<_ArgumentsT...>;


	public:
	template <typename... _ArgumentsT_>
	ResultType operator ()(_ArgumentsT_&&... __arguments_);


};



DD_DETAIL_END



DD_PLACE_HOLDER_BEGIN
template <SubscriptType _index_c>
using PlaceHolder = ::DD::_detail::_PlaceHolder<_index_c>;



DD_PLACE_HOLDER_END



DD_GENERATE_PLACE_HOLDER(0)
DD_GENERATE_PLACE_HOLDER(1)
DD_GENERATE_PLACE_HOLDER(2)
DD_GENERATE_PLACE_HOLDER(3)
DD_GENERATE_PLACE_HOLDER(4)
DD_GENERATE_PLACE_HOLDER(5)
DD_GENERATE_PLACE_HOLDER(6)
DD_GENERATE_PLACE_HOLDER(7)
DD_GENERATE_PLACE_HOLDER(8)
DD_GENERATE_PLACE_HOLDER(9)
DD_GENERATE_PLACE_HOLDER(10)
DD_GENERATE_PLACE_HOLDER(11)
DD_GENERATE_PLACE_HOLDER(12)
DD_GENERATE_PLACE_HOLDER(13)
DD_GENERATE_PLACE_HOLDER(14)
DD_GENERATE_PLACE_HOLDER(15)
DD_GENERATE_PLACE_HOLDER(16)
DD_GENERATE_PLACE_HOLDER(17)
DD_GENERATE_PLACE_HOLDER(18)
DD_GENERATE_PLACE_HOLDER(19)
DD_GENERATE_PLACE_HOLDER(20)
DD_GENERATE_PLACE_HOLDER(21)
DD_GENERATE_PLACE_HOLDER(22)
DD_GENERATE_PLACE_HOLDER(23)
DD_GENERATE_PLACE_HOLDER(24)
DD_GENERATE_PLACE_HOLDER(25)
DD_GENERATE_PLACE_HOLDER(26)
DD_GENERATE_PLACE_HOLDER(27)
DD_GENERATE_PLACE_HOLDER(28)
DD_GENERATE_PLACE_HOLDER(29)
DD_GENERATE_PLACE_HOLDER(30)
DD_GENERATE_PLACE_HOLDER(31)



DD_BEGIN
template <typename _FunctionT, typename... _ArgumentsT>
inline _detail::_BindFunctor<_FunctionT, _ArgumentsT...> bind(
	_FunctionT&& __function,
	_ArgumentsT&&... __arguments
) {
	return _detail::_BindFunctor<_FunctionT, _ArgumentsT...>(forward<_FunctionT>(__function), forward<_ArgumentsT>(__arguments)...);
}



DD_END



#	undef DD_PLACE_HOLDER_BEGIN
#	undef DD_PLACE_HOLDER_END



#endif
