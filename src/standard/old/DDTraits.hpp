// DDTraits.hpp
#ifndef _DDTRAITS_
 #define _DDTRAITS_



 #include "DDGlobal.hpp"
 #include <type_traits>



DD_BEGIN
template <typename ObjectT>
struct DDTraits;

template <typename ObjectT, ObjectT value_c>
struct DDIntegralConstant;

template <ValidityType condition_c, typename ThenT, typename ElseT>
struct DDConditional;
template <typename ThenT, typename ElseT>
struct DDConditional<false, ThenT, ElseT>;

template <typename... ConditionsT>
struct DDOr;
template <>
struct DDOr<>;
template <typename ConditionT>
struct DDOr<ConditionT>;
template <typename ConditionT1, typename ConditionT2>
struct DDOr<ConditionT1, ConditionT2>;
template <typename ConditionT1, typename ConditionT2, typename ConditionT3, typename... ConditionsT>
struct DDOr<ConditionT1, ConditionT2, ConditionT3, ConditionsT...>;

template <typename... ConditionsT>
struct DDAnd;
template <>
struct DDAnd<>;
template <typename ConditionT>
struct DDAnd<ConditionT>;
template <typename ConditionT1, typename ConditionT2>
struct DDAnd<ConditionT1, ConditionT2>;
template <typename ConditionT1, typename ConditionT2, typename ConditionT3, typename... ConditionsT>
struct DDAnd<ConditionT1, ConditionT2, ConditionT3, ConditionsT...>;

template <typename ConditionT>
struct DDNot;

DDIMPLEMENT_BEGIN
template <typename ObjectT>
struct DDIsVoid_;
template <>
struct DDIsVoid_<void>;

template <typename ObjectT>
struct DDIsIntegral_;
template <>
struct DDIsIntegral_<bool>;
template <>
struct DDIsIntegral_<char>;
template <>
struct DDIsIntegral_<unsigned char>;
template <>
struct DDIsIntegral_<signed char>;
template <>
struct DDIsIntegral_<wchar_t>;
template <>
struct DDIsIntegral_<char16_t>;
template <>
struct DDIsIntegral_<char32_t>;
template <>
struct DDIsIntegral_<unsigned short>;
template <>
struct DDIsIntegral_<short>;
template <>
struct DDIsIntegral_<unsigned int>;
template <>
struct DDIsIntegral_<int>;
template <>
struct DDIsIntegral_<unsigned long>;
template <>
struct DDIsIntegral_<long>;
template <>
struct DDIsIntegral_<unsigned long long>;
template <>
struct DDIsIntegral_<long long>;

template <typename ObjectT>
struct DDIsFloatingPoint_;
template <>
struct DDIsFloatingPoint_<float>;
template <>
struct DDIsFloatingPoint_<double>;
template <>
struct DDIsFloatingPoint_<long double>;

template <typename ObjectT>
struct DDIsArray_;
template <typename ObjectT, LengthType length_c>
struct DDIsArray_<ObjectT[length_c]>;
template <typename ObjectT>
struct DDIsArray_<ObjectT[]>;

template <typename ObjectT>
struct DDIsPointer_;
template <typename ObjectT>
struct DDIsPointer_<ObjectT*>;
template <>
struct DDIsPointer_<std::nullptr_t>;

template <typename ObjectT>
struct DDIsFunction_;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...)>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...)>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) volatile>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const volatile>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) volatile>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const volatile>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) &>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) volatile&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const volatile&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) &>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) volatile&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const volatile&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) &&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const&&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) volatile&&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const volatile&&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) &&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const&&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) volatile&&>;
template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const volatile&&>;

template <typename ObjectT>
struct DDIsMemberFunctionPointer_;
template <typename ObjectT, typename ClassT>
struct DDIsMemberFunctionPointer_<ObjectT ClassT::*>;

template <typename ObjectT>
struct DDIsMemberObjectPointer_;
template <typename ObjectT, typename ClassT>
struct DDIsMemberObjectPointer_<ObjectT ClassT::*>;

