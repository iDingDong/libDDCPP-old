// DDInventory.hpp
#ifndef _DDINVENTORY_
 #define _DDINVENTORY_



 #include "DDContainer.hpp"



 #define DDINVENTORY_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDInventory<ValueT>
 #define DDINVENTORY_SPECIALIZED(target, ...) template <> __VA_ARGS__ DDInventory<target>
 #define DDINVENTORY_CURSOR_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDInventory<ValueT>::Cursor



DD_BEGIN
template <typename ValueT>
class DDInventory;


template <typename ValueT>
DDErrorType swap(DDInventory<ValueT>& inventory_1, DDInventory<ValueT>& inventory_2) noexcept;


template <typename ValueT>
std::ostream &operator <<(std::ostream &os, const DDInventory<ValueT>& inventory);
template <typename ValueT>
std::ostream &operator <<(std::ostream &os, const typename DDInventory<ValueT>::Cursor& cursor) noexcept;
template <typename ValueT>
std::ostream &operator <<(std::ostream &os, const typename DDInventory<ValueT>::SCursor& scursor) noexcept;
template <typename ValueT>
std::wostream &operator <<(std::wostream &wos, const DDInventory<ValueT>& inventory);

template <typename ValueT>
std::istream &operator >>(std::istream &is, DDInventory<ValueT>& inventory);
template <typename ValueT>
std::wistream &operator >>(std::wistream &wis, DDInventory<ValueT>& inventory);


template <typename ValueT>
class DDInventory final : public DDImplement::IndirectContainerBase<ValueT> {
    public:
    using ValueType = ValueT;
    using Cursor = typename DDImplement::IndirectContainerBase<ValueT>::Cursor;
    using CCursor = typename DDImplement::IndirectContainerBase<ValueT>::CCursor;
    using SCursor = typename DDImplement::IndirectContainerBase<ValueT>::SCursor;
    using SCCursor = typename DDImplement::IndirectContainerBase<ValueT>::SCCursor;
    
    //temp
    using DDImplement::IndirectContainerBase<ValueT>::at;
    using DDImplement::IndirectContainerBase<ValueT>::get_top;
    using DDImplement::IndirectContainerBase<ValueT>::get_bottom;
    
    public:
    friend Cursor;
    friend CCursor;
    template <typename ValueT_>
    friend std::ostream &operator <<(std::ostream &os, const DDInventory<ValueT_>& inventory);
    template <typename ValueT_>
    friend std::wostream &operator <<(std::wostream &wos, const DDInventory<ValueT_>& inventory);
    
