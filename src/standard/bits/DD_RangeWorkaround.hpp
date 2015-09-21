//	DDCPP/standard/bits/DD_RangeWorkaround.hpp
#ifndef _DD_RANGE_WORKAROUND_HPP_INCLUDED
#	define _DD_RANGE_WORKAROUND_HPP_INCLUDED 1



#	if __cplusplus >= 201103L DDCPP_DEPRECATION_WARNING
#		warning Range workarounds are deprecated with ISO 14882:2011 or a later version support.



#	endif
#	include "DD_IsRange.hpp"
#	include "DD_Iterator.hpp"



_DD_END
template <typename _ObjectT, typename _is_range_c>
struct _IteratorSwitch {
	typedef _ObjectT Type;


};



template <typename _ObjectT>
struct _IteratorSwitch<true> {
	typedef typename Iterator<_ObjectT>::Type Type;


};



_DD_BEGIN



_DD_BEGIN
template <typename _ObjectT>
struct IteratorSwitch {
	typedef _detail::_IteratorSwitch<_ObjectT, IsRange<_ObjectT>> Type;


};



_DD_END



#endif
