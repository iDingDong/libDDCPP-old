//	DDCPP/standard/bits/DD_bind.hpp
#ifndef DD_BIND_HPP_INCLUDED_
#	define DD_BIND_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::bind'.



#	endif
#	include "DD_IsMemberFunctionPointer.hpp"
#	include "DD_Decay.hpp"
#	include "DD_fabricate.hpp"
#	include "DD_move.hpp"
#	include "DD_invoke.hpp"
#	include "DD_Tuple.hpp"
#	include "DD_Functor.hpp"



#	define DD_PLACE_HOLDER_BEGIN_ DD_BEGIN_ namespace place_holder {
#	define DD_PLACE_HOLDER_END_ } DD_END_

#	define DD_GENERATE_PLACE_HOLDER(ARG_index_)\
		DD_PLACE_HOLDER_BEGIN_\
		static PlaceHolder<ARG_index_> constexpr _##ARG_index_##_;\
		\
		\
		\
		DD_PLACE_HOLDER_END_



DD_DETAIL_BEGIN_
template <SubscriptType... subscripts_c_>
struct Indexs_ {
};



template <SubscriptType subscript_c_, SubscriptType... subscripts_c>
struct MakeIndexs_ : MakeIndexs_<subscript_c_ - 1, subscript_c_ - 1, subscripts_c...> {
};



template <SubscriptType... subscripts_c_>
struct MakeIndexs_<0, subscripts_c_...> {
	using Type = Indexs_<subscripts_c_...>;


};



template <SubscriptType index_c_>
struct PlaceHolder_ {
	static constexpr SubscriptType index = index_c_;


};



template <typename FunctionT_>
struct ResultOf_ : ResultOf_<decltype(&FunctionT_::operator ())> {
};



template <typename FunctionT_>
struct ResultOf_<FunctionT_*> : ResultOf_<FunctionT_> {
};



template <typename ResultT_, typename... ArgumentsT_>
struct ResultOf_<ResultT_(*)(ArgumentsT_...)> {
	using Type = ResultT_;


};



template <typename ResultT_, typename ClassT_, typename... ArgumentsT_>
struct ResultOf_<ResultT_(ClassT_::*)(ArgumentsT_...)> {
	using Type = ResultT_;


};



template <typename ResultT_, typename ClassT_, typename... ArgumentsT_>
struct ResultOf_<ResultT_(ClassT_::*)(ArgumentsT_...) const> {
	using Type = ResultT_;


};



template <typename ResultT_, typename ClassT_, typename... ArgumentsT_>
struct ResultOf_<ResultT_(ClassT_::*)(ArgumentsT_...) volatile> {
	using Type = ResultT_;


};



template <typename ResultT_, typename ClassT_, typename... ArgumentsT_>
struct ResultOf_<ResultT_(ClassT_::*)(ArgumentsT_...) const volatile> {
	using Type = ResultT_;


};



template <typename ValueT_, typename TupleT_>
struct ArgumentAt_ {
	using Type = ValueT_ const&;


};



template <SubscriptType index_c_, typename TupleT_>
struct ArgumentAt_<PlaceHolder_<index_c_>, TupleT_> {
	using Type = typename TupleT_::template At<index_c_>;


};



template <typename ArgumentT_, typename... ArgumentsT_>
inline ArgumentT_&& select_(ArgumentT_&& argument__, Tuple<ArgumentsT_...>& arguments_pack_) noexcept {
	return forward<ArgumentT_>(argument__);
}

template <SubscriptType index_c_, typename... ArgumentsT_>
inline auto select_(
	PlaceHolder_<index_c_> place_holder__,
	Tuple<ArgumentsT_...>& arguments_pack_
) noexcept(noexcept(get_value<index_c_>(arguments_pack_))) -> decltype(get_value<index_c_>(arguments_pack_)) {
	return get_value<index_c_>(arguments_pack_);
}



template <typename IndexsT_>
struct BindCall_;




