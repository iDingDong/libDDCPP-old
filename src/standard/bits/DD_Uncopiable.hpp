//	DDCPP/standard/bits/DD_Uncopiable.hpp
#ifndef _DD_UNCOPIABLE_HPP_INCLUDED
#	define _DD_UNCOPIABLE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
struct Uncopiable {
	public:
	DD_ALIAS(ThisType, Uncopiable)


#	if __cplusplus >= 201103L
	protected:
	Uncopiable() = default;

	public:
	Uncopiable(ThisType const&) = delete;

	protected:
	~Uncopiable() = default;


	public:
	ThisType& operator =(ThisType const&) = delete;
#	else
	protected:
	Uncopiable() throw() {
	}

	private:
	Uncopiable(ThisType const&);

	protected:
	~Uncopiable() throw() {
	}


	private:
	ThisType& operator =(ThisType const&);
#	endif


};



_DD_END



#endif
