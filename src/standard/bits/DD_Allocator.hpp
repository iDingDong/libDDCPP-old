//	DDCPP/standard/bits/DD_Allocator.hpp
#ifndef _DD_ALLOCATOR_HPP_INCLUDED
#	define _DD_ALLOCATOR_HPP_INCLUDED 1



#	include <cstdlib>

#	include "DD_ValueTypeNested.hpp"
#	include "DD_AllocationFailure.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyDestructible.hpp"
#		include "DD_forward.hpp"
#	endif
#	include "DD_debugger_definitions.hpp"
#	include "DD_address_of.hpp"



_DD_DETAIL_BEGIN
template <typename _ValueT = void>
class Allocator {
	public:
	DD_ALIAS(ThisType, Allocator<_ValueT>);
	DD_VALUE_TYPE_NESTED(_ValueT)


};



template <>
class Allocator<void> {
	public:
	DD_ALIAS(ThisType, Allocator<void>);
	DD_ALIAS(ValueType, void);

	public:
	DD_ALIAS(Basic, Allocator<void>);

	public:
	DD_ALIAS(PointerType, ValueType*);
	DD_ALIAS(SizeType, DD::SizeType);


	static PointerType allocate(SizeType _size) {
		PointerType temp = ::operator new(_size);
		if (temp) {
			return temp;
		}
		throw AllocationFailure("'DD::Allocator' Failed to allocate.");
	}


	static ProcessType deallocate(PointerType _pointer) DD_NOEXCEPT {
		::operator delete(_pointer);
	}


	static ProcessType deallocate(PointerType _pointer, SizeType _size) DD_NOEXCEPT {
		::operator delete(_pointer);
	}


#	if __cplusplus >= 201103L
	template <typename _ValueT_, typename... _ArgumentsT_>
	static void construct(_ValueT_* _pointer, _ArgumentsT_&&... __arguments_) noexcept(
		noexcept(new (_pointer) _ValueT_(forward<_ArgumentsT_>(__arguments_)...))
	) {
		new (_pointer) _ValueT_(forward<_ArgumentsT_>(__arguments_)...);
	}
#	else
	template <typename _ValueT_>
	static void construct(_ValueT_* _pointer, _ValueT_ const& __value_) {
		new (_pointer) _ValueT_(__value_);
	}
#	endif


};



_DD_DETAIL_END



_DD_BEGIN
using _detail::Allocator;



_DD_END



#endif
