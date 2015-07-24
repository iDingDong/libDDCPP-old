// DDGlobal.hpp
#ifndef _DDGLOBAL_
 #define _DDGLOBAL_



 #include <cstddef>
 #include <new>



 #define _DDCPP_ 1000000L

 #ifndef __cplusplus
  #error Compiler should support ISO C++.
 #elif __cplusplus < 201103L
  #error ISO/IEC 14882:2011 or a later version support is required.
 #endif

 #ifndef DD_DEBUG
  #define DD_DEBUG 0
 #endif

 #define DD_UNREALIZED throw DDError(DDErrorType::UNREALIZED, "Unrealized Feature. ")

 #define DD_BEGIN namespace DD {
 #define DD_END }
 #define DDIMPLEMENT_BEGIN namespace DDImplement {
 #define DDIMPLEMENT_END }

 #define DDERROR_MONITOR try {
 #define DDERROR_SOLVE } catch (DD::DDError& error) {
 #define DDERROR_REST(...) } catch (...) { __VA_ARGS__ }
 #define DDERROR_SOLVED }
 #define DDERROR_SUBMIT throw error; }

 #define DDALLOCATE(allocate, prompt, ...) try { allocate; } catch (DD::DDError& error) { __VA_ARGS__ throw error; } catch (...) { __VA_ARGS__ throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, (prompt)); }

 #if DD_DEBUG > 0
  #define DD_DEBUG_ASSERT
 #endif
 #ifdef DD_DEBUG_ASSERT
  #define DD_ASSERT_PROMPT(file, line) "Assertion failure in " #file " at line " #line ". "
  #define DD_ASSERT(...) if (!(__VA_ARGS__)) { throw DDError(DDErrorType::ASSERTION_FAILURE, DD_ASSERT_PROMPT(__FILE__, __LINE__)); }
 #else
  #define DD_ASSERT(...)
 #endif



DD_BEGIN
using ProcessType = void;

using CharType = char;

using ValidityType = bool;
using CheckType = bool;

using UnsignedType = unsigned int;

using IntegerType = int;
using IntSignType = int;

using ScaleType = std::ptrdiff_t;
using CounterType = std::ptrdiff_t;
using SizeType = std::ptrdiff_t;
using LengthType = std::ptrdiff_t;
using SubscriptType = std::ptrdiff_t;
using QuantityType = std::ptrdiff_t;

using LongLongType = long long int;

using GlobalPointerType = void*;

using CStringType = char*;

using CStringConstType = const char*;
using PromptType = const char*;

template <typename ValueT>
using ReferenceType = ValueT&;

template <typename ValueT, LengthType LengthT>
using ArrayType = ValueT[LengthT];

template <typename ValueT>
using PointerType = ValueT*;


enum class DDCompareResult {
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
    
};


enum class DDErrorType {
    NONE = 0,
    UNSUPPORTED = 1,
    INVALID_ARGUMENT = 2,
    MEMORY_ALLOCATION_FAILURE = 3,
    ACCESS_DENIED = 4,
    ACTION_BANNED = 5,
    
    UNKNOWN = -1,
 #ifdef DD_DEBUG_ASSERT
    ASSERTION_FAILURE = -2,
 #endif
    UNREALIZED = -3
    
};


struct DDNil;


struct DDNilPointer;


using Nil = DDNil;
using NilPointer = DDNilPointer;


class DDError;


struct DDNil {
};


struct DDNilPointer {
    public:
    template <typename ValueT>
    constexpr operator ValueT*() const noexcept;
    
};


class DDError {
    public:
    DDError(PromptType error_prompt = "Unknown error") noexcept;
    DDError(DDError const& origin) noexcept = default;
    DDError(DDErrorType error_type, PromptType error_prompt = "Undetailed error") noexcept;
    ~DDError() noexcept;
    const DDErrorType get_type() const noexcept;
    PromptType get_prompt() const noexcept;
    
    public:
    DDError &operator =(const DDError &origin) noexcept;
    
    protected:
    DDErrorType type = DDErrorType::UNKNOWN;
    PromptType prompt = nullptr;
    
};


template <typename ObjectT>
ObjectT& add(ObjectT& object_1, ObjectT const& object_2);

