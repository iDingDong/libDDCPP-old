//	DDCPP/standard/bits/DD_Predicator.hpp
#ifndef DD_PREDICATOR_HPP_INCLUDED_
#	define DD_PREDICATOR_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Predicator'.



#	endif
#	include "DD_Function.hpp"



#	define DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(ARG_name_, ARG_operator_)\
	template <typename ResultT_, typename... ArgumentsT_>\
	inline Predicator<ResultT_(ArgumentsT_...)> constexpr ARG_name_(\
		Predicator<ResultT_(ArgumentsT_...)> predicator_1_,\
		Predicator<ResultT_(ArgumentsT_...)> predicator_2_\
	) {\
		return Predicator<ResultT_(ArgumentsT_...)>([predicator_1_, predicator_2_](ArgumentsT_... arguments__) mutable {\
			return predicator_1_(arguments__...) ARG_operator_ predicator_2_(arguments__...);\
		});\
	}\
	\
	\
	\
	template <typename ResultT_, typename... ArgumentsT_>\
	inline Predicator<ResultT_(ArgumentsT_...)> constexpr operator ARG_operator_(\
		Predicator<ResultT_(ArgumentsT_...)> predicator_1_,\
		Predicator<ResultT_(ArgumentsT_...)> predicator_2_\
	) {\
		return ARG_name_(predicator_1_, predicator_2_);\
	}



DD_DETAIL_BEGIN_
template <typename FunctionT_>
struct Predicator;



template <typename ResultT_, typename... ArgumentsT_>
struct Predicator<ResultT_(ArgumentsT_...)> : Function<ResultT_(ArgumentsT_...)> {
	using SuperType = Function<ResultT_(ArgumentsT_...)>;
	using ThisType = Predicator<ResultT_(ArgumentsT_...)>;


	constexpr Predicator() = default;

	constexpr Predicator(ThisType const& origin_) = default;

	constexpr Predicator(ThisType&& origin_) = default;

	constexpr Predicator(ThisType& origin_) : Predicator(static_cast<ThisType const&>(origin_)) {
	}

	template <typename FunctionT__>
	constexpr Predicator(FunctionT__&& function___) : SuperType(forward<FunctionT__>(function___)) {
	}


	~Predicator() = default;


	ThisType& operator =(ThisType const& origin_) = default;

	ThisType& operator =(ThisType&& origin_) = default;


};



template <typename ResultT_, typename... ArgumentsT_>
inline Predicator<ResultT_(ArgumentsT_...)> constexpr make_predicator(PointerType<ResultT_(ArgumentsT_...)> function_) noexcept(
	noexcept(Predicator<ResultT_(ArgumentsT_...)>(function_))
) {
	return Predicator<ResultT_(ArgumentsT_...)>(function_);
}



DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(add, +)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(subtract, -)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(multiply, *)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(divide, /)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(mod, %)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(bit_or, |)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(bit_and, &)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(logical_or, ||)
DD_GENERATE_PREDICATOR_BINARY_OPERATORS_(logical_and, &&)



DD_DETAIL_END_



DD_BEGIN_
using detail_::Predicator;

using detail_::make_predicator;
using detail_::add;
using detail_::subtract;
using detail_::multiply;
using detail_::divide;
using detail_::mod;
using detail_::bit_or;
using detail_::bit_and;
using detail_::logical_or;
using detail_::logical_and;



DD_END_



#	undef DD_GENERATE_PREDICATOR_BINARY_OPERATORS_



#endif
