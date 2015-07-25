//	DDCPP/standard/bits/DD_forward.hpp
#ifndef _DD_FORWARD_HPP_INCLUDED
#	define _DD_FORWARD_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::forward'.



#	endif
#	include "DD_IsLvalueReference.hpp"
#	include "DD_RemoveReference.hpp"



DD_BEGIN
template <typename _ObjectT>
inline _ObjectT&& forward(RemoveReferenceType<_ObjectT>& __object) noexcept {
	return static_cast<_ObjectT&&>(__object);
}

template <typename _ObjectT>
inline _ObjectT&& forward(RemoveReferenceType<_ObjectT>&& __object) noexcept {
	static_assert(!IsLvalueReference<_ObjectT>::value, "Template argument substituting '_ObjectT' is an lvalue reference type");
	return static_cast<_ObjectT&&>(__object);
}



DD_END



#endif