template <SubscriptType... indexs_c_>
struct BindCall_<Indexs_<indexs_c_...>> {
	template <typename FunctionT__, typename TupleT1__, typename TupleT2__>
	static typename ResultOf_<FunctionT__>::Type call_(
		FunctionT__ const& function___,
		TupleT1__ const& arguments_1___,
		TupleT2__&& arguments_2___
	) noexcept(noexcept(invoke(
		function___,
		forward<typename ArgumentAt_<typename TupleT1__::template At<indexs_c_>, TupleT2__>::Type>(
			select_(get_value<indexs_c_>(arguments_1___), arguments_2___)
		)...
	))) {
		return invoke(
			function___,
			forward<typename ArgumentAt_<typename TupleT1__::template At<indexs_c_>, TupleT2__>::Type>(
				select_(get_value<indexs_c_>(arguments_1___), arguments_2___)
			)...
		);
	}


};



template <typename FunctionT_, typename... ArgumentsT_>
struct BindFunctor_ : Functor<typename ResultOf_<FunctionT_>::Type, ArgumentsT_...> {
	public:
	using ThisType = BindFunctor_<FunctionT_, ArgumentsT_...>;
	using FunctionType = FunctionT_;
	using ArgumentsList = TypeList<ArgumentsT_...>;

	public:
	using ResultType = typename ResultOf_<FunctionT_>::Type;
	using ArgumentsPack = Tuple<ArgumentsT_...>;


	private:
	FunctionType m_function_;
	ArgumentsPack m_arguments_;


	public:
	template <typename FunctionT__, typename... ArgumentsT__>
	BindFunctor_(FunctionT__&& function___, ArgumentsT__&&... arguments___) noexcept(
		noexcept(FunctionType(forward<FunctionT__>(function___))) &&
		noexcept(ArgumentsPack(forward<ArgumentsT__>(arguments___)...))
	) : m_function_(forward<FunctionT__>(function___)), m_arguments_(forward<ArgumentsT__>(arguments___)...) {
	}


	public:
	FunctionType& get_function() noexcept {
		return m_function_;
	}

	public:
	FunctionType const& get_function() const noexcept {
		return m_function_;
	}


	public:
	ArgumentsPack& get_arguments() noexcept {
		return m_arguments_;
	}

	public:
	ArgumentsPack const& get_arguments() const noexcept {
		return m_arguments_;
	}


	public:
	template <typename... ArgumentsT__>
	ResultType operator ()(ArgumentsT__&&... arguments___) noexcept(
		noexcept(BindCall_<typename MakeIndexs_<ArgumentsPack::length>::Type>::call_(
			fabricate<ThisType>().get_function(),
			fabricate<ThisType>().get_arguments(),
			make_tuple(forward<ArgumentsT__>(arguments___)...)
		))
	) {
		return BindCall_<typename MakeIndexs_<ArgumentsPack::length>::Type>::call_(
			get_function(),
			get_arguments(),
			make_tuple(forward<ArgumentsT__>(arguments___)...)
		);
	}


};



template <typename FunctionT_, typename... ArgumentsT_>
inline BindFunctor_<DecayType<FunctionT_>, DecayType<ArgumentsT_>...> bind(
	FunctionT_&& function__,
	ArgumentsT_&&... arguments__
) noexcept(noexcept(
	BindFunctor_<DecayType<FunctionT_>, DecayType<ArgumentsT_>...>(
		forward<FunctionT_>(function__),
		forward<ArgumentsT_>(arguments__)...
	)
)) {
	return BindFunctor_<DecayType<FunctionT_>, DecayType<ArgumentsT_>...>(
		forward<FunctionT_>(function__),
		forward<ArgumentsT_>(arguments__)...
	);
}



DD_DETAIL_END_



DD_PLACE_HOLDER_BEGIN_
template <SubscriptType index_c_>
using PlaceHolder = ::DD::detail_::PlaceHolder_<index_c_>;



DD_PLACE_HOLDER_END_



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



DD_BEGIN_
using detail_::bind;



DD_END_



#endif
