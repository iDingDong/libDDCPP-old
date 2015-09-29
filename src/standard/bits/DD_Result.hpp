//	DDCPP/standard/bits/DD_Result.hpp
#ifndef DD_RESULT_HPP_INCLUDED_
#	define DD_RESULT_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ResultOf'.



#	endif
#	include <type_traits>

#	include "DD_IntegralConstant.hpp"



DD_BEGIN_
template <typename FunctionT_>
struct Result {
	using Type = typename std::result_of<FunctionT_>::type;


};



template <typename FunctionT_>
using ResultType = typename Result<FunctionT_>::Type;



DD_END_



#endif
