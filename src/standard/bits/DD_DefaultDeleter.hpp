//	DDCPP/standard/bits/DD_DefualtDeleter.hpp
#ifndef DD_DEFAULT_DELETER_HPP_INCLUDED_
#	define DD_DEFAULT_DELETER_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_IntegralConstant.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct DefaultDeleter {
	DD_ALIAS(ThisType, DefaultDeleter<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	DD_ALIAS(NeedInstance, FalseType);


	static ProcessType call(ValueType* pointer_) DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type.");
		delete pointer_;
	}


	ProcessType operator ()(ValueType* pointer_) DD_NOEXCEPT {
		call(pointer_);
	}


};



template <typename ValueT_>
struct DefaultDeleter<ValueT_[]> {
	DD_ALIAS(ThisType, DefaultDeleter<ValueT_[]>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	DD_ALIAS(NeedInstance, FalseType);


	static ProcessType call(ValueType* pointer_) DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type.");
		delete[] pointer_;
	}


	ProcessType operator ()(ValueType* pointer_) DD_NOEXCEPT {
		call(pointer_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::DefaultDeleter;



DD_END_



#endif
