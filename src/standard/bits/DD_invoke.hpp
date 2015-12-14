//	DDCPP/standard/bits/DD_invoke.hpp
#ifndef DD_INVOKE_HPP_INCLUDED_
#	define DD_INVOKE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::invoke'.



#	endif
#	include "DD_forward.hpp"



DD_DETAIL_BEGIN_
template <typename MemberT_, typename BaseT_, typename DerrivedT_, typename... ArgumentsT_>
inline auto DD_CONSTEXPR invoke_(MemberT_ BaseT_::* member_pointer_, DerrivedT_&& object__, ArgumentsT_&&... arguments__) noexcept(
	noexcept((::DD::forward<DerrivedT_>(object__).*member_pointer_)(::DD::forward<ArgumentsT_>(arguments__)...))
) -> decltype((::DD::forward<DerrivedT_>(object__).*member_pointer_)(::DD::forward<ArgumentsT_>(arguments__)...)) {
	return (::DD::forward<DerrivedT_>(object__).*member_pointer_)(::DD::forward<ArgumentsT_>(arguments__)...);
}

template <typename MemberPointerT_, typename PointerT_, typename... ArgumentsT_>
inline auto DD_CONSTEXPR invoke_(MemberPointerT_ member_pointer__, PointerT_&& pointer__, ArgumentsT_&&... arguments__) noexcept(
	noexcept((::DD::forward<PointerT_>(pointer__)->*member_pointer__)(::DD::forward<ArgumentsT_>(arguments__)...))
) -> decltype((::DD::forward<PointerT_>(pointer__)->*member_pointer__)(::DD::forward<ArgumentsT_>(arguments__)...)) {
	return (::DD::forward<PointerT_>(pointer__)->*member_pointer__)(::DD::forward<ArgumentsT_>(arguments__)...);
}

template <typename MemberT_, typename BaseT_, typename DerrivedT_>
inline auto DD_CONSTEXPR invoke_(MemberT_ BaseT_::* member_pointer_, DerrivedT_&& object__) noexcept(
	noexcept(::DD::forward<DerrivedT_>(object__).*member_pointer_)
) -> decltype(::DD::forward<DerrivedT_>(object__).*member_pointer_) {
	return ::DD::forward<DerrivedT_>(object__).*member_pointer_;
}

template <typename MemberPointerT_, typename PointerT_>
inline auto DD_CONSTEXPR invoke_(MemberPointerT_ member_pointer__, PointerT_&& pointer__) noexcept(
	noexcept((*::DD::forward<PointerT_>(pointer__)).*member_pointer__)
) -> decltype((*::DD::forward<PointerT_>(pointer__)).*member_pointer__) {
	return (*::DD::forward<PointerT_>(pointer__)).*member_pointer__;
}

template <typename FunctionT_, typename... ArgumentsT_>
inline auto DD_CONSTEXPR invoke_(FunctionT_&& function__, ArgumentsT_&&... arguments__) noexcept(
	noexcept(::DD::forward<FunctionT_>(function__)(::DD::forward<ArgumentsT_>(arguments__)...))
) -> decltype(::DD::forward<FunctionT_>(function__)(::DD::forward<ArgumentsT_>(arguments__)...)) {
	return ::DD::forward<FunctionT_>(function__)(::DD::forward<ArgumentsT_>(arguments__)...);
}


template <typename FunctionT_, typename... ArgumentsT_>
inline auto DD_CONSTEXPR invoke(FunctionT_&& function__, ArgumentsT_&&... arguments__) noexcept(
	noexcept(invoke_(::DD::forward<FunctionT_>(function__), ::DD::forward<ArgumentsT_>(arguments__)...))
) -> decltype(invoke_(::DD::forward<FunctionT_>(function__), ::DD::forward<ArgumentsT_>(arguments__)...)) {
	return invoke_(::DD::forward<FunctionT_>(function__), ::DD::forward<ArgumentsT_>(arguments__)...);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::invoke;



DD_END_



#endif
