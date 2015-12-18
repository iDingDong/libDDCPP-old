//	DDCPP/standard/bits/DD_construct.hpp
#ifndef DD_CONSTRUCT_HPP_INCLUDED_HPP_
#	define DD_CONSTRUCT_HPP_INCLUDED_HPP_ 1



#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_address_of.hpp"
#	include "DD_IteratorValue.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename PointerT_, typename... ArgumentsT_>
ProcessType construct(PointerT_ pointer__, ArgumentsT_&&... arguments__) noexcept(
	noexcept(new (::DD::address_of(*pointer__)) IteratorValueType<PointerT_>(forward<ArgumentsT_>(arguments__)...))
) {
	new (::DD::address_of(*pointer__)) IteratorValueType<PointerT_>(forward<ArgumentsT_>(arguments__)...);
}
#	else
template <typename PointerT_, typename ValueT_>
ProcessType construct(PointerT_ pointer__, ValueT_ const& value__) {
	new (::DD::address_of(*pointer__)) typename IteratorValue<PointerT_>::Type(value__);
}
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::construct;



DD_END_



#endif
