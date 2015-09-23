//	DDCPP/standard/bits/DD_Result.hpp
#ifndef _DD_RESULT_HPP_INCLUDED
#	define _DD_RESULT_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ResultOf'.



#	endif
#	include <type_traits>

#	include "DD_IntegralConstant.hpp"



_DD_BEGIN
template <typename _FunctionT>
struct Result {
	using Type = typename std::result_of<_FunctionT>::type;


};



template <typename _FunctionT>
using ResultType = typename Result<_FunctionT>::Type;



_DD_END



#endif
