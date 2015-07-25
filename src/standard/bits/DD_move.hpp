//	DDCPP/standard/bits/DD_move.hpp
#ifndef _DD_MOVE_HPP_INCLUDED
#	define _DD_MOVE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::move'.



#	endif
#	include "DD_RemoveReference.hpp"



DD_BEGIN
template <typename _ObjectT>
inline RemoveReferenceType<_ObjectT>&& move(_ObjectT&& _object) DD_NOEXCEPT {
	return static_cast<RemoveReferenceType<_ObjectT>&&>(_object);
}



DD_END



#endif
