//	DDCPP/standard/bits/DD_get_instance.hpp
#ifndef DD_GET_INSTANCE_HPP_INCLUDED_
#	define DD_GET_INSTANCE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
inline ObjectT_& get_instance() DD_NOEXCEPT {
	static ObjectT_ instance_;
	return instance_;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::get_instance;



DD_END_



#endif
