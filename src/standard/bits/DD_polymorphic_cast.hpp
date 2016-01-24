//	DDCPP/standard/bits/DD_polymorphic_cast.hpp
#ifndef DD_POLYMORPHIC_CAST_HPP_INCLUDED_
#	define DD_POLYMORPHIC_CAST_HPP_INCLUDED_ 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_address_of.hpp"



DD_DETAIL_BEGIN_
template <typename TargetT_, typename SourceClassT_>
inline TargetT_ DD_UNCONSTRIANED_CONSTEXPR polymorphic_cast(SourceClassT_* source_) DD_NOEXCEPT_AS(
	static_cast<TargetT_>(source_)
) {
    DD_ASSERT(dynamic_cast<TargetT_>(source_) == source_, "Invalid cast: 'DD::polymorphic_cast'");
	return static_cast<TargetT_>(source_);
}

template <typename TargetT_, typename SourceClassT_>
inline TargetT_ DD_UNCONSTRIANED_CONSTEXPR polymorphic_cast(SourceClassT_& source_) DD_NOEXCEPT_AS(
	static_cast<TargetT_>(source_)
) {
	DD_ASSERT(
		dynamic_cast<TargetT_>(::DD::address_of(source_) == ::DD::address_of(source_)),
		"Invalid cast: 'DD::polymorphic_cast'"
	);
	return static_cast<TargetT_>(source_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::polymorphic_cast;



DD_END_



#endif
