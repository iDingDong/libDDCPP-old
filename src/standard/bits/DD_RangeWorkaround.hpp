//	DDCPP/standard/bits/DD_RangeWorkaround.hpp
#ifndef DD_RANGE_WORKAROUND_HPP_INCLUDED_
#	define DD_RANGE_WORKAROUND_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L DDCPP_DEPRECATION_WARNING
#		warning Range workarounds are deprecated with ISO 14882:2011 or a later version support.



#	endif
#	include "DD_IsRange.hpp"
#	include "DD_Iterator.hpp"



DD_END_
template <typename ObjectT_, typename is_range_c_>
struct IteratorSwitch_ {
	typedef ObjectT_ Type;


};



template <typename ObjectT_>
struct IteratorSwitch_<true> {
	typedef typename Iterator<ObjectT_>::Type Type;


};



DD_BEGIN_



DD_BEGIN_
template <typename ObjectT_>
struct IteratorSwitch {
	typedef detail_::IteratorSwitch_<ObjectT_, IsRange<ObjectT_>> Type;


};



DD_END_



#endif
