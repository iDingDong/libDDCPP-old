// DDMemory.hpp
#ifndef _DDMEMORY_
 #define _DDMEMORY_



 #include "DDAllocator.hpp"
 #include <cstdlib>
 #include <iostream>



 #define DDUPOINTER_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDUPointer<ValueT>
 #define DDUPOINTER_SPECIALIZED_MEMBER(template_argument, ...) template <> __VA_ARGS__ DDUPointer<template_argument>
 #define DDSPOINTER_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDSPointer<ValueT>
 #define DDWPOINTER_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDWPointer<ValueT>



DD_BEGIN
DDIMPLEMENT_BEGIN
template <typename ValueT>
class DDPointer;

struct SPointerCounter;


DDIMPLEMENT_END


template <typename ValueT>
class DDUPointer;

template <> template <typename ElementT>
class DDUPointer<ElementT[]>;

template <typename ValueT>
class DDSPointer;


template <typename CursorT>
ProcessType default_delete(CursorT target);

template <typename CursorT>
ProcessType array_default_delete(CursorT target);

template <typename ValueT, typename... ArgumentsT>
DDSPointer<ValueT> make_spointer(ArgumentsT&&... construct_arguments);

template <typename ValueT, typename... ArgumentsT>
DDUPointer<ValueT> make_upointer(ArgumentsT&&... construct_arguments);

template <typename ValueT>
ProcessType swap(DDSPointer<ValueT>& spointer_1, DDSPointer<ValueT>& spointer_2);
template <typename ValueT>
ProcessType swap(DDUPointer<ValueT>& upointer_1, DDUPointer<ValueT>& upointer_2);

template <typename ValueT>
std::ostream &operator <<(std::ostream &os, const DDImplement::DDPointer<ValueT>& m_pointer) noexcept;


DDIMPLEMENT_BEGIN
template <typename ValueT>
class DDPointer {
    public:
    using ValueType = ValueT;
    using DeleterType = ProcessType(ValueT*);
    
    protected:
    DDPointer<ValueT>() noexcept = default;
    DDPointer<ValueT>(const DDPointer<ValueT>&) = delete;
    DDPointer<ValueT>(DDPointer<ValueT>&&) = delete;
    DDPointer<ValueT>(ValueT* const target, DeleterType& deleter = DD::default_delete<ValueT*>) noexcept;
    
    public:
    ~DDPointer<ValueT>() noexcept = default;
    ValueT* get_address() const noexcept;// Pointers assigned by this shouldn't be deleted, and there is no garentee on its validity. Do not use it to initialize a DDSPointer.
    
    protected:
    DDPointer<ValueT>& operator =(const DDPointer<ValueT>&) = delete;
    DDPointer<ValueT>& operator =(DDPointer<ValueT>&&) = delete;
    
    public:
    ValueT& operator *() const noexcept;
    ValueT* operator ->() const noexcept;
    explicit operator ValidityType() const noexcept;
    
    protected:
    ValueT* m_pointer = nullptr;
    DeleterType const* m_deleter = &DD::default_delete<ValueT*>;
    
};


struct SPointerCounter {
    public:
    QuantityType scount;
    QuantityType wcount;
    
};


DDIMPLEMENT_END


template <typename ValueT>
class DDUPointer : public DDImplement::DDPointer<ValueT> {
    public:
    using ValueType = ValueT;
    using DeleterType = typename DDImplement::DDPointer<ValueT>::DeleterType;
    
    public:
    DDUPointer<ValueT>() noexcept = default;
    DDUPointer<ValueT>(const DDUPointer<ValueT>& origin) = delete;
    DDUPointer<ValueT>(DDUPointer<ValueT>&& origin) noexcept;
    DDUPointer<ValueT>(ValueT* const target) noexcept;
    ~DDUPointer<ValueT>() noexcept;
    DDUPointer<ValueT>& swap(DDUPointer<ValueT>& target) noexcept;
    DDUPointer<ValueT>& reset() noexcept;
    DDUPointer<ValueT>& reset(ValueT* target) noexcept;
    DDUPointer<ValueT>& reset(DDUPointer<ValueT>&& origin) noexcept;
    
