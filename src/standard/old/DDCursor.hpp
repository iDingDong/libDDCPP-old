// DDCursor.hpp
#ifndef _DDCURSOR_
 #define _DDCURSOR_



 #include "DDTraits.hpp"



 #define DDARRAY_CURSOR_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDArrayCursor<ValueT>
 #define DDTABLE_CURSOR_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDTableCursor<ValueT>



DD_BEGIN
enum class DDCursorCatagory {
    UNKNOWN = 0,
    FIXED = 1,
    UNDIRECTIONAL = 2,
    BIDIRECTIONAL = 3,
    FREE_ACCESS = 4
    
};


template <typename CursorT>
struct DDCursorTraits;
template <typename ValueT>
struct DDCursorTraits<ValueT*>;

template <typename CursorT>
struct DDIsUCursor;

template <typename CursorT>
struct DDIsBCursor;

template <typename CursorT>
struct DDIsFCursor;

template <typename CursorT>
struct DDDereference;

template <typename CursorT>
using DDCursorValueType = DDDereference<CursorT>;

template <typename CursorT>
struct DDCursorDifferenceType;

struct DDUCursorBasic;

struct DDBCursorBasic;

struct DDFCursorBasic;

template <typename ValueT>
struct DDTableCursor;

template <typename ValueT>
struct DDArrayCursor;

DDIMPLEMENT_BEGIN
template <typename NodeT>
struct DDListCursor_;

DDIMPLEMENT_END

template <typename NodeT>
struct DDUListCursor;

template <typename NodeT>
struct DDBListCursor;


template <typename CursorT>
using Dereference = typename DDDereference<CursorT>::Type;

template <typename CursorT>
using CursorValueType = typename DDCursorValueType<CursorT>::Type;
template <typename CursorT>
using CursorDifferenceType = typename DDCursorDifferenceType<CursorT>::Type;

template <typename ValueT, LengthType length_c>
DDArrayCursor<ValueT> begin(ArrayType<ValueT, length_c>& array);
template <typename ContainerT>
typename ContainerT::Cursor begin(ContainerT& container);

template <typename ValueT, LengthType length_c>
DDArrayCursor<ValueT> end(ArrayType<ValueT, length_c>& array);
template <typename ContainerT>
typename ContainerT::Cursor end(ContainerT& container);

DDIMPLEMENT_BEGIN
template <typename UCursorT>
ProcessType advance_(UCursorT& begin, CursorDifferenceType<UCursorT> step, DDFalseType) noexcept(true);
template <typename FCursorT>
ProcessType advance_(FCursorT& begin, CursorDifferenceType<FCursorT> step, DDTrueType) noexcept(true);

DDIMPLEMENT_END

template <typename UCursorT>
ProcessType advance(UCursorT& begin, CursorDifferenceType<UCursorT> step) noexcept;

DDIMPLEMENT_BEGIN
template <typename UCursorT>
CursorDifferenceType<UCursorT> distance_(UCursorT begin, UCursorT end, DDFalseType) noexcept(true);
template <typename FCursorT>
CursorDifferenceType<FCursorT> distance_(FCursorT begin, FCursorT end, DDTrueType) noexcept(true);

DDIMPLEMENT_END

template <typename UCursorT>
CursorDifferenceType<UCursorT> distance(UCursorT begin, UCursorT end) noexcept(true);


template <typename CursorT>
struct DDCursorTraits {
    public:
    using ValueType = RemoveReference<decltype(*CursorT())>;
    using ReferenceType = ValueType&;
    using PointerType = ValueType*;
    using DifferenceType = LengthType;
    static constexpr DDCursorCatagory catagory = CursorT::catagory;
    
};


template <typename ValueT>
struct DDCursorTraits<ValueT*> {
    public:
    using ValueType = ValueT;
    using ReferenceType = ValueT&;
    using PointerType = ValueT*;
    using DifferenceType = RemoveConst<decltype(PointerType() - PointerType())>;
    static constexpr DDCursorCatagory catagory = DDCursorCatagory::FREE_ACCESS;
    
};


template <typename CursorT>
struct DDIsUCursor : public DDBoolConstant<DDCursorTraits<CursorT>::catagory >= DDCursorCatagory::UNDIRECTIONAL> {
};


template <typename CursorT>
struct DDIsBCursor : public DDBoolConstant<DDCursorTraits<CursorT>::catagory >= DDCursorCatagory::BIDIRECTIONAL> {
};


template <typename CursorT>
struct DDIsFCursor : public DDBoolConstant<DDCursorTraits<CursorT>::catagory >= DDCursorCatagory::FREE_ACCESS> {
};


template <typename CursorT>
struct DDDereference {
    public:
    using Type = typename DDCursorTraits<CursorT>::ValueType;
    
};


