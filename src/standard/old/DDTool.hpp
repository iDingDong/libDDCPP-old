#ifndef _DDTOOL_
 #define _DDTOOL_



 #include "DDTraits.hpp"



DD_BEGIN
template <ValidityType ConditionT, typename ThenT, typename ElseT>
using DDStaticIf = DDConditional<ConditionT, ThenT, ElseT>;


DDIMPLEMENT_BEGIN
template <typename ObjectT>
struct Matcher;

template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
class TypeCompare;
template <typename ObjectT1, typename ObjectT2>
class TypeCompare<ObjectT1, ObjectT2>;
template <typename ObjectT>
class TypeCompare<ObjectT, ObjectT>; 

template <typename ObjectT>
class IsContainer;

template <typename ObjectT, ValidityType IsContainerT>
class DimentionCount;
template <typename ObjectT>
class DimentionCount<ObjectT, true>;


DDIMPLEMENT_END


constexpr SizeType size_distance(GlobalPointerType pointer_1, GlobalPointerType pointer_2) noexcept(true);

template <typename ValueT>
ValueT* address_of(ValueT& target) noexcept(true);

template <typename ObjectT>
ProcessType swap(ObjectT& object_1, ObjectT& object_2) noexcept(DDIsNoexceptSwapable<ObjectT>::value);// To optimize

template <typename ObjectT>
RemoveReference<ObjectT>&& move(ObjectT&& origin) noexcept;

template <typename ObjectT>
ObjectT&& forward(RemoveReference<ObjectT>& origin) noexcept;
template <typename ObjectT>
ObjectT&& forward(RemoveReference<ObjectT>&& origin) noexcept;

template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
constexpr ValidityType is_same_type();
template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
constexpr ValidityType is_same_type(ObjectT1 const&, ObjectT2 const&, ObjectsT&&...);

template <typename ObjectT1, typename ObjectT2>
constexpr ValidityType is_type(ObjectT2 const&);

template <typename ObjectT>
constexpr ValidityType is_container();
template <typename ObjectT>
constexpr ValidityType is_container(ObjectT const&);


template <typename ObjectT>
constexpr QuantityType count_dimention();
template <typename ObjectT>
constexpr QuantityType count_dimention(ObjectT const&);


template <typename ObjectT>
ObjectT const& minimum(ObjectT const& object_1, ObjectT const& object_2);
template <typename ObjectT, typename... ObjectsT>
ObjectT const& minimum(ObjectT const& object_1, ObjectT const& object_2, ObjectsT&&... objects);

template <typename ObjectT>
ObjectT const& maximum(ObjectT const& object_1, ObjectT const& object_2);
template <typename ObjectT, typename... ObjectsT>
ObjectT const& maximum(ObjectT const& object_1, ObjectT const& object_2, ObjectsT&&... objects);


DDIMPLEMENT_BEGIN
template <typename ObjectT>
struct Matcher {
    public:
    using ObjectType = ObjectT;
    
};


template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
class TypeCompare final {
    public:
    static constexpr ValidityType result = TypeCompare<ObjectT1, ObjectT2>::result && TypeCompare<ObjectT2, ObjectsT...>::result;
    
};

template <typename ObjectT1, typename ObjectT2>
class TypeCompare<ObjectT1, ObjectT2> final {
    public:
    static constexpr ValidityType result = false;
    
};

template <typename ObjectT>
class TypeCompare<ObjectT, ObjectT> final {
    public:
    static constexpr ValidityType result = true;
    
};


template <typename ObjectT>
class IsContainer final {
    private:
    template <typename ObjectT_>
    static constexpr ValidityType judge(Matcher<typename ObjectT_::IsContainer>*);
    template <typename ObjectT_>
    static constexpr ValidityType judge(...);
    
    public:
    static constexpr ValidityType result = judge<ObjectT>(nullptr);
    
};


template <typename ObjectT, ValidityType IsContainerT>
class DimentionCount final {
    public:
    static constexpr QuantityType result = 0;
    
};

template <typename ObjectT>
class DimentionCount<ObjectT, true> final {
    public:
    static constexpr QuantityType result = DimentionCount<typename ObjectT::ValueType, DD::is_container<typename ObjectT::ValueType>()>::result + 1;
    
};


