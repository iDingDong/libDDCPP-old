//	DDCPP/standard/bits/DD_Bitset.hpp
#ifndef DD_BITSET_HPP_INCLUDED_
#	define DD_BITSET_HPP_INCLUDED_ 1



#	include "DD_ArithmeticLimit.hpp"



DD_DETAIL_BEGIN_
template <LengthType length_c_>
struct Bitset {
	public:
	DD_ALIAS(ThisType, Bitset<length_c_>);
	static DD_CONSTEXPR LengthType length = length_c_;

	private:
	DD_ALIAS(WordType_, unsigned long int);

	public:



};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
