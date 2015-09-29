//	DDCPP/standard/bits/DD_Pool.hpp
#ifndef DD_POOL_HPP_INCLUDED_
#	define DD_POOL_HPP_INCLUDED_ 1



#	include "DD_FreeList.hpp"



DD_BEGIN_
template <ValidityType is_thread_safe_c_>
class Pool {



};



template <>
class Pool<true> {
};



DD_END_



#endif
