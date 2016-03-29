//	DDCPP/standard/bits/DD_Producer.hpp
#ifndef DD_PRODUCER_HPP_INCLUDED_
#	define DD_PRODUCER_HPP_INCLUDED_ 1



#	include "DD_construct.hpp"
#	include "DD_Allocateable.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct Producer : protected Allocateable<AllocatorT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(ThisType, Producer);
	DD_VALUE_TYPE_NESTED(ValueT_);
	DD_ALIAS(AllocatorType, AllocatorT_);


	public:
	AllocatorType& get_allocator() const DD_NOEXCEPT {
		return AllocateAgent::get_allocator();
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	PointerType call(ArgumentsT__&&... arguments___) {
		PointerType pointer_ = AllocateAgent::basic_allocate(sizeof(*pointer_));
		try {
			::DD::construct(pointer_, ::DD::forward<ArgumentsT__>(arguments___)...);
		} catch (...) {
			AllocateAgent::basic_deallocate(pointer_, sizeof(*pointer_));
		}
		return pointer_;
	}
#	else
	public:
	PointerType call() {
		PointerType pointer_ = AllocateAgent::basic_allocate(sizeof(*pointer_));
		try {
			::DD::construct(pointer_);
		} catch (...) {
			AllocateAgent::basic_deallocate(pointer_, sizeof(*pointer_));
		}
		return pointer_;
	}

	public:
	template <typename ArgumentT__>
	PointerType call(ArgumentT__ const& argument___) {
		PointerType pointer_ = AllocateAgent::basic_allocate(sizeof(*pointer_));
		try {
			::DD::construct(pointer_, argument___);
		} catch (...) {
			AllocateAgent::basic_deallocate(pointer_, sizeof(*pointer_));
		}
		return pointer_;
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	PointerType operator ()(ArgumentsT__&&... arguments___) {
		return call(pointer_, ::DD::forward<ArgumentsT__>(arguments___)...);
	}
#	else
	public:
	PointerType operator ()() {
		return call();
	}

	public:
	template <typename ArgumentT__>
	PointerType operator ()(ArgumentT__ const& argument___) {
		return call(argument___);
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
