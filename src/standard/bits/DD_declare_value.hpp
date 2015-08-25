//	DDCPP/standard/bits/DD_declare_value.hpp
#ifndef _DD_DECLARE_VALUE_HPP_INCLUDED
#	define _DD_DECLARE_VALUE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::declare_value'.



#	endif
#	include "DD_AddRvalueReference.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _declare_value_protector {
	static constexpr ValidityType value = false;
	static AddRvalueReferenceType<_ObjectT> _declare_value() noexcept;
	
	
};



DD_DETAIL_END



DD_BEGIN
template <typename _ObjectT>
AddRvalueReferenceType<_ObjectT> declare_value() noexcept {
	static_assert(_detail::_declare_value_protector<_ObjectT>::value, "DD::declare_value is forbidden to be evaluated.");
	return _detail::_declare_value_protector<_ObjectT>::_declare_value();
}



DD_END



#endif
