// DDArray.cpp
#ifndef _DDARRAY_
 #define _DDARRAY_



 #define DDARRAYBASE_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDArrayBase<ValueT>
 #define DDARRAY_MEMBER(...) template <typename ValueT, LengthType LengthT> __VA_ARGS__ DDArray<ValueT, LengthT>



 #include "DDContainer.hpp"



DD_BEGIN
DDIMPLEMENT_BEGIN
template <typename ValueT>
class DDArrayBase;


DDIMPLEMENT_END


template <typename ValueT, LengthType LengthT>
class DDArray;


DDIMPLEMENT_BEGIN
template <typename ValueT>
class DDArrayBase {
    public:
    struct IsContainer;
    
    
    public:
    using ValueType = ValueT;
    using Cursor = typename DDImplement::TightContainerCursor<ValueT>;
    using SCursor = typename DDImplement::ContainerSCursor<DDArrayBase<ValueT>>;
    
    public:
    friend Cursor;
    
    protected:
    DDArrayBase() noexcept;
    DDArrayBase(const DDArrayBase<ValueT>&) = delete;
    DDArrayBase(DDArrayBase<ValueT>&&) = delete;
    
    public:
    ~DDArrayBase() noexcept;
    Cursor get(SubscriptType index) noexcept;
    Cursor begin() noexcept;
    Cursor get_cursor(SubscriptType index) noexcept;
    Cursor begin_cursor() noexcept;
    SCursor get_scursor(SubscriptType index) noexcept;
    SCursor begin_scursor() noexcept;
    
    public:
    DDArrayBase<ValueT>& operator =(const DDArrayBase<ValueT>&) = delete;
    DDArrayBase<ValueT>& operator =(DDArrayBase<ValueT>&&) = delete;
    
    protected:
    ValueT* m_content = nullptr;
    
};




DDIMPLEMENT_END


template <typename ValueT, LengthType LengthT>
class DDArray final : public DDImplement::DDArrayBase<ValueT> {
    static_assert(LengthT >= 0, "Length of DDArray should be no less than 0.");
    
    public:
    using ValueType = ValueT;
    using Cursor = typename DDImplement::DDArrayBase<ValueT>::Cursor;
    using SCursor = typename DDImplement::DDArrayBase<ValueT>::SCursor;
    
    public:
    template <typename ValueT_, LengthType LengthT_>
    friend std::ostream &operator <<(std::ostream &os, const DDArray<ValueT_, LengthT_>& array);
    template <typename ValueT_, LengthType LengthT_>
    friend std::wostream &operator <<(std::wostream &wos, const DDArray<ValueT_, LengthT_>& array);
    
    public:
    DDArray();
    DDArray(const DDArray<ValueT, LengthT>& origin);
    DDArray(DDArray<ValueT, LengthT>&& origin);
    DDArray(std::initializer_list<ValueT> initializer);
    template <typename... ArgumentsT>
    DDArray(ArgumentsT&&... construct_arguments);
    ~DDArray() noexcept;
    static constexpr LengthType get_length() noexcept;
    ValueT& at(SubscriptType index);
    const ValueT& at(SubscriptType index) const;
    Cursor end() noexcept;
    Cursor end_cursor() noexcept;
    SCursor end_scursor() noexcept;
    
    public:
    ValueT &operator [](SubscriptType index);
    const ValueT &operator [](SubscriptType index) const;
    
    private:
    SubscriptType& check_index(SubscriptType& index) const;
    static constexpr SizeType get_size() noexcept;
    
    //private:
    //ValueT* m_content = nullptr;
    
};


template <typename ValueT, LengthType LengthT>
std::ostream &operator <<(std::ostream &os, const DDArray<ValueT, LengthT>& array);
template <typename ValueT, LengthType LengthT>
std::wostream &operator <<(std::wostream &wos, const DDArray<ValueT, LengthT>& array);


DD_END



DD_BEGIN
DDIMPLEMENT_BEGIN
DDARRAYBASE_MEMBER(inline)::DDArrayBase() noexcept : m_content(nullptr) {
}


DDARRAYBASE_MEMBER(inline)::~DDArrayBase() noexcept {
}


DDARRAYBASE_MEMBER(inline typename DDArrayBase<ValueT>::Cursor)::get(SubscriptType index) noexcept {
    return get_cursor(index);
}


DDARRAYBASE_MEMBER(inline typename DDArrayBase<ValueT>::Cursor)::begin() noexcept {
    return begin_cursor();
}


DDARRAYBASE_MEMBER(inline typename DDArrayBase<ValueT>::Cursor)::get_cursor(SubscriptType index) noexcept {
    return Cursor(*this, index);
}


DDARRAYBASE_MEMBER(inline typename DDArrayBase<ValueT>::Cursor)::begin_cursor() noexcept {
    return Cursor(m_content);
}


