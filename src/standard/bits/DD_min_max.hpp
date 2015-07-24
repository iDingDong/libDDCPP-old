//	standard/bits/DD_min_max.hpp
#ifndef _DD_MIN_MAX_HPP_INCLUDED
#	define _DD_MIN_MAX_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_get_last_argument.hpp"
#		include "DD_IsSame.hpp"
#		include "DD_InitializerList.hpp"
#		include "DD_find_min_max.hpp"
#	else
#		include "DD_Pair.hpp"
#	endif



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <ValidityType _use_default_compare>
struct _MinMax {
	public:
	template <typename _ObjectT_, typename _BinaryPredicatorT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_,
		_BinaryPredicatorT_ const& __less_
	) noexcept {
		return Pair<_ObjectT_ const&>{__object_, __object_};
	}
	
	public:
	template <typename _ObjectT_, typename _BinaryPredicatorT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_1_,
		_ObjectT_ const& __object_2_,
		_BinaryPredicatorT_ const& __less_
	) noexcept(noexcept(__less_(__object_1_, __object_2_))) {
		return __less_(__object_2_, __object_1_) ? Pair<_ObjectT_ const&>{__object_2_, __object_1_} : Pair<_ObjectT_ const&>{__object_1_, __object_2_};
	}
	
	private:
	template <typename _ObjectT_, typename _BinaryPredicatorT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_,
		Pair<_ObjectT_ const&> const& _pair,
		_BinaryPredicatorT_ const& __less_
	) noexcept(noexcept(__object_ < __object_)) {
		return __less_(_pair.first, __object_) ? Pair<_ObjectT_ const&>{_pair.first, __less_(__object_, _pair.second) ? _pair.second : __object_} : Pair<_ObjectT_ const&>{__object_, _pair.second};
	}
	
	public:
	template <typename _ObjectT_, typename... _ObjectsT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_,
		_ObjectsT_ const&... __objects_
	) noexcept(noexcept(_min_max(__objects_...))) {
		return _min_max(__object_, _min_max(__objects_...), get_last_argument(__objects_...));
	}
};



template <>
struct _MinMax<true> {
	public:
	template <typename _ObjectT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_
	) noexcept {
		return Pair<_ObjectT_ const&>{__object_, __object_};
	}
	
	public:
	template <typename _ObjectT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_1_,
		_ObjectT_ const& __object_2_
	) noexcept(noexcept(__object_1_ < __object_2_)) {
		return __object_2_ < __object_1_ ? Pair<_ObjectT_ const&>{__object_2_, __object_1_} : Pair<_ObjectT_ const&>{__object_1_, __object_2_};
	}
	
	private:
	template <typename _ObjectT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_,
		Pair<_ObjectT_ const&> const& _pair
	) noexcept(noexcept(__object_ < __object_)) {
		return _pair.first < __object_ ? Pair<_ObjectT_ const&>{_pair.first, __object_ < _pair.second ? _pair.second : __object_} : Pair<_ObjectT_ const&>{__object_, _pair.second};
	}
	
	public:
	template <typename _ObjectT_, typename... _ObjectsT_>
	static Pair<_ObjectT_ const&> constexpr _min_max(
		_ObjectT_ const& __object_,
		_ObjectsT_ const&... __objects_
	) noexcept(noexcept(_min_max(__objects_...))) {
		return _min_max(__object_, _min_max(__objects_...));
	}
	
	
};



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ObjectT, typename... _ObjectsT>
inline Pair<_ObjectT const&> constexpr min_max(
	_ObjectT const& __object,
	_ObjectsT const&... __objects
) noexcept(noexcept(detail::_MinMax<IsSame<_ObjectT, _ObjectsT...>::value>::_min_max(__object, __objects...))) {
	return detail::_MinMax<IsSame<_ObjectT, _ObjectsT...>::value>::_min_max(__object, __objects...);
}

template <typename _ObjectT>
inline Pair<_ObjectT const&> constexpr min_max(
	InitializerList<_ObjectT> _initializer_list
) {
	return dereference(find_min_max(_initializer_list.cbegin(), _initializer_list.cend()));
}

template <typename _ObjectT, typename _BinaryPredicatorT>
inline Pair<_ObjectT const&> constexpr min_max(
	InitializerList<_ObjectT> _initializer_list,
	_BinaryPredicatorT const& __less
) {
	return dereference(find_min_max(_initializer_list.cbegin(), _initializer_list.cend(), __less));
}
#	else
template <typename _ObjectT>
inline inline Pair<_ObjectT const&> constexpr min_max(
	_ObjectT const& __object_1,
	_ObjectT const& __object_2
) {
	return __object_2 < __object_1 : Pair<_ObjectT const&>{__object_2, __object_1} : Pair<_ObjectT const&>{__object_1, __object_2};
}

template <typename _ObjectT, typename _BinaryPredicatorT>
inline inline Pair<_ObjectT const&> constexpr min_max(
	_ObjectT const& __object_1,
	_ObjectT const& __object_2,
	_BinaryPredicatorT const& __less
) {
	return __less(__object_2, __object_1) : Pair<_ObjectT const&>{__object_2, __object_1} : Pair<_ObjectT const&>{__object_1, __object_2};
}
#	endif



DD_END



#endif
