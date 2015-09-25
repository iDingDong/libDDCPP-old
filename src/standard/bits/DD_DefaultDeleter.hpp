//	DDCPP/standard/bits/DD_DefualtDeleter.hpp
#ifndef _DD_DEFAULT_DELETER_HPP_INCLUDED
#	define _DD_DEFAULT_DELETER_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ValueT>
class DefaultDeleter {
	public:
	DD_ALIAS(ValueType, _ValueT);


#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR DefaultDeleter() = default;


#	endif
	public:
	ProcessType operator ()(_ValueT* _pointer) DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type.");
		delete _pointer;
	}


};



_DD_END



#endif
