//	DDCPP/standard/bits/DD_FunctorGreater.hpp
#ifndef DD_FUNCTOR_GREATER_HPP_INCLUDED_
#	define DD_FUNCTOR_GREATER_HPP_INCLUDED_ 1



#	include "DD_Functor.hpp"



DD_BEGIN
template <typename ObjectT_>
struct FunctorGreater : BinaryFunctor<ValidityType, ObjectT_, ObjectT_> {
	ValidityType operator ()(ObjectT_ object_1__, ObjectT_ object_2__) const DD_NOEXCEPT_AS(bool(object_2__ < object_1__)) {
		return object_2__ < object_1__;
	}
	
	
};



DD_END



#endif
