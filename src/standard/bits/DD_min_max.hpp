//	DDCPP/standard/bits/DD_min_max.hpp
#ifndef DD_MIN_MAX_HPP_INCLUDED_
#	define DD_MIN_MAX_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_get_last_argument.hpp"
#		include "DD_IsSame.hpp"
#		include "DD_InitializerList.hpp"
#		include "DD_find_min_max.hpp"
#	else
#		include "DD_Pair.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <ValidityType use_default_compare_>
struct MinMax_ {
	public:
	template <typename ObjectT__, typename BinaryPredicatorT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object___,
		BinaryPredicatorT__ less___
	) noexcept {
		return Pair<ObjectT__ const&>(object___, object___);
	}

	public:
	template <typename ObjectT__, typename BinaryPredicatorT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object_1___,
		ObjectT__ const& object_2___,
		BinaryPredicatorT__ less___
	) noexcept(noexcept(less___(object_1___, object_2___))) {
		return less___(object_2___, object_1___) ?
			Pair<ObjectT__ const&>(object_2___, object_1___) :
			Pair<ObjectT__ const&>(object_1___, object_2___)
		;
	}

	private:
	template <typename ObjectT__, typename BinaryPredicatorT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object___,
		Pair<ObjectT__ const&> const& pair_,
		BinaryPredicatorT__ const& less___
	) noexcept(noexcept(object___ < object___)) {
		return less___(pair_.first, object___) ?
			Pair<ObjectT__ const&>(pair_.first, less___(object___, pair_.second) ? pair_.second : object___) :
			Pair<ObjectT__ const&>(object___, pair_.second)
		;
	}

	public:
	template <typename ObjectT__, typename... ObjectsT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object___,
		ObjectsT__ const&... objects___
	) noexcept(noexcept(min_max(objects___...))) {
		return min_max(object___, min_max(objects___...), get_last_argument(objects___...));
	}
};



template <>
struct MinMax_<true> {
	public:
	template <typename ObjectT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object___
	) noexcept {
		return Pair<ObjectT__ const&>{object___, object___};
	}

	public:
	template <typename ObjectT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object_1___,
		ObjectT__ const& object_2___
	) noexcept(noexcept(object_1___ < object_2___)) {
		return object_2___ < object_1___ ?
			Pair<ObjectT__ const&>(object_2___, object_1___) :
			Pair<ObjectT__ const&>(object_1___, object_2___)
		;
	}

	private:
	template <typename ObjectT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object___,
		Pair<ObjectT__ const&> const& pair_
	) noexcept(noexcept(object___ < object___)) {
		return pair_.first < object___ ?
			Pair<ObjectT__ const&>(pair_.first, object___ < pair_.second ? pair_.second : object___) :
			Pair<ObjectT__ const&>(object___, pair_.second)
		;
	}

	public:
	template <typename ObjectT__, typename... ObjectsT__>
	static Pair<ObjectT__ const&> constexpr min_max(
		ObjectT__ const& object___,
		ObjectsT__ const&... objects___
	) noexcept(noexcept(min_max(objects___...))) {
		return min_max(object___, min_max(objects___...));
	}


};



template <typename ObjectT_, typename... ObjectsT_>
inline Pair<ObjectT_ const&> constexpr min_max(
	ObjectT_ const& object__,
	ObjectsT_ const&... objects__
) noexcept(noexcept(MinMax_<IsSame<ObjectT_, ObjectsT_...>::value>::min_max(object__, objects__...))) {
	return MinMax_<IsSame<ObjectT_, ObjectsT_...>::value>::min_max(object__, objects__...);
}

template <typename ObjectT_>
inline Pair<ObjectT_ const&> constexpr min_max(
	InitializerList<ObjectT_> initializer_list_
) {
	return dereference(find_min_max(initializer_list_.cbegin(), initializer_list_.cend()));
}

template <typename ObjectT_, typename BinaryPredicatorT_>
inline Pair<ObjectT_ const&> constexpr min_max(
	InitializerList<ObjectT_> initializer_list_,
	BinaryPredicatorT_ const& less__
) {
	return dereference(find_min_max(initializer_list_.cbegin(), initializer_list_.cend(), less__));
}
#	else
template <typename ObjectT_>
inline inline Pair<ObjectT_ const&> constexpr min_max(
	ObjectT_ const& object_1__,
	ObjectT_ const& object_2__
) {
	return object_2__ < object_1__ : Pair<ObjectT_ const&>{object_2__, object_1__} : Pair<ObjectT_ const&>{object_1__, object_2__};
}

template <typename ObjectT_, typename BinaryPredicatorT_>
inline inline Pair<ObjectT_ const&> constexpr min_max(
	ObjectT_ const& object_1__,
	ObjectT_ const& object_2__,
	BinaryPredicatorT_ const& less__
) {
	return less__(object_2__, object_1__) : Pair<ObjectT_ const&>{object_2__, object_1__} : Pair<ObjectT_ const&>{object_1__, object_2__};
}
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::min_max;



DD_END_



#endif
