//	standard/bits/DD_IsReferable.hpp(Undone)
#ifndef DD_IS_REFERABLE_HPP_INCLUDED_
#	define DD_IS_REFERABLE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::IsReferable'.



#	endif
#	include <type_traits>
#	include "DD_Or.hpp"
#	include "DD_IsReference.hpp"



DD_BEGIN_
template <typename ObjectT_>
struct IsReferable : OrType<std::is_object<ObjectT_>, IsReference<ObjectT_>> {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsReferable<ResultT_(ArgumentsT_...)> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsReferable<ResultT_(ArgumentsT_... ...)> : TrueType {
};



DD_END_



#endif
