//	DDCPP/standard/bits/DD_Dereferenceable.hpp
#ifndef DD_DEREFERENCEABLE_HPP_INCLUDED_
#	define DD_DEREFERENCEABLE_HPP_INCLUDED_ 1



#	include "DD_address_of.hpp"
#	include "DD_IteratorPointer.hpp"



DD_BEGIN_
template <typename ObjectT_>
struct Dereferenceable {
	public:
	DD_ALIAS(Type, ObjectT_);


	public:
	DD_MODIFY_TRAIT(IteratorPointer, Type) operator ->() DD_NOEXCEPT_AS(address_of(*Type())) {
		return address_of(*static_cast<Type const&>(*this));
	}


};



DD_END_



#endif
