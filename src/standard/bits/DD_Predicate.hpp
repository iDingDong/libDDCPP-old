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
template <typename FunctionT_, typename AllocatorT_ = Allocator<void>>
struct Predicate;



template <typename AllocatorT_, typename ResultT_, typename... ArgumentsT_>
struct Predicate<ResultT_(ArgumentsT_...), AllocatorT_> : Function<ResultT_(ArgumentsT_...), AllocatorT_> {
	public:
	using SuperType = Function<ResultT_(ArgumentsT_...), AllocatorT_>;
	using ThisType = Predicate<ResultT_(ArgumentsT_...), AllocatorT_>;
	using AllocatorType = AllocatorT_;


	public:
	constexpr Predicate() = default;

	public:
	Predicate(ThisType const& origin_) = default;

	public:
	Predicate(ThisType&& origin_) = default;

	public:
	Predicate(ThisType& origin_) noexcept(
		noexcept(SuperType(static_cast<SuperType&>(origin_)))
	) : SuperType(static_cast<SuperType&>(origin_)) {
	}

	public:
	explicit Predicate(AllocatorType const& allocator_) noexcept(
		noexcept(SuperType(allocator_))
	) : SuperType(allocator_) {
	}

	public:
	template <typename FunctionT__>
	Predicate(FunctionT__&& function___) noexcept(
		noexcept(SuperType(forward<FunctionT__>(function___)))
	) : SuperType(forward<FunctionT__>(function___)) {
	}

	public:
	template <typename FunctionT__>
	Predicate(AllocatorType const& allocator_, FunctionT__&& function___) noexcept(
		noexcept(SuperType(allocator_, forward<FunctionT__>(function___)))
	) : SuperType(allocator_, forward<FunctionT__>(function___)) {
	}


	public:
	ProcessType swap(ThisType& other_) noexcept(noexcept(fabricate<ThisType>().SuperType::swap(other_))) {
		SuperType::swap(other_);
	}


	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;

	public:
	ThisType& operator =(ThisType& origin_) {
		static_cast<SuperType&>(*this) = static_cast<SuperType&>(origin_);
		return *this;
	}

	public:
	template <typename FunctionT__>
	ThisType& operator =(FunctionT__&& function___) {
		static_cast<SuperType&>(*this) = forward<FunctionT__>(function___);
		return *this;
	}


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
