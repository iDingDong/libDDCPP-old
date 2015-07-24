// DDString.hpp
#ifndef _DDSTRING_
 #define _DDSTRING_



 #include "DDContainer.hpp"



DD_BEGIN
class DDString;


class DDString final {
    public:
    using ValueType = CharType;
    using Cursor = typename DDImplement::TightContainerCursor<ValueType>;
    
    public:
    DDString();
    DDString(ValueType const* origin);
    ~DDString() noexcept;
    LengthType get_length() const noexcept;// Time: O(n)
    LengthType get_capacity() const noexcept;
    Cursor get(SubscriptType index = 0) noexcept;
    Cursor begin() noexcept;
    Cursor end() noexcept;// Time: O(n)
    ValueType* cstring() const noexcept;// Do not delete pointer assigned by this.
    
    private:
    ValueType* get_end() const noexcept;// Time: O(n)
    
    private:
    LengthType capacity = 0;
    ValueType* m_content = nullptr;
    
};


template <typename CharT>
CharT* cstring_search_first(CharT* cstring, typename DDRemoveCV<CharT>::Type target) {
    static_assert(is_same_type<CharType, typename DDRemoveCV<CharT>::Type>(), "This template only works on chars");
    for (; *cstring; ++cstring) {
        if (*cstring == target) {
            return cstring;
        }
    }
    return nullptr;
}


std::ostream& operator <<(std::ostream& os, const DDString& string);


DD_END



DD_BEGIN
inline DDString::DDString() try : capacity(2), m_content(new char[capacity]{}) {
} catch (...) {
    throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate DDString. ");
}


inline DDString::DDString(ValueType const* origin) : capacity(0), m_content(nullptr) {
    auto current = origin;
    while (*current++) {
    }
    capacity = (current - origin) * 2;
    DDALLOCATE(m_content = new char[capacity]{}, "Failed to allocate DDString. ", capacity = 0; )
    while (--current >= origin) {
        m_content[current - origin] = *current;
    }
}


inline DDString::~DDString() noexcept {
    delete[] m_content;
}


inline LengthType DDString::get_length() const noexcept {
    return get_end() - m_content;
}


inline LengthType DDString::get_capacity() const noexcept {
    return capacity;
}


inline typename DDString::Cursor DDString::get(SubscriptType index) noexcept {
    return Cursor(m_content + index);
}


inline typename DDString::Cursor DDString::begin() noexcept {
    return Cursor(m_content);
}


inline typename DDString::Cursor DDString::end() noexcept {
    return Cursor(get_end() + 1);
}


inline typename DDString::ValueType* DDString::cstring() const noexcept {
    return m_content;
}


inline typename DDString::ValueType* DDString::get_end() const noexcept {
    auto current = m_content;
    while (*current) {
        ++current;
    }
    return current;
}


inline std::ostream& operator <<(std::ostream& os, const DDString& string) {
    return os << string.cstring();
}


DD_END



#endif
