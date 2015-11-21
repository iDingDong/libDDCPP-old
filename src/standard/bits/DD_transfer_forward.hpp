//	DDCPP/standard/bits/DD_transfer_forward.hpp
#ifndef DD_TRANSFER_FORWARD_HPP_INCLUDED_
#	define DD_TRANSFER_FORWARD_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		include "DD_IteratorValue.hpp"
#	endif
#	include "DD_next.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	else
#		include "DD_copy.hpp"
#	endif



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
inline ProcessType transfer_forward(UndirectionalIteratorT_ const& from_, UndirectionalIteratorT_ const& to_) {
#	if __cplusplus >= 201103L
	auto temp_(::DD::move(*from_));
	::DD::move(::DD::next(from_), ::DD::next(to_), from_);
	*to_ = ::DD::move(temp_);
#	else
	typename IteratorValue<UndirectionalIteratorT_>::Type temp_ = *from_;
	copy(next(from_), next(to_), from_);
	*to_ = temp_;
#	endif
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transfer_forward;



DD_END_



#endif
