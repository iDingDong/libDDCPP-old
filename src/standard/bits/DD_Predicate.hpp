//	DDCPP/standard/bits/DD_Predicate.hpp
#ifndef DD_Predicate_HPP_INCLUDED_
#	define DD_Predicate_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Predicate'.



#	endif
#	include "DD_Function.hpp"



#	define DD_GENERATE_PREDICATE_BINARY_OPERATORS_(ARG_name_, ARG_operator_)\
	template <typename ResultT_, typename... ArgumentsT_>\
	inline Predicate<ResultT_(ArgumentsT_...)> constexpr ARG_name_(\
		Predicate<ResultT_(ArgumentsT_...)> predicate_1_,\
		Predicate<ResultT_(ArgumentsT_...)> predicate_2_\
	) {\
		return Predicate<ResultT_(ArgumentsT_...)>([predicate_1_, predicate_2_](ArgumentsT_... arguments__) mutable {\
			return predicate_1_(arguments__...) ARG_operator_ predicate_2_(arguments__...);\
		});\
	}\
	\
	\
	\
	template <typename ResultT_, typename... ArgumentsT_>\
	inline Predicate<ResultT_(ArgumentsT_...)> constexpr operator ARG_operator_(\
		Predicate<ResultT_(ArgumentsT_...)> predicate_1_,\
		Predicate<ResultT_(ArgumentsT_...)> predicate_2_\
	) {\
		return ARG_name_(predicate_1_, predicate_2_);\
	}



DD_DETAIL_BEGIN_
template <typename FunctionT_>
struct Predicate;



template <typename ResultT_, typename... ArgumentsT_>
struct Predicate<ResultT_(ArgumentsT_...)> : Function<ResultT_(ArgumentsT_...)> {
	using SuperType = Function<ResultT_(ArgumentsT_...)>;
	using ThisType = Predicate<ResultT_(ArgumentsT_...)>;


	constexpr Predicate() = default;

	constexpr Predicate(ThisType const& origin_) = default;

	constexpr Predicate(ThisType&& origin_) = default;

	constexpr Predicate(ThisType& origin_) : Predicate(static_cast<ThisType const&>(origin_)) {
	}

	template <typename FunctionT__>
	constexpr Predicate(FunctionT__&& function___) : SuperType(forward<FunctionT__>(function___)) {
	}


	~Predicate() = default;


	ThisType& operator =(ThisType const& origin_) = default;

	ThisType& operator =(ThisType&& origin_) = default;


};



template <typename ResultT_, typename... ArgumentsT_>
inline Predicate<ResultT_(ArgumentsT_...)> constexpr make_predicate(PointerType<ResultT_(ArgumentsT_...)> function_) noexcept(
	noexcept(Predicate<ResultT_(ArgumentsT_...)>(function_))
) {
	return Predicate<ResultT_(ArgumentsT_...)>(function_);
}



DD_GENERATE_PREDICATE_BINARY_OPERATORS_(add, +)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(subtract, -)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(multiply, *)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(divide, /)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(mod, %)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(bit_or, |)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(bit_and, &)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(logical_or, ||)
DD_GENERATE_PREDICATE_BINARY_OPERATORS_(logical_and, &&)



DD_DETAIL_END_



DD_BEGIN_
using detail_::Predicate;

using detail_::make_predicate;
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



#	undef DD_GENERATE_Predicate_BINARY_OPERATORS_



#endif
