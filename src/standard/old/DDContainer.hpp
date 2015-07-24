// DDContainer.hpp
#ifndef _DDCONTAINER_
 #define _DDCONTAINER_



 #include "DDMemory.hpp"
 #include "DDRandom.hpp"
 #include <initializer_list>



DD_BEGIN
DDIMPLEMENT_BEGIN
class SequenceContainerBase;

template <typename ValueT>
class TightContainerBase;

template <typename ValueT>
class IndirectContainerBase;

template <typename ValueT>
struct FListNode;

template <typename ValueT>
struct ListNode;

template <typename ValueT>
struct TreeNode;

template <typename ValueT>
class ListBase; 

template <typename ValueT>
class FListBase;

template <typename ValueT>
class TightContainerCursor;

template <typename ValueT>
class IndirectContainerCursor;

template <typename ValueT>
class FListCursor;

template <typename ContainerT>
class ContainerSCursor;


DDIMPLEMENT_END


template <typename ValueT>
DDImplement::TightContainerCursor<ValueT> begin(ValueT* array);


template <typename ValueT, LengthType LengthT>
DDImplement::TightContainerCursor<ValueT> end(ArrayType<ValueT, LengthT>& array);


template <typename ContainerT>
LengthType get_length(const ContainerT& container);


DDIMPLEMENT_BEGIN
class SequenceContainerBase {
    public:
    struct IsContainer;
    
    protected:
    SequenceContainerBase() = delete;
    SequenceContainerBase(const SequenceContainerBase&) = delete;
    SequenceContainerBase(SequenceContainerBase&&) = delete;
    SequenceContainerBase(LengthType new_length) noexcept;
    
    public:
    ~SequenceContainerBase() noexcept;
    LengthType get_length() const noexcept;
    ValidityType is_empty() const noexcept;
    ValidityType is_available(SubscriptType index) const noexcept;
    
    public:
    SequenceContainerBase& operator =(const SequenceContainerBase&) = delete;
    SequenceContainerBase& operator =(SequenceContainerBase&&) = delete;
    explicit operator ValidityType() const noexcept;
    explicit operator LengthType() const noexcept;
    
    protected:
    SubscriptType& check_index(SubscriptType& index) const;
    
    protected:
    LengthType m_length = 0;
    
};


template <typename ValueT>
class TightContainerBase : public SequenceContainerBase {
    public:
    using ValueType = ValueT;
    using Cursor = TightContainerCursor<ValueT>;
    using CCursor = TightContainerCursor<const ValueT>;
    using SCursor = ContainerSCursor<TightContainerBase<ValueT>>;
    using SCCursor = ContainerSCursor<const TightContainerBase<ValueT>>;
    
    public:
    friend Cursor;
    friend CCursor;
    
    protected:
    TightContainerBase() = delete;
    TightContainerBase(const TightContainerBase<ValueT>&) = delete;
    TightContainerBase(TightContainerBase<ValueT>&&) = delete;
    TightContainerBase(LengthType new_length, ValueT** new_content) noexcept;
    
    public:
    ~TightContainerBase() noexcept;
    /*ValidityType equal(const TightContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    ValidityType equal(FunctionT& equal_judge, const TightContainerBase<ValueT>& target) const;
    ValidityType less(const TightContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    ValidityType less(FunctionT& comparer, const TightContainerBase<ValueT>& target) const;
    ValidityType greater(const TightContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    ValidityType greater(FunctionT& comparer, const TightContainerBase<ValueT>& target) const;
    DDCompareResult compare(const TightContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    DDCompareResult compare(FunctionT& comparer, const TightContainerBase<ValueT>& target) const;*/
    ValueT& at(SubscriptType index);
    const ValueT& at(SubscriptType index) const;
    
    public:
    IndirectContainerBase<ValueT>& operator =(const IndirectContainerBase<ValueT>&) = delete;
    IndirectContainerBase<ValueT>& operator =(IndirectContainerBase<ValueT>&&) = delete;
    ValueT& operator [](SubscriptType index);
    const ValueT& operator [](SubscriptType index) const;
    
    protected:
    ValueT* m_content;
    
};


template <typename ValueT>
class IndirectContainerBase : public SequenceContainerBase {
    public:
    using ValueType = ValueT;
    using Cursor = IndirectContainerCursor<ValueT>;
    using CCursor = IndirectContainerCursor<const ValueT>;
    using SCursor = ContainerSCursor<IndirectContainerBase<ValueT>>;
    using SCCursor = ContainerSCursor<const IndirectContainerBase<ValueT>>;
    
    public:
    friend Cursor;
    friend CCursor;
    
    protected:
    IndirectContainerBase() = delete;
    IndirectContainerBase(const IndirectContainerBase<ValueT>&) = delete;
    IndirectContainerBase(IndirectContainerBase<ValueT>&&) = delete;
    IndirectContainerBase(LengthType new_length, DDUPointer<ValueT>* new_content) noexcept;
    
