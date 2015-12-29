//	DDCPP/standard/bits/DD_Allocateable.hpp
#ifndef DD_ALLOCATEABLE_HPP_INCLUDED_
#	define DD_ALLOCATEABLE_HPP_INCLUDED_



#	include "DD_Agent.hpp"
#	include "DD_Allocator.hpp"



DD_DETAIL_BEGIN_
template <typename AllocatorT_, ValidityType need_instance_c_>
struct Allocateable_ {
	public:
	DD_ALIAS(ThisType, Allocateable_<AllocatorT_ DD_COMMA need_instance_c_>);
	DD_ALIAS(AllocatorType, AllocatorT_);
	static ValidityType DD_CONSTANT need_instance = need_instance_c_;

	public:
	DD_ALIAS(ValueType, typename AllocatorType::ValueType);
	DD_ALIAS(ValueConstType, typename AllocatorType::ValueConstType);
	DD_ALIAS(ReferenceType, typename AllocatorType::ReferenceType);
	DD_ALIAS(ConstReferenceType, typename AllocatorType::ConstReferenceType);
	DD_ALIAS(PointerType, typename AllocatorType::PointerType);
	DD_ALIAS(ConstPointerType, typename AllocatorType::ConstPointerType);


#	if __cplusplus >= 201103L
	protected:
	constexpr Allocateable_() = default;

	protected:
	constexpr Allocateable_(ThisType const& origin_) = default;

	protected:
	constexpr Allocateable_(ThisType&& origin_) = default;
#	else
	protected:
	Allocateable_() throw() {
	}
#	endif

	protected:
	Allocateable_(AllocatorType const& allocator_) DD_NOEXCEPT {
	}


#	if __cplusplus >= 201103L
	protected:
	~Allocateable_() = default;


#	endif
	public:
	AllocatorType& get_allocator() DD_NOEXCEPT {
		static AllocatorType instance_ = AllocatorType();
		return instance_;
	}


	public:
	static GlobalPointerType basic_allocate(SizeType size_) {
		return AllocatorType::Basic::allocate(size_);
	}


	public:
	static PointerType allocate(LengthType length_) {
		return AllocatorType::allocate(length_);
	}


	public:
	static ProcessType basic_deallocate(GlobalPointerType pointer_) DD_NOEXCEPT {
		return AllocatorType::Basic::deallocate(pointer_);
	}

	public:
	static ProcessType basic_deallocate(GlobalPointerType pointer_, SizeType size_) DD_NOEXCEPT {
		return AllocatorType::Basic::deallocate(pointer_, size_);
	}


	public:
	static ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		return AllocatorType::deallocate(pointer_);
	}

	public:
	static ProcessType deallocate(PointerType pointer_, LengthType length_) DD_NOEXCEPT {
		return AllocatorType::deallocate(pointer_, length_);
	}


#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType const& origin_) = default;

	protected:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename AllocatorT_>
struct Allocateable_<AllocatorT_, true> {
	public:
	DD_ALIAS(ThisType, Allocateable_<AllocatorT_ DD_COMMA true>);
	DD_ALIAS(AllocatorType, AllocatorT_);
	static ValidityType DD_CONSTANT need_instance = true;

	public:
	DD_ALIAS(ValueType, typename AllocatorType::ValueType);
	DD_ALIAS(ValueConstType, typename AllocatorType::ValueConstType);
	DD_ALIAS(ReferenceType, typename AllocatorType::ReferenceType);
	DD_ALIAS(ConstReferenceType, typename AllocatorType::ConstReferenceType);
	DD_ALIAS(PointerType, typename AllocatorType::PointerType);
	DD_ALIAS(ConstPointerType, typename AllocatorType::ConstPointerType);


	private:
	AllocatorType mutable m_allocator_ DD_IN_CLASS_INITIALIZE(AllocatorType());


#	if __cplusplus >= 201103L
	protected:
	constexpr Allocateable_() = default;

	protected:
	constexpr Allocateable_(ThisType const& origin_) = default;

	protected:
	constexpr Allocateable_(ThisType&& origin_) = default;
#	else
	protected:
	Allocateable_() throw() : m_allocator_() {
	}
#	endif

	protected:
	Allocateable_(AllocatorType const& allocator_) : m_allocator_(allocator_) {
	}


#	if __cplusplus >= 201103L
	protected:
	~Allocateable_() = default;


#	endif
	public:
	AllocatorType& get_allocator() const DD_NOEXCEPT {
		return m_allocator_;
	}


	protected:
	GlobalPointerType basic_allocate(SizeType size_) const {
		return get_allocator().AllocatorType::Basic::allocate(size_);
	}


	protected:
	PointerType allocate(LengthType length_) const {
		return get_allocator().allocate(length_);
	}


	protected:
	ProcessType basic_deallocate(GlobalPointerType pointer_) const DD_NOEXCEPT {
		return get_allocator().AllocatorType::Basic::deallocate(pointer_);
	}

	protected:
	ProcessType basic_deallocate(GlobalPointerType pointer_, SizeType size_) const DD_NOEXCEPT {
		return get_allocator().AllocatorType::Basic::deallocate(pointer_, size_);
	}


	protected:
	ProcessType deallocate(PointerType pointer_) const DD_NOEXCEPT {
		return get_allocator().deallocate(pointer_);
	}

	protected:
	ProcessType deallocate(PointerType pointer_, LengthType length_) const DD_NOEXCEPT {
		return get_allocator().deallocate(pointer_, length_);
	}


#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType const& origin_) = default;

	protected:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



#	if __cplusplus >= 201103L
template <typename AllocatorT_ = Allocator<void>>
#	else
template <typename AllocatorT_ = Allocator<void> >
#	endif
struct Allocateable : Allocateable_<AllocatorT_, NeedInstance<AllocatorT_>::value> {
	public:
	DD_ALIAS(SuperType, Allocateable_<AllocatorT_ DD_COMMA NeedInstance<AllocatorT_>::value>);
	DD_ALIAS(ThisType, Allocateable<AllocatorT_>);
	DD_ALIAS(AllocatorType, AllocatorT_);


#	if __cplusplus >= 201103L
	public:
	using SuperType::SuperType;
#	else
	public:
	Allocateable() {
	}

	public:
	Allocateable(AllocatorType const& allocator_) : SuperType(allocator_) {
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Allocateable;



DD_END_



#endif