template <typename CursorT>
struct DDCursorDifferenceType {
    public:
    using Type = typename DDCursorTraits<CursorT>::DifferenceType;
    
};


struct DDUCursorBasic {
    public:
    static constexpr DDCursorCatagory catagory = DDCursorCatagory::UNDIRECTIONAL; 
    
};


struct DDBCursorBasic {
    public:
    static constexpr DDCursorCatagory catagory = DDCursorCatagory::BIDIRECTIONAL;
    
};


struct DDFCursorBasic {
    public:
    static constexpr DDCursorCatagory catagory = DDCursorCatagory::FREE_ACCESS;
    
};


template <typename ValueT>
struct DDArrayCursor : public DDFCursorBasic {
    public:
    using ValueType = ValueT;
    using ReferenceType = ValueT&;
    using PointerType = ValueT*;
    using DifferenceType = LengthType;
    
    public:
    DDArrayCursor() noexcept(true) = default;
    DDArrayCursor(DDArrayCursor<ValueT> const& origin) noexcept(true) = default;
    DDArrayCursor(ValueT* target) noexcept(true);
    
    public:
    ~DDArrayCursor() noexcept(true) = default;
    
    public:
    DDArrayCursor<ValueT>& operator =(DDArrayCursor<ValueT> const& origin) noexcept(true) = default;
    
    public:
    DDArrayCursor<ValueT>& operator ++() noexcept(true);
    DDArrayCursor<ValueT> operator ++(IntSignType) noexcept(true);
    DDArrayCursor<ValueT>& operator --() noexcept(true);
    DDArrayCursor<ValueT> operator --(IntSignType) noexcept(true);
    DDArrayCursor<ValueT>& operator +=(DifferenceType step) noexcept(true);
    DDArrayCursor<ValueT>& operator -=(DifferenceType step) noexcept(true);
    ValueT& operator [](SubscriptType index) const noexcept(true);
    ValueT& operator *() const noexcept(true);
    ValueT* operator ->() const noexcept(true);
    explicit operator ValueT*() const noexcept(true);
    explicit operator ValidityType() const noexcept(true);
    
    private:
    ValueT* m_target = nullptr;
    
};


template <typename ValueT>
struct DDTableCursor : public DDFCursorBasic {
    public:
    using ValueType = ValueT;
    using ReferenceType = ValueT&;
    using PointerType = ValueT*;
    using DifferenceType = LengthType;
    
    public:
    DDTableCursor() noexcept(true) = default;
    DDTableCursor(DDTableCursor<ValueT> const& origin) noexcept(true) = default;
    
    private:
    DDTableCursor(ValueT** target) noexcept(true);
    
    public:
    ~DDTableCursor() noexcept(true) = default;
    
    public:
    DDTableCursor<ValueT>& operator =(DDTableCursor<ValueT> const& origin) noexcept(true) = default;
    
    public:
    DDTableCursor<ValueT>& operator ++() noexcept(true);
    DDTableCursor<ValueT> operator ++(IntSignType) noexcept(true);
    DDTableCursor<ValueT>& operator --() noexcept(true);
    DDTableCursor<ValueT> operator --(IntSignType) noexcept(true);
    DDTableCursor<ValueT>& operator +=(LengthType step) noexcept(true);
    DDTableCursor<ValueT>& operator -=(LengthType step) noexcept(true);
    ValueT& operator [](SubscriptType index) const noexcept(true);
    ValueT& operator *() const noexcept(true);
    ValueT* operator ->() const noexcept(true);
    explicit operator ValueT*() const noexcept(true);
    explicit operator ValidityType() const noexcept;
    
    private:
    ValueT** m_target = nullptr;
    
};


DDIMPLEMENT_BEGIN
template <typename ValueT>
struct DDListCursor_;


DDIMPLEMENT_END


template <typename ValueT>
struct DDUListCursor;


template <typename ValueT>
struct DDBListCursor;


DD_END



DD_BEGIN
DDIMPLEMENT_BEGIN
template <typename UCursorT>
ProcessType advance_(UCursorT& begin, CursorDifferenceType<UCursorT> step, DDFalseType) noexcept(true) {
    constexpr auto end = decltype(step)();
    for (; step < end; ++step) {
        --begin;
    }
    for (; end < step; --step) {
        ++begin;
    }
    return;
}

template <typename FCursorT>
ProcessType advance_(FCursorT& begin, CursorDifferenceType<FCursorT> step, DDTrueType) noexcept(true) {
    begin += step;
    return;
}


DDIMPLEMENT_END


template <typename UCursorT>
ProcessType advance(UCursorT& begin, CursorDifferenceType<UCursorT> step) noexcept(true) {
    DDImplement::advance_(begin, step, DDIsFCursor<UCursorT>());
    return;
}


