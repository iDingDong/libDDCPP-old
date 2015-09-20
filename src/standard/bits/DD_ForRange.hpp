//	DDCPP/standard/bits/DD_ForRange.hpp
#ifndef _DD_FOR_RANGE_HPP_INCLUDED
#	define _DD_FOR_RANGE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_global_definitions.hpp"
#	else
#		include "DD_Range.hpp"
#		include "DD_IteratorReference.hpp"
#	endif



#	if __cplusplus >= 201103L
#		define DD_FOR_RANGE(_ARG_element, ...) for (_ARG_element : __VA_ARGS__)
#	else
DD_DETAIL_BEGIN
struct _AutoAnyBase {
	DD_CONSTEXPR operator ValidityType() const DD_NOEXCEPT {
		return false;
	}


};



template <typename _ValueT>
struct _AutoAny : _AutoAnyBase {
	mutable _ValueT _m_item;


	_AutoAny(_ValueT const& t) : _m_item(_ValueT) {}


};



template <typename _ValueT>
_ValueT& _auto_any_cast(_AutoAnyBase const& __any) {
	return static_cast<_AutoAny<_ValueT> const&>(__any)._m_item;


};



template<typename _ValueT>
ValidityType _done(_AutoAnyBase const& __current, _AutoAnyBase const& __end, _ValueT const&) {
	typename Iterator<_ValueT>::Type _IteratorType;
	return _auto_any_cast<_IteratorType>(__current) == _auto_any_cast<_IteratorType>(__end);
}



template<typename _ValueT>
void _next(_AutoAnyBase const& __current, _ValueT const&) {
	++_auto_any_cast<typename Iterator<_ValueT>::Type>(__current);
}



template<typename _ValueT>
typename IteratorReference<_ValueT>::Type const& _dereference(auto_any_base const& __current, T const&) {
	return *_auto_any_cast<typename Iterator<_ValueT>::Type>(__current);
}



DD_DETAIL_END



#		define DD_FOR_RANGE(_ARG_element, _ARG_range)\
			if (::DD::_detail::_AutoAnyBase const& b = ::DD::begin(_ARG_range)) {\
			} else if (::DD::_detail::_AutoAnyBase const& e = ::DD::end(_ARG_range)) {\
			} else\
				for (\
					bool more = true;\
					more && !::DD::_detail::done(b,e,container);\
					more ? ::DD::_detail::_next(b,container) : void(0)\
				) {\
					if (more = false) {\
					} else\
						for (_ARG_element = ::DD::_detail::_dereference(b,container); !more; more = true)
#	endif



#endif
