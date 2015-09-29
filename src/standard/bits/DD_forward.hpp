//	DDCPP/standard/bits/DD_forward.hpp
#ifndef DD_FORWARD_HPP_INCLUDED_
#	define DD_FORWARD_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::forward'.



#	endif
#	include "DD_IsLvalueReference.hpp"
#	include "DD_RemoveReference.hpp"



DD_BEGIN_
template <typename ObjectT_>
inline ObjectT_&& forward(RemoveReferenceType<ObjectT_>& object__) noexcept {
	return static_cast<ObjectT_&&>(object__);
}

template <typename ObjectT_>
inline ObjectT_&& forward(RemoveReferenceType<ObjectT_>&& object__) noexcept {
	static_assert(!IsLvalueReference<ObjectT_>::value, "Template argument substituting 'ObjectT_' is an lvalue reference type.");
	return static_cast<ObjectT_&&>(object__);
}



DD_END_



#endif
