//	DDCPP/standard/bits/DD_dereference.hpp
#ifndef DD_DEREFERENCE_HPP_INCLUDED_
#	define DD_DEREFERENCE_HPP_INCLUDED_ 1



#	include "DD_IteratorReference.hpp"



DD_BEGIN_
template <typename PointerT_>
inline DD_MODIFY_TRAIT(IteratorReference, PointerT_) DD_CONSTEXPR dereference(PointerT_ const& pointer__) DD_NOEXCEPT_AS(*pointer__) {
	return *pointer__;
}



DD_END_



#endif
