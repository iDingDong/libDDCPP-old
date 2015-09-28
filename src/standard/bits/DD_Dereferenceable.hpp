//	DDCPP/standard/bits/DD_Dereferenceable.hpp
#ifndef _DD_DEREFERENCEABLE_HPP_INCLUDED
#	define _DD_DEREFERENCEABLE_HPP_INCLUDED 1



#	include "DD_address_of.hpp"
#	include "DD_IteratorPointer.hpp"



_DD_BEGIN
template <typename _ObjectT>
struct Dereferenceable {
	public:
	DD_ALIAS(Type, _ObjectT);


	public:
	DD_MODIFY_TRAIT(IteratorPointer, Type) operator ->() DD_NOEXCEPT_AS(address_of(*Type())) {
		return address_of(*static_cast<Type const&>(*this));
	}


};



_DD_END



#endif
