//	DDCPP/standard/bits/DD_Destroy.hpp
#ifndef DD_DESTROY_HPP_INCLUDED_
#	define DD_DESTROY_HPP_INCLUDED_



#	include "DD_debugger_definitions.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_DefaultDeleter.hpp"
#	include "DD_get_pointer.hpp"



DD_DETAIL_BEGIN_
struct Destroy {
	DD_ALIAS(ThisType, Destroy);


#	if DDCPP_GUARD_DESTROY
	template <typename ValueT_, typename DeleterT_>
	static ProcessType call(ValueT_*& pointer_, DeleterT_ deleter__) DD_NOEXCEPT {
		DD_ASSERT(pointer_ != reinterpret_cast<ValueT_*>(get_invalid_address_()), "Dangling pointer dereferenced: 'DD::Destroy'");
		deleter__(pointer_);
		pointer_ = reinterpret_cast<ValueT_*>(get_invalid_address_());
	}

#	endif
	template <typename PointerT_, typename DeleterT_>
	static ProcessType call(PointerT_ const& pointer__, DeleterT_ deleter__) DD_NOEXCEPT {
#	if DDCPP_GUARD_DESTROY
		DD_ASSERT(pointer_ != reinterpret_cast<ValueT_*>(get_invalid_address_()), "Dangling pointer dereferenced: 'DD::Destroy'");
#	endif
		deleter__(::DD::get_pointer(pointer__));
	}

#	if DDCPP_GUARD_DESTROY
	template <typename ValueT_>
	static ProcessType call(ValueT_*& pointer_) DD_NOEXCEPT {
		call(pointer__, DefaultDeleter<ValueT_>);
	}

#	endif
	template <typename PointerT_>
	static ProcessType call(PointerT_ const& pointer__) DD_NOEXCEPT {
		call(pointer__, DefaultDeleter<DD_MODIFY_TRAIT(IteratorValue, PointerT_)>());
	}


#	if DDCPP_GUARD_DESTROY
	template <typename ValueT_, typename DeleterT_>
	ProcessType operator ()(ValueT_*& pointer_, DeleterT_ deleter__) DD_NOEXCEPT {
		call(pointer__, deleter__);
	}

#	endif
	template <typename PointerT_, typename DeleterT_>
	ProcessType operator ()(PointerT_ const& pointer__, DeleterT_ deleter__) const DD_NOEXCEPT {
		call(pointer__, deleter__);
	}

#	if DDCPP_GUARD_DESTROY
	template <typename ValueT_>
	ProcessType operator ()(ValueT_*& pointer_) DD_NOEXCEPT {
		call(pointer__);
	}

#	endif
	template <typename PointerT_>
	ProcessType operator ()(PointerT_ const& pointer__) const DD_NOEXCEPT {
		call(pointer__);
	}


} DD_CONSTANT destroy;



DD_DETAIL_END_



DD_BEGIN_
using detail_::Destroy;

using detail_::destroy;



DD_END_



#endif
