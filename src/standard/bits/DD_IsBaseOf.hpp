//	DDCPP/standard/bits/DD_IsBaseOf.hpp
#ifndef DD_IS_BASE_OF_HPP_INCLUDED_
#	define DD_IS_BASE_OF_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsBaseOf'.



#	endif
#	include "DD_Or.hpp"
#	include "DD_IsClass.hpp"



DD_DETAIL_BEGIN_
template <typename BaseT_, typename DerivedT_>
struct IsBaseOf_ {
	template <typename BaseT__, typename DerivedT__>
	struct Host_ {
		DD_CONSTEXPR operator BaseT__*() const DD_NOEXCEPT;
		DD_CONSTEXPR operator DerivedT__*() DD_NOEXCEPT;


	};


	static FalseType constexpr match_(BaseT_*, int) noexcept;

	template <typename IntT_>
	static TrueType constexpr match_(DerivedT_*, IntT_) noexcept {
		return true;
	}


	static ValidityType constexpr value = OrType<
		AndType<decltype(IsBaseOf_<BaseT_, DerivedT_>::match_(Host_<BaseT_, DerivedT_>(), int())), IsClass<BaseT_, DerivedT_>>,
		StdIntegralConstant<std::is_base_of<BaseT_, DerivedT_>>
	>::value;


};



template <typename ObjectT_>
struct IsBaseOf_<ObjectT_, ObjectT_> {
	static ValidityType constexpr value = IsClass<ObjectT_>::value || std::is_base_of<ObjectT_, ObjectT_>::value;


};



template <typename BaseT_, typename... DerivedsT_>
struct IsBaseOf : AndType<BoolConstant<IsBaseOf_<BaseT_, DerivedsT_>::value>...> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsBaseOf;



DD_END_



#endif
