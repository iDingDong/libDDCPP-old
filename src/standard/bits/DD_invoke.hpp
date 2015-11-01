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
	noexcept((forward<DerrivedT_>(object__).*member_pointer_)(forward<ArgumentsT_>(arguments__)...))
) -> decltype((forward<DerrivedT_>(object__).*member_pointer_)(forward<ArgumentsT_>(arguments__)...)) {
	return (forward<DerrivedT_>(object__).*member_pointer_)(forward<ArgumentsT_>(arguments__)...);
}

template <typename MemberPointerT_, typename PointerT_, typename... ArgumentsT_>
inline auto DD_CONSTEXPR invoke_(MemberPointerT_ member_pointer__, PointerT_&& pointer__, ArgumentsT_&&... arguments__) noexcept(
	noexcept((forward<PointerT_>(pointer__)->*member_pointer__)(forward<ArgumentsT_>(arguments__)...))
) -> decltype((forward<PointerT_>(pointer__)->*member_pointer__)(forward<ArgumentsT_>(arguments__)...)) {
	return (forward<PointerT_>(pointer__)->*member_pointer__)(forward<ArgumentsT_>(arguments__)...);
}

template <typename MemberT_, typename BaseT_, typename DerrivedT_>
inline auto DD_CONSTEXPR invoke_(MemberT_ BaseT_::* member_pointer_, DerrivedT_&& object__) noexcept(
	noexcept(std::forward<DerrivedT_>(object__).*member_pointer_)
) -> decltype(std::forward<DerrivedT_>(object__).*member_pointer_) {
	return std::forward<DerrivedT_>(object__).*member_pointer_;
}

template <typename MemberPointerT_, typename PointerT_>
inline auto DD_CONSTEXPR invoke_(MemberPointerT_ member_pointer__, PointerT_&& pointer__) noexcept(
	noexcept((*std::forward<PointerT_>(pointer__)).*member_pointer__)
) -> decltype((*std::forward<PointerT_>(pointer__)).*member_pointer__) {
	return (*std::forward<PointerT_>(pointer__)).*member_pointer__;
}

template <typename FunctionT_, typename... ArgumentsT_>
inline auto DD_CONSTEXPR invoke_(FunctionT_&& function__, ArgumentsT_&&... arguments__) noexcept(
	noexcept(forward<FunctionT_>(function__)(forward<ArgumentsT_>(arguments__)...))
) -> decltype(forward<FunctionT_>(function__)(forward<ArgumentsT_>(arguments__)...)) {
	return forward<FunctionT_>(function__)(forward<ArgumentsT_>(arguments__)...);
}


template <typename FunctionT_, typename... ArgumentsT_>
inline auto DD_CONSTEXPR invoke(FunctionT_&& function__, ArgumentsT_&&... arguments__) noexcept(
	noexcept(invoke_(forward<FunctionT_>(function__), forward<ArgumentsT_>(arguments__)...))
) -> decltype(invoke_(forward<FunctionT_>(function__), forward<ArgumentsT_>(arguments__)...)) {
	return invoke_(forward<FunctionT_>(function__), forward<ArgumentsT_>(arguments__)...);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::invoke;



DD_END_



#endif
