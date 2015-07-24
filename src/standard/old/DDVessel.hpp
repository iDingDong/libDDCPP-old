// DDVessel.hpp
#ifndef _DDVESSEL_
 #define _DDVESSEL_






 #include "DDContainer.hpp"



 #define DDVESSEL_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDVessel<ValueT>



DD_BEGIN
template <typename ValueT>
class DDVessel : public DDImplement::TightContainerBase<ValueT> {
    public:
    using ValueType = ValueT;
    
    public:
    DDVessel();
    DDVessel(const DDVessel<ValueT>& origin);
    DDVessel(DDVessel<ValueT>&& origin) noexcept;
    DDVessel(std::initializer_list<ValueT> initializer);
    template <typename... ArgumentsT>
    DDVessel(LengthType new_length, ArgumentsT&&... construct_arguments);
    ~DDVessel() noexcept;
    LengthType get_length() const noexcept;
    ValidityType is_empty() const noexcept;
    ValidityType is_available(SubscriptType index) const noexcept;
    template <typename... ArgumentsT>
    DDVessel<ValueT>& lengthen(LengthType extra_length, ArgumentsT&&... construct_arguments);
    template <typename ContainerT>
    DDVessel<ValueT>& clone(const ContainerT& origin);
    DDVessel<ValueT>& clone(DDVessel<ValueT>&& origin) noexcept;
    DDVessel<ValueT>& swap(DDVessel<ValueT>& target) noexcept;
    DDVessel<ValueT>& clear() noexcept;
    
    public:
    DDVessel<ValueT>& operator =(const DDVessel<ValueT>& origin);
    DDVessel<ValueT>& operator =(DDVessel<ValueT>&& origin) noexcept;
    ValueT& operator [](SubscriptType index);
    const ValueT& operator [](SubscriptType index) const;
    
    protected:
    SubscriptType& check_index(SubscriptType& index) const;
    
    protected:
    LengthType m_length = 0;
    ValueT* m_content = nullptr;
    
};


DD_END



DD_BEGIN
DDVESSEL_MEMBER(inline)::DDVessel() : DDImplement::TightContainerBase<ValueT>(0, nullptr) {
}

DDVESSEL_MEMBER()::DDVessel(const DDVessel<ValueT>& origin) try : DDImplement::TightContainerBase<ValueT>(origin.m_length, (ValueT*)(::operator new(sizeof(ValueT) * m_length))) {
    for (CounterType i = 0; i < this->m_length; ++i) {
        DDALLOCATE(new (this->m_content + i) ValueT(origin.m_content[i]), "Failed to allocate DDVessal. ", while (i) { this->m_content[--i].~ValueT(); } ::operator delete(this->m_content); );
    }
} catch(std::bad_alloc) {
    this->m_length = 0;
    throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate DDVessal. ");
}

DDVESSEL_MEMBER(inline)::DDVessel(DDVessel<ValueT>&& origin) noexcept : DDImplement::TightContainerBase<ValueT>(origin.m_length, origin.m_content) {
    origin.m_length = 0;
    origin.m_content = nullptr;
}

DDVESSEL_MEMBER()::DDVessel(std::initializer_list<ValueT> initializer) try :  DDImplement::TightContainerBase<ValueT>(initializer.size(), (ValueT*)(::operator new(sizeof(ValueT) * m_length))) {
    for (CounterType i = 0; i < this->m_length; ++i) {
        DDALLOCATE(new (this->m_content + i) ValueT(initializer.begin()[i]), "Failed to allocate DDVessal. ", while (i) { this->m_content[--i].~ValueT(); } ::operator delete(this->m_content); );
    }
} catch(std::bad_alloc) {
    this->m_length = 0;
    throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate DDVessal. ");
}

DDVESSEL_MEMBER(template <typename... ArgumentsT>)::DDVessel(LengthType new_length, ArgumentsT&&... construct_arguments) :  DDImplement::TightContainerBase<ValueT>(new_length, nullptr) {
    if (m_length < 0) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid initial m_length of DDVessel. ");
    }
    DDALLOCATE(this->m_content = (ValueT*)(::operator new(sizeof(ValueT) * this->m_length)), "Failed to allocate DDVessel. ", this->m_length = 0; )
    for (CounterType i = 0; i < m_length; ++i) {
        DDALLOCATE(new (this->m_content + i) ValueT(construct_arguments...), "Failed to allocate DDVessal. ", while (i) { this->m_content[--i].~ValueT(); } ::operator delete(this->m_content); );
    }
}


DDVESSEL_MEMBER(inline)::~DDVessel() noexcept {
    this->destruct();
}


DDVESSEL_MEMBER(template <typename... ArgumentsT> DDVessel<ValueT>&)::lengthen(LengthType extra_length, ArgumentsT&&... construct_arguments) {
    if (extra_length) {
        m_length += extra_length;
        if (m_length < 0) {
            throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid new m_length of DDVessel. ");
        } else if (m_length == 0) {
            return clear();
        }
        ValueT* tmp_content;
        DDALLOCATE(tmp_content = (ValueT*)(::operator new(sizeof(ValueT) * m_length)), "Failed to allocate new vessel. ", m_length -= extra_length; )
        for (auto i = 0; i < m_length; ++i) {
            DDALLOCATE(new (tmp_content + i) ValueT(*(this->m_content + i)), "Failed to allocate DDVessal. ", while (i) { tmp_content[--i].~ValueT(); } ::operator delete(tmp_content); );
        }
        for (auto i = extra_length; i > 0; --i) {
            DDALLOCATE(new (tmp_content + this->m_length - i) ValueT(construct_arguments...), "Failed to allocate DDVessal. ", for (auto j = this->m_length - i; j; --j) { tmp_content[j].~ValueT(); } ::operator delete(tmp_content); );
        }
    }
    //throw DDErrorType(DDErrorType::UNREALIZED, "Unrealized DD::DDVessel::lengthen. ");
    return *this;
}


DDVESSEL_MEMBER(template <typename ContainerT> DDVessel<ValueT>&)::clone(const ContainerT& origin) {
    throw DDErrorType(DDErrorType::UNREALIZED, "Unrealized DD::DDVessel::clone. ");
}

DDVESSEL_MEMBER(DDVessel<ValueT>&)::clone(DDVessel<ValueT>&& origin) noexcept {
    return this->swap(origin);
}


DDVESSEL_MEMBER(inline DDVessel<ValueT>&)::swap(DDVessel<ValueT>& target) noexcept {
    DD::swap(m_length, target.m_length);
    DD::swap(m_content, target.m_content);
    return *this;
}


DDVESSEL_MEMBER(inline DDVessel<ValueT>&)::clear() noexcept {
    this->destruct();
    return *this;
}


DDVESSEL_MEMBER(inline DDVessel<ValueT>&)::operator =(const DDVessel<ValueT>& origin) {
    this->clone(origin);
}

DDVESSEL_MEMBER(inline DDVessel<ValueT>&)::operator =(DDVessel<ValueT>&& origin) noexcept {
    return this->swap(origin);
}


DD_END



#endif
