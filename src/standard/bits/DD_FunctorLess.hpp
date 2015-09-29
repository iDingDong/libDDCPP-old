//	DDCPP/standard/bits/DD_FunctorLess.hpp
#ifndef DD_FUNCTOR_LESS_HPP_INCLUDED_
#	define DD_FUNCTOR_LESS_HPP_INCLUDED_ 1



#	include "DD_Functor.hpp"



DD_BEGIN
template <typename ObjectT_>
struct FunctorLess : BinaryFunctor<ValidityType, ObjectT_, ObjectT_> {
	ValidityType operator ()(ObjectT_ object_1__, ObjectT_ object_2__) const DD_NOEXCEPT_AS(bool(object_1__ < object_2__)) {
		return object_1__ < object_2__;
	}
	
	
};



DD_END



#endif
