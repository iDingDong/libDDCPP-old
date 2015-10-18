//	DDCPP/standard/bits/DD_transfer.hpp
#ifndef DD_TRANSFER_HPP_INCLUDED_
#	define DD_TRANSFER_HPP_INCLUDED_



#	include "DD_transfer_backward.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_>
ProcessType transfer(FreeAccessIteratorT_ const& from_, FreeAccessIteratorT_ const& to_) {
	if (to_ < from_) {
		transfer_backward(from_, to_);
	} else {
		transfer_forward(from_, to_);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transfer;



DD_END_



#endif