template <typename ObjectT>
struct DDIsLvalueReference_;
template <typename ObjectT>
struct DDIsLvalueReference_<ObjectT&>;

template <typename ObjectT>
struct DDIsRvalueReference_;
template <typename ObjectT>
struct DDIsRvalueReference_<ObjectT&&>;

template <typename ObjectT>
struct DDIsConst_;
template <typename ObjectT>
struct DDIsConst_<ObjectT const>;

template <typename ObjectT>
struct DDIsVolatile_;
template <typename ObjectT>
struct DDIsVolatile_<ObjectT volatile>;

template <typename ObjectT>
struct DDIsNoexceptMoveConstructible_;

DDIMPLEMENT_END

template <typename... ObjectsT>
struct DDIsVoid;

template <typename... ObjectsT>
struct DDIsIntegral;

template <typename... ObjectsT>
struct DDIsFloatingPoint;

template <typename... ObjectsT>
struct DDIsArray;

template <typename... ObjectsT>
struct DDIsPointer;

template <typename... ObjectsT>
struct DDIsFunction;

template <typename... ObjectsT>
struct DDIsMemberObjectPointer;

template <typename... ObjectsT>
struct DDIsMemberFunctionPointer;

template <typename... ObjectsT>
struct DDIsLvalueReference;

template <typename... ObjectsT>
struct DDIsRvalueReference;

template <typename... ObjectsT>
struct DDIsConst;

template <typename... ObjectsT>
struct DDIsVolatile;

template <typename... ObjectsT>
struct DDIsScalar;

template <typename... ObjectsT>
struct DDIsTriviallyDestructible;// Bad realization

template <typename... ObjectsT>
struct DDIsTriviallyCopyAssignable;// Bad realization

template <typename... ObjectsT>
struct DDIsNoexceptMoveConstructible;// Bad realization

template <typename... ObjectsT>
struct DDIsNoexceptSwapable;

template <typename... ObjectsT>
struct DDIsSame;
template <typename ObjectT>
struct DDIsSame<ObjectT, ObjectT>;
template <typename ObjectT1, typename ObjectT2>
struct DDIsSame<ObjectT1, ObjectT2>;
template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
struct DDIsSame<ObjectT1, ObjectT2, ObjectsT...>;

template <typename ObjectT>
struct DDRank;
template <typename ObjectT, LengthType length_c>
struct DDRank<ObjectT[length_c]>;
template <typename ObjectT>
struct DDRank<ObjectT[]>;

template <typename ObjectT>
struct DDAddLvalueReference;// Unrealized
template <typename ObjectT>
struct DDAddRvalueReference;// Unrealized

template <typename ObjectT>
struct DDRemoveReference;
template <typename ObjectT>
struct DDRemoveReference<ObjectT&>;
template <typename ObjectT>
struct DDRemoveReference<ObjectT&&>;

template <typename ObjectT>
struct DDAddConst;

template <typename ObjectT>
struct DDRemoveConst;
template <typename ObjectT>
struct DDRemoveConst<ObjectT const>;

template <typename ObjectT>
struct DDAddVolatile;

template <typename ObjectT>
struct DDRemoveVolatile;
template <typename ObjectT>
struct DDRemoveVolatile<ObjectT volatile>;

template <typename ObjectT>
struct DDAddCV;

template <typename ObjectT>
struct DDRemoveCV;

template <typename ObjectT>
struct DDRemoveExtent;
template <typename ObjectT, LengthType length_c>
struct DDRemoveExtent<ObjectT[length_c]>;
template <typename ObjectT>
struct DDRemoveExtent<ObjectT[]>;

template <typename ObjectT>
struct DDRemoveAllExtents;
template <typename ObjectT, LengthType length_c>
struct DDRemoveAllExtents<ObjectT[length_c]>;
template <typename ObjectT>
struct DDRemoveAllExtents<ObjectT[]>;

