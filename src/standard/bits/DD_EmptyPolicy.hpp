//	DDCPP/standard/bits/DD_EmptyPolicy.hpp
#ifndef DD_EMPTY_POLICY_HPP_INCLUDED_
#	define DD_EMPTY_POLICY_HPP_INCLUDED_ 1



#	include "DD_forward.hpp"



DD_DETAIL_BEGIN_
struct EmptyPolicy {
	public:
	DD_ALIAS(ThisType, EmptyPolicy);


	public:
#	if __cplusplus >= 201103L
	template <typename... ArgumentsT_>
	static ProcessType call(ArgumentsT_&&... arguments__) noexcept {
	}
#	else
	static ProcessType call() throw() {
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	template <typename... ArgumentsT_>
	ProcessType operator ()(ArgumentsT_&&... arguments__) noexcept(
		noexcept(call(::DD::forward<ArgumentsT_>(arguments__)...))
	) {
		call(::DD::forward<ArgumentsT_>(arguments__)...);
	}
#	else
	ProcessType operator ()() throw() {
	}
#	endif


} empty_policy;



DD_DETAIL_END_



DD_BEGIN_
using detail_::EmptyPolicy;

using detail_::empty_policy;



DD_END_



#endif
