//	standard/bits/DD_IsReferable.hpp(Undone)
#ifndef _DD_IS_REFERABLE_HPP_INCLUDED
#	define _DD_IS_REFERABLE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsReferable'.



#	endif
#	include <type_traits>
#	include "DD_Or.hpp"
#	include "DD_IsReference.hpp"



DD_BEGIN
template <typename _ObjectT>
struct IsReferable : OrType<std::is_object<_ObjectT>, IsReference<_ObjectT>> {
};



template <typename _ResultT, typename... _ArgumentsT>
struct IsReferable<_ResultT(_ArgumentsT...)> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct IsReferable<_ResultT(_ArgumentsT... ...)> : TrueType {
};



DD_END



#endif