template <typename ObjectT>
ObjectT plus(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType equal(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType less(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType Greater(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
DDCompareResult compare(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ProcessType sort_pair(ObjectT& object_1, ObjectT& object_2, CheckType ascend = true);

template <typename ObjectT1, typename ObjectT2>
ObjectT1 operator +(const ObjectT1 &object_1, const ObjectT2 &object_2);

template <typename ObjectT1, typename ObjectT2>
ObjectT1 operator -(const ObjectT1 &object_1, const ObjectT2 &object_2);

template <typename ObjectT>
ValidityType operator <(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType operator <=(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType operator >(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType operator >=(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType operator ==(ObjectT const& object_1, ObjectT const& object_2);

template <typename ObjectT>
ValidityType operator !=(ObjectT const& object_1, ObjectT const& object_2);


DD_END



DD_BEGIN
template <typename ValueT>
inline constexpr DDNilPointer::operator ValueT*() const noexcept {
    return 0;
}


inline DDError::DDError(PromptType error_prompt) noexcept : type(DDErrorType::UNKNOWN), prompt(error_prompt) {
}

inline DDError::DDError(DDErrorType error_type, PromptType error_prompt) noexcept : type(error_type), prompt(error_prompt) {
}


inline DDError::~DDError() {
}


inline const DDErrorType DDError::get_type() const noexcept {
    return type;
}


inline PromptType DDError::get_prompt() const noexcept {
    return prompt;
}


inline DDError &DDError::operator =(const DDError& origin) noexcept {
    type = origin.type;
    prompt = origin.prompt;
    return *this;
}


template <typename ObjectT>
inline ObjectT& add(ObjectT& object_1, ObjectT const& object_2) {
    return object_1 += object_2;
}


template <typename ObjectT>
inline ObjectT plus(ObjectT const& object_1, ObjectT const& object_2) {
    ObjectT result = object_1;
    return result += object_2;
}


template <typename ObjectT>
inline ValidityType equal(ObjectT const& object_1, ObjectT const& object_2) {
    return object_1 == object_2;
}


template <typename ObjectT>
ValidityType less(ObjectT const& object_1, ObjectT const& object_2) {
    return object_1 < object_2;
}


template <typename ObjectT>
ValidityType Greater(ObjectT const& object_1, ObjectT const& object_2) {
    return object_2 < object_1;
}


template <typename ObjectT>
inline DDCompareResult compare(ObjectT const& object_1, ObjectT const& object_2) {
    if (object_2 < object_1) {
        return DDCompareResult::GREATER;
    } else if (object_1 < object_2) {
        return DDCompareResult::LESS;
    }
    return DDCompareResult::EQUAL;
}


template <typename ObjectT>
inline ProcessType sort_pair(ObjectT& object_1, ObjectT& object_2, CheckType ascend = true) {
    if (ascend) {
        if (object_2 < object_1) {
            swap(object_1, object_2);
        }
    } else if (object_1 < object_2) {
        swap(object_1, object_2);
    }
    return;
}


template <typename ObjectT1, typename ObjectT2>
ObjectT1 operator +(const ObjectT1 &object_1, const ObjectT2 &object_2) {
    ObjectT1 tmp_object = object_1;
    return tmp_object += object_2;
}


template <typename ObjectT1, typename ObjectT2>
ObjectT1 operator -(const ObjectT1 &object_1, const ObjectT2 &object_2) {
    ObjectT1 tmp_object = object_1;
    return tmp_object -= object_2;
}


template <typename ObjectT>
inline ValidityType operator <(ObjectT const& object_1, ObjectT const& object_2) {
    return object_1.compare(object_2) == DDCompareResult::LESS;
}


template <typename ObjectT>
inline CheckType operator <=(ObjectT const& object_1, ObjectT const& object_2) {
    return !object_1 > object_2;
}


template <typename ObjectT>
inline CheckType operator >(ObjectT const& object_1, ObjectT const& object_2) {
    return object_2 < object_1;
}


template <typename ObjectT>
inline CheckType operator >=(ObjectT const& object_1, ObjectT const& object_2) {
    return !object_1 < object_2;
}


template <typename ObjectT>
inline CheckType operator ==(ObjectT const& object_1, ObjectT const& object_2) {
    return object_1.equal(object_2);
}


template <typename ObjectT>
inline CheckType operator !=(ObjectT const& object_1, ObjectT const& object_2) {
    return !object_1 == object_2;
}


DD_END



#endif