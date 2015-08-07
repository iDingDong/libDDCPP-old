//	DDCPP/standard/bits/DD_FunctorGreater.hpp
#ifndef _DD_FUNCTOR_GREATER_HPP_INCLUDED
#	define _DD_FUNCTOR_GREATER_HPP_INCLUDED 1



#	include "DD_Functor.hpp"



DD_BEGIN
template <typename _ObjectT>
struct FunctorGreater : BinaryFunctor<ValidityType, _ObjectT, _ObjectT> {
	ValidityType operator ()(_ObjectT __object_1, _ObjectT __object_2) const DD_NOEXCEPT_AS(bool(__object_2 < __object_1)) {
		return __object_2 < __object_1;
	}
	
	
};



DD_END



#endif