DDIMPLEMENT_BEGIN
template <typename UCursorT>
CursorDifferenceType<UCursorT> distance_(UCursorT begin, UCursorT end, DDFalseType) noexcept {
    auto distance = CursorDifferenceType<UCursorT>();
    while (begin != end) {
        ++begin;
        ++distance;
    }
    return distance;
}

template <typename FCursorT>
inline CursorDifferenceType<FCursorT> distance_(FCursorT begin, FCursorT end, DDTrueType) noexcept {
    return end - begin;
}


DDIMPLEMENT_END


template <typename UCursorT>
inline CursorDifferenceType<UCursorT> distance(UCursorT begin, UCursorT end) noexcept {
    return DDImplement::distance_(begin, end, DDIsFCursor<UCursorT>());
}


DDARRAY_CURSOR_MEMBER(inline)::DDArrayCursor(ValueT* target) noexcept(true) : m_target(target) {
}


DDARRAY_CURSOR_MEMBER(inline DDArrayCursor<ValueT>&)::operator ++() noexcept(true) {
    ++this->m_target;
    return *this;
}

DDARRAY_CURSOR_MEMBER(inline DDArrayCursor<ValueT>)::operator ++(IntSignType) noexcept(true) {
    return DDArrayCursor<ValueT>(this->m_target++);
}


DDARRAY_CURSOR_MEMBER(inline DDArrayCursor<ValueT>&)::operator --() noexcept(true) {
    --this->m_target;
    return *this;
}

DDARRAY_CURSOR_MEMBER(inline DDArrayCursor<ValueT>)::operator --(IntSignType) noexcept(true) {
    return DDArrayCursor<ValueT>(this->m_target--);
}


DDARRAY_CURSOR_MEMBER(inline DDArrayCursor<ValueT>&)::operator +=(LengthType step) noexcept(true) {
    this->m_target += step;
    return *this;
}


DDARRAY_CURSOR_MEMBER(inline DDArrayCursor<ValueT>&)::operator -=(LengthType step) noexcept(true) {
    this->m_target -= step;
    return *this;
}


DDARRAY_CURSOR_MEMBER(ValueT&)::operator [](SubscriptType index) const noexcept(true) {
    return this->m_target[index];
}


DDARRAY_CURSOR_MEMBER(ValueT&)::operator *() const noexcept(true) {
    return *this->m_target;
}


DDARRAY_CURSOR_MEMBER(ValueT*)::operator ->() const noexcept(true) {
    return this->m_target;
}


DDARRAY_CURSOR_MEMBER()::operator ValueT*() const noexcept(true) {
    return this->m_target;
}


DDARRAY_CURSOR_MEMBER()::operator ValidityType() const noexcept(true) {
    return this->m_target;
}


DDTABLE_CURSOR_MEMBER(inline)::DDTableCursor(ValueT** target) noexcept(true) : m_target(target) {
}


DDTABLE_CURSOR_MEMBER(inline DDTableCursor<ValueT>&)::operator ++() noexcept(true) {
    ++this->m_target;
    return *this;
}

DDTABLE_CURSOR_MEMBER(inline DDTableCursor<ValueT>)::operator ++(IntSignType) noexcept(true) {
    return DDTableCursor<ValueT>(this->m_target++);
}


DDTABLE_CURSOR_MEMBER(inline DDTableCursor<ValueT>&)::operator --() noexcept(true) {
    --this->m_target;
    return *this;
}

DDTABLE_CURSOR_MEMBER(inline DDTableCursor<ValueT>)::operator --(IntSignType) noexcept(true) {
    return DDTableCursor<ValueT>(this->m_target--);
}


DDTABLE_CURSOR_MEMBER(inline DDTableCursor<ValueT>&)::operator +=(LengthType step) noexcept(true) {
    this->m_target += step;
    return *this;
}


DDTABLE_CURSOR_MEMBER(inline DDTableCursor<ValueT>&)::operator -=(LengthType step) noexcept(true) {
    this->m_target -= step;
    return *this;
}


DDTABLE_CURSOR_MEMBER(ValueT&)::operator [](SubscriptType index) const noexcept(true) {
    return *this->m_target[index];
}


DDTABLE_CURSOR_MEMBER(ValueT&)::operator *() const noexcept(true) {
    return **this->m_target;
}


DDTABLE_CURSOR_MEMBER(ValueT*)::operator ->() const noexcept(true) {
    return *this->m_target;
}


DDTABLE_CURSOR_MEMBER()::operator ValueT*() const noexcept(true) {
    return *this->m_target;
}


DDTABLE_CURSOR_MEMBER(inline)::operator ValidityType() const noexcept(true) {
    return *this->m_target;
}


DD_END



 #undef DDARRAY_CURSOR_MEMBER
 #undef DDTABLE_CURSOR_MEMBER



#endif