//	DDCPP/standard/bits/DD_min.hpp
#ifndef DD_MIN_HPP_INCLUDED_
#	define DD_MIN_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_get_last_argument.hpp"
#		include "DD_IsSame.hpp"
#		include "DD_InitializerList.hpp"
#	endif
#	if __cplusplus >= 201103L
#		include "DD_find_min.hpp"
#	else
#		include "DD_LessThan.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <ValidityType use_default_compare_c_>
struct Min_ {
	template <typename ObjectT__, typename BinaryPredicateT__>
	static ObjectT__ constexpr const& min(
		ObjectT__ const& object___,
		BinaryPredicateT__ less___
	) noexcept {
		return object___;
	}

	template <typename ObjectT__, typename BinaryPredicateT__>
	static ObjectT__ constexpr const& min(
		ObjectT__ const& object_1___,
		ObjectT__ const& object_2___,
		BinaryPredicateT__ less___
	) noexcept(noexcept(less___(object_2___, object_1___))) {
		return less___(object_2___, object_1___) ? object_2___ : object_1___;
	}

	template <typename ObjectT__, typename... ArgumentsT__>
	static ObjectT__ constexpr const& min(
		ObjectT__ const& object___,
		ArgumentsT__ const&... arguments___
	) noexcept(noexcept(min(object___, min(arguments___...), get_last_argument(arguments___...)))) {
		return min(object___, min(arguments___...), get_last_argument(arguments___...));
	}


};



template <>
struct Min_<true> {
	template <typename ObjectT__, typename... ObjectsT__>
	static ObjectT__ constexpr const& min(
		ObjectT__ const& object___,
		ObjectsT__ const&... objects___
	) noexcept(noexcept(Min_<false>::min(object___, objects___..., less_than))) {
		return Min_<false>::min(object___, objects___..., less_than);
	}


};



template <typename ObjectT_, typename... ArgumentsT_>
inline ObjectT_ constexpr const& min(
	ObjectT_ const& object__,
	ArgumentsT_ const&... arguments__
) noexcept(noexcept(Min_<IsSame<ObjectT_, ArgumentsT_...>::value>::min(object__, arguments__...))) {
	return Min_<IsSame<ObjectT_, ArgumentsT_...>::value>::min(object__, arguments__...);
}

template <typename ObjectT_, typename BinaryPredicateT_>
inline ObjectT_ constexpr const& min(
	InitializerList<ObjectT_> initializer_list_,
	BinaryPredicateT_ const& less__
) noexcept(noexcept(::DD::find_min(initializer_list_.cbegin(), initializer_list_.cengd(), less__))) {
	return *::DD::find_min(initializer_list_.cbegin(), initializer_list_.cengd(), less__);
}

template <typename ObjectT_>
inline ObjectT_ constexpr const& min(
	InitializerList<ObjectT_> initializer_list_
) noexcept(noexcept(::DD::detail_::min(initializer_list_, less_than))) {
	return ::DD::detail_::min(initializer_list_, less_than);
}
#	else
template <typename ObjectT_, typename BinaryPredicateT_>
inline ObjectT_ const& min(
	ObjectT_ const& object_1__,
	ObjectT_ const& object_2__,
	BinaryPredicateT_ const& less__
) {
	return less__(object_2__, object_1__) ? object_2__ : object_1__;
}

template <typename ObjectT_>
inline ObjectT_ const& min(
	ObjectT_ const& object_1__,
	ObjectT_ const& object_2__
) {
	return ::DD::detail_::min(object_1__, object_2__, less_than);
}
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::min;



DD_END_



#endif
