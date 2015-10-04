//	DDCPP/standard/bits/DD_Pool.hpp
#ifndef DD_POOL_HPP_INCLUDED_
#	define DD_POOL_HPP_INCLUDED_ 1



#	include "DD_NeedInstance.hpp"
#	include "DD_Array.hpp"
#	include "DD_Allocator.hpp"



#	ifndef DDCPP_POOL_INITIALIZE_ALL_LISTS
#		define DDCPP_POOL_INITIALIZE_ALL_LISTS 0
#	endif

#	ifndef DDCPP_POOL_MAXIMUM_MEMORY_UNITS
#		define DDCPP_POOL_MAXIMUM_MEMORY_UNITS 64
#	endif



DD_DETAIL_BEGIN_
template <typename AllocatorT_, ValidityType need_instance_c_>
struct Pool_ {
	public:
	DD_ALIAS(ThisType, Pool_<AllocatorT_ DD_COMMA need_instance_c_>);
	DD_ALIAS(AllocatorType, AllocatorT_);
	DD_ALIAS(ValueType, void);

	public:
	DD_ALIAS(PointerType, void*);
	DD_ALIAS(BasicAllocatorType, typename AllocatorType::Basic);

	public:
	DD_ALIAS(SizeType, ::DD::SizeType);
	DD_ALIAS(LengthType, ::DD::LengthType);
	static DD_CONSTANT SizeType unit = sizeof(void*);
	static DD_CONSTANT LengthType maximum_units = DDCPP_POOL_MAXIMUM_MEMORY_UNITS;
	static DD_CONSTANT SizeType maximum_size = unit * maximum_units;


	public:
	DD_ALIAS(FreeListsType_, Array<void* DD_COMMA maximum_units>);


	private:
	FreeListsType_ m_free_lists_ DD_IN_CLASS_INITIALIZE({});


	public:
#	if __cplusplus >= 201103L
	Pool_() = default;
#	else
	Pool_() throw() : m_free_lists_{{}} {
	}
#	endif

	public:
	DD_DELETE_COPY_CONSTRUCTOR(Pool_);

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(Pool_);


	public:
	~Pool_() DD_NOEXCEPT {
		clear();
	}


	private:
	static SizeType DD_CONSTEXPR get_size_(LengthType index_) DD_NOEXCEPT {
		return unit * (index_ + 1);
	}


	private:
	static LengthType DD_CONSTEXPR get_index_(SizeType size_) DD_NOEXCEPT {
		return size_ ? size_ - 1 / unit : 0;
	}


	private:
	static PointerType*& get_next_(PointerType node_) DD_NOEXCEPT {
		return reinterpret_cast<PointerType*>(node_);
	}


	private:
	PointerType fetch_(LengthType index_) DD_NOEXCEPT_AS(
		static_cast<PointerType>(BasicAllocatorType::allocate(get_size_(index_)))
	) {
		PointerType temp_;
		if (m_free_lists_[index_]) {
			temp_ = m_free_lists_[index_];
			m_free_lists_[index_] = get_next_(temp_);
		} else {
			temp_ = BasicAllocatorType::allocate(get_size_(index_));
		}
		return temp_;
	}


	private:
	ProcessType recycle_(PointerType temp_, LengthType index_) DD_NOEXCEPT {
		get_next_(temp_) = m_free_lists_[index_];
		m_free_lists_[index_] = temp_;
	}


	public:
	ProcessType breed(SizeType size_) DD_NOEXCEPT_AS(breed_(get_index_(size_))) {
		breed_(get_index_(size_));
	}


	private:
	ProcessType breed_(LengthType index_) DD_NOEXCEPT_AS(
		static_cast<PointerType>(BasicAllocatorType::allocate(get_size_(index_)))
	) {
		PointerType temp_ = BasicAllocatorType::allocate(get_size_(index_));
		recycle_(temp_, index_);
	}


	public:
	ProcessType clear() {
		for (LengthType current_ = 0; current_ < maximum_units; ++ current_) {
			clear_(current_);
		}
	}

	private:
	ProcessType clear_(LengthType index_) {
		for (PointerType temp_ = m_free_lists_[index_]; temp_; m_free_lists_[index_] = temp_) {
			temp_ = get_next_(temp_);
			BasicAllocatorType::deallocate(m_free_lists_[index_], get_size_(index_));
		}
	}


	public:
	PointerType allocate(SizeType size_) DD_NOEXCEPT_AS(fetch_(get_index_(size_))) {
		return fetch_(get_index_(size_));
	}


	public:
	ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		BasicAllocatorType::deallocate(pointer_);
	}

	public:
	ProcessType deallocate(PointerType pointer_, SizeType size_) DD_NOEXCEPT {
		recycle_(pointer_, get_index_(size_));
	}


};



template <typename AllocatorT_ = Allocator<void>>
class Pool {
	public:
	DD_ALIAS(ThisType, Pool<AllocatorT_>);
	DD_ALIAS(AllocatorType, AllocatorT_);
	DD_ALIAS(ValueType, void);


	public:
	DD_ALIAS(PointerType, void*);
	DD_ALIAS(BasicAllocatorType, typename AllocatorType::Basic);

	public:
	DD_ALIAS(SizeType, ::DD::SizeType);
	DD_ALIAS(LengthType, ::DD::LengthType);
	static DD_CONSTANT SizeType unit = sizeof(void*);
	static DD_CONSTANT LengthType maximum_units = DDCPP_POOL_MAXIMUM_MEMORY_UNITS;
	static DD_CONSTANT SizeType maximum_size = unit * maximum_units;

	public:
	DD_ALIAS(Basic, ThisType);
	DD_ALIAS(NeedInstance, FalseType);


	private:
	DD_ALIAS(ActualPoolType, Pool_<AllocatorT_ DD_COMMA ::DD::NeedInstance<AllocatorT_>::value>);


	private:
	static ActualPoolType m_pool_;


	public:
	static ProcessType breed(SizeType size_) DD_NOEXCEPT_AS(m_pool_.breed(size_)) {
		m_pool_.breed(size_);
	}


	public:
	static ProcessType clear() DD_NOEXCEPT {
		m_pool_.clear();
	}


	public:
	static PointerType allocate(SizeType size_) DD_NOEXCEPT_AS(m_pool_.allocate(size_)) {
		return m_pool_.allocate(size_);
	}


	public:
	static ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		m_pool_.deallocate(pointer_);
	}

	public:
	static ProcessType deallocate(PointerType pointer_, SizeType size_) DD_NOEXCEPT {
		m_pool_.deallocate(pointer_, size_);
	}


	public:
#	if __cplusplus >= 201103L
	template <typename ValueT__, typename... ArgumentsT__>
	static ProcessType construct(ValueT__* pointer_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(BasicAllocatorType::construct(pointer_, forward<ArgumentsT__>(arguments___)...))
	) {
		BasicAllocatorType::construct(pointer_, forward<ArgumentsT__>(arguments___)...);
	}
#	else
	template <typename ValueT__>
	static ProcessType construct(ValueT__* pointer_, ValueT__ const& value___) {
		BasicAllocatorType::construct(pointer_, value__);
	}
#	endif


	public:
	template <typename ValueT__>
	static ProcessType destruct(ValueT__* pointer_) DD_NOEXCEPT {
		BasicAllocatorType::destruct(pointer_);
	}


	public:
	template <typename ValueT__>
	static ProcessType destruct(ValueT__* begin_, ValueT__* end_) DD_NOEXCEPT {
		BasicAllocatorType::destruct(begin_, end_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Pool;



DD_END_



#endif
