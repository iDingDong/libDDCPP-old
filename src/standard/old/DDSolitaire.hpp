#ifndef _DDSOLITAIRE_
 #define _DDSOLITAIRE_



 #define DDSOLITAIRE_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDSolitaire<ValueT>



 #include "DDContainer.hpp"



DD_BEGIN
template <typename ValueT>
class DDSolitaire;


template <typename ValueT>
class DDSolitaire final : public DDImplement::FListBase<ValueT> {
    public:
    using ValueType = ValueT;
    using Cursor = typename DDImplement::FListBase<ValueT>::Cursor;
    using CCursor = typename DDImplement::FListBase<ValueT>::CCursor;
    
    public:
    DDSolitaire() = default;
    //DDSolitaire<ValueT>& insert();
    
    public:
    DDSolitaire<ValueT>& swap(DDSolitaire<ValueT>& target) noexcept;
    
    private:
    DDImplement::FListNode<ValueT>* m_last = nullptr;
    
};


DD_END



DD_BEGIN
DDSOLITAIRE_MEMBER(inline DDSolitaire<ValueT>&)::swap(DDSolitaire<ValueT>& target) noexcept {
    DDImplement::FListBase<ValueT>::swap(target);
    DD::swap(this->last, target.next);
    return *this;
}


DD_END



 #undef DDSOLITAIRE_MEMBER



#endif