    public:
    ~IndirectContainerBase() noexcept;
    ValidityType equal(const IndirectContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    ValidityType equal(FunctionT& equal_judge, const IndirectContainerBase<ValueT>& target) const;
    ValidityType less(const IndirectContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    ValidityType less(FunctionT& comparer, const IndirectContainerBase<ValueT>& target) const;
    ValidityType greater(const IndirectContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    ValidityType greater(FunctionT& comparer, const IndirectContainerBase<ValueT>& target) const;
    DDCompareResult compare(const IndirectContainerBase<ValueT>& target) const;
    template <typename FunctionT>
    DDCompareResult compare(FunctionT& comparer, const IndirectContainerBase<ValueT>& target) const;
    ValueT& at(SubscriptType index);
    const ValueT& at(SubscriptType index) const;
    ValueT& get_top();
    const ValueT& get_top() const;
    ValueT& get_bottom();
    const ValueT& get_bottom() const;
    ValueT& get_random();
    const ValueT& get_random() const;
    ValueT& get_random(SubscriptType begin_index, SubscriptType end_index);
    const ValueT& get_random(SubscriptType begin_index, SubscriptType end_index) const;
    Cursor get(SubscriptType index = 0) noexcept;
    Cursor begin() noexcept;
    Cursor end() noexcept;
    CCursor cget(SubscriptType index = 0) const noexcept;
    CCursor cbegin() const noexcept;
    CCursor cend() const noexcept;
    SCursor sget(SubscriptType index = 0) noexcept;
    SCursor sbegin() noexcept;
    SCursor send() noexcept;
    SCCursor scget(SubscriptType index = 0) const noexcept;
    SCCursor scbegin() const noexcept;
    SCCursor scend() const noexcept;
    
    public:
    IndirectContainerBase<ValueT>& operator =(const IndirectContainerBase<ValueT>&) = delete;
    IndirectContainerBase<ValueT>& operator =(IndirectContainerBase<ValueT>&&) = delete;
    ValueT& operator [](SubscriptType index);
    const ValueT& operator [](SubscriptType index) const;
    
    protected:
    ProcessType reverse_implement(SubscriptType begin_index, SubscriptType end_index);
    ProcessType shuffle_implement(SubscriptType begin_index, SubscriptType end_index);
    template <typename FunctionT>
    ProcessType sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType bubble_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType heap_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType heapify(SubscriptType begin_index, SubscriptType end_index, SubscriptType root_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType insert_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType merge_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType quick_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType select_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    template <typename FunctionT>
    ProcessType shell_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer);
    
    protected:
    DDUPointer<DDUPointer<ValueT>[]> m_content;
    
};


template <typename ValueT>
struct FListNode final {
    public:
    using ValueType = ValueT;
    
    public:
    ValueT value;
    DDUPointer<ListNode<ValueT>> next;
    
};


template <typename ValueT>
struct ListNode final {
    public:
    using ValueType = ValueT;
    
    public:
    ValueT value;
    ListNode<ValueT>* previous;
    DDUPointer<ListNode<ValueT>> next;
    
};


template <typename ValueT>
struct TreeNode final {
    public:
    using ValueType = ValueT;
    
    public:
    ValueT value;
    TreeNode<ValueT>* previous;
    DDUPointer<TreeNode<ValueT>> left;
    DDUPointer<TreeNode<ValueT>> right;
    
};


template <typename ValueT>
class ListBase {
    public:
    using ValueType = ValueT;
    
    protected:
    ListBase() = default;
    ListBase(ListBase<ValueT> const& origin);
    ListBase(ListBase<ValueT>&& origin) noexcept;
    
    public:
    ~ListBase() = default;
    
    protected:
    ProcessType swap(ListBase<ValueT>& target) noexcept;
    template <typename... ArgumentsT>
    ProcessType push_end(ArgumentsT&&... construct_arguments);
    
    protected:
    DDUPointer<ListNode<ValueT>> m_first;
    ListNode<ValueT>* m_last = nullptr;
    
};
#warning remember to remove these code
template <typename ValueT>
inline ListBase<ValueT>::ListBase(ListBase<ValueT> const& origin) {
    DD_UNREALIZED;
}


template <typename ValueT>
inline ListBase<ValueT>::ListBase(ListBase<ValueT>&& origin) noexcept : m_first(DD::move(origin.m_first)), m_last(origin.m_last) {
}


template <typename ValueT>
inline ProcessType ListBase<ValueT>::swap(ListBase<ValueT>& origin) noexcept {
    DD::swap(this->m_first, origin.m_first);
    DD::swap(this->m_last, origin.m_last);
    return;
}


template <typename ValueT> template <typename... ArgumentsT>
inline ProcessType ListBase<ValueT>::push_end(ArgumentsT&&... construct_arguments) {
    try {
        DDUPointer<ValueT> tmp(new ListNode<ValueT>{ValueT(construct_arguments...), nullptr, DDUPointer<ValueT>()});
        if (this->is_empty()) {
            DD::swap(this->m_first, tmp);
            this->m_last = this->m_first.get_address();
        } else {
            DD::swap(this->m_last->next, tmp);
            this->m_last = this->m_last->next.get_address();
        }
    } catch (std::bad_alloc error) {
        throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate for new element. ");
    }
    return;
}


#warning end up here


template <typename ValueT>
class FListBase {
    public:
    using ValueType = ValueT;
    using Cursor = typename DDImplement::FListCursor<ValueT>;
    using CCursor = typename DDImplement::FListCursor<ValueT const>;
    
    public:
    friend Cursor;
    friend CCursor;
    
    protected:
    FListBase() = default;
    FListBase(const FListBase<ValueT>& origin);
    FListBase(FListBase<ValueT>&& origin) noexcept;
    
    public:
    ~FListBase() = default;
    
    protected:
    ProcessType swap(FListBase<ValueT>& target) noexcept;
    
    protected:
    DDUPointer<FListNode<ValueT>> m_first;
    
};


template <typename ValueT>
class TightContainerCursor final {
    public:
    using ValueType = ValueT;
    
    public:
    TightContainerCursor() noexcept;
    TightContainerCursor(const TightContainerCursor<ValueT>& origin) noexcept;
    TightContainerCursor(ValueT* target) noexcept;
    template <typename ContainerT>
    TightContainerCursor(const ContainerT& container, SubscriptType index) noexcept;
    ValidityType equal(const TightContainerCursor<ValueT>& target) const noexcept;
    DDCompareResult compare(const TightContainerCursor<ValueT>& target) const noexcept;
    ValueT* get_address() const noexcept;
    LengthType relative(const TightContainerCursor<ValueT>& target) const noexcept;
    TightContainerCursor<ValueT>& move(LengthType step) noexcept;
    
    public:
    TightContainerCursor<ValueT>& operator ++() noexcept;
    TightContainerCursor<ValueT> operator ++(IntSignType) noexcept;
    TightContainerCursor<ValueT>& operator --() noexcept;
    TightContainerCursor<ValueT> operator --(IntSignType) noexcept;
    TightContainerCursor<ValueT>& operator +=(LengthType step) noexcept;
    TightContainerCursor<ValueT>& operator -=(LengthType step) noexcept;
    ValueT& operator *() const noexcept;
    ValueT* operator ->() const noexcept;
    ValueT& operator [](SubscriptType index) const noexcept;
    explicit operator ValidityType() const noexcept;
    
    protected:
    ValueT* m_pointer;
    
};


template <typename ValueT>
class IndirectContainerCursor final {
    public:
    using ValueType = ValueT;
    
    public:
    IndirectContainerCursor() noexcept;
    IndirectContainerCursor(const IndirectContainerCursor<ValueT>& origin) noexcept;
    template <typename ContainerT>
    IndirectContainerCursor(ContainerT& container, SubscriptType index) noexcept;
    ValidityType equal(const IndirectContainerCursor<ValueT>& target) const noexcept;
    DDCompareResult compare(const IndirectContainerCursor<ValueT>& target) const noexcept;
    ValueT* get_address() const noexcept;
    LengthType relative(const IndirectContainerCursor<ValueT>& target) const noexcept;
    IndirectContainerCursor<ValueT>& move(LengthType step) noexcept;
    
    public:
    IndirectContainerCursor<ValueT>& operator ++() noexcept;
    IndirectContainerCursor<ValueT> operator ++(IntSignType) noexcept;
    IndirectContainerCursor<ValueT>& operator --() noexcept;
    IndirectContainerCursor<ValueT> operator --(IntSignType) noexcept;
    IndirectContainerCursor<ValueT>& operator +=(LengthType step) noexcept;
    IndirectContainerCursor<ValueT>& operator -=(LengthType step) noexcept;
    ValueT& operator *() const noexcept;
    ValueT* operator ->() const noexcept;
    ValueT& operator [](SubscriptType index) const noexcept;
    explicit operator ValidityType() const noexcept;
    
    private:
    ValueT** m_target = nullptr;
    
};


template <typename ValueT>
class FListCursor {
    public:
    using ValueType = ValueT;
    
    public:
    FListCursor() = default;
    FListCursor(const FListCursor<ValueT>& origin) = default;
    FListCursor(const FListBase<ValueT>& target) noexcept;
    ValidityType equal(const FListCursor<ValueT>& target) const noexcept;
    ValueT* get_address() const noexcept;
    
    public:
    FListCursor<ValueT>& operator ++() noexcept;
    FListCursor<ValueT> operator ++(IntSignType) noexcept;
    ValueT& operator *() const noexcept;
    ValueT* operator ->() const noexcept;
    explicit operator ValidityType() const noexcept;
    
    private:
    ListNode<ValueT>* m_target;
    
};


template <typename ContainerT>
class ContainerSCursor final {
    public:
    using ContainerType = ContainerT;
    using ValueType = typename ContainerT::ValueType;
    
    public:
    ContainerSCursor() noexcept;
    ContainerSCursor(const ContainerSCursor<ContainerT>& origin) noexcept;
    ContainerSCursor(ContainerT& container, SubscriptType index = 0) noexcept;
    ValidityType equal(const ContainerSCursor<ContainerT>& target) const noexcept;
    DDCompareResult compare(const ContainerSCursor<ContainerT>& target) const;
    ValueType* get_address() const noexcept;
    LengthType relative(const ContainerSCursor<ContainerT>& target) const;
    ContainerSCursor<ContainerT>& move(LengthType step) noexcept;
    
    public:
    ContainerSCursor<ContainerT>& operator ++() noexcept;
    ContainerSCursor<ContainerT> operator ++(IntSignType) noexcept;
    ContainerSCursor<ContainerT>& operator --() noexcept;
    ContainerSCursor<ContainerT> operator --(IntSignType) noexcept;
    ContainerSCursor<ContainerT>& operator +=(LengthType step) noexcept;
    ContainerSCursor<ContainerT>& operator -=(LengthType step) noexcept;
    ValueType& operator *() const;
    ValueType* operator ->() const;
    ValueType& operator [](SubscriptType index) const;
    explicit operator ValidityType() const noexcept;
    
    private:
    ContainerT* m_binding = nullptr;
    SubscriptType m_index = 0;
    
};


DDIMPLEMENT_END


DD_END



DD_BEGIN
template <typename ValueT>
DDImplement::TightContainerCursor<ValueT> begin(ValueT* array) {
    return DDImplement::TightContainerCursor<ValueT>(array);
}


template <typename ValueT, LengthType LengthT>
DDImplement::TightContainerCursor<ValueT> end(ArrayType<ValueT, LengthT>& array) {
    return DDImplement::TightContainerCursor<ValueT>(array + LengthT);
}


template <typename ContainerT>
inline LengthType get_length(const ContainerT& container) {
    return container.get_length();
}


DDIMPLEMENT_BEGIN
inline SequenceContainerBase::SequenceContainerBase(LengthType new_length) noexcept : m_length(new_length) {
}


inline SequenceContainerBase::~SequenceContainerBase() noexcept {
}


inline LengthType SequenceContainerBase::get_length() const noexcept {
    return this->m_length;
}


inline ValidityType SequenceContainerBase::is_empty() const noexcept {
    return !this->m_length;
}


inline ValidityType SequenceContainerBase::is_available(SubscriptType index) const noexcept {
    return index >= 0 && index < this->m_length;
}


inline SubscriptType& SequenceContainerBase::check_index(SubscriptType& index) const {
    if (index < 0 || index >= this->m_length) { 
        throw DDError(DDErrorType::ACCESS_DENIED, "Element called out of range. ");
    }
    return index;
}


inline SequenceContainerBase::operator ValidityType() const noexcept {
    return this->m_length >= 0;
}


inline SequenceContainerBase::operator LengthType() const noexcept {
    return this->m_length;
}


template <typename ValueT>
inline TightContainerBase<ValueT>::TightContainerBase(LengthType new_length, ValueT** new_content) noexcept : SequenceContainerBase(new_length), m_content(new_content) {
}

template <typename ValueT>
inline TightContainerBase<ValueT>::~TightContainerBase() noexcept {
}


template <typename ValueT>
inline ValueT& TightContainerBase<ValueT>::at(SubscriptType index) {
    return this->m_content[this->check_index(index)];
}

template <typename ValueT>
inline const ValueT& TightContainerBase<ValueT>::at(SubscriptType index) const {
    return this->m_content[this->check_index(index)];
}


template <typename ValueT>
inline ValueT& TightContainerBase<ValueT>::operator [](SubscriptType index) {
    DD_ASSERT(index >= 0 && index < this->m_length)
    return this->m_content[index];
}

template <typename ValueT>
inline const ValueT& TightContainerBase<ValueT>::operator [](SubscriptType index) const {
    DD_ASSERT(index >= 0 && index < this->m_length)
    return this->m_content[index];
}


template <typename ValueT>
inline IndirectContainerBase<ValueT>::IndirectContainerBase(LengthType new_length, DDUPointer<ValueT>* new_content) noexcept : SequenceContainerBase(new_length), m_content(new_content) {
}


template <typename ValueT>
inline IndirectContainerBase<ValueT>::~IndirectContainerBase() noexcept {
}


template <typename ValueT>
inline ValidityType IndirectContainerBase<ValueT>::equal(const IndirectContainerBase<ValueT>& target) const {
    return this->equal(DD::equal<ValueT>, target);
}

template <typename ValueT> template <typename FunctionT>
ValidityType IndirectContainerBase<ValueT>::equal(FunctionT& equal_judge, const IndirectContainerBase<ValueT>& target) const {
    if (this != &target) {
        if (this->m_length != target.m_length) {
            return false;
        }
        for (CounterType i = 0; i < this->m_length; ++i) {
            if (!equal_judge(*this->m_content[i], *target.m_content[i])) {
                return false;
            }
        }
    }
    return true;
}


template <typename ValueT>
inline ValidityType IndirectContainerBase<ValueT>::less(const IndirectContainerBase<ValueT>& target) const {
    return this->less(DD::compare<ValueT>, target);
}

template <typename ValueT> template <typename FunctionT>
ValidityType IndirectContainerBase<ValueT>::less(FunctionT& comparer, const IndirectContainerBase<ValueT>& target) const {
    if (this != &target) {
        LengthType compare_length = this->m_length < target.m_length ? this->m_length : target.m_length;
        for (CounterType i = 0; i < compare_length; ++i) {
            if (comparer(*this->m_content[i], *target.m_content[i]) == DDCompareResult::LESS) {
                return true;
            }
            if (comparer(*this->m_content[i], *target.m_content[i]) == DDCompareResult::GREATER) {
                return false;
            }
        }
        if (this->m_length < target.m_length) {
            return true;
        }
    }
    return false;
}


template <typename ValueT>
inline ValidityType IndirectContainerBase<ValueT>::greater(const IndirectContainerBase<ValueT>& target) const {
    return this->greater(DD::compare<ValueT>, target);
}

template <typename ValueT> template <typename FunctionT>
inline ValidityType IndirectContainerBase<ValueT>::greater(FunctionT& comparer, const IndirectContainerBase<ValueT>& target) const {
    return target.less(*this);
}


template <typename ValueT>
inline DDCompareResult IndirectContainerBase<ValueT>::compare(const IndirectContainerBase<ValueT>& target) const {
    return this->compare(DD::compare<ValueT>, target);
}

template <typename ValueT> template <typename FunctionT>
DDCompareResult IndirectContainerBase<ValueT>::compare(FunctionT& comparer, const IndirectContainerBase<ValueT>& target) const {
    if (this != &target) {
        LengthType compare_length = this->m_length < target.m_length ? this->m_length : target.m_length;
        for (CounterType i = 0; i < compare_length; ++i) {
            if (comparer(*this->m_content[i], *target.m_content[i]) == DDCompareResult::LESS) {
                return DDCompareResult::LESS;
            }
            if (comparer(*this->m_content[i], *target.m_content[i]) == DDCompareResult::GREATER) {
                return DDCompareResult::GREATER;
            }
        }
        if (this->m_length < target.m_length) {
            return DDCompareResult::LESS;
        }
        if (this->m_length > target.m_length) {
            return DDCompareResult::GREATER;
        }
    }
    return DDCompareResult::EQUAL;
}


template <typename ValueT>
inline ValueT& IndirectContainerBase<ValueT>::at(SubscriptType index) {
    return *this->m_content[this->check_index(index)];
}

template <typename ValueT>
inline const ValueT& IndirectContainerBase<ValueT>::at(SubscriptType index) const {
    return *this->m_content[this->check_index(index)];
}


template <typename ValueT>
inline ValueT& IndirectContainerBase<ValueT>::get_top() {
    if (this->m_length <= 0) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to get top of an empty DDInventory. ");
    }
    return *this->m_content[this->m_length - 1];
}

template <typename ValueT>
inline const ValueT& IndirectContainerBase<ValueT>::get_top() const {
    if (this->m_length <= 0) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to get top of an empty DDInventory. ");
    }
    return *this->m_content[this->m_length - 1];
}


template <typename ValueT>
inline ValueT& IndirectContainerBase<ValueT>::get_bottom() {
    if (this->m_length <= 0) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to get bottom of an empty DDInventory. ");
    }
    return *this->m_content[0];
}

