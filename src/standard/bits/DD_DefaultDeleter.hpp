//	DDCPP/standard/bits/DD_DefualtDeleter.hpp
#ifndef DD_DEFAULT_DELETER_HPP_INCLUDED_
#	define DD_DEFAULT_DELETER_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ValueT_>
class DefaultDeleter {
	public:
	DD_ALIAS(ValueType, ValueT_);


#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR DefaultDeleter() = default;


#	endif
	public:
	ProcessType operator ()(ValueT_* pointer_) DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type.");
		delete pointer_;
	}


	public:
	static ProcessType operate(ValueT_* pointer_) DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type.");
		delete pointer_;
	}


};



DD_END_



#endif