DDARRAYBASE_MEMBER(inline typename DDArrayBase<ValueT>::SCursor)::get_scursor(SubscriptType index) noexcept {
    return SCursor(*this, index);
}


DDARRAYBASE_MEMBER(inline typename DDArrayBase<ValueT>::SCursor)::begin_scursor() noexcept {
    return SCursor(*this, 0);
}


DDIMPLEMENT_END


DDARRAY_MEMBER(inline)::DDArray() : DDImplement::DDArrayBase<ValueT>() {
    DDALLOCATE(this->m_content = (ValueT*)(::operator new(get_size())), "Failed to allocate DDArray. ", )
    for (CounterType i = 0; i < LengthT; ++i) {
        DDALLOCATE(new (this->m_content + i) ValueT, "Failed to allocate element of DDArray. ", )
    }
}

DDARRAY_MEMBER(inline)::DDArray(const DDArray<ValueT, LengthT>& origin) : DDImplement::DDArrayBase<ValueT>() {
    DDALLOCATE(this->m_content = (ValueT*)(::operator new(get_size())), "Failed to allocate DDArray. ", )
    for (CounterType i = 0; i < LengthT; ++i) {
        DDALLOCATE(new (this->m_content + i) ValueT(origin.m_content[i]), "Failed to allocate element of DDArray. ", )
    }
}

DDARRAY_MEMBER(inline)::DDArray(std::initializer_list<ValueT> initializer) : DDImplement::DDArrayBase<ValueT>() {
    DDALLOCATE(this->m_content = (ValueT*)(::operator new(get_size())), "Failed to allocate DDArray. ", )
    for (CounterType i = 0; i < LengthT && initializer.begin() + i != initializer.end(); ++i) {
        DDALLOCATE(new (this->m_content + i) ValueT(initializer.begin()[i]), "Failed to allocate element of DDArray. ", )
    }
}

DDARRAY_MEMBER(template <typename... ArgumentsT> inline)::DDArray(ArgumentsT&&... construct_arguments) : DDImplement::DDArrayBase<ValueT>() {
    DDALLOCATE(this->m_content = (ValueT*)(::operator new(get_size())), "Failed to allocate DDArray. ", )
    for (CounterType i = 0; i < LengthT; ++i) {
        DDALLOCATE(new (this->m_content + i) ValueT(construct_arguments...), "Failed to allocate element of DDArray. ", )
    }
}


DDARRAY_MEMBER(inline)::~DDArray() noexcept {
    for (CounterType i = 0; i < LengthT; ++i) {
        this->m_content[i].~ValueT();
    }
    ::operator delete(this->m_content);
}


DDARRAY_MEMBER(constexpr LengthType)::get_length() noexcept {
    return LengthT;
}


DDARRAY_MEMBER(inline ValueT&)::at(SubscriptType index) {
    return this->m_content[check_index(index)];
}

DDARRAY_MEMBER(inline const ValueT&)::at(SubscriptType index) const {
    return this->m_content[check_index(index)];
}


DDARRAY_MEMBER(inline typename DDImplement::DDArrayBase<ValueT>::Cursor)::end() noexcept {
    return end_cursor();
}


DDARRAY_MEMBER(inline typename DDImplement::DDArrayBase<ValueT>::Cursor)::end_cursor() noexcept {
    return Cursor(this->m_content + LengthT);
}


DDARRAY_MEMBER(inline typename DDImplement::DDArrayBase<ValueT>::SCursor)::end_scursor() noexcept {
    return SCursor(*this, LengthT);
}


DDARRAY_MEMBER(inline ValueT&)::operator [](SubscriptType index) {
    return this->m_content[check_index(index)];
}

DDARRAY_MEMBER(inline const ValueT&)::operator [](SubscriptType index) const {
    return this->m_content[check_index(index)];
}


DDARRAY_MEMBER(inline SubscriptType&)::check_index(SubscriptType& index) const {
    if (index < 0 || index >= LengthT) { 
        throw DDError(DDErrorType::ACCESS_DENIED, "Element called out of range. ");
    }
    return index;
}


DDARRAY_MEMBER(constexpr SizeType)::get_size() noexcept {
    return sizeof(ValueT) * LengthT;
}


template <typename ValueT, LengthType LengthT>
std::ostream &operator <<(std::ostream &os, const DDArray<ValueT, LengthT>& array) {
    os << '{';
    if (LengthT > 0) {
        os << *array.m_content;
        for (auto i = 1; i < LengthT; ++i) {
            os << ", " << array.m_content[i];
        }
    }
    return os << '}';
}

template <typename ValueT, LengthType LengthT>
std::wostream &operator <<(std::wostream &wos, const DDArray<ValueT, LengthT>& array) {
    wos << '{';
    if (array.m_length > 0) {
        wos << *array.m_content;
        for (auto i = 1; i < LengthT; ++i) {
            wos << ", " << array.m_content[i];
        }
    }
    return wos << '}';
}


DD_END



 #undef DDARRAY_MEMBER



#endif
