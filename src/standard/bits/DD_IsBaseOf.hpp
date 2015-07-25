//	DDCPP/standard/bits/DD_IsBaseOf.hpp
#ifndef _DD_IS_BASE_OF_HPP_INCLUDED
#	define _DD_IS_BASE_OF_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsBaseOf'.



#	endif
#	include "DD_Or.hpp"
#	include "DD_IsClass.hpp"



DD_DETAIL_BEGIN
template <typename _BaseT, typename _DerivedT>
struct _IsBaseOf {
	template <typename _BaseT_, typename _DerivedT_>
	struct _Host {
		DD_CONSTEXPR operator _BaseT_*() const DD_NOEXCEPT;
		DD_CONSTEXPR operator _DerivedT_*() DD_NOEXCEPT;
		
		
	};
	
	
	static FalseType constexpr _match(_BaseT*, int) noexcept;
	
	template <typename IntT_>
	static TrueType constexpr _match(_DerivedT*, IntT_) noexcept {
		return true;
	}
	
	
	static ValidityType constexpr value = OrType<
		AndType<decltype(_IsBaseOf<_BaseT, _DerivedT>::_match(_Host<_BaseT, _DerivedT>(), int())), IsClass<_BaseT, _DerivedT>>,
		StdIntegralConstant<std::is_base_of<_BaseT, _DerivedT>>
	>::value;
	
	
};



template <typename _ObjectT>
struct _IsBaseOf<_ObjectT, _ObjectT> {
	static ValidityType constexpr value = IsClass<_ObjectT>::value || std::is_base_of<_ObjectT, _ObjectT>::value;
	
	
};



DD_DETAIL_END



DD_BEGIN
template <typename _BaseT, typename... _DerivedsT>
using IsBaseOf = AndType<BoolConstant<detail::_IsBaseOf<_BaseT, _DerivedsT>::value>...>;



DD_END



#endif
