//	DDCPP/standard/bits/DD_max.hpp
#ifndef DD_MAX_HPP_INCLUDED_
#	define DD_MAX_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_get_last_argument.hpp"
#		include "DD_IsSame.hpp"
#		include "DD_InitializerList.hpp"
#		include "DD_find_max.hpp"
#	else
#		include "DD_global_definitions.hpp"
#	endif



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN_
template <ValidityType use_default_compare_c_>
struct Max_ {
	template <typename ObjectT__, typename BinaryPredicatorT__>
	static ObjectT__ constexpr const& max_(
		ObjectT__ const& object___,
		BinaryPredicatorT__ const& less___
	) noexcept {
		return object___;
	}

	template <typename ObjectT__, typename BinaryPredicatorT__>
	static ObjectT__ constexpr const& max_(
		ObjectT__ const& object_1___,
		ObjectT__ const& object_2___,
		BinaryPredicatorT__ const& less___
	) noexcept(noexcept(less___(object_2___, object_1___))) {
		return less___(object_2___, object_1___) ? object_1___ : object_2___;
	}

	template <typename ObjectT__, typename... ArgumentsT__>
	static ObjectT__ constexpr const& max_(
		ObjectT__ const& object___,
		ArgumentsT__ const&... arguments___
	) noexcept(noexcept(max_(object___, max_(arguments___...), get_last_argument(arguments___...)))) {
		return max_(object___, max_(arguments___...), get_last_argument(arguments___...));
	}


};



template <>
struct Max_<true> {
	template <typename ObjectT__>
	static ObjectT__ constexpr const& max_(
		ObjectT__ const& object___
	) noexcept {
		return object___;
	}

	template <typename ObjectT__>
	static ObjectT__ constexpr const& max_(
		ObjectT__ const& object_1___,
		ObjectT__ const& object_2___
	) noexcept(noexcept(object_2___ < object_1___)) {
		return object_2___ < object_1___ ? object_1___ : object_2___;
	};

	template <typename ObjectT__, typename... ObjectsT__>
	static ObjectT__ constexpr const& max_(
		ObjectT__ const& object___,
		ObjectsT__ const&... objects___
	) noexcept(noexcept(max_(object___, max_(objects___...)))) {
		return max_(object___, max_(objects___...));
	}


};



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename ObjectT_, typename... ArgumentsT_>
inline ObjectT_ constexpr const& max(
	ObjectT_ const& object__,
	ArgumentsT_ const&... arguments__
) noexcept(noexcept(detail_::Max_<IsSame<ObjectT_, ArgumentsT_...>::value>::max_(object__, arguments__...))) {
	return detail_::Max_<IsSame<ObjectT_, ArgumentsT_...>::value>::max_(object__, arguments__...);
}

template <typename ObjectT_>
inline ObjectT_ constexpr const& max(
	InitializerList<ObjectT_> initializer_list_
) noexcept(noexcept(find_min(initializer_list_.cbegin(), initializer_list_.cengd()))) {
	return *find_max(initializer_list_.cbegin(), initializer_list_.cengd());
}

template <typename ObjectT_, typename BinaryPredicatorT_>
inline ObjectT_ constexpr const& max(
	InitializerList<ObjectT_> initializer_list_,
	BinaryPredicatorT_ const& less__
) noexcept(noexcept(find_min(initializer_list_.cbegin(), initializer_list_.cengd()))) {
	return *find_max(initializer_list_.cbegin(), initializer_list_.cengd(), less__);
}
#	else
template <typename ObjectT_>
inline ObjectT_ const& max(
	ObjectT_ const& object_1__,
	ObjectT_ const& object_2__
) {
	return object_2__ < object_1__ ? object_1__ : object_2__;
}

template <typename ObjectT_, typename BinaryPredicatorT_>
inline ObjectT_ const& max(
	ObjectT_ const& object_1__,
	ObjectT_ const& object_2__,
	BinaryPredicatorT_ const& less__
) {
	return less__(object_2__, object_1__) ? object_1__ : object_2__;
}
#	endif



DD_END_



#endif