template <typename ValueT>
inline const ValueT& IndirectContainerBase<ValueT>::get_bottom() const {
    if (this->m_length <= 0) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to get bottom of an empty DDInventory. ");
    }
    return *this->m_content[0];
}


template <typename ValueT>
inline ValueT& IndirectContainerBase<ValueT>::get_random() {
    if (this->m_length <= 0) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to randomly get from an empty DDInventory. ");
    }
    return *this->m_content[DD::randomer(0, this->m_length)];
}

template <typename ValueT>
inline const ValueT& IndirectContainerBase<ValueT>::get_random() const {
    if (this->m_length <= 0) {
        throw DDError(DDErrorType::ACCESS_DENIED, "Failed to randomly get from an empty DDInventory. ");
    }
    return *this->m_content[DD::randomer(0, this->m_length)];
}

template <typename ValueT>
inline ValueT& IndirectContainerBase<ValueT>::get_random(SubscriptType begin_index, SubscriptType end_index) {
    if (this->check_index(begin_index) > this->check_index(end_index)) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "No element in range to get randomly. ");
    }
    return *this->m_content[DD::randomer(begin_index, end_index + 1)];
}

template <typename ValueT>
inline const ValueT& IndirectContainerBase<ValueT>::get_random(SubscriptType begin_index, SubscriptType end_index) const {
    if (this->check_index(begin_index) > this->check_index(end_index)) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "No element in range to get randomly. ");
    }
    return *this->m_content[DD::randomer(begin_index, end_index + 1)];
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::Cursor IndirectContainerBase<ValueT>::get(SubscriptType index) noexcept {
    return Cursor(*this, index);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::Cursor IndirectContainerBase<ValueT>::begin() noexcept {
    return Cursor(*this, 0);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::Cursor IndirectContainerBase<ValueT>::end() noexcept {
    return Cursor(*this, this->m_length);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::CCursor IndirectContainerBase<ValueT>::cget(SubscriptType index) const noexcept {
    return CCursor(*this, index);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::CCursor IndirectContainerBase<ValueT>::cbegin() const noexcept {
    return CCursor(*this, 0);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::CCursor IndirectContainerBase<ValueT>::cend() const noexcept {
    return CCursor(*this, this->m_length);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::SCursor IndirectContainerBase<ValueT>::sget(SubscriptType index) noexcept {
    return SCursor(*this, index);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::SCursor IndirectContainerBase<ValueT>::sbegin() noexcept {
    return SCursor(*this, 0);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::SCursor IndirectContainerBase<ValueT>::send() noexcept {
    return SCursor(*this, this->m_length);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::SCCursor IndirectContainerBase<ValueT>::scget(SubscriptType index) const noexcept {
    return SCCursor(*this, index);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::SCCursor IndirectContainerBase<ValueT>::scbegin() const noexcept {
    return SCCursor(*this, 0);
}


template <typename ValueT>
inline typename IndirectContainerBase<ValueT>::SCCursor IndirectContainerBase<ValueT>::scend() const noexcept {
    return SCCursor(*this, this->m_length);
}


template <typename ValueT>
inline ValueT& IndirectContainerBase<ValueT>::operator [](SubscriptType index) {
    DD_ASSERT(index >= 0 && index < this->m_length)
    return *this->m_content[index];
}

template <typename ValueT>
inline const ValueT& IndirectContainerBase<ValueT>::operator [](SubscriptType index) const {
    DD_ASSERT(index >= 0 && index < this->m_length)
    return *this->m_content[index];
}


template <typename ValueT>
ProcessType IndirectContainerBase<ValueT>::reverse_implement(SubscriptType begin_index, SubscriptType end_index) {
    while (begin_index < end_index) {
        DD::swap(*this->m_content[begin_index++], *this->m_content[end_index--]);
    }
    return;
}


template <typename ValueT>
ProcessType IndirectContainerBase<ValueT>::shuffle_implement(SubscriptType begin_index, SubscriptType end_index) {
    for (; begin_index < end_index; ++begin_index) {
        DD::swap(this->m_content[begin_index], *this->m_content[DD::random(begin_index, end_index + 1)]);
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    if (end_index - begin_index >= 1600000) {
        DDERROR_MONITOR
        this->merge_sort_implement(begin_index, end_index, comparer);
        return;
        DDERROR_SOLVE
        if (error.get_type() != DDErrorType::MEMORY_ALLOCATION_FAILURE) {
            throw error;
        }
        DDERROR_SOLVED
    }
    if (begin_index < end_index) {
        DDUPointer<SubscriptType[]> stack;
        DDALLOCATE(stack = new SubscriptType[end_index - begin_index + 1], "Failed to sort. ", );
        auto top = 0;
        stack[top++] = begin_index;
        stack[top++] = end_index;
        do {
            auto high = stack[--top];
            auto low = stack[--top];
            if (high - low < 8) {
                this->insert_sort_implement(low, high, comparer);
                continue;
            }
            auto first = low;
            auto last = high;
            DD::swap(this->m_content[first], this->m_content[DD::random(first, last + 1)]);
            auto& key = *this->m_content[low];
            while (first < last) {
                while (first < last && comparer(*this->m_content[last], key) != DDCompareResult::LESS) {
                    --last;
                }
                DD::swap(this->m_content[first], this->m_content[last]);
                while (first < last && comparer(*this->m_content[first], key) != DDCompareResult::GREATER) {
                    ++first;
                }
                DD::swap(this->m_content[first], this->m_content[last]);
            }
            if (low < first) {
                stack[top++] = low;
                stack[top++] = first;
            }
            if (++last < high) {
                stack[top++] = last;
                stack[top++] = high;
            }
        } while (top);
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::bubble_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    for (ValidityType sorted; --end_index >= begin_index; ) {
        sorted = true;
        for (auto i = begin_index; i <= end_index; ++i) {
            if (comparer(*this->m_content[i], *this->m_content[i + 1]) == DDCompareResult::GREATER) { 
                DD::swap(this->m_content[i], this->m_content[i + 1]);
                sorted = false;
            }
        }
        if (sorted) {
            return;
        }
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::heap_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    for (auto i = (end_index + begin_index) / 2; i >= begin_index; --i) {
        this->heapify(begin_index, end_index, i, comparer);
    }
    while (begin_index < end_index) {
        DD::swap(this->m_content[begin_index], this->m_content[end_index]);
        heapify(begin_index, --end_index, begin_index, comparer);
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::heapify(SubscriptType begin_index, SubscriptType end_index, SubscriptType root_index, FunctionT& comparer) {
    for (SubscriptType index = root_index; ; ) {
        auto child_index = root_index * 2 - begin_index + 1;
        if (child_index <= end_index) {
            if (comparer(*this->m_content[index], *this->m_content[child_index]) == DDCompareResult::LESS) {
                index = child_index;
            }
            if (++child_index <= end_index && comparer(*this->m_content[index], *this->m_content[child_index]) == DDCompareResult::LESS) {
                index = child_index;
            }
        }
        if (index == root_index) {
            break;
        }
        DD::swap(this->m_content[index], this->m_content[root_index]);
        root_index = index;
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::insert_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    for (auto i = begin_index + 1; i <= end_index; ++i) {
        decltype(*m_content) tmp_record;
        DD::swap(tmp_record, m_content[i]);
        SubscriptType current = i;
        for (; current > begin_index && comparer(*tmp_record, *this->m_content[current - 1]) == DDCompareResult::LESS; --current) { 
            this->m_content[current] = this->m_content[current - 1];
        }
        this->m_content[current] = tmp_record;
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::merge_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    auto distance = end_index - begin_index;
    if (distance > 0) {
        SubscriptType buffer[3];
        decltype(this->m_content) tmp_content;
        DDALLOCATE(tmp_content = new DDUPointer<ValueT>[distance + 1], "Failed to sort. ", )
        for (auto i = 1; i <= distance; i *= 2) {
            for (auto j = begin_index; j <= end_index; ) {
                auto k = 0;
                do {
                    buffer[k++] = j;
                } while (k < 3 && (j += i) <= end_index);
                if (k < 3) {
                    buffer[2] = end_index + 1;
                    if (k < 2) {
                        buffer[1] = end_index;
                    }
                }
                auto left = buffer[0];
                auto right = buffer[1];
                for (buffer[0] -= begin_index; ; ++buffer[0]) {
                    if (left >= buffer[1]) {
                        buffer[1] = right;
                        break;
                    }
                    if (right >= buffer[2]) {
                        buffer[1] = left;
                        break;
                    }
                    if (comparer(*this->m_content[left], *this->m_content[right]) == DDCompareResult::LESS) {
                        DD::swap(tmp_content[buffer[0]], this->m_content[left++]);
                    } else {
                        DD::swap(tmp_content[buffer[0]], this->m_content[right++]);
                    }
                }
                buffer[2] -= begin_index;
                while (buffer[0] < buffer[2]) {
                    DD::swap(tmp_content[buffer[0]++], this->m_content[buffer[1]++]);
                }
            }
            for (auto i = 0; i <= distance; ++i) {
                DD::swap(this->m_content[begin_index + i], tmp_content[i]);
            }
        }
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::quick_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    if (begin_index < end_index) {
        DDUPointer<SubscriptType[]> stack;
        DDALLOCATE(stack = new SubscriptType[end_index - begin_index + 1], "Failed to sort. ", );
        auto top = 0;
        stack[top++] = begin_index;
        stack[top++] = end_index;
        do {
            auto high = stack[--top];
            auto low = stack[--top];
            auto first = low;
            auto last = high;
            auto& key = *this->m_content[low];
            while (first < last) {
                while (first < last && comparer(*this->m_content[last], key) != DDCompareResult::LESS) {
                    --last;
                }
                DD::swap(this->m_content[first], this->m_content[last]);
                while (first < last && comparer(*this->m_content[first], key) != DDCompareResult::GREATER) {
                    ++first;
                }
                DD::swap(this->m_content[first], this->m_content[last]);
            }
            if (low < first) {
                stack[top++] = low;
                stack[top++] = first;
            }
            if (++last < high) {
                stack[top++] = last;
                stack[top++] = high;
            }
        } while (top);
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::select_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    for (SubscriptType index; begin_index < end_index; ++begin_index) {
        index = begin_index;
        for (auto i = begin_index + 1; i <= end_index; ++i) { 
            if (comparer(*this->m_content[index], *this->m_content[i]) == DDCompareResult::GREATER) { 
                index = i;
            }
        }
        DD::swap(this->m_content[index], this->m_content[begin_index]);
    }
    return;
}


template <typename ValueT> template <typename FunctionT>
ProcessType IndirectContainerBase<ValueT>::shell_sort_implement(SubscriptType begin_index, SubscriptType end_index, FunctionT& comparer) {
    for (LengthType division = (end_index - begin_index) / 2; division; division /= 2) {
        for (auto i = begin_index + division; i <= end_index; ++i) {
            ValueT* tmp_record = this->m_content[i];
            auto current_index = i - division;
            for (; current_index >= begin_index && comparer(*tmp_record, *this->m_content[current_index]) == DDCompareResult::LESS; current_index -= division) {
                this->m_content[current_index + division] = this->m_content[current_index];
            }
            this->m_content[current_index + division] = tmp_record;
        }
    }
    return;
}


template <typename ValueT>
inline FListBase<ValueT>::FListBase(FListBase<ValueT>&& origin) noexcept : m_first(DD::move(origin.m_first)) {
}


template <typename ValueT>
inline ProcessType FListBase<ValueT>::swap(FListBase<ValueT>& target) noexcept {
    DD::swap(this->m_first, target.m_first);
    return;
}


template <typename ValueT>
inline TightContainerCursor<ValueT>::TightContainerCursor() noexcept : m_pointer(nullptr) {
}

template <typename ValueT>
inline TightContainerCursor<ValueT>::TightContainerCursor(const TightContainerCursor<ValueT>& origin) noexcept : m_pointer(origin.m_pointer) {
}

template <typename ValueT>
inline TightContainerCursor<ValueT>::TightContainerCursor(ValueT* target) noexcept : m_pointer(target) {
}

template <typename ValueT> template <typename ContainerT>
inline TightContainerCursor<ValueT>::TightContainerCursor(const ContainerT& container, SubscriptType index) noexcept : m_pointer(container.m_content + index) {
}


template <typename ValueT>
ValidityType TightContainerCursor<ValueT>::equal(const TightContainerCursor<ValueT>& target) const noexcept {
    return m_pointer == target.m_pointer;
}


template <typename ValueT>
inline DDCompareResult TightContainerCursor<ValueT>::compare(const TightContainerCursor<ValueT>& target) const noexcept {
    return DD::compare(m_pointer, target.m_pointer);
}


template <typename ValueT>
inline ValueT* TightContainerCursor<ValueT>::get_address() const noexcept {
    return m_pointer;
}


template <typename ValueT>
inline LengthType TightContainerCursor<ValueT>::relative(const TightContainerCursor<ValueT>& target) const noexcept {
    return m_pointer - target.m_pointer;
}


template <typename ContainerT>
inline TightContainerCursor<ContainerT>& TightContainerCursor<ContainerT>::move(LengthType step) noexcept {
    m_pointer += step;
    return *this;
}


template <typename ValueT>
inline TightContainerCursor<ValueT>& TightContainerCursor<ValueT>::operator ++() noexcept {
    ++m_pointer;
    return *this;
}

template <typename ValueT>
inline TightContainerCursor<ValueT> TightContainerCursor<ValueT>::operator ++(IntSignType) noexcept {
    return TightContainerCursor(m_pointer++);
}


template <typename ValueT>
TightContainerCursor<ValueT>& TightContainerCursor<ValueT>::operator --() noexcept {
    --m_pointer;
    return *this;
}

template <typename ValueT>
inline TightContainerCursor<ValueT> TightContainerCursor<ValueT>::operator --(IntSignType) noexcept {
    return TightContainerCursor(m_pointer--);
}


template <typename ValueT>
inline TightContainerCursor<ValueT>& TightContainerCursor<ValueT>::operator +=(LengthType step) noexcept {
    return move(step);
}


template <typename ValueT>
inline TightContainerCursor<ValueT>& TightContainerCursor<ValueT>::operator -=(LengthType step) noexcept {
    return move(-step);
}


template <typename ValueT>
inline ValueT& TightContainerCursor<ValueT>::operator *() const noexcept {
    return *m_pointer;
}


template <typename ValueT>
inline ValueT* TightContainerCursor<ValueT>::operator ->() const noexcept {
    return m_pointer;
}


template <typename ValueT>
inline ValueT& TightContainerCursor<ValueT>::operator [](SubscriptType index) const noexcept {
    return m_pointer[index];
}


template <typename ValueT>
inline TightContainerCursor<ValueT>::operator ValidityType() const noexcept {
    return m_pointer;
}


template <typename ValueT>
inline IndirectContainerCursor<ValueT>::IndirectContainerCursor() noexcept : m_target(nullptr) {
}

template <typename ValueT>
inline IndirectContainerCursor<ValueT>::IndirectContainerCursor(const IndirectContainerCursor<ValueT>& origin) noexcept : m_target((ValueT**)(origin.m_target)) {
}

template <typename ValueT> template <typename ContainerT>
inline IndirectContainerCursor<ValueT>::IndirectContainerCursor(ContainerT& container, SubscriptType index) noexcept : m_target((ValueT**)(container.m_content.get_address() + index)) {
}


template <typename ValueT>
inline ValidityType IndirectContainerCursor<ValueT>::equal(const IndirectContainerCursor<ValueT>& target) const noexcept {
    return m_target == target.m_target;
}


template <typename ValueT>
inline DDCompareResult IndirectContainerCursor<ValueT>::compare(const IndirectContainerCursor<ValueT>& target) const noexcept {
    return DD::compare(m_target, target.m_target);
}


template <typename ValueT>
inline ValueT* IndirectContainerCursor<ValueT>::get_address() const noexcept {
    return *m_target;
}


template <typename ValueT>
inline LengthType IndirectContainerCursor<ValueT>::relative(const IndirectContainerCursor<ValueT>& target) const noexcept {
    DD_ASSERT(m_target && target.m_target)
    return m_target - target.m_target;
}


template <typename ValueT>
inline IndirectContainerCursor<ValueT>& IndirectContainerCursor<ValueT>::move(LengthType step) noexcept {
    DD_ASSERT(m_target)
    m_target += step;
    return *this;
}


template <typename ValueT>
inline IndirectContainerCursor<ValueT>& IndirectContainerCursor<ValueT>::operator ++() noexcept {
    DD_ASSERT(m_target)
    ++m_target;
    return *this;
}

template <typename ValueT>
inline IndirectContainerCursor<ValueT> IndirectContainerCursor<ValueT>::operator ++(IntSignType) noexcept {
    DD_ASSERT(m_target)
    auto tmp = *this;
    ++m_target;
    return tmp;
}


template <typename ValueT>
inline IndirectContainerCursor<ValueT>& IndirectContainerCursor<ValueT>::operator --() noexcept {
    DD_ASSERT(m_target)
    --m_target;
    return *this;
}

template <typename ValueT>
inline IndirectContainerCursor<ValueT> IndirectContainerCursor<ValueT>::operator --(IntSignType) noexcept {
    DD_ASSERT(m_target)
    auto tmp = *this;
    --m_target;
    return tmp;
}


template <typename ValueT>
inline IndirectContainerCursor<ValueT>& IndirectContainerCursor<ValueT>::operator +=(LengthType step) noexcept {
    return move(step);
}


template <typename ValueT>
inline IndirectContainerCursor<ValueT>& IndirectContainerCursor<ValueT>::operator -=(LengthType step) noexcept {
    return move(-step);
}


template <typename ValueT>
inline ValueT& IndirectContainerCursor<ValueT>::operator *() const noexcept {
    DD_ASSERT(m_target)
    return **m_target;
}


template <typename ValueT>
inline ValueT* IndirectContainerCursor<ValueT>::operator ->() const noexcept {
    DD_ASSERT(m_target)
    return *m_target;
}


template <typename ValueT>
inline ValueT& IndirectContainerCursor<ValueT>::operator [](SubscriptType index) const noexcept {
    DD_ASSERT(m_target)
    return *m_target[index];
}


template <typename ValueT>
inline IndirectContainerCursor<ValueT>::operator ValidityType() const noexcept {
    return m_target;
}


template <typename ValueT>
inline FListCursor<ValueT>::FListCursor(const FListBase<ValueT>& target) noexcept : m_target(target.m_first.get_address()) {
}


template <typename ValueT>
inline ValidityType FListCursor<ValueT>::equal(const FListCursor<ValueT>& target) const noexcept {
    return this->m_target = target.m_target;
}


template <typename ValueT>
inline FListCursor<ValueT>& FListCursor<ValueT>::operator ++() noexcept {
    DD_ASSERT(m_target)
    this->m_target = m_target->next;
    return *this;
}

template <typename ValueT>
inline FListCursor<ValueT> FListCursor<ValueT>::operator ++(IntSignType) noexcept {
    DD_ASSERT(m_target)
    auto tmp = *this;
    this->m_target = m_target->next;
    return tmp;
}


template <typename ValueT>
inline ValueT& FListCursor<ValueT>::operator *() const noexcept {
    DD_ASSERT(m_target)
    return m_target->value;
}


template <typename ValueT>
inline ValueT* FListCursor<ValueT>::operator ->() const noexcept {
    DD_ASSERT(m_target)
    return &m_target->value;
}


template <typename ValueT>
inline FListCursor<ValueT>::operator ValidityType() const noexcept {
    return m_target;
}


template <typename ContainerT>
inline ContainerSCursor<ContainerT>::ContainerSCursor() noexcept : m_binding(nullptr), m_index(0) {
}

template <typename ContainerT>
inline ContainerSCursor<ContainerT>::ContainerSCursor(const ContainerSCursor<ContainerT>& origin) noexcept : m_binding(origin.m_binding), m_index(origin.m_index) {
}

template <typename ContainerT>
inline ContainerSCursor<ContainerT>::ContainerSCursor(ContainerT& container, SubscriptType index) noexcept : m_binding(&container), m_index(index) {
}


template <typename ContainerT>
inline ValidityType ContainerSCursor<ContainerT>::equal(const ContainerSCursor<ContainerT>& target) const noexcept {
    return m_binding == target.m_binding && m_index == target.m_index;
}


template <typename ContainerT>
inline DDCompareResult ContainerSCursor<ContainerT>::compare(const ContainerSCursor<ContainerT>& target) const {
    if (m_binding != target.m_binding) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Failed to compare SCursor binded to different container. ");
    }
    return DD::compare(m_index, target.m_index);
}


template <typename ContainerT>
inline typename ContainerT::ValueType* ContainerSCursor<ContainerT>::get_address() const noexcept {
    return &m_binding->at(m_index);
}


template <typename ContainerT>
inline LengthType ContainerSCursor<ContainerT>::relative(const ContainerSCursor<ContainerT>& target) const {
    if (m_binding != target.m_binding) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Failed to position SCursor binded to different container. ");
    }
    return m_index - target.m_index;
}


template <typename ContainerT>
inline ContainerSCursor<ContainerT>& ContainerSCursor<ContainerT>::move(LengthType step) noexcept {
    m_index += step;
    return *this;
}


template <typename ContainerT>
inline ContainerSCursor<ContainerT>& ContainerSCursor<ContainerT>::operator ++() noexcept {
    ++m_index;
    return *this;
}

template <typename ContainerT>
inline ContainerSCursor<ContainerT> ContainerSCursor<ContainerT>::operator ++(IntSignType) noexcept {
    auto tmp = *this;
    ++m_index;
    return tmp;
}


template <typename ContainerT>
inline ContainerSCursor<ContainerT>& ContainerSCursor<ContainerT>::operator --() noexcept {
    --m_index;
    return *this;
}

template <typename ContainerT>
inline ContainerSCursor<ContainerT> ContainerSCursor<ContainerT>::operator --(IntSignType) noexcept {
    auto tmp = *this;
    --m_index;
    return tmp;
}


template <typename ContainerT>
inline ContainerSCursor<ContainerT>& ContainerSCursor<ContainerT>::operator +=(LengthType step) noexcept {
    return move(step);
}


template <typename ContainerT>
inline ContainerSCursor<ContainerT>& ContainerSCursor<ContainerT>::operator -=(LengthType step) noexcept {
    return move(-step);
}


template <typename ContainerT>
inline typename ContainerT::ValueType& ContainerSCursor<ContainerT>::operator *() const {
    if (!m_binding) {
        throw DDError(DDErrorType::ACCESS_DENIED, "No container binded to this SCursor. ");
    }
    return m_binding->at(m_index);
}


template <typename ContainerT>
inline typename ContainerT::ValueType* ContainerSCursor<ContainerT>::operator ->() const {
    if (!m_binding) {
        throw DDError(DDErrorType::ACCESS_DENIED, "No container binded to this SCursor. ");
    }
    return &m_binding->at(m_index);
}


template <typename ContainerT>
inline typename ContainerT::ValueType& ContainerSCursor<ContainerT>::operator [](SubscriptType index) const {
    if (!m_binding) {
        throw DDError(DDErrorType::ACCESS_DENIED, "No container binded to this SCursor. ");
    }
    return m_binding->at(m_index + index);
}


template <typename ContainerT>
inline ContainerSCursor<ContainerT>::operator ValidityType() const noexcept {
    return m_binding;
}


DDIMPLEMENT_END


DD_END



#endif