    public:
    DDInventory() noexcept;
    DDInventory(const DDInventory<ValueT>& origin);
    DDInventory(DDInventory &&origin) noexcept;
    DDInventory(std::initializer_list<ValueT> initializer);
    template <typename ContainerT>
    DDInventory(const ContainerT& origin);
    template <typename ContainerT>
    DDInventory(SubscriptType begin_index, SubscriptType end_index, const ContainerT& origin);
    template <typename... ArgumentsT>
    DDInventory(LengthType new_length, ArgumentsT&&... construct_arguments);
    ~DDInventory() noexcept;
    template <typename... ArgumentsT>
    DDInventory<ValueT>& lengthen(LengthType extra_length, ArgumentsT&&... construct_arguments);
    template <typename... ArgumentsT>
    DDInventory<ValueT>& set_length(LengthType new_length, ArgumentsT&&... construct_arguments);
    template <typename ContainerT>
    DDInventory<ValueT>& clone(const ContainerT& origin);
    DDInventory<ValueT>& clone(DDInventory<ValueT>&& origin) noexcept;
    template <typename ContainerT>
    DDInventory<ValueT>& clone(SubscriptType target_begin_index, SubscriptType target_end_index, const ContainerT& origin);
    DDInventory<ValueT>& clone(SubscriptType target_begin_index, SubscriptType target_end_index, DDInventory<ValueT>&& origin);
    DDInventory<ValueT>& swap(DDInventory &target) noexcept;
    DDInventory<ValueT>& append(DDInventory<ValueT>&& target);
    template <typename ObjectT>
    DDInventory<ValueT>& append(ObjectT const& object);
    template <typename ObjectT>
    DDInventory<ValueT>& push_begin(ObjectT const& leader);
    DDInventory<ValueT>& push_end(const ValueT& follower);
    DDInventory<ValueT>& push_end(DDInventory<ValueT>&& follower);
    template <typename ContainerT>
    DDInventory<ValueT>& push_end(const ContainerT& follower);
    DDInventory<ValueT>& insert(SubscriptType index, const ValueT& jumper);
    DDInventory<ValueT>& insert(SubscriptType index, DDInventory<ValueT>&& jumper);
    template <typename ContainerT>
    DDInventory<ValueT>& insert(SubscriptType index, const ContainerT& jumper);
    DDInventory<ValueT>& enter(const ValueT& element);// Not suitable if not ordered.
    DDInventory<ValueT>& enter(CheckType ascend, const ValueT& element);// Not suitable if not ordered.
    template <typename FunctionT>
    DDInventory<ValueT>& enter(FunctionT& comparer, const ValueT& element);// Not suitable if not ordered.
    template <typename FunctionT>
    DDInventory<ValueT>& enter(FunctionT& comparer, CheckType ascend, const ValueT& element);// Not suitable if not ordered.
    ValueT take();
    DDInventory<ValueT>& take_to(ValueT& target);
    DDInventory<ValueT>& take_to(DDInventory<ValueT>& target);
    template <typename ContainerT>
    DDInventory<ValueT>& take_to(ContainerT& target);
    ValueT fetch(SubscriptType index);
    DDInventory<ValueT>& fetch_to(ValueT& target, SubscriptType index);
    DDInventory<ValueT>& fetch_to(DDInventory<ValueT>& target, SubscriptType index);
    template <typename ContainerT>
    DDInventory<ValueT>& fetch_to(ContainerT& target, SubscriptType index);
    ValueT draw();
    ValueT draw(SubscriptType begin_index, SubscriptType end_index);
    DDInventory<ValueT>& draw_to(ValueT& target);
    DDInventory<ValueT>& draw_to(SubscriptType begin_index, SubscriptType end_index, ValueT& target);
    template <typename ContainerT>
    DDInventory<ValueT>& draw_to(ContainerT& target);
    template <typename ContainerT>
    DDInventory<ValueT>& draw_to(SubscriptType begin_index, SubscriptType end_index, ContainerT& target);
    DDInventory<ValueT>& pop_begin();
    DDInventory<ValueT>& pop_begin(LengthType to_pop);
    DDInventory<ValueT>& pop_end();
    DDInventory<ValueT>& pop_end(LengthType to_pop);
    DDInventory<ValueT>& remove();
    DDInventory<ValueT>& remove(SubscriptType index);
    DDInventory<ValueT>& remove(SubscriptType begin_index, SubscriptType end_index);
    DDInventory<ValueT>& clear() noexcept;
    DDInventory<ValueT>& copy(DDInventory<ValueT>&& origin);
    DDInventory<ValueT>& copy(SubscriptType begin_index, SubscriptType end_index, DDInventory<ValueT>&& origin);
    template <typename ContainerT>
    DDInventory<ValueT>& copy(const ContainerT& origin);
    template <typename ContainerT>
    DDInventory<ValueT>& copy(SubscriptType begin_index, SubscriptType end_index, const ContainerT& origin);
    DDInventory<ValueT>& swap_index(SubscriptType index_1, SubscriptType index_2);
    DDInventory<ValueT>& move(SubscriptType index, SubscriptType target_index);
    DDInventory<ValueT>& rotate(LengthType steps);
    DDInventory<ValueT>& rotate(SubscriptType begin_index, SubscriptType end_index, LengthType steps);
    DDInventory<ValueT>& reverse();
    DDInventory<ValueT>& reverse(SubscriptType begin_index, SubscriptType end_index);
    DDInventory<ValueT>& shuffle();
    DDInventory<ValueT>& shuffle(SubscriptType begin_index, SubscriptType end_index);
    DDInventory<ValueT>& sort(CheckType ascend = true);
    DDInventory<ValueT>& sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& sort(FunctionT& comparer, CheckType ascend = true);// Time O(nlog(n))
    template <typename FunctionT>
    DDInventory<ValueT>& sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& bubble_sort(CheckType ascend = true);// Strongly not suggested. Time: O(n^2)
    DDInventory<ValueT>& bubble_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);// Strongly not suggested.
    template <typename FunctionT>
    DDInventory<ValueT>& bubble_sort(FunctionT& comparer, CheckType ascend = true);// Strongly not suggested.
    template <typename FunctionT>
    DDInventory<ValueT>& bubble_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);// Strongly not suggested.
    DDInventory<ValueT>& heap_sort(CheckType ascend = true);// Time: O(nlog(n))
    template <typename FunctionT>
    DDInventory<ValueT>& heap_sort(FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& heap_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& heap_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& insert_sort(CheckType ascend = true);// Time: O(n^2)
    template <typename FunctionT>
    DDInventory<ValueT>& insert_sort(FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& insert_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& insert_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& merge_sort(CheckType ascend = true);// Time: O(nlog(n))
    template <typename FunctionT>
    DDInventory<ValueT>& merge_sort(FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& merge_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& merge_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& quick_sort(CheckType ascend = true);// Time: O(nlog(n)) ~ O(n^2)
    template <typename FunctionT>
    DDInventory<ValueT>& quick_sort(FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& quick_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& quick_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& select_sort(CheckType ascend = true);// Time: O(n^2)
    template <typename FunctionT>
    DDInventory<ValueT>& select_sort(FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& select_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& select_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& shell_sort(CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& shell_sort(FunctionT& comparer, CheckType ascend = true);
    DDInventory<ValueT>& shell_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend = true);
    template <typename FunctionT>
    DDInventory<ValueT>& shell_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend = true);
    
    public:
    DDInventory<ValueT>& operator =(const DDInventory<ValueT>& origin);
    DDInventory<ValueT>& operator =(DDInventory<ValueT>&& origin) noexcept;
    template <typename ContainerT>
    DDInventory<ValueT>& operator =(const ContainerT& origin);
    template <typename ObjectT>
    DDInventory<ValueT>& operator <<(ObjectT const& object);
    template <typename ObjectT>
    DDInventory<ValueT>& operator >>(ObjectT& target);
    template <typename ObjectT>
    DDInventory<ValueT>& operator +=(ObjectT const& phasor);
    
    private:
    template <typename FunctionT>
    DDInventory<int> sequence_search_all_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& judger) const;
    
};


DD_END



DD_BEGIN
template <typename ValueT>
inline ProcessType swap(DDInventory<ValueT>& inventory_1, DDInventory<ValueT>& inventory_2) noexcept {
    inventory_1.swap(inventory_2);
    return;
}


template <typename ValueT>
std::ostream &operator <<(std::ostream &os, const DDInventory<ValueT>& inventory) {
    os << '{';
    if (inventory.m_length > 0) {
        os << *inventory.m_content[0];
        for (auto i = 1; i < inventory.m_length; ++i) {
            os << ", " << *inventory.m_content[i];
        }
    }
    return os << '}';
}

template <typename ValueT>
inline std::ostream &operator <<(std::ostream &os, const typename DDInventory<ValueT>::Cursor& cursor) noexcept {
    return os << cursor.get_address();
}

template <typename ValueT>
inline std::ostream &operator <<(std::ostream &os, const typename DDInventory<ValueT>::SCursor& scursor) noexcept {
    return os << scursor.get_address();
}

template <typename ValueT>
std::wostream &operator <<(std::wostream &wos, const DDInventory<ValueT>& inventory) {
    wos << '{';
    if (inventory.m_length > 0) {
        wos << *inventory.m_content[0];
        for (auto i = 1; i < inventory.m_length; ++i) {
            wos << ", " << *inventory.m_content[i];
        }
    }
    return wos << '}';
}


template <typename ValueT>
std::istream &operator >>(std::istream &is, DDInventory<ValueT>& inventory) {
    return is >> inventory.lengthen(1).get_top();
}

template <typename ValueT>
std::wistream &operator >>(std::wistream &wis, DDInventory<ValueT>& inventory) {
    return wis >> inventory.lengthen(1).get_top();
}


DDINVENTORY_MEMBER(inline)::DDInventory() noexcept : DDImplement::IndirectContainerBase<ValueT>(0, nullptr) {
}

DDINVENTORY_MEMBER()::DDInventory(const DDInventory<ValueT>& origin)  : DDImplement::IndirectContainerBase<ValueT>(origin.m_length, nullptr) {
    DDALLOCATE(this->m_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate DDInventory. ", this->m_length = 0; )
    for (CounterType i = 0; i < this->m_length; ++i) {
        DDALLOCATE(this->m_content[i] = new ValueT(*origin.m_content[i]), "Failed to allocate element. ", clear(); )
    }
}

DDINVENTORY_MEMBER(inline)::DDInventory(DDInventory<ValueT>&& origin) noexcept : DDImplement::IndirectContainerBase<ValueT>(origin.m_length, origin.m_content) {
    origin.m_length = 0;
    origin.m_content = nullptr;
}

DDINVENTORY_MEMBER()::DDInventory(std::initializer_list<ValueT> initializer) : DDImplement::IndirectContainerBase<ValueT>(initializer.size(), nullptr) {
    DDALLOCATE(this->m_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate DDInventory. ", this->m_length = 0; )
    for (CounterType i = 0; i < this->m_length; ++i) {
        DDALLOCATE(this->m_content[i] = new ValueT(initializer.begin()[i]), "Failed to allocate element. ", clear(); )
    }
}

DDINVENTORY_MEMBER(template <typename ContainerT>)::DDInventory(const ContainerT& origin) : DDImplement::IndirectContainerBase<ValueT>(origin.end() - origin.begin(), nullptr) {
    DDALLOCATE(this->m_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate DDInventory. ", this->m_length = 0;)
    for (CounterType i = 0; i < this->m_length; ++i) {
        DDALLOCATE(this->m_content[i] = new ValueT(origin.begin()[i]), "Failed to allocate element. ", clear(); )
    }
}

DDINVENTORY_MEMBER(template <typename ContainerT>)::DDInventory(SubscriptType target_begin_index, SubscriptType target_end_index, const ContainerT& origin) : DDImplement::IndirectContainerBase<ValueT>(target_begin_index - target_end_index + 1, nullptr) {
    if (this->m_length < 0) {
        this->m_length = 0;
    } else {
        auto begin = origin.begin()[target_begin_index];
        auto end = begin + this->m_length;
        if (end > origin.end()) {
            this->m_length = 0;
            throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid index of origin called. ");
        }
        DDALLOCATE(this->m_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate DDInventory. ", this->m_length = 0; )
        while (--end >= begin) {
            DDALLOCATE(this->m_content[end - begin] = new ValueT(*end), "Failed to allocate element. ", clear();)
        }
    }
}

DDINVENTORY_MEMBER(template <typename... ArgumentsT>)::DDInventory(LengthType new_length, ArgumentsT&&... construct_arguments) : DDImplement::IndirectContainerBase<ValueT>(new_length, nullptr) {
    if (this->m_length < 0) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid initial this->m_length of DDInventory. ");
    }
    DDALLOCATE(this->m_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate inventory. ", this->m_length = 0;);
    for (CounterType i = 0; i < this->m_length; ++i) {
        DDALLOCATE(this->m_content[i] = new ValueT(construct_arguments...), "Failed to allocate element. ", clear(); )
    }
}


DDINVENTORY_MEMBER(inline)::~DDInventory() noexcept {
    clear();
}


DDINVENTORY_MEMBER(template <typename... ArgumentsT> DDInventory<ValueT>&)::lengthen(LengthType extra_length, ArgumentsT&&... construct_arguments) {
    if (extra_length) {
        this->m_length += extra_length;
        if (this->m_length < 0) {
            throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid new this->m_length of DDInventory. ");
        } else if (this->m_length == 0) {
            return clear();
        }
        decltype(this->m_content) tmp_content;
        DDALLOCATE(tmp_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate new inventory. ", this->m_length -= extra_length; )
        for (CounterType i = 0; i < this->m_length && i < this->m_length - extra_length; ++i) {
            DD::swap(tmp_content[i], this->m_content[i]);
        }
        DD::swap(this->m_content, tmp_content);
        for (CounterType i = 1; i <= extra_length; ++i) {
            DDALLOCATE(this->m_content[this->m_length - i] = new ValueT(construct_arguments...), "Failed to allocate element. ", clear(); )
        }
    }
    return *this;
}


DDINVENTORY_MEMBER(template <typename... ArgumentsT> inline DDInventory<ValueT>&)::set_length(LengthType new_length, ArgumentsT&&... construct_arguments) {
    return lengthen(new_length - this->m_length, construct_arguments...);
}


DDINVENTORY_MEMBER(template <typename ContainerT> inline DDInventory<ValueT>&)::clone(const ContainerT& origin) {
    set_length(origin.end() - origin.begin());
    return copy(origin);
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::clone(DDInventory<ValueT>&& origin) noexcept {
    return swap(origin);
}

DDINVENTORY_MEMBER(template <typename ContainerT> DDInventory<ValueT>&)::clone(SubscriptType target_begin_index, SubscriptType target_end_index, const ContainerT& origin) {
    auto begin = origin.begin()[target_begin_index];
    auto end = origin.begin()[target_end_index + 1];
    if (begin > origin.end() || end > origin.end()) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Invalid index of origin called. ");
    }
    if (begin >= end) {
        return clear();
    }
    set_length(end - begin);
    while (--end >= begin) {
        *this->m_content[end - begin] = *end;
    }
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::clone(SubscriptType target_begin_index, SubscriptType target_end_index, DDInventory<ValueT>&& origin) {
    LengthType new_length = origin.check_index(target_end_index) - origin.check_index(target_begin_index) + 1;
    if (new_length < 0) {
        return this->clear();
    }
    set_length(new_length);
    for (CounterType i = 0; i < this->m_length; ++i) {
        DD::swap(this->m_content[i], origin.m_content[target_begin_index + i]);
    }
    return *this;
}


DDINVENTORY_MEMBER(DDInventory<ValueT>&)::swap(DDInventory &target) noexcept {
    DD::swap(this->m_length, target.m_length);
    DD::swap(this->m_content, target.m_content);
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::append(DDInventory<ValueT>&& target) {
    return this->push_end(target);
}

DDINVENTORY_MEMBER(template <typename ObjectT> inline DDInventory<ValueT>&)::append(ObjectT const& object) {
    return this->push_end(object);
}


DDINVENTORY_MEMBER(template <typename ObjectT> inline DDInventory<ValueT>&)::push_begin(ObjectT const& leader) {
    return this->insert(leader, 0);
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::push_end(const ValueT& follower) {
    return this->lengthen(1, follower);
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::push_end(DDInventory<ValueT>&& follower) {
    LengthType original_length = this->m_length;
    lengthen(follower.m_length);
    return this->copy(follower, original_length, this->m_length - 1);
}


DDINVENTORY_MEMBER(template <typename ContainerT> inline DDInventory<ValueT>&)::push_end(const ContainerT& follower) {
    LengthType original_length = this->m_length;
    lengthen(follower.m_length);
    return this->copy(follower, original_length, this->m_length - 1);
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::insert(SubscriptType index, const ValueT& jumper) {
    this->check_index(index);
    push_end(jumper);
    return this->move(this->m_length - 1, index);
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::insert(SubscriptType index, DDInventory<ValueT>&& jumper) {
    this->check_index(index);
    push_end(jumper);
    return this->move(this->m_length - 1, index);
}

DDINVENTORY_MEMBER(template <typename ContainerT> DDInventory<ValueT>&)::insert(SubscriptType index, const ContainerT& jumper) {
    this->check_index(index);
    LengthType original_length = this->m_length;
    push_end(jumper);
    if (original_length > index) {
        reverse(index, original_length - 1);
        reverse(original_length, this->m_length - 1);
        reverse(index, this->m_length - 1);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::enter(const ValueT& element) {
    return this->enter(DD::compare<ValueT>, true, element);
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::enter(CheckType ascend, const ValueT& element) {
    return this->enter(DD::compare<ValueT>, ascend, element);
}

DDINVENTORY_MEMBER(template <typename FunctionT> inline DDInventory<ValueT>&)::enter(FunctionT& comparer, const ValueT& element) {
    return this->enter(comparer, true, element);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::enter(FunctionT& comparer, CheckType ascend, const ValueT& element) {
    SubscriptType index = binary_search(comparer, ascend, element);
    if (index < 0) {
        if (comparer(element, get_bottom()) == DDCompareResult::LESS) {
            index = 0;
        } else {
            return push_end(element);
        }
    }
    return this->insert(element, index);
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::take_to(ValueT& target) {
    if (this->is_empty()) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to take from an empty DDInventory. ");
    }
    target = *this->m_content[this->m_length - 1];
    return this->lengthen(-1);
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::take_to(DDInventory<ValueT>& target) {
    if (this->is_empty()) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to take from an empty DDInventory. ");
    }
    target.lengthen(1);
    DD::swap(this->m_content[this->m_length - 1], target.m_content[target.m_length - 1]);
    return this->pop_end();
}

DDINVENTORY_MEMBER(template <typename ContainerT> inline DDInventory<ValueT>&)::take_to(ContainerT& target) {
    if (this->is_empty()) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to take from an empty DDInventory. ");
    }
    target.append(*this->m_content[this->m_length - 1]);
    return this->pop_end();
}


DDINVENTORY_MEMBER(inline ValueT)::fetch(SubscriptType index) {
    ValueT tmp_element = *this->m_content[this->check_index(index)];
    this->remove(index);
    return this->tmp_element;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::fetch_to(ValueT& target, SubscriptType index) {
    target = *this->m_content[this->check_index(index)];
    return this->remove(index);
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::fetch_to(DDInventory<ValueT>& target, SubscriptType index) {
    target.lengthen(1);
    DD::swap(this->m_content[index], target.m_content[target.m_length - 1]);
    return this->remove(index);
}

DDINVENTORY_MEMBER(template <typename ContainerT> inline DDInventory<ValueT>&)::fetch_to(ContainerT& target, SubscriptType index) {
    target.append(*this->m_content[this->check_index(index)]);
    return this->remove(index);
}


DDINVENTORY_MEMBER(inline ValueT)::draw() {
    if (this->m_length <= 0) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to draw from an empty DDInventory. ");
    }
    return this->fetch(DD::randomer(0, this->m_length));
}

DDINVENTORY_MEMBER(inline ValueT)::draw(SubscriptType begin_index, SubscriptType end_index) {
    if (this->check_index(begin_index) > this->check_index(end_index)) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "No element in range to draw. ");
    }
    return this->fetch(DD::randomer(begin_index, end_index + 1));
}


DDINVENTORY_MEMBER(DDInventory<ValueT>&)::draw_to(ValueT& target) {
    if (!this->m_length) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to draw from an empty DDInventory. ");
    }
    return this->fetch_to(target, DD::randomer(0, this->m_length));
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::draw_to(SubscriptType begin_index, SubscriptType end_index, ValueT& target) {
    if (this->check_index(begin_index) > this->check_index(end_index)) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "No element in range to draw. ");
    }
    return this->fetch_to(target, DD::randomer(begin_index, end_index + 1));
}

DDINVENTORY_MEMBER(template <typename ContainerT> DDInventory<ValueT>&)::draw_to(ContainerT& target) {
    if (this->is_empty()) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to draw from an empty DDInventory. . ");
    }
    return this->fetch_to(target, DD::randomer(0, this->m_length));
}

DDINVENTORY_MEMBER(template <typename ContainerT> DDInventory<ValueT>&)::draw_to(SubscriptType begin_index, SubscriptType end_index, ContainerT& target) {
    if (this->check_index(begin_index) > this->check_index(end_index)) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "No element in range to draw. ");
    }
    return this->fetch_to(target, DD::randomer(begin_index, end_index + 1));
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::pop_begin() {
    if (this->m_length < 1) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to pop from an empty DDInventory. ");
    } else if (this->m_length == 1) {
        return this->clear();
    }
    return this->remove(0);
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::pop_begin(LengthType to_pop) {
    if (this->m_length < to_pop) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "No enough elements to pop. ");
    } else if (this->m_length == to_pop) {
        return this->clear();
    }
    if (to_pop > 0) {
        this->m_length -= to_pop;
        decltype(this->m_content) tmp_content;
        DDALLOCATE(tmp_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate new inventory. ", this->m_length += to_pop; )
        for (CounterType i = 0; i < this->m_length; ++i) {
            DD::swap(tmp_content[i], this->m_content[to_pop + i]);
        }
        DD::swap(this->m_content, tmp_content);
    }
    return *this;
}


DDINVENTORY_MEMBER(DDInventory<ValueT>&)::pop_end() {
    if (this->m_length < 1) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to pop from an empty DDInventory. ");
    } else if (this->m_length == 1) {
        return this->clear();
    }
    decltype(this->m_content) tmp_content;
    DDALLOCATE(tmp_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate new inventory. ", ++this->m_length; )
    for (CounterType i = 0; i < this->m_length; ++i) {
        DD::swap(tmp_content[i], this->m_content[i]);
    }
    DD::swap(this->m_content, tmp_content);
    return *this;
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::pop_end(LengthType to_pop) {
    if (this->m_length < to_pop) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "No enough elements to pop. ");
    } else if (this->m_length == to_pop) {
        return this->clear();
    }
    if (to_pop > 0) {
        decltype(this->m_content) tmp_content;
        DDALLOCATE(tmp_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate new inventory. ", this->m_length += to_pop; )
        for (CounterType i = 0; i < this->m_length; ++i) {
            DD::swap(tmp_content[i], this->m_content[i]);
        }
        DD::swap(this->m_content, tmp_content);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::remove() {
    return clear();
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::remove(SubscriptType index) {
    this->check_index(index);
    --this->m_length;
    if (this->m_length <= 0) {
        return this->clear();
    }
    decltype(this->m_content) tmp_content;
    DDALLOCATE(tmp_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate new inventory. ", ++this->m_length; )
    for (CounterType i = 0; i < index; ++i) {
        DD::swap(tmp_content[i], this->m_content[i]);
    }
    for (CounterType i = index; i < this->m_length; ++i) {
        DD::swap(tmp_content[i], this->m_content[i + 1]);
    }
    DD::swap(this->m_content, tmp_content);
    return *this;
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::remove(SubscriptType begin_index, SubscriptType end_index) {
    if (this->check_index(begin_index) <= this->check_index(end_index)) {
        this->m_length -= end_index - begin_index + 1;
        if (this->m_length <= 0) {
            return this->clear();
        }
        decltype(this->m_content) tmp_content;
        DDALLOCATE(tmp_content = new DDUPointer<ValueT>[this->m_length], "Failed to allocate new inventory. ", this->m_length += end_index - begin_index + 1; )
        for (CounterType i = 0; i < begin_index; ++i) {
            DD::swap(tmp_content[i], this->m_content[i]);
        }
        while (begin_index < this->m_length) {
            DD::swap(tmp_content[begin_index++], this->m_content[++end_index]);
        }
        DD::swap(this->m_content, tmp_content);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::clear() noexcept {
    this->m_length = 0;
    this->m_content.reset();
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::copy(DDInventory<ValueT>&& origin) {
    if (this != &origin) {
        for (int i = this->m_length < origin.get_length() ? this->m_length : origin.get_length(); i--; ) {
            DD::swap(this->m_content[i], origin.m_content[i]);
        }
    }
    return *this;
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::copy(SubscriptType begin_index, SubscriptType end_index, DDInventory<ValueT>&& origin) {
    LengthType range = this->check_index(end_index) - this->check_index(begin_index) + 1;
    if (begin_index > 0 || end_index < this->m_length - 1 || this != &origin) {
        for (CounterType i = range < origin.get_length() ? range : origin.get_length(); --i >= 0; ) {
            DD::swap(this->m_content[begin_index + i], origin.m_content[i]);
        }
    }
    return *this;
}

DDINVENTORY_MEMBER(template <typename ContainerT> inline DDInventory<ValueT>&)::copy(const ContainerT& origin) {
    if (this != &origin) {
        for (int i = this->m_length < origin.get_length() ? this->m_length : origin.get_length(); i--; ) {
            *this->m_content[i] = *origin.begin()[i];
        }
    }
    return *this;
}

DDINVENTORY_MEMBER(template <typename ContainerT> DDInventory<ValueT>&)::copy(SubscriptType begin_index, SubscriptType end_index, const ContainerT& origin) {
    if (!origin.is_available(begin_index) || !origin.is_available(end_index)) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid index of origin called. ");
    }
    if (begin_index > 0 || end_index < this->m_length - 1 || this != &origin) {
        LengthType target_length = end_index - begin_index + 1;
        for (CounterType i = target_length < origin.get_length() ? target_length : origin.get_length(); --i >= 0; ) {
            *this->m_content[begin_index + i] = origin[i];
        }
    }
    return *this;
}


DDINVENTORY_MEMBER(inline ValueT)::take() {
    ValueT tmp_element = this->get_top();
    this->pop_end();
    return tmp_element;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::swap_index(SubscriptType index_1, SubscriptType index_2) {
    if (this->check_index(index_1) != this->check_index(index_2)) {
        ValueT* tmp_record = this->m_content[index_1];
        this->m_content[index_1] = this->m_content[index_2];
        this->m_content[index_2] = tmp_record;
    }
    return *this;
}


DDINVENTORY_MEMBER(DDInventory<ValueT>&)::move(SubscriptType index, SubscriptType target_index) {
    if (this->check_index(index) != this->check_index(target_index)) {
        ValueT* tmp_record = this->m_content[index];
        for (; index < target_index; ++index) {
            this->m_content[index] = this->m_content[index + 1];
        }
        for (; index > target_index; --index) {
            this->m_content[index] = this->m_content[index - 1];
        }
        this->m_content[target_index] = tmp_record;
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::rotate(LengthType steps) {
    return rotate(steps, 0, this->m_length - 1);
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::rotate(LengthType steps, SubscriptType begin_index, SubscriptType end_index) {
    if (this->check_index(begin_index) < this->check_index(end_index)) {
        steps %= end_index - begin_index + 1;
        if (steps != 0) {
            SubscriptType divide_index;
            if (steps > 0) {
                divide_index = end_index - steps;
            } else {
                divide_index = begin_index - steps - 1;
            }
            this->reverse_implement(begin_index, divide_index);
            this->reverse_implement(divide_index + 1, end_index);
            this->reverse_implement(begin_index, end_index);
        }
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::reverse() {
    this->reverse_implement(0, this->m_length - 1);
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::reverse(SubscriptType begin_index, SubscriptType end_index) {
    this->reverse_implement(this->check_index(begin_index), this->check_index(end_index));
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::shuffle() {
    this->shuffle_implement(0, this->m_length - 1);
    return *this;
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::shuffle(SubscriptType begin_index, SubscriptType end_index) {
    this->shuffle_implement(this->check_index(begin_index), this->check_index(end_index));
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::sort(CheckType ascend) {
    return this->sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::bubble_sort(CheckType ascend) {
    return this->bubble_sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::bubble_sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->bubble_sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->bubble_sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::bubble_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->bubble_sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::bubble_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->bubble_sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->bubble_sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::heap_sort(CheckType ascend) {
    return this->heap_sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::heap_sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->heap_sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->heap_sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::heap_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->heap_sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::heap_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->heap_sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->heap_sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::insert_sort(CheckType ascend) {
    return this->insert_sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::insert_sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->insert_sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->insert_sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::insert_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->insert_sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::insert_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->insert_sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->insert_sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::merge_sort(CheckType ascend) {
    return this->merge_sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::merge_sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->merge_sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->merge_sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::merge_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->merge_sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::merge_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->merge_sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->merge_sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::quick_sort(CheckType ascend) {
    return this->quick_sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::quick_sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->quick_sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->quick_sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::quick_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->quick_sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::quick_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->quick_sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->quick_sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::select_sort(CheckType ascend) {
    return this->select_sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::select_sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->select_sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->select_sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::select_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->select_sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::select_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->select_sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->select_sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::shell_sort(CheckType ascend) {
    return this->shell_sort(DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::shell_sort(FunctionT& comparer, CheckType ascend) {
    if (ascend) {
        this->shell_sort_implement(0, this->m_length - 1, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->shell_sort_implement(0, this->m_length - 1, tmp_comparer);
    }
    return *this;
}

DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::shell_sort(SubscriptType begin_index, SubscriptType end_index, CheckType ascend) {
    return this->shell_sort(begin_index, end_index, DD::compare<ValueT>, ascend);
}

DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<ValueT>&)::shell_sort(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer, CheckType ascend) {
    this->check_index(begin_index);
    this->check_index(end_index);
    if (ascend) {
        this->shell_sort_implement(begin_index, end_index, comparer);
    } else {
        auto tmp_comparer = [&comparer](const ValueT& element_1, const ValueT& element_2) { return comparer(element_2, element_1); };
        this->shell_sort_implement(begin_index, end_index, tmp_comparer);
    }
    return *this;
}


DDINVENTORY_MEMBER(inline DDInventory<ValueT>&)::operator =(const DDInventory<ValueT>& origin) {
    return this->clone(origin);
}

DDINVENTORY_MEMBER(DDInventory<ValueT>&)::operator =(DDInventory<ValueT>&& origin) noexcept {
    this->swap(origin);
    return *this;
}

DDINVENTORY_MEMBER(template <typename ContainerT> inline DDInventory<ValueT>&)::operator =(const ContainerT& origin) {
    return this->clone(origin);
}


DDINVENTORY_MEMBER(template <typename ObjectT> inline DDInventory<ValueT>&)::operator <<(ObjectT const& object) {
    return this->append(object);
}


DDINVENTORY_MEMBER(template <typename ObjectT> inline DDInventory<ValueT>&)::operator >>(ObjectT& target) {
    return this->take_to(target);
}


DDINVENTORY_MEMBER(template <typename ObjectT> inline DDInventory<ValueT>&)::operator +=(ObjectT const& phasor) {
    return this->translate(phasor);
}


DDINVENTORY_MEMBER(template <typename FunctionT> DDInventory<int>)::sequence_search_all_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& judger) const {
    DDInventory<int> result;
    while ((begin_index = this->sequence_search_implement(begin_index, end_index, judger)) >= 0) {
        result.append(begin_index);
    }
    return result;
}


DD_END



 #undef DDINVENTORY_MEMBER
 #undef DDINVENTORY_SPECIALIZED
 #undef DDINVENTORY_CURSOR_MEMBER



#endif
