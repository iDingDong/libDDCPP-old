//	DDCPP/standard/bits/DD_StrictAutoPointer.hpp
#ifndef DD_STRICT_AUTO_POINTER_HPP_INCLUDED_
#	define DD_STRICT_AUTO_POINTER_HPP_INCLUDED_ 1



#	include "DD_StrictPointer.hpp"



DD_DETAIL_BEGIN_
template <
	typename ValueT_,
	ProcessType(&deleter_c_)(DD_MODIFY_TRAIT(RemoveExtent, ValueT_)*) DD_NOEXCEPT = DefaultDeleter<ValueT_>::destroy
>
struct StrictAutoPointer : StrictPointer<ValueT_, deleter_c_> {
	public:
	typedef StrictPointer<ValueT_, deleter_c_> SuperType;
	typedef StrictAutoPointer<ValueT_, deleter_c_> ThisType;
	DD_VALUE_TYPE_NESTED(ValueT_);


	public:
	StrictAutoPointer() throw() {
	}

	public:
	StrictAutoPointer(PointerType pointer_) throw() : SuperType(pointer_) {
	}


	public:
	ThisType operator =(ThisType const& origin_) throw() {
		this->reset(origin_.release());
	}


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
