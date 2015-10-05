//	DDCPP/standard/bits/DD_fabricate.hpp
#ifndef DD_FABRICATE_HPP_INCLUDED_
#	define DD_FABRICATE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
ObjectT_& fabricate() DD_NOEXCEPT;



DD_DETAIL_END_



DD_BEGIN_
using detail_::fabricate;



DD_END_



#endif