DDIMPLEMENT_END


DD_END



DD_BEGIN
inline constexpr SizeType size_distance(GlobalPointerType pointer_1, GlobalPointerType pointer_2) noexcept(true) {
    return static_cast<char*>(pointer_2) - static_cast<char*>(pointer_1);
}


template <typename ValueT>
ValueT* address_of(ValueT& target) noexcept(true) {
    return reinterpret_cast<ValueT*>(&const_cast<char&>(reinterpret_cast<char const volatile&>(target)));
}


template <typename ObjectT>
inline ProcessType swap(ObjectT& object_1, ObjectT& object_2) noexcept(DDIsNoexceptSwapable<ObjectT>::value) {
    auto temp_object(DD::move(object_1));
    object_1.~ObjectT();
    new (DD::address_of(object_1)) ObjectT(DD::move(object_2));
    object_2.~ObjectT();
    new (DD::address_of(object_2)) ObjectT(DD::move(temp_object));
    return;
}


template <typename ObjectT>
inline RemoveReference<ObjectT>&& move(ObjectT&& origin) noexcept {
    return static_cast<RemoveReference<ObjectT>&&>(origin);
}


template <typename ObjectT>
inline ObjectT&& forward(RemoveReference<ObjectT>& origin) noexcept {
    return static_cast<ObjectT&&>(origin);
}

template <typename ObjectT>
inline ObjectT&& forward(RemoveReference<ObjectT>&& origin) noexcept {
    static_assert(!DDIsLvalueReference<ObjectT>::value, "Template argument substituting 'ObjectT' is an lvalue reference type");
    return static_cast<ObjectT&&>(origin);
}


template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
constexpr ValidityType is_same_type() {
    return DDImplement::TypeCompare<ObjectT1, ObjectT2, ObjectsT...>::result;
}

template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
constexpr ValidityType is_same_type(ObjectT1 const&, ObjectT2 const&, ObjectsT&&...) {
    return is_same_type<ObjectT1, ObjectT2, ObjectsT...>();
}


template <typename ObjectT1, typename ObjectT2>
constexpr ValidityType is_type(ObjectT2 const&) {
    return is_same_type<ObjectT1, ObjectT2>();
}


template <typename ObjectT>
constexpr ValidityType is_container() {
    return DDImplement::IsContainer<ObjectT>::result;
}

template <typename ObjectT>
constexpr ValidityType is_container(ObjectT const&) {
    return is_container<ObjectT>();
}


template <typename ObjectT>
constexpr QuantityType count_dimention() {
    return DDImplement::DimentionCount<ObjectT, is_container<ObjectT>()>::result;
}

template <typename ObjectT>
constexpr QuantityType count_dimention(ObjectT const&) {
    return count_dimention<ObjectT>();
}


template <typename ObjectT>
inline ObjectT const& minimum(ObjectT const& object_1, ObjectT const& object_2) {
    return object_1 < object_2 ? object_1 : object_2;
}

template <typename ObjectT, typename... ObjectsT>
ObjectT const& minimum(ObjectT const& object_1, ObjectT const& object_2, ObjectsT&&... objects) {
    return minimum(object_1, minimum(object_2, objects...));
}


template <typename ObjectT>
inline ObjectT const& maximum(ObjectT const& object_1, ObjectT const& object_2) {
    return object_2 < object_1 ? object_1 : object_2;
}

template <typename ObjectT, typename... ObjectsT>
ObjectT const& maximum(ObjectT const& object_1, ObjectT const& object_2, ObjectsT&&... objects) {
    return maximum(object_1, maximum(object_2, objects...));
}


DDIMPLEMENT_BEGIN
template <typename ObjectT> template <typename ObjectT_>
constexpr ValidityType IsContainer<ObjectT>::judge(Matcher<typename ObjectT_::IsContainer>*) {
    return true;
}

template <typename ObjectT> template <typename ObjectT_>
constexpr ValidityType IsContainer<ObjectT>::judge(...) {
    return false;
}


DDIMPLEMENT_END


DD_END



#endif