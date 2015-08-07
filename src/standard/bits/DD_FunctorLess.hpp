//	DDCPP/standard/bits/DD_FunctorLess.hpp
#ifndef _DD_FUNCTOR_LESS_HPP_INCLUDED
#	define _DD_FUNCTOR_LESS_HPP_INCLUDED 1



#	include "DD_Functor.hpp"



DD_BEGIN
template <typename _ObjectT>
struct FunctorLess : BinaryFunctor<ValidityType, _ObjectT, _ObjectT> {
	ValidityType operator ()(_ObjectT __object_1, _ObjectT __object_2) const DD_NOEXCEPT_AS(bool(__object_1 < __object_2)) {
		return __object_1 < __object_2;
	}
	
	
};



DD_END



#endif
