//	DDCPP/standard/bits/DD_ForRange.hpp
#ifndef DD_FOR_RANGE_HPP_INCLUDED_
#	define DD_FOR_RANGE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_global_definitions.hpp"
#	else
#		include "DD_Range.hpp"
#		include "DD_IteratorReference.hpp"
#	endif



#	if __cplusplus >= 201103L
#		define DD_FOR_RANGE(ARG_element_, ...) for (ARG_element_ : __VA_ARGS__)
#	else
DD_DETAIL_BEGIN_
struct AutoAnyBase_ {
	DD_CONSTEXPR operator ValidityType() const DD_NOEXCEPT {
		return false;
	}


};



template <typename ValueT_>
struct AutoAny_ : AutoAnyBase_ {
	mutable ValueT_ m_item_;


	AutoAny_(ValueT_ const& t) : m_item_(ValueT_) {}


};



template <typename ValueT_>
ValueT_& auto_any_cast_(AutoAnyBase_ const& any__) {
	return static_cast<AutoAny_<ValueT_> const&>(any__).m_item_;


};



template<typename ValueT_>
ValidityType done_(AutoAnyBase_ const& current__, AutoAnyBase_ const& end__, ValueT_ const&) {
	typename Iterator<ValueT_>::Type IteratorType_;
	return auto_any_cast_<IteratorType_>(current__) == auto_any_cast_<IteratorType_>(end__);
}



template<typename ValueT_>
void next_(AutoAnyBase_ const& current__, ValueT_ const&) {
	++auto_any_cast_<typename Iterator<ValueT_>::Type>(current__);
}



template<typename ValueT_>
typename IteratorReference<ValueT_>::Type const& dereference_(auto_any_base const& current__, T const&) {
	return *auto_any_cast_<typename Iterator<ValueT_>::Type>(current__);
}



DD_DETAIL_END_



#		define DD_FOR_RANGE(ARG_element_, ARG_range_)\
			if (::DD::detail_::AutoAnyBase_ const& b = ::DD::begin(ARG_range_)) {\
			} else if (::DD::detail_::AutoAnyBase_ const& e = ::DD::end(ARG_range_)) {\
			} else\
				for (\
					bool more = true;\
					more && !::DD::detail_::done(b,e,container);\
					more ? ::DD::detail_::next_(b,container) : void(0)\
				) {\
					if (more = false) {\
					} else\
						for (ARG_element_ = ::DD::detail_::dereference_(b,container); !more; more = true)
#	endif



#endif