template <typename ObjectT>
struct DDAddPointer;

template <typename ObjectT>
struct DDRemovePointer;
template <typename ObjectT>
struct DDRemovePointer<ObjectT*>;
template <typename ObjectT>
struct DDRemovePointer<ObjectT* const>;
template <typename ObjectT>
struct DDRemovePointer<ObjectT* volatile>;
template <typename ObjectT>
struct DDRemovePointer<ObjectT* const volatile>;

//template <typename ObjectT>
//struct DDDecay;


template <bool value_c>
using DDBoolConstant = DDIntegralConstant<bool, value_c>;
using DDTrueType = DDBoolConstant<true>;
using DDFalseType = DDBoolConstant<false>;

template <LengthType quantity_c>
using DDLengthConstant = DDIntegralConstant<LengthType, quantity_c>;

template <ValidityType condition_c, typename ThenT, typename ElseT>
using Conditional = typename DDConditional<condition_c, ThenT, ElseT>::Type;

template <typename... ConditionsT>
using Or = typename DDOr<ConditionsT...>::Type;
template <typename... ConditionsT>
using And = typename DDAnd<ConditionsT...>::Type;
template <typename ConditionT>
using Not = typename DDNot<ConditionT>::Type;

template <typename ObjectT>
using AddLvalueReference = typename DDAddLvalueReference<ObjectT>::Type;
template <typename ObjectT>
using AddRvalueReference = typename DDAddRvalueReference<ObjectT>::Type;

template <typename ObjectT>
using RemoveReference = typename DDRemoveReference<ObjectT>::Type;

template <typename ObjectT>
using AddConst = typename DDAddConst<ObjectT>::Type;
template <typename ObjectT>
using RemoveConst = typename DDRemoveConst<ObjectT>::Type;

template <typename ObjectT>
using AddVolatile = typename DDAddVolatile<ObjectT>::Type;
template <typename ObjectT>
using RemoveVolatile = typename DDRemoveVolatile<ObjectT>::Type;

template <typename ObjectT>
using AddCV = typename DDAddCV<ObjectT>::Type;
template <typename ObjectT>
using RemoveCV = typename DDRemoveCV<ObjectT>::Type;

template <typename ObjectT>
using RemoveExtent = typename DDRemoveExtent<ObjectT>::Type;

template <typename ObjectT>
using RemoveAllExtents = typename DDRemoveAllExtents<ObjectT>::Type;

template <typename ObjectT>
using AddPointer = typename DDAddPointer<ObjectT>::Type;
template <typename ObjectT>
using RemovePointer = typename DDRemovePointer<ObjectT>::Type;

template <typename StdIntegralT>
using StdIntegralConstant = DDIntegralConstant<typename StdIntegralT::value_type, StdIntegralT::value>;


template <typename ObjectT>
struct DDTraits {
    public:
    using Type = ObjectT;
    
};


template <typename ObjectT, ObjectT value_c>
struct DDIntegralConstant {
    public:
    using ValueType = ObjectT;
    using Type = DDIntegralConstant<ObjectT, value_c>;
    
    public:
    constexpr operator ObjectT() noexcept;
    
    public:
    static constexpr ObjectT value = value_c;
    
};


template <ValidityType ConditionT, typename ThenT, typename ElseT>
struct DDConditional {
    public:
    using Type = ElseT;
    
};

template <typename ThenT, typename ElseT>
struct DDConditional<true, ThenT, ElseT> {
    public:
    using Type = ThenT;
    
};


template <>
struct DDOr<> : public DDFalseType {
};

template <typename ConditionT>
struct DDOr<ConditionT> : public ConditionT::Type {
};

template <typename ConditionT1, typename ConditionT2>
struct DDOr<ConditionT1, ConditionT2> : public Conditional<ConditionT1::value, ConditionT1, ConditionT2> {
};

