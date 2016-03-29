//	DDCPP/standard/bits/DD_CopyOnWrite.hpp
#ifndef DD_COPY_ON_WRITE_HPP_INCLUDED_
#	define DD_COPY_ON_WRITE_HPP_INCLUDED_ 1



#	include "DD_destruct.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_Deleter.hpp"
#	include "DD_ParasiticPointer.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct CopyOnWrite {
	public:
	DD_ALIAS(ThisType, CopyOnWrite<ValueT_ DD_COMMA AllocatorT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
#	if __cplusplus >= 201103L
	using StorageType_ = ParasiticPointer<ValueT_, Deleter<AllocatorType>>;
#	else
	typedef ParasiticPointer<ValueT_, Deleter<AllocatorType> > StorageType_;
#	endif


	private:
	StorageType_ m_storage__;

	public:
	CopyOnWrite() {
		AllocatorType allocator_ = AllocatorType();
		StorageType_::ParasitiferPointerType pointer_ = allocator_.Basic::allocate(sizeof(*pointer_));
		try {
			::DD::construct(pointer_, Deleter<AllocatorType>(allocator_));
		} catch (...) {
			allocator_.Basic::deallocate(pointer_, sizeof(*pointer_));
			throw;
		}
		m_storage__ = pointer_;
	}

#	if __cplusplus >= 201103L
	public:
	CopyOnWrite(ThisType const& origin_) = default;

	public:
	CopyOnWrite(ThisType&& origin_) = default;

	public:
	CopyOnWrite(ThisType& origin_) : ThisType(static_cast<ThisType const&>(origin_)) {
	}

	public:
	template <typename... ArgumentsT__>
	CopyOnWrite(ArgumentsT__&&... arguments___) {
		AllocatorType allocator_ = AllocatorType();
		StorageType_::ParasitiferPointerType pointer_ = allocator_.Basic::allocate(sizeof(*pointer_));
		try {
			::DD::construct(pointer_, ::DD::forward<ArgumentsT__>(arguments___)...);
		} catch (...) {
			allocator_.Basic::deallocate(pointer_, sizeof(*pointer_));
			throw;
		}
		m_storage__ = pointer_;
	}
#	else
	public:
	template <typename ValueT__>
	CopyOnWrite(ValueT__ const& value___) {
		AllocatorType allocator_ = AllocatorType();
		StorageType_::ParasitiferPointerType pointer_ = allocator_.Basic::allocate(sizeof(*pointer_));
		try {
			::DD::construct(
				pointer_,
				StorageType_::ParasitiferType(Deleter<AllocatorType>(allocator_), construct_tag, value___)
			);
		} catch (...) {
			allocator_.Basic::deallocate(pointer_, sizeof(*pointer_));
			throw;
		}
		m_storage__ = pointer_;
	}
#	endif


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap()
	}

#	if __cplusplus >= 201103L
	public:
	ProcessType swap(ThisType&& other_) DD_NOEXCEPT {
		swap(other_);
	}

#	endif

	public:
	ConstReferenceType read() const DD_NOEXCEPT {
		return *m_storage__;
	}


	public:
	ReferenceType write() const DD_NOEXCEPT {
		if (!is_unique()) {
			reset(read());
		}
		return *m_storage__;
	}


}



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
