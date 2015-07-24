// DDTuple.hpp
#ifndef _DDTUPLE_
 #define _DDTUPLE_



 #include "DDTool.hpp"
 #include "DDMemory.hpp"



 #define DDTUPLE_MEMBER(...) template <typename... ValuesT> __VA_ARGS__ DDTuple<ValuesT...>



DD_BEGIN
DDIMPLEMENT_BEGIN
template <SubscriptType SubscriptT, typename ValueT, typename... ValuesT>
struct DDTupleImplement;
template <SubscriptType SubscriptT, typename ValueT>
struct DDTupleImplement<SubscriptT, ValueT>;


//template <typename ValueT>


DDIMPLEMENT_END


template <typename... ValuesT>
struct DDTuple;
template <>
struct DDTuple<>;

template <typename ValueT>
struct DDIsTuple;
template <typename... ValuesT>
struct DDIsTuple<DDTuple<ValuesT...>>;


template <typename... ValuesT>
constexpr DDTuple<RemoveReference<ValuesT>...> make_tuple(ValuesT&&... values);

template <SubscriptType SubscriptT, typename ValueT>
ValueT& get(typename DDImplement::DDTupleImplement<SubscriptT, ValueT>& tuple) noexcept;
template <SubscriptType SubscriptT, typename ValueT>
ValueT const& get(typename DDImplement::DDTupleImplement<SubscriptT, ValueT> const& tuple) noexcept;


DDIMPLEMENT_BEGIN
template <SubscriptType SubscriptT, typename ValueT, typename... ValuesT>
struct DDTupleImplement : public DDTupleImplement<SubscriptT, ValueT>, public DDTupleImplement<SubscriptT + 1, ValuesT...> {
    public:
    using ValueType = ValueT;
    
    protected:
    DDTupleImplement() = default;
    DDTupleImplement(DDTupleImplement<SubscriptT, ValueT, ValuesT...> const& origin) = default;
    DDTupleImplement(DDTupleImplement<SubscriptT, ValueT, ValuesT...>&& origin) = default;
    DDTupleImplement(ValueT&& value, ValuesT&&... values);
    
    public:
    ValidityType equal(DDTupleImplement<SubscriptT, ValueT, ValuesT...> const& target) const;
    template <typename ValueT_, typename... ValuesT_>
    constexpr ValidityType equal(DDTupleImplement<SubscriptT, ValueT_, ValuesT_...> const& target) const;
    
    public:
    static constexpr SubscriptType index = SubscriptT;
    
};

template <SubscriptType SubscriptT, typename ValueT>
struct DDTupleImplement<SubscriptT, ValueT> {
    public:
    using ValueType = ValueT;
    
    public:
    friend ValueT& DD::get<SubscriptT, ValueT>(DDTupleImplement<SubscriptT, ValueT>& tuple);
    friend ValueT const& DD::get<SubscriptT, ValueT>(DDTupleImplement<SubscriptT, ValueT> const& tuple);
    
    protected:
    DDTupleImplement();
    DDTupleImplement(DDTupleImplement<SubscriptT, ValueT> const& origin);
    DDTupleImplement(DDTupleImplement<SubscriptT, ValueT>&& origin);
    DDTupleImplement(ValueT&& value);
    
    public:
    ValidityType equal(DDTupleImplement<SubscriptT, ValueT> const& target) const;
    template <typename ValueT_>
    constexpr ValidityType equal(DDTupleImplement<SubscriptT, ValueT_> const& target) const;
    DDCompareResult compare(DDTupleImplement<SubscriptT, ValueT> const& target) const;
    template <typename... ValuesT_>
    DDCompareResult compare(DDTupleImplement<SubscriptT, ValueT, ValuesT_...> const& target) const;
    
    public:
    static constexpr SubscriptType index = SubscriptT;
    
    private:
    DDUPointer<ValueT> m_value;
    
};


DDIMPLEMENT_END


template <typename... ValuesT>
struct DDTuple : public DDImplement::DDTupleImplement<0, ValuesT...> {
    public:
    DDTuple() = default;
    DDTuple(DDTuple<ValuesT...> const& origin) = default;
    DDTuple(DDTuple<ValuesT...>&& origin) = default;
    DDTuple(ValuesT&&... values);
    template <SubscriptType SubscriptT_>
    auto at() noexcept -> decltype(DD::get<SubscriptT_>(*this));
    template <SubscriptType SubscriptT_>
    auto at() const noexcept -> decltype(DD::get<SubscriptT_>(*this));
    
    public:
    static constexpr LengthType length = sizeof...(ValuesT);
    
};

template <>
struct DDTuple<> {
    public:
    DDTuple() = default;
    DDTuple(DDTuple<> const& origin) = default;
    DDTuple(DDTuple<>&& origin) = default;
    
    public:
    DDTuple<>& operator =(DDTuple<> const& origin) = default;
    DDTuple<>& operator =(DDTuple<>&& origin) = default;
    
    public:
    static constexpr LengthType length = 0;
    
};


template <typename ValueT>
struct DDIsTuple : public DDFalseType {
};