    public:
    DDUPointer<ValueT>& operator =(const DDUPointer<ValueT>& origin) = delete;
    DDUPointer<ValueT>& operator =(DDUPointer<ValueT>&& origin) noexcept;
    DDUPointer<ValueT>& operator =(ValueT* const target) noexcept;
    
};


template <> template <typename ValueT>
class DDUPointer<ValueT[]> final : DDImplement::DDPointer<ValueT> {
    public:
    using ValueType = ValueT;
    
    public:
    DDUPointer<ValueT[]>() noexcept = default;
    DDUPointer<ValueT[]>(const DDUPointer<ValueT[]>& origin) = delete;
    DDUPointer<ValueT[]>(DDUPointer<ValueT[]>&& origin) noexcept;
    DDUPointer<ValueT[]>(ValueT* const target) noexcept;
    ~DDUPointer<ValueT[]>() noexcept;
    DDUPointer<ValueT[]>& swap(DDUPointer<ValueT[]>& target) noexcept;
    DDUPointer<ValueT[]>& reset() noexcept;
    DDUPointer<ValueT[]>& reset(ValueT* target) noexcept;
    DDUPointer<ValueT[]>& reset(DDUPointer<ValueT[]>&& origin) noexcept;
    
    public:
    DDUPointer<ValueT[]>& operator =(const DDUPointer<ValueT[]>& origin) = delete;
    DDUPointer<ValueT[]>& operator =(DDUPointer<ValueT[]>&& origin) noexcept;
    DDUPointer<ValueT[]>& operator =(ValueT* const target) noexcept;
    ValueT& operator [](SubscriptType index) const noexcept;
    
};


template <typename ValueT>
class DDSPointer : public DDImplement::DDPointer<ValueT> {
    public:
    using ValueType = ValueT;
    
    public:
    DDSPointer<ValueT>() noexcept = default;
    DDSPointer<ValueT>(const DDSPointer<ValueT>& origin) noexcept;
    template <typename ValueT_>
    DDSPointer<ValueT>(const DDSPointer<ValueT_>& origin) noexcept;
    DDSPointer<ValueT>(DDSPointer<ValueT>&& origin) noexcept;
    DDSPointer<ValueT>(ValueT* target);
    ~DDSPointer<ValueT>() noexcept;
    ValidityType is_unique() const noexcept;
    const QuantityType& count_user() const noexcept;
    DDSPointer<ValueT>& swap(DDSPointer<ValueT>& target) noexcept;
    DDSPointer<ValueT>& reset() noexcept;
    DDSPointer<ValueT>& reset(ValueT* const target);
    template <typename ValueT_>
    DDSPointer<ValueT>& reset(const DDSPointer<ValueT_>& origin) noexcept;
    DDSPointer<ValueT>& reset(DDSPointer<ValueT>&& origin) noexcept;
    
    public:
    DDSPointer<ValueT>& operator =(const DDSPointer<ValueT>& origin) noexcept;
    DDSPointer<ValueT>& operator =(DDSPointer<ValueT>&& origin) noexcept;
    template <typename ValueT_>
    DDSPointer<ValueT>& operator =(const DDSPointer<ValueT_>& origin) noexcept;
    DDSPointer<ValueT>& operator =(ValueT* const target) noexcept;
    
    private:
    DDImplement::SPointerCounter* m_user_count = nullptr;
    
};


DD_END



DD_BEGIN
template <typename CursorT>
inline ProcessType default_delete(CursorT target) {
    delete &*target;
    return;
}

template <typename CursorT>
inline ProcessType array_default_delete(CursorT target) {
    delete[] &*target;
    return;
}

template <typename ValueT, typename... ArgumentsT>
inline DDSPointer<ValueT> make_spointer(ArgumentsT&&... construct_arguments) {
    return DDSPointer<ValueT>(new ValueT(construct_arguments...));
}


template <typename ValueT, typename... ArgumentsT>
inline DDUPointer<ValueT> make_upointer(ArgumentsT&&... construct_arguments) {
    return DDUPointer<ValueT>(new ValueT(construct_arguments...));
}


template <typename ValueT>
inline ProcessType swap(DDSPointer<ValueT>& spointer_1, DDSPointer<ValueT>& spointer_2) {
    spointer_1.swap(spointer_2);
    return;
}

template <typename ValueT>
inline ProcessType swap(DDUPointer<ValueT>& upointer_1, DDUPointer<ValueT>& upointer_2) {
    upointer_1.swap(upointer_2);
    return;
}


