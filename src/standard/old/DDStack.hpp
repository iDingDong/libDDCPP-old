#ifndef _DDESTACK_
 #define _DDESTACK_



 #define DDSTACK_MEMBER(...) template <typename ValueT, typename ContainerT> __VA_ARGS__ DDStack<ValueT, ContainerT>
 #define DDESTACK_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDEStack<ValueT>



 #include "DDGlobal.hpp"
 #include "DDInventory.hpp"



DD_BEGIN
template <typename ValueT, typename ContainerT = DDInventory<ValueT>>
class DDStack;

template <typename ValueT>
class DDEStack;


template <typename ValueT, typename ContainerT>
class DDStack {
    public:
    using ValueType = ValueT;
    
    public:
    DDStack();
    ~DDStack();
    const LengthType &get_length() const;
    ValidityType is_empty() const;
    ValueT& get_top();
    const ValueT& get_top() const;
    DDStack<ValueT, ContainerT>& push(const ValueT& follower);
    DDStack<ValueT, ContainerT>& pop();
    
    protected:
    ContainerT m_content;
    
};


template <typename ValueT>
class DDEStack {
    public:
    using ValueType = ValueT;
    
    protected:
    struct DDEStackItem;
    
    public:
    DDEStack();
    ~DDEStack();
    LengthType get_length() const;
    ValidityType is_empty() const;
    const ValueT& at(SubscriptType index) const;// To realize...
    ValueT& get_top();
    const ValueT& get_top() const;
    ValueT take();
    DDEStack<ValueT>& take_to(ValueT& target);
    template <typename ContainerT>
    DDEStack<ValueT>& take_to(ContainerT& target);
    DDEStack<ValueT>& push(const ValueT& element);
    DDEStack<ValueT>& pop();
    DDEStack<ValueT>& append(const ValueT& element);
    DDEStack<ValueT>& clear();
    DDEStack<ValueT>& operator <<(const ValueT element);
    template <typename ContainerT>
    DDEStack<ValueT>& operator >>(ContainerT& target);
    
    protected:
    DDEStackItem *last_item = nullptr;
    
};


template <typename ValueT>
struct DDEStack<ValueT>::DDEStackItem {
    public:
    ValueT m_content;
    DDEStackItem *previous;
    
};


DD_END



DD_BEGIN
DDSTACK_MEMBER(inline)::DDStack() : m_content() {
}


DDSTACK_MEMBER(inline)::~DDStack() {
}


DDSTACK_MEMBER(inline const LengthType&)::get_length() const {
    return m_content.get_length();
}


DDSTACK_MEMBER(inline ValidityType)::is_empty() const {
    return m_content.is_empty();
}


DDSTACK_MEMBER(inline ValueT&)::get_top() {
    return m_content.get_top();
}

DDSTACK_MEMBER(inline const ValueT&)::get_top() const {
    return m_content.get_top();
}


DDSTACK_MEMBER(DDStack<ValueT, ContainerT>&)::push(const ValueT& follower) {
    m_content.push_end(follower);
    return *this;
}


DDSTACK_MEMBER(DDStack<ValueT, ContainerT>&)::pop() {
    m_content.pop_end();
    return *this;
}


DDESTACK_MEMBER(inline)::DDEStack() : last_item(nullptr) {
}


DDESTACK_MEMBER(inline)::~DDEStack() {
    clear();
}


DDESTACK_MEMBER(LengthType)::get_length() const {
    CounterType count = 0;
    for (DDEStackItem *current = last_item; current; current = current->previous)
        ++count;
    return count;
}


DDESTACK_MEMBER(inline ValidityType)::is_empty() const {
    return last_item;
}


DDESTACK_MEMBER(const ValueT&)::at(SubscriptType index) const {
    return ValueT();
}


DDESTACK_MEMBER(inline ValueT&)::get_top() {
    return last_item->m_content;
}


DDESTACK_MEMBER(inline const ValueT&)::get_top() const {
    return last_item->m_content;
}


DDESTACK_MEMBER(inline ValueT)::take() {
    if (!last_item)
        throw DDError(DDErrorType::ACCESS_DENIED, "Not enough element to take. ");
    ValueT tmp_element = get_top();
    pop();
    return tmp_element;
}


DDESTACK_MEMBER(inline DDEStack<ValueT>&)::take_to(ValueT& target) {
    if (!last_item)
        throw DDError(DDErrorType::ACCESS_DENIED, "Not enough element to take. ");
    target = get_top();
    return pop();
}


DDESTACK_MEMBER(template <typename ContainerT> inline DDEStack<ValueT>&)::take_to(ContainerT& target) {
    if (!last_item)
        throw DDError(DDErrorType::ACCESS_DENIED, "Not enough element to take. ");
    target.append(get_top());
    return pop();
}


DDESTACK_MEMBER(inline DDEStack<ValueT>&)::push(const ValueT& element) {
    DDEStackItem *new_item = new DDEStackItem{element, last_item};
    if (!new_item) {
        throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate element. ");
    }
    last_item = new_item;
    return *this;
}


DDESTACK_MEMBER(inline DDEStack<ValueT>&)::pop() {
    if (last_item) {
        DDEStackItem *previous_item = last_item->previous;
        delete last_item;
        last_item = previous_item;
    }
    return *this;
}


DDESTACK_MEMBER(inline DDEStack<ValueT>&)::append(const ValueT& element) {
    return push(element);
}


DDESTACK_MEMBER(inline DDEStack<ValueT>&)::clear() {
    for (DDEStackItem *current; last_item;) {
        current = last_item;
        last_item = last_item->previous;
        delete current;
    }
    return *this;
}


DDESTACK_MEMBER(template <typename ContainerT> inline DDEStack<ValueT>&)::operator >>(ContainerT& target) {
    return take_to(target);
}


DD_END



 #undef DDSTACK_MEMBER
 #undef DDESTACK_MEMBER



#endif
