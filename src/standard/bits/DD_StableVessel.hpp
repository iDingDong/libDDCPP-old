//	DDCPP/standard/bits/DD_StableVessel.hpp
#ifndef DD_STABLE_VESSEL_HPP_INCLUDED_
#	define DD_STABLE_VESSEL_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_IteratorNested.hpp"
#	include "DD_fabricate.hpp"
#	include "DD_destruct.hpp"
#	include "DD_Allocateable.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct StableVessel_ {
	public:
	DD_ALIAS(ThisType, StableVessel_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_ALIAS(Iterator, PointerType);
	DD_ALIAS(ConstIterator, ConstPointerType);
	DD_ITERATOR_NESTED


	protected:
	PointerType m_begin_ = PointerType();
	PointerType m_end_ = PointerType();


	protected:
#	if __cplusplus >= 201103L
	constexpr StableVessel_() = default;
#	else
	StableVessel_() : m_begin_(), m_end_() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(StableVessel_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(StableVessel_)

	protected:
	DD_CONSTEXPR StableVessel_(
		PointerType begin_, PointerType end_
	) DD_NOEXCEPT : m_begin_(begin_), m_end_(end_) {
	}


	protected:
	~StableVessel_() DD_NOEXCEPT {
		destruct_();
	}


	public:
	Iterator begin() DD_NOEXCEPT {
		return Iterator(m_begin_);
	}

	public:
	ConstIterator DD_UNCONSTRIANED_CONSTEXPR begin() const DD_NOEXCEPT {
		return Iterator(m_begin_);
	}


	public:
	Iterator end() DD_NOEXCEPT {
		return Iterator(m_end_);
	}

	public:
	ConstIterator DD_UNCONSTRIANED_CONSTEXPR end() const DD_NOEXCEPT {
		return Iterator(m_end_);
	}


	public:
	LengthType DD_CONSTEXPR get_length() const DD_NOEXCEPT {
		return end() - begin();
	}


	protected:
	ProcessType destruct_() DD_NOEXCEPT {
		::DD::destruct(begin(), end());
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(StableVessel_)


};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct StableVessel : protected Allocateable<AllocatorT_>, StableVessel_<ValueT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(SuperType, StableVessel_<ValueT_>);
	DD_ALIAS(ThisType, StableVessel<ValueT_>);

#	if __cplusplus >= 201103L
	public:
	constexpr StableVessel() = default;
#	else
	public:
	StableVessel() throw() {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename ValueT__>
	ProcessType emplace_back(ValueT__&& value___) {
		PointerType new_begin_ = AllocateAgent::allocate(this->get_length() + 1);
		try {
			PointerType new_end_ = ::DD::transconstruct(this->begin(), this->end(), new_begin_);
			SuperType::destruct_();
			destruct_();
			this->m_begin_ = new_begin_;
			this->m_end_ = new_end_;
		} catch (...) {
			AllocateAgent::deallocate(new_begin_, this->get_length() + 1);
		}
	}

	public:
	template <typename ValueT__>
	ProcessType push_back(ValueT__&& value___) {
	}
#	else
#	endif


}



DD_DETAIL_END_



#endif
