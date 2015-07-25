//	DDCPP/standard/bits/DD_max.hpp
#ifndef _DD_MAX_HPP_INCLUDED
#	define _DD_MAX_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_get_last_argument.hpp"
#		include "DD_IsSame.hpp"
#		include "DD_InitializerList.hpp"
#		include "DD_find_max.hpp"
#	else
#		include "DD_global_definitions.hpp"
#	endif



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <ValidityType _use_default_compare_c>
struct _Max {
	template <typename _ObjectT_, typename _BinaryPredicatorT_>
	static _ObjectT_ constexpr const& _max(
		_ObjectT_ const& __object_,
		_BinaryPredicatorT_ const& __less_
	) noexcept {
		return __object_;
	}
	
	template <typename _ObjectT_, typename _BinaryPredicatorT_>
	static _ObjectT_ constexpr const& _max(
		_ObjectT_ const& __object_1_,
		_ObjectT_ const& __object_2_,
		_BinaryPredicatorT_ const& __less_
	) noexcept(noexcept(__less_(__object_2_, __object_1_))) {
		return __less_(__object_2_, __object_1_) ? __object_1_ : __object_2_;
	}
	
	template <typename _ObjectT_, typename... _ArgumentsT_>
	static _ObjectT_ constexpr const& _max(
		_ObjectT_ const& __object_,
		_ArgumentsT_ const&... __arguments_
	) noexcept(noexcept(_max(__object_, _max(__arguments_...), get_last_argument(__arguments_...)))) {
		return _max(__object_, _max(__arguments_...), get_last_argument(__arguments_...));
	}
	
	
};



template <>
struct _Max<true> {
	template <typename _ObjectT_>
	static _ObjectT_ constexpr const& _max(
		_ObjectT_ const& __object_
	) noexcept {
		return __object_;
	}
	
	template <typename _ObjectT_>
	static _ObjectT_ constexpr const& _max(
		_ObjectT_ const& __object_1_,
		_ObjectT_ const& __object_2_
	) noexcept(noexcept(__object_2_ < __object_1_)) {
		return __object_2_ < __object_1_ ? __object_1_ : __object_2_;
	};
	
	template <typename _ObjectT_, typename... _ObjectsT_>
	static _ObjectT_ constexpr const& _max(
		_ObjectT_ const& __object_,
		_ObjectsT_ const&... __objects_
	) noexcept(noexcept(_max(__object_, _max(__objects_...)))) {
		return _max(__object_, _max(__objects_...));
	}
	
	
};



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ObjectT, typename... _ArgumentsT>
inline _ObjectT constexpr const& max(
	_ObjectT const& __object,
	_ArgumentsT const&... __arguments
) noexcept(noexcept(detail::_Max<IsSame<_ObjectT, _ArgumentsT...>::value>::_max(__object, __arguments...))) {
	return detail::_Max<IsSame<_ObjectT, _ArgumentsT...>::value>::_max(__object, __arguments...);
}

template <typename _ObjectT>
inline _ObjectT constexpr const& max(
	InitializerList<_ObjectT> _initializer_list
) noexcept(noexcept(find_min(_initializer_list.cbegin(), _initializer_list.cengd()))) {
	return *find_max(_initializer_list.cbegin(), _initializer_list.cengd());
}

template <typename _ObjectT, typename _BinaryPredicatorT>
inline _ObjectT constexpr const& max(
	InitializerList<_ObjectT> _initializer_list,
	_BinaryPredicatorT const& __less
) noexcept(noexcept(find_min(_initializer_list.cbegin(), _initializer_list.cengd()))) {
	return *find_max(_initializer_list.cbegin(), _initializer_list.cengd(), __less);
}
#	else
template <typename _ObjectT>
inline _ObjectT const& max(
	_ObjectT const& __object_1,
	_ObjectT const& __object_2
) {
	return __object_2 < __object_1 ? __object_1 : __object_2;
}

template <typename _ObjectT, typename _BinaryPredicatorT>
inline _ObjectT const& max(
	_ObjectT const& __object_1,
	_ObjectT const& __object_2,
	_BinaryPredicatorT const& __less
) {
	return __less(__object_2, __object_1) ? __object_1 : __object_2;
}
#	endif



DD_END



#endif
