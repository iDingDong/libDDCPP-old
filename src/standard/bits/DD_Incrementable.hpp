//	DDCPP/standard/bits/DD_Incrementable.hpp
#ifndef DD_INCREMENTABLE_HPP_INCLUDED_
#	define DD_INCREMENTABLE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ObjectT_>
struct Incrementable {
	public:
	DD_ALIAS(Type, ObjectT_);


	public:
	friend Type operator ++(Type& object_, int) DD_NOEXCEPT_AS(++object_, Type(object_)) {
		Type temp_(object_);
		++object_;
		return temp_;
	}


};



DD_END_



#endif