template <typename ValueT>
inline std::ostream &operator <<(std::ostream &os, const DDImplement::DDPointer<ValueT>& pointer) noexcept {
    return os << pointer.get_address();
}


DDIMPLEMENT_BEGIN
template <typename ValueT>
inline DDPointer<ValueT>::DDPointer(ValueT* target, DeleterType& deleter) noexcept : m_pointer(target), m_deleter(&deleter) {
}


template <typename ValueT>
inline ValueT* DDPointer<ValueT>::get_address() const noexcept {
    return this->m_pointer;
}


template <typename ValueT>
inline ValueT& DDPointer<ValueT>::operator *() const noexcept {
    return *this->m_pointer;
}


template <typename ValueT>
inline ValueT* DDPointer<ValueT>::operator ->() const noexcept {
    return this->m_pointer;
}


template <typename ValueT>
inline DDPointer<ValueT>::operator ValidityType() const noexcept {
    return this->m_pointer;
}


DDIMPLEMENT_END


DDUPOINTER_MEMBER(inline)::DDUPointer(DDUPointer<ValueT>&& origin) noexcept : DDImplement::DDPointer<ValueT>(origin.m_pointer) {
    origin.m_pointer = nullptr;
}

DDUPOINTER_MEMBER(inline)::DDUPointer(ValueT* const target) noexcept : DDImplement::DDPointer<ValueT>(target) {
}


DDUPOINTER_MEMBER(inline)::~DDUPointer() noexcept {
    delete this->m_pointer;
}


DDUPOINTER_MEMBER(inline DDUPointer<ValueT>&)::swap(DDUPointer<ValueT>& origin) noexcept {
    DD::swap(this->m_pointer, origin.m_pointer);
    return *this;
}


DDUPOINTER_MEMBER(inline DDUPointer<ValueT>&)::reset() noexcept {
    delete this->m_pointer;
    this->m_pointer = nullptr;
    return *this;
}

DDUPOINTER_MEMBER(inline DDUPointer<ValueT>&)::reset(DDUPointer<ValueT>&& origin) noexcept {
    return this->swap(origin);
}

DDUPOINTER_MEMBER(inline DDUPointer<ValueT>&)::reset(ValueT* const target) noexcept {
    delete this->m_pointer;
    this->m_pointer = target;
    return *this;
}

DDUPOINTER_MEMBER(inline DDUPointer<ValueT>&)::operator =(DDUPointer<ValueT>&& origin) noexcept {
    return this->swap(origin);
}

DDUPOINTER_MEMBER(inline DDUPointer<ValueT>&)::operator =(ValueT* const target) noexcept {
    return this->reset(target);
}


DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline)::DDUPointer(DDUPointer<ValueT[]>&& origin) noexcept : DDImplement::DDPointer<ValueT>(origin.m_pointer) {
    origin.m_pointer = nullptr;
}

DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline)::DDUPointer(ValueT* const target) noexcept : DDImplement::DDPointer<ValueT>(target) {
}


DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline)::~DDUPointer() noexcept {
    delete[] this->m_pointer;
}


DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline DDUPointer<ValueT[]>&)::swap(DDUPointer<ValueT[]>& origin) noexcept {
    DD::swap(this->m_pointer, origin.m_pointer);
    return *this;
}


DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline DDUPointer<ValueT[]>&)::reset() noexcept {
    delete[] this->m_pointer;
    this->m_pointer = nullptr;
    return *this;
}

DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline DDUPointer<ValueT[]>&)::reset(DDUPointer<ValueT[]>&& origin) noexcept {
    return this->swap(origin);
}

DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline DDUPointer<ValueT[]>&)::reset(ValueT* const target) noexcept {
    delete[] this->m_pointer;
    this->m_pointer = target;
    return *this;
}

DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline DDUPointer<ValueT[]>&)::operator =(DDUPointer<ValueT[]>&& origin) noexcept {
    return this->swap(origin);
}

DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline DDUPointer<ValueT[]>&)::operator =(ValueT* const target) noexcept {
    return this->reset(target);
}


DDUPOINTER_SPECIALIZED_MEMBER(ValueT[], template <typename ValueT> inline ValueT&)::operator [](SubscriptType index) const noexcept {
    return this->m_pointer[index];
}


