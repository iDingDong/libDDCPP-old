//	DDCPP/standard/bits/DD_Uncopiable.hpp
#ifndef DD_UNCOPIABLE_HPP_INCLUDED_
#	define DD_UNCOPIABLE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
struct Uncopiable {
	public:
	DD_ALIAS(ThisType, Uncopiable);


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



DD_END_



#endif