template <typename... ValuesT>
struct DDIsTuple<DDTuple<ValuesT...>> : public DDTrueType {
};


DD_END



DD_BEGIN
template <typename... ValuesT>
inline constexpr DDTuple<RemoveReference<ValuesT>...> make_tuple(ValuesT&&... values) {
    return DDTuple<RemoveReference<ValuesT>...>(DD::forward<ValuesT>(values)...);
}


template <SubscriptType SubscriptT, typename ValueT>
inline ValueT& get(typename DDImplement::DDTupleImplement<SubscriptT, ValueT>& tuple) noexcept {
    return *tuple.m_value;
}

template <SubscriptType SubscriptT, typename ValueT>
inline ValueT const& get(typename DDImplement::DDTupleImplement<SubscriptT, ValueT> const& tuple) noexcept {
    return *tuple.m_value;
}


DDIMPLEMENT_BEGIN
template <SubscriptType SubscriptT, typename ValueT, typename... ValuesT>
DDTupleImplement<SubscriptT, ValueT, ValuesT...>::DDTupleImplement(ValueT&& value, ValuesT&&... values) : DDTupleImplement<SubscriptT, ValueT>(DD::forward<ValueT>(value)), DDTupleImplement<SubscriptT + 1, ValuesT...>(DD::forward<ValuesT>(values)...) {
}


template <SubscriptType SubscriptT, typename ValueT, typename... ValuesT>
inline ValidityType DDTupleImplement<SubscriptT, ValueT, ValuesT...>::equal(DDTupleImplement<SubscriptT, ValueT, ValuesT...> const& target) const {
    return DDTupleImplement<SubscriptT, ValueT>::equal(target) && DDTupleImplement<SubscriptT + 1, ValuesT...>::equal(target);
}


template <SubscriptType SubscriptT, typename ValueT, typename... ValuesT> template <typename ValueT_, typename... ValuesT_>
constexpr ValidityType DDTupleImplement<SubscriptT, ValueT, ValuesT...>::equal(DDTupleImplement<SubscriptT, ValueT_, ValuesT_...> const& target) const {
    return false;
}


template <SubscriptType SubscriptT, typename ValueT>
inline DDTupleImplement<SubscriptT, ValueT>::DDTupleImplement() : m_value(new ValueT()) {
}

template <SubscriptType SubscriptT, typename ValueT>
inline DDTupleImplement<SubscriptT, ValueT>::DDTupleImplement(DDTupleImplement<SubscriptT, ValueT> const& origin) : m_value(new ValueT(*origin.m_value)) {
}

template <SubscriptType SubscriptT, typename ValueT>
inline DDTupleImplement<SubscriptT, ValueT>::DDTupleImplement(DDTupleImplement<SubscriptT, ValueT>&& origin) : m_value(DD::move(origin.m_value)) {
}

template <SubscriptType SubscriptT, typename ValueT>
inline DDTupleImplement<SubscriptT, ValueT>::DDTupleImplement(ValueT&& value) : m_value(new ValueT(DD::forward<ValueT>(value))) {
}


template <SubscriptType SubscriptT, typename ValueT>
inline ValidityType DDTupleImplement<SubscriptT, ValueT>::equal(DDTupleImplement<SubscriptT, ValueT> const& target) const {
    return *this->m_value == *target.m_value;
}

template <SubscriptType SubscriptT, typename ValueT> template <typename ValueT_>
constexpr ValidityType DDTupleImplement<SubscriptT, ValueT>::equal(DDTupleImplement<SubscriptT, ValueT_> const& target) const {
    return false;
}


template <SubscriptType SubscriptT, typename ValueT>
inline DDCompareResult DDTupleImplement<SubscriptT, ValueT>::compare(DDTupleImplement<SubscriptT, ValueT> const& target) const {
    return DD::compare(*this->m_value, *target.m_value);
}

template <SubscriptType SubscriptT, typename ValueT> template <typename... ValuesT_>
inline DDCompareResult DDTupleImplement<SubscriptT, ValueT>::compare(DDTupleImplement<SubscriptT, ValueT, ValuesT_...> const& target) const {
    auto result = this->compare(static_cast<DDTupleImplement<SubscriptT, ValueT>>(target));
    return result == DDCompareResult::EQUAL ? DDCompareResult::LESS : result;
}


DDIMPLEMENT_END


DDTUPLE_MEMBER(inline)::DDTuple(ValuesT&&... values) : DDImplement::DDTupleImplement<0, ValuesT...>(DD::forward<ValuesT>(values)...) {
}


DDTUPLE_MEMBER(template <SubscriptType SubscriptT_> inline auto)::at() noexcept -> decltype(DD::get<SubscriptT_>(*this)) {
    return DD::get<SubscriptT_>(*this);
}

DDTUPLE_MEMBER(template <SubscriptType SubscriptT_> inline auto)::at() const noexcept -> decltype(DD::get<SubscriptT_>(*this)) {
    return DD::get<SubscriptT_>(*this);
}


DD_END



 #undef DDTUPLE_MEMBER



#endif