template <typename ConditionT1, typename ConditionT2, typename ConditionT3, typename... ConditionsT>
struct DDOr<ConditionT1, ConditionT2, ConditionT3, ConditionsT...> : public Conditional<ConditionT1::value, ConditionT1, DDOr<ConditionT2, ConditionT3, ConditionsT...>> {
};


template <>
struct DDAnd<> : public DDTrueType {
};

template <typename ConditionT>
struct DDAnd<ConditionT> : public ConditionT::Type {
};

template <typename ConditionT1, typename ConditionT2>
struct DDAnd<ConditionT1, ConditionT2> : public Conditional<ConditionT1::value, ConditionT2, ConditionT1> {
};

template <typename ConditionT1, typename ConditionT2, typename ConditionT3, typename... ConditionsT>
struct DDAnd<ConditionT1, ConditionT2, ConditionT3, ConditionsT...> : public Conditional<ConditionT1::value, DDAnd<ConditionT2, ConditionT3, ConditionsT...>, ConditionT1> {
};


template <typename ConditionT>
struct DDNot : public DDIntegralConstant<ValidityType, !ConditionT::value> {
};


DDIMPLEMENT_BEGIN
template <typename ObjectT>
struct DDIsVoid_ : public StdIntegralConstant<std::is_void<ObjectT>> {
};

template <>
struct DDIsVoid_<void> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsIntegral_ : public StdIntegralConstant<std::is_integral<ObjectT>> {
};

template <>
struct DDIsIntegral_<bool> : public DDTrueType {
};

template <>
struct DDIsIntegral_<char> : public DDTrueType {
};

template <>
struct DDIsIntegral_<unsigned char> : public DDTrueType {
};

template <>
struct DDIsIntegral_<signed char> : public DDTrueType {
};

template <>
struct DDIsIntegral_<wchar_t> : public DDTrueType {
};

template <>
struct DDIsIntegral_<char16_t> : public DDTrueType {
};

template <>
struct DDIsIntegral_<char32_t> : public DDTrueType {
};

template <>
struct DDIsIntegral_<unsigned short> : public DDTrueType {
};

template <>
struct DDIsIntegral_<short> : public DDTrueType {
};

template <>
struct DDIsIntegral_<unsigned> : public DDTrueType {
};

template <>
struct DDIsIntegral_<int> : public DDTrueType {
};

template <>
struct DDIsIntegral_<unsigned long> : public DDTrueType {
};

template <>
struct DDIsIntegral_<long> : public DDTrueType {
};

template <>
struct DDIsIntegral_<unsigned long long> : public DDTrueType {
};

template <>
struct DDIsIntegral_<long long> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsFloatingPoint_ : public StdIntegralConstant<std::is_floating_point<ObjectT>> {
};

template <>
struct DDIsFloatingPoint_<float> : public DDTrueType {
};

template <>
struct DDIsFloatingPoint_<double> : public DDTrueType {
};

template <>
struct DDIsFloatingPoint_<long double> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsArray_ : public StdIntegralConstant<std::is_array<ObjectT>> {
};

template <typename ObjectT, LengthType length_c>
struct DDIsArray_<ObjectT[length_c]> : public DDTrueType {
};

template <typename ObjectT>
struct DDIsArray_<ObjectT[]> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsPointer_ : public StdIntegralConstant<std::is_pointer<ObjectT>> {
};

template <typename ObjectT>
struct DDIsPointer_<ObjectT*> : public DDTrueType {
};

template <>
struct DDIsPointer_<std::nullptr_t> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsFunction_ : public StdIntegralConstant<std::is_function<ObjectT>> {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...)> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...)> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) volatile> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const volatile> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) volatile> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const volatile> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) &> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) volatile&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const volatile&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) &> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) volatile&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const volatile&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) &&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const&&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) volatile&&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT...) const volatile&&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) &&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const&&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) volatile&&> : public DDTrueType {
};

template <typename ValueT, typename... ArgumentsT>
struct DDIsFunction_<ValueT(ArgumentsT... ...) const volatile&&> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsMemberFunctionPointer_ : public StdIntegralConstant<std::is_member_function_pointer<ObjectT>> {
};

