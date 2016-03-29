//	DDCPP/standard/bits/DD_wrap_standard_exception.hpp
#ifndef DD_WRAP_STANDARD_EXCEPTION_HPP_INCLUDED_
#	define DD_WRAP_STANDARD_EXCEPTION_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename TargetExceptionT_, typename StandardExcetionT_>
TargetExceptionT_ wrap_standard_exception(StandardExcetionT_ const& exception__) DD_NOEXCEPT {
	return TargetExceptionT_(exception__.what());
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::wrap_standard_exception;



DD_END_



#endif
