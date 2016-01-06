//	DDCPP/standard/bits/DD_StronglyReferable.hpp
#ifndef DD_STRONGLY_REFERABLE_HPP_INCLUDED_
#	define DD_STRONGLY_REFERABLE_HPP_INCLUDED_ 1



#	include "DD_WeakPointer.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
#	if __cplusplus >= 201103L
StronglyReferable<ValueT_>::StronglyReferable() noexcept = default;
#	else
StronglyReferable<ValueT_>::StronglyReferable() throw() {
}
#	endif

template <typename ValueT_>
StronglyReferable<ValueT_>::StronglyReferable(StronglyReferable<ValueT_> const& origin_) DD_NOEXCEPT {
}

#	if __cplusplus >= 201103L
template <typename ValueT_>
StronglyReferable<ValueT_>::StronglyReferable(StronglyReferable<ValueT_>&& origin_) DD_NOEXCEPT {
}

#	endif

template <typename ValueT_>
typename StronglyReferable<ValueT_>::StrongPointerType StronglyReferable<ValueT_>::get_strong_pointer() DD_NOEXCEPT {
	return m_weak_pointer_.lock();
}

template <typename ValueT_>
typename StronglyReferable<ValueT_>::ConstStrongPointerType StronglyReferable<ValueT_>::get_strong_pointer() const DD_NOEXCEPT {
	return m_weak_pointer_.lock().get_const_strong_pointer();
}


template <typename ValueT_>
typename StronglyReferable<ValueT_>::WeakPointerType StronglyReferable<ValueT_>::get_weak_pointer() DD_NOEXCEPT {
	return m_weak_pointer_;
}

template <typename ValueT_>
typename StronglyReferable<ValueT_>::ConstWeakPointerType StronglyReferable<ValueT_>::get_weak_pointer() const DD_NOEXCEPT {
	return m_weak_pointer_.get_const_weak_pointer();
}


template <typename ValueT_>
ProcessType StronglyReferable<ValueT_>::set_manager_(StronglyReferable<ValueT_>::ManagerPointerType manager_pointer_) DD_NOEXCEPT {
	m_weak_pointer_.set_manager_(manager_pointer_);
}



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
