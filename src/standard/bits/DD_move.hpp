//	DDCPP/standard/bits/DD_move.hpp
#ifndef DD_MOVE_HPP_INCLUDED_
#	define DD_MOVE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::move'.



#	endif
#	include "DD_RemoveReference.hpp"



DD_BEGIN_
template <typename ObjectT_>
inline RemoveReferenceType<ObjectT_>&& move(ObjectT_&& object_) DD_NOEXCEPT {
	return static_cast<RemoveReferenceType<ObjectT_>&&>(object_);
}



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline UndirectionalIteratorT1_ watched_move(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_& result_begin__
) noexcept(noexcept(begin__ != end__) && noexcept(*++result_begin__ = move(*++begin__))) {
	for (; begin__ != end__; ++begin__, ++result_begin__) {
		*result_begin__ = move(*begin__);
	}
	return result_begin__;
}



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline UndirectionalIteratorT1_ move(
	UndirectionalIteratorT1_ const& begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_ result_begin__
) noexcept(noexcept(watched_move(begin__, end__, result_begin__))) {
	watched_move(begin__, end__, result_begin__)
	return result_begin__;
}



DD_END_



#endif
