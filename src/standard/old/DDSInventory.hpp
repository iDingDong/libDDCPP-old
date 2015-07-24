#ifndef _DDSINVENTORY_
 #define _DDSINVENTORY_


 #include "DDGlobal.hpp"



DD_BEGIN
template <typename T>
class DDSInventory;


template <typename T>
class DDSInventory {
    public:
    DDSInventory(); 
    DDSInventory(int new_length);
    DDSInventory(int new_length, const T& initial_value);
    ~DDSInventory(); 
    int get_capacity() const;
    int get_length() const;
    bool is_full() const;
    bool is_empty() const;
    T& at(int index);
    DDSInventory<T>& expand(int extra_capacity);
    DDSInventory<T>& set_capacity(int new_capacity);
    DDSInventory<T>& lengthen(int extra_length);
    DDSInventory<T>& lengthen(int extra_length, const T& initial_value);
    DDSInventory<T>& set_length(int new_length);
    DDSInventory<T>& set_length(int new_length, const T& initial_value);
    DDSInventory<T>& append(const T& element);
    T& operator [](int index);
    const T& operator [](int index) const;//Unlike DDInventory, operator of DDSInventory does not check index. use member at for index check.
    
    protected:
    int& check_index(int& index) const;
    DDSInventory<T>& destruct();
    int capacity = 0;
    int m_length = 0;
    T** m_content = nullptr;
    
};


DD_END



DD_BEGIN 
 #define DDSINVENTORY_MEMBER(...) template <typename T> __VA_ARGS__ DDSInventory<T>
DDSINVENTORY_MEMBER()::DDSInventory() : capacity(0), m_length(0), m_content(nullptr) {
}


DDSINVENTORY_MEMBER()::DDSInventory(int new_length) : capacity(2 * new_length), m_length(new_length), m_content(nullptr) {
    if (m_length < 0)
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid initial m_length of sinventory. ");
    DDALLOCATE(m_content = new T*[capacity], "Failed to allocate sinventory. ", capacity = 0; m_length = 0;)
    for (int i = 0; i < m_length; ++i)
        DDALLOCATE(m_content[i] = new T, "Failed to allocate element. ", lengthen(i - m_length););
}


DDSINVENTORY_MEMBER()::DDSInventory(int new_length, const T& initial_value) : capacity(2 * new_length), m_length(new_length), m_content(nullptr) {
    if (m_length < 0)
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid initial m_length of sinventory. ");
    DDALLOCATE(m_content = new T*[capacity], "Failed to allocate sinventory. ", capacity = 0; m_length = 0;)
    for (int i = 0; i < m_length; ++i)
        DDALLOCATE(m_content[i] = new T(initial_value), "Failed to allocate element. ", lengthen(i - m_length);)
}


DDSINVENTORY_MEMBER()::~DDSInventory() {
    destruct();
}


DDSINVENTORY_MEMBER(inline int)::get_capacity() const {
    return capacity;
}


DDSINVENTORY_MEMBER(inline int)::get_length() const {
    return m_length;
}


DDSINVENTORY_MEMBER(inline bool)::is_full() const {
    return capacity <= m_length;
}


DDSINVENTORY_MEMBER(inline bool)::is_empty() const {
    return m_length == 0;
}


DDSINVENTORY_MEMBER(T&)::at(int index) {
    return *m_content[check_index(index)];
}


DDSINVENTORY_MEMBER(DDSInventory<T>&)::expand(int extra_capacity) {
    capacity += extra_capacity;
    if (capacity < 0)
       throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid new capacity of sinventory. ");
    if (extra_capacity) {
        T** tmp_content;
        DDALLOCATE(tmp_content = new T*[capacity], "Failed to allocate new sinventory. ", capacity -= extra_capacity;)
        for (int i = 0; i < m_length && i < capacity; ++i)
            tmp_content[i] = m_content[i];
        while (m_length > capacity)
            delete m_content[--m_length];
        delete[] m_content;
        m_content = tmp_content;
    }
    return *this; 
}


DDSINVENTORY_MEMBER(inline DDSInventory<T>&)::set_capacity(int new_capacity) {
    return expand(new_capacity - capacity);
}


DDSINVENTORY_MEMBER(DDSInventory<T>&)::lengthen(int extra_length) {
    m_length += extra_length;// Maybe not very safe. I'll keep my eye on it. 
    if (m_length < 0)
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid new m_length of sinventory. ");
    if (extra_length) {
        if (m_length > capacity) {
            DDERROR_MONITOR
            set_capacity(2 * m_length);
            DDERROR_SOLVE
            m_length -= extra_length;
            DDERROR_SUBMIT
        }
        for (int i = extra_length + 1; i <= 0; ++i) {
            delete m_content [m_length - i];
        }
        for (int i = 1; i <= extra_length; ++i)
            DDALLOCATE(m_content[m_length - i] = new T, "Failed to allocate element. ", destruct(););
    }
    return *this;
}

DDSINVENTORY_MEMBER(DDSInventory<T>&)::lengthen(int extra_length, const T& initial_value) {
    m_length += extra_length;// Maybe not very safe. I'll keep my eye on it. 
    if (m_length < 0)
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid new m_length of sinventory. ");
    if (extra_length) {
        if (m_length > capacity) {
            DDERROR_MONITOR
            set_capacity(2 * m_length);
            DDERROR_SOLVE
            m_length -= extra_length;
            DDERROR_SUBMIT
        }
        for (int i = extra_length + 1; i <= 0; ++i) {
            delete m_content [m_length - i];
        }
        for (int i = 1; i <= extra_length; ++i)
            DDALLOCATE(m_content[m_length - i] = new T(initial_value), "Failed to allocate element. ", destruct(););
    }
    return *this;
}


DDSINVENTORY_MEMBER(inline DDSInventory<T>&)::set_length(int new_length) {
     return lengthen(new_length - m_length);
}

DDSINVENTORY_MEMBER(inline DDSInventory<T>&)::set_length(int new_length, const T& initial_value) {
     return lengthen(new_length - m_length, initial_value);
}


DDSINVENTORY_MEMBER(inline DDSInventory<T>&)::append(const T& element) {
    return lengthen(1, element);
}


DDSINVENTORY_MEMBER(inline T&)::operator [](int index) {
    return *m_content[index];
}


DDSINVENTORY_MEMBER(inline const T&)::operator [](int index) const {
    return *m_content[index];
}


DDSINVENTORY_MEMBER(inline int&)::check_index(int& index) const {
    if (index < 0 || index >= m_length)
        throw DDError(DDErrorType::ACCESS_DENIED, "Invalid index of DDSInventory called. ");
    return index;
}


DDSINVENTORY_MEMBER(DDSInventory<T>&)::destruct() {
    while (m_length)
        delete m_content[--m_length];
    delete[] m_content;
    m_content = nullptr;
    return *this;
}


#undef DDSINVENTORY_MEMBER


DD_END



#endif