template <typename ObjectT, typename ClassT>
struct DDIsMemberFunctionPointer_<ObjectT ClassT::*> : public DDIsFunction<ObjectT> {
};


template <typename ObjectT>
struct DDIsMemberObjectPointer_ : public StdIntegralConstant<std::is_member_object_pointer<ObjectT>> {
};

template <typename ObjectT, typename ClassT>
struct DDIsMemberObjectPointer_<ObjectT ClassT::*> : public DDBoolConstant<!DDIsFunction<ObjectT>::value> {
};


template <typename ObjectT>
struct DDIsLvalueReference_ : public StdIntegralConstant<std::is_lvalue_reference<ObjectT>> {
};

template <typename ObjectT>
struct DDIsLvalueReference_<ObjectT&> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsRvalueReference_ : public StdIntegralConstant<std::is_rvalue_reference<ObjectT>> {
};

template <typename ObjectT>
struct DDIsRvalueReference_<ObjectT&&> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsConst_ : public StdIntegralConstant<std::is_const<ObjectT>> {
};

template <typename ObjectT>
struct DDIsConst_<ObjectT const> : public DDTrueType {
};


template <typename ObjectT>
struct DDIsVolatile_ : public StdIntegralConstant<std::is_volatile<ObjectT>> {
};

template <typename ObjectT>
struct DDIsVolatile_<ObjectT volatile> : DDTrueType {
};


template <typename ObjectT>
struct DDIsNoexceptMoveConstructible_ : public StdIntegralConstant<std::is_nothrow_move_constructible<ObjectT>> {
};


DDIMPLEMENT_END


template <typename... ObjectsT>
struct DDIsVoid : public And<DDImplement::DDIsVoid_<RemoveCV<ObjectsT>>...> {
};


template <typename... ObjectsT>
struct DDIsIntegral : public And<DDImplement::DDIsIntegral_<RemoveCV<ObjectsT>>...> {
};


template <typename... ObjectsT>
struct DDIsFloatingPoint : public And<DDImplement::DDIsFloatingPoint_<RemoveCV<ObjectsT>>...> {
};


template <typename... ObjectsT>
struct DDIsArray : public And<DDImplement::DDIsArray_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsPointer : public And<DDImplement::DDIsPointer_<DDRemoveCV<ObjectsT>>...> {
};


template <typename... ObjectsT>
struct DDIsMemberObjectPointer : public And<DDImplement::DDIsMemberObjectPointer_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsMemberFunctionPointer : public And<DDImplement::DDIsMemberFunctionPointer_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsFunction : public And<DDImplement::DDIsFunction_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsLvalueReference : public And<DDImplement::DDIsLvalueReference_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsRvalueReference : public And<DDImplement::DDIsRvalueReference_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsConst : public And<DDImplement::DDIsConst_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsVolatile : public And<DDImplement::DDIsVolatile_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsScalar : public DDOr<DDIsIntegral<ObjectsT>..., DDIsFloatingPoint<ObjectsT>..., DDIsPointer<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsTriviallyDestructible : public DDIsScalar<ObjectsT...> {
};


template <typename... ObjectsT>
struct DDIsTriviallyCopyAssignable : public DDIsScalar<ObjectsT...> {
};


template <typename... ObjectsT>
struct DDIsNoexceptMoveConstructible : public And<DDImplement::DDIsNoexceptMoveConstructible_<ObjectsT>...> {
};


template <typename... ObjectsT>
struct DDIsNoexceptSwapable : public DDIsNoexceptMoveConstructible<ObjectsT...> {
};


template <typename... ObjectsT>
struct DDIsSame : public DDTrueType {
};

template <typename ObjectT>
struct DDIsSame<ObjectT, ObjectT> : public DDTrueType {
};

