//	DDCPP/standard/bits/DD_make_unique.hpp
#ifndef DD_MAKE_UNIQUE_HPP_INCLUDED_
#	define DD_MAKE_UNIQUE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::make_unique'.



#	endif
#	include "DD_UniquePointer.hpp"



DD_BEGIN_
template <typename ValueT_, typename... ArgumentsT_>
inline UniquePointer<ValueT_, void> make_unique(ArgumentsT_&&... arguments__) {
	return UniquePointer<ValueT_, void>(new ValueT_(arguments__...));
}



DD_END_



#endif
