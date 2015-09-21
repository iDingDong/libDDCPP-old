//	DDCPP/standard/bits/DD_Incrementable.hpp
#ifndef _DD_INCREMENTABLE_HPP_INCLUDED
#	define _DD_INCREMENTABLE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ObjectT>
struct Incrementable {
	public:
	DD_ALIAS(Type, _ObjectT)


	public:
	friend Type operator ++(Type& _object, int) DD_NOEXCEPT_AS(++_object, Type(_object)) {
		Type _temp(_object);
		++_object;
		return _temp;
	}


};



_DD_END



#endif
