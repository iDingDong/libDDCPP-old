//	standard/bits/DD_make_unique.hpp
#ifndef _DD_MAKE_UNIQUE_HPP_INCLUDED
#	define _DD_MAKE_UNIQUE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::make_unique'.



#	endif
#	include "DD_UniquePointer.hpp"



DD_BEGIN
template <typename _ValueT, typename... _ArgumentsT>
inline UniquePointer<_ValueT, void> make_unique(_ArgumentsT&&... __arguments) {
	return UniquePointer<_ValueT, void>(new _ValueT(__arguments...));
}



DD_END



#endif
