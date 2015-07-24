//	standard/bits/DD_min.hpp
#ifndef _DD_MIN_HPP_INCLUDED
#	define _DD_MIN_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_get_last_argument.hpp"
#		include "DD_IsSame.hpp"
#		include "DD_InitializerList.hpp"
#		include "DD_find_min.hpp"
#	else
#		include "DD_global_definitions.hpp"
#	endif



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <ValidityType _use_default_compare_c>
struct _Min {
	template <typename _ObjectT_, typename _BinaryPredicatorT_>
	static _ObjectT_ constexpr const& _min(
		_ObjectT_ const& __object_,
		_BinaryPredicatorT_ const& __less_
	) noexcept {
		return __object_;
	}
	
	template <typename _ObjectT_, typename _BinaryPredicatorT_>
	static _ObjectT_ constexpr const& _min(
		_ObjectT_ const& __object_1_,
		_ObjectT_ const& __object_2_,
		_BinaryPredicatorT_ const& __less_
	) noexcept(noexcept(__less_(__object_2_, __object_1_))) {
		return __less_(__object_2_, __object_1_) ? __object_2_ : __object_1_;
	}
	
	template <typename _ObjectT_, typename... _ArgumentsT_>
	static _ObjectT_ constexpr const& _min(
		_ObjectT_ const& __object_,
		_ArgumentsT_ const&... __arguments_
	) noexcept(noexcept(_min(__object_, _min(__arguments_...), get_last_argument(__arguments_...)))) {
		return _min(__object_, _min(__arguments_...), get_last_argument(__arguments_...));
	}
	
	
};



template <>
struct _Min<true> {
	template <typename _ObjectT_>
	static _ObjectT_ constexpr const& _min(
		_ObjectT_ const& __object_
	) noexcept {
		return __object_;
	}
	
	template <typename _ObjectT_>
	static _ObjectT_ constexpr const& _min(
		_ObjectT_ const& __object_1_,
		_ObjectT_ const& __object_2_
	) noexcept(noexcept(__object_2_ < __object_1_)) {
		return __object_2_ < __object_1_ ? __object_2_ : __object_1_;
	};
	
	template <typename _ObjectT_, typename... _ObjectsT_>
	static _ObjectT_ constexpr const& _min(
		_ObjectT_ const& __object_,
		_ObjectsT_ const&... __objects_
	) noexcept(noexcept(_min(__object_, _min(__objects_...)))) {
		return _min(__object_, _min(__objects_...));
	}
	
	
};



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ObjectT, typename... _ArgumentsT>
inline _ObjectT constexpr const& min(
	_ObjectT const& __object,
	_ArgumentsT const&... __arguments
) noexcept(noexcept(detail::_Min<IsSame<_ObjectT, _ArgumentsT...>::value>::_min(__object, __arguments...))) {
	return detail::_Min<IsSame<_ObjectT, _ArgumentsT...>::value>::_min(__object, __arguments...);
}

template <typename _ObjectT>
inline _ObjectT constexpr const& min(
	InitializerList<_ObjectT> _initializer_list
) noexcept(noexcept(find_min(_initializer_list.cbegin(), _initializer_list.cengd()))) {
	return *find_min(_initializer_list.cbegin(), _initializer_list.cengd());
}

template <typename _ObjectT, typename _BinaryPredicatorT>
inline _ObjectT constexpr const& min(
	InitializerList<_ObjectT> _initializer_list,
	_BinaryPredicatorT const& __less
) noexcept(noexcept(find_min(_initializer_list.cbegin(), _initializer_list.cengd()))) {
	return *find_min(_initializer_list.cbegin(), _initializer_list.cengd(), __less);
}
#	else
template <typename _ObjectT>
inline _ObjectT const& min(
	_ObjectT const& __object_1,
	_ObjectT const& __object_2
) {
	return __object_2 < __object_1 ? __object_2 : __object_1;
}

template <typename _ObjectT, typename _BinaryPredicatorT>
inline _ObjectT const& min(
	_ObjectT const& __object_1,
	_ObjectT const& __object_2,
	_BinaryPredicatorT const& __less
) {
	return __less(__object_2, __object_1) ? __object_2 : __object_1;
}
#	endif



DD_END



#endif
