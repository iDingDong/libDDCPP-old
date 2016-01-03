//	DDCPP/standard/bits/DD_Allocateable.hpp
#ifndef DD_ALLOCATEABLE_HPP_INCLUDED_
#	define DD_ALLOCATEABLE_HPP_INCLUDED_



#	include "DD_Agent.hpp"
#	include "DD_Allocator.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename AllocatorT_ = Allocator<void>>
#	else
template <typename AllocatorT_ = Allocator<void> >
#	endif
struct Allocateable : protected Agent<AllocatorT_> {
	public:
	DD_ALIAS(AllocateAgent, Agent<AllocatorT_>);
	DD_ALIAS(ThisType, Allocateable<AllocatorT_>);
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_ALIAS(ValueType, typename AllocatorType::ValueType);
	DD_ALIAS(ValueConstType, typename AllocatorType::ValueConstType);
	DD_ALIAS(ReferenceType, typename AllocatorType::ReferenceType);
	DD_ALIAS(ConstReferenceType, typename AllocatorType::ConstReferenceType);
	DD_ALIAS(PointerType, typename AllocatorType::PointerType);
	DD_ALIAS(ConstPointerType, typename AllocatorType::ConstPointerType);



#	if __cplusplus >= 201103L
	public:
	constexpr Allocateable() = default;

	public:
	constexpr Allocateable(ThisType const& origin_) = default;

	public:
	constexpr Allocateable(ThisType&& origin_) = default;
#	else
	public:
	Allocateable() {
	}
#	endif

	public:
	Allocateable(AllocatorType const& allocator_) : AllocateAgent(allocator_) {
	}


#	if __cplusplus >= 201103L
	public:
	~Allocateable() = default;


#	endif
	public:
	AllocatorType& get_allocator() const DD_NOEXCEPT {
		return AllocateAgent::get_instance();
	}


	public:
	GlobalPointerType basic_allocate(SizeType size_) const {
		return get_allocator().AllocatorType::Basic::allocate(size_);
	}


	public:
	PointerType allocate(LengthType length_) const {
		return get_allocator().allocate(length_);
	}


	public:
	ProcessType basic_deallocate(GlobalPointerType pointer_) const DD_NOEXCEPT {
		get_allocator().AllocatorType::Basic::deallocate(pointer_);
	}

	public:
	ProcessType basic_deallocate(GlobalPointerType pointer_, SizeType size_) const DD_NOEXCEPT {
		get_allocator().AllocatorType::Basic::deallocate(pointer_, size_);
	}


	public:
	ProcessType deallocate(PointerType pointer_) const DD_NOEXCEPT {
		get_allocator().deallocate(pointer_);
	}

	public:
	ProcessType deallocate(PointerType pointer_, LengthType length_) const DD_NOEXCEPT {
		get_allocator().deallocate(pointer_, length_);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Allocateable;



DD_END_



#endif
