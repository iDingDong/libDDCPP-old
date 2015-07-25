//	DDCPP/standard/bits/DD_dereference.hpp
#ifndef _DD_DEREFERENCE_HPP_INCLUDED
#	define _DD_DEREFERENCE_HPP_INCLUDED 1



#	include "DD_IteratorReference.hpp"



DD_BEGIN
template <typename _PointerT>
inline DD_MODIFY_TRAIT(IteratorReference, _PointerT) DD_CONSTEXPR dereference(_PointerT const& __pointer) DD_NOEXCEPT_AS(*__pointer) {
	return *__pointer;
}



DD_END



#endif