DDSPOINTER_MEMBER(inline)::DDSPointer(const DDSPointer<ValueT>& origin) noexcept : DDImplement::DDPointer<ValueT>(origin.m_pointer), m_user_count(origin.m_user_count) {
    if (this->m_user_count) {
        ++this->m_user_count->scount;
    }
}

DDSPOINTER_MEMBER(template <typename ValueT_> inline)::DDSPointer(const DDSPointer<ValueT_>& origin) noexcept : DDImplement::DDPointer<ValueT>(origin.get_address), m_user_count((QuantityType*)(&origin.count_user())) {
    if (this->m_user_count) {
        ++this->m_user_count->scount;
    }
}

DDSPOINTER_MEMBER(inline)::DDSPointer(DDSPointer<ValueT>&& origin) noexcept : DDImplement::DDPointer<ValueT>(origin.m_pointer), m_user_count(origin.m_user_count) {
    origin.m_pointer = nullptr;
    origin.m_user_count = nullptr;
}

DDSPOINTER_MEMBER(inline)::DDSPointer(ValueT* const target) try : DDImplement::DDPointer<ValueT>(target), m_user_count(this->m_pointer ? new DDImplement::SPointerCounter{1, 0} : nullptr) {
} catch (std::bad_alloc error) {
    delete this->m_pointer;
    throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate counter for DDSPointer. ");
}


DDSPOINTER_MEMBER(inline)::~DDSPointer() noexcept {
    this->reset();
}


DDSPOINTER_MEMBER(inline ValidityType)::is_unique() const noexcept {
    return *this->m_user_count == 1;
}


DDSPOINTER_MEMBER(inline const QuantityType&)::count_user() const noexcept {
    return this->m_user_count->scount;
}


DDSPOINTER_MEMBER(inline DDSPointer<ValueT>&)::swap(DDSPointer<ValueT>& target) noexcept {
    DD::swap(this->m_pointer, target.m_pointer);
    DD::swap(this->m_user_count, target.m_user_count);
    return *this;
}


DDSPOINTER_MEMBER(DDSPointer<ValueT>&)::reset() noexcept {
    if (this->m_user_count) {
        if (this->m_user_count->scount > 1) {
            --this->m_user_count->scount;
        } else {
            delete this->m_pointer;
            this->m_pointer = nullptr;
            if (this->m_user_count->wcount <= 0) {
                delete this->m_user_count;
                this->m_user_count = nullptr;
            }
        }
    }
    return *this;
}

DDSPOINTER_MEMBER(inline DDSPointer<ValueT>&)::reset(ValueT* const target) {
    this->reset();
    if (target) {
        this->m_pointer = target;
        try {
            this->m_user_count = new DDImplement::SPointerCounter{1, 0};
        } catch (std::bad_alloc error) {
            delete this->m_pointer;
            throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate counter for DDSPointer. ");
        }
    }
    return *this;
}

DDSPOINTER_MEMBER(template <typename ValueT_> inline DDSPointer<ValueT>&)::reset(const DDSPointer<ValueT_>& origin) noexcept {
    auto tmp = origin;
    return this->swap(tmp);
}

DDSPOINTER_MEMBER(DDSPointer<ValueT>&)::reset(DDSPointer<ValueT>&& origin) noexcept {
    return this->swap(origin);
}


DDSPOINTER_MEMBER(inline DDSPointer<ValueT>&)::operator =(const DDSPointer<ValueT>& origin) noexcept {
    return this->reset(origin);
}

DDSPOINTER_MEMBER(template <typename ValueT_> inline DDSPointer<ValueT>&)::operator =(const DDSPointer<ValueT_>& origin) noexcept {
    return this->reset(origin);
}

DDSPOINTER_MEMBER(inline DDSPointer<ValueT>&)::operator =(DDSPointer<ValueT>&& origin) noexcept {
    return this->swap(origin);
}

DDSPOINTER_MEMBER(inline DDSPointer<ValueT>&)::operator =(ValueT* const target) noexcept {
    return this->reset(target);
}


DD_END



 #undef DDUPOINTER_MEMBER
 #undef DDUPOINTER_SPECIALIZED_MEMBER
 #undef DDSPOINTER_MEMBER
 #undef DDWPOINTER_MEMBER



#endif