//	DDCPP/standard/bits/DD_back_pusher.hpp
#ifndef DD_BACK_PUSHER_HPP_INCLUDED_
#	define DD_BACK_PUSHER_HPP_INCLUDED_ 1



#	include "DD_BackPushIterator.hpp"



DD_DETAIL_BEGIN_
template <typename ContainerT_>
BackPushIterator<ContainerT_> back_pusher(ContainerT_& container__) DD_NOEXCEPT_AS(BackPushIterator<ContainerT_>(container__)) {
	return BackPushIterator<ContainerT_>(container__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::back_pusher;



DD_END_



#endif
