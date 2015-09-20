//	DDCPP/standard/bits/DD_IsClass.hpp
#ifndef _DD_IS_CLASS_HPP_INCLUDED
#	define _DD_IS_CLASS_HPP_INCLUDED 1


#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsClass'.



#	endif
#	include "DD_Nil.hpp"
#	include "DD_IsUnion.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsClass {
	template <typename _ObjectT_>
	static ValidityType constexpr _match(int _ObjectT_::*) noexcept {
		return true;
	}

	template <typename _ObjectT_>
	static ValidityType constexpr _match(...) noexcept {
		return false;
	}


	static ValidityType constexpr value = (_IsClass<_ObjectT>::_match<_ObjectT>(nil_pointer) && !IsUnion<_ObjectT>::value ) || std::is_class<_ObjectT>::value;


};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsClass = AndType<BoolConstant<_detail::_IsClass<_ObjectsT>::value>...>;



DD_END



#endif