template <typename ObjectT1, typename ObjectT2>
struct DDIsSame<ObjectT1, ObjectT2> : public StdIntegralConstant<std::is_same<ObjectT1, ObjectT2>> {
};

template <typename ObjectT1, typename ObjectT2, typename... ObjectsT>
struct DDIsSame<ObjectT1, ObjectT2, ObjectsT...> : public And<DDIsSame<ObjectT1, ObjectT2>, DDIsSame<ObjectT2, ObjectsT...>> {
};


template <typename ObjectT>
struct DDRank : public DDLengthConstant<0> {
};

template <typename ObjectT, LengthType length_c>
struct DDRank<ObjectT[length_c]> : public DDLengthConstant<DDRank<ObjectT>::value + 1> {
};

template <typename ObjectT>
struct DDRank<ObjectT[]> : public DDLengthConstant<DDRank<ObjectT>::value + 1> {
};


template <typename ObjectT>
struct DDRemoveReference {
    public:
    using Type = ObjectT;
    
};

template <typename ObjectT>
struct DDRemoveReference<ObjectT&> {
    public:
    using Type = ObjectT;
    
};

template <typename ObjectT>
struct DDRemoveReference<ObjectT&&> {
    public:
    using Type = ObjectT;
    
};


template <typename ObjectT>
struct DDAddConst {
    public:
    using Type = ObjectT const;
    
};


template <typename ObjectT>
struct DDRemoveConst {
    public:
    using Type = ObjectT;
    
};

template <typename ObjectT>
struct DDRemoveConst<ObjectT const> {
    public:
    using Type = ObjectT;
    
};


template <typename ObjectT>
struct DDAddVolatile {
    public:
    using Type = ObjectT volatile;
};


template <typename ObjectT>
struct DDRemoveVolatile {
    public:
    using Type = ObjectT;
    
};

template <typename ObjectT>
struct DDRemoveVolatile<ObjectT volatile> {
    public:
    using Type = ObjectT;
    
};


template <typename ObjectT>
struct DDAddCV {
    using Type = AddConst<AddVolatile<ObjectT>>;
};


template <typename ObjectT>
struct DDRemoveCV {
    public:
    using Type = RemoveConst<RemoveVolatile<ObjectT>>;
    
};


template <typename ObjectT>
struct DDRemoveExtent {
    public:
    using Type = ObjectT;
    
};

template <typename ObjectT, LengthType length_c>
struct DDRemoveExtent<ObjectT[length_c]> {
    public:
    using Type = ObjectT;
    
};

template <typename ObjectT>
struct DDRemoveExtent<ObjectT[]> {
    public:
    using Type = ObjectT;
    
};


template <typename ObjectT>
struct DDRemoveAllExtents {
    public:
    using Type = ObjectT;
    
};

template <typename ObjectT, LengthType length_c>
struct DDRemoveAllExtents<ObjectT[length_c]> {
    public:
    using Type = RemoveAllExtents<ObjectT>;
    
};

template <typename ObjectT>
struct DDRemoveAllExtents<ObjectT[]> {
    public:
    using Type = RemoveAllExtents<ObjectT>;
    
};


template <typename ObjectT>
struct DDAddPointer {
    using Type = RemoveReference<ObjectT>*;
};


template <typename ObjectT>
struct DDRemovePointer {
    using Type = ObjectT;
};

template <typename ObjectT>
struct DDRemovePointer<ObjectT*> {
    using Type = ObjectT;
};

template <typename ObjectT>
struct DDRemovePointer<ObjectT* const> {
    using Type = ObjectT;
};

template <typename ObjectT>
struct DDRemovePointer<ObjectT* volatile> {
    using Type = ObjectT;
};

template <typename ObjectT>
struct DDRemovePointer<ObjectT* const volatile> {
    using Type = ObjectT;
};


DD_END



DD_BEGIN
template <typename ObjectT, ObjectT ValueT>
constexpr DDIntegralConstant<ObjectT, ValueT>::operator ObjectT() noexcept {
    return this->value;
}


DD_END



#endif