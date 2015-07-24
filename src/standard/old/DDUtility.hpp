#ifndef _DDUTILITY_
 #define _DDUTILITY_



 #include "DDTool.hpp"



 #define DDPAIR_MEMBER(...) template <typename ValueT1, typename ValueT2> __VA_ARGS__ DDPair<ValueT1, ValueT2>
 #define DDOPTIONAL_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDOptional<ValueT>



DD_BEGIN
template <typename ValueT1, typename ValueT2>
struct DDPair;

template <typename ValueT>
struct DDOptional;


template <typename ObjectT>
inline ProcessType swap(DDPair<ObjectT, ObjectT>& objects) noexcept(false);// To optimize


template <typename ValueT1, typename ValueT2>
struct DDPair {
    public:
    using LeftValueType = ValueT1;
    using RightValueType = ValueT2;
    
    public:
    ValueT1 left;
    ValueT2 right;
    
};


template <typename ValueT>
struct DDOptional {
    public:
    using ValueType = ValueT;
    using StorageType = typename std::aligned_storage<sizeof(ValueT), std::alignment_of<ValueT>::value>::type;
    
    public:
    DDOptional(Nil const& nil) noexcept(true);
    template <typename... ArgumentsT>
    DDOptional(ArgumentsT&&... construct_arguments) noexcept(false);// To optimize
    ValidityType is_valid() const noexcept(true);
    ValueT& get_reference() noexcept(true);
    ValueT* get_address() noexcept(true);
    
    private:
    ValidityType m_validity = false;
    StorageType m_value;
    
};


DD_END



DD_BEGIN
template <typename ObjectT>
inline ProcessType swap(DDPair<ObjectT, ObjectT>& objects) noexcept(false) {
    using DD::swap;
    swap(objects.left, objects.right);
}


DDOPTIONAL_MEMBER(inline ValidityType)::is_valid() const noexcept(true) {
    return this->m_validity;
}


DDOPTIONAL_MEMBER(inline ValueT&)::get_reference() noexcept(true) {
    return reinterpret_cast<ValueT&>(m_value);
}


DDOPTIONAL_MEMBER(inline ValueT*)::get_address() noexcept(true) {
    return this->m_validity ? DD::address_of(get_reference()) : nullptr;
}


DD_END



 #undef DDPAIR_MEMBER
 #undef DDOPTIONAL_MEMBER



#endif