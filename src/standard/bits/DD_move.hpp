//	DDCPP/standard/bits/DD_move.hpp
#ifndef DD_MOVE_HPP_INCLUDED_
#	define DD_MOVE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::move'.



#	endif
#	include "DD_RemoveReference.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
inline RemoveReferenceType<ObjectT_>&& move(ObjectT_&& object_) DD_NOEXCEPT {
	return static_cast<RemoveReferenceType<ObjectT_>&&>(object_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::move;



DD_END_



#endif
