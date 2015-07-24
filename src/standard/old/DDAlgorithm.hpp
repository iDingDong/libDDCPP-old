// DDAlgorithm.hpp
#ifndef _DDALGORITHM_
 #define _DDALGORITHM_



 #include "DDUtility.hpp"
 #include "DDCursor.hpp"
 #include <cstring>



DD_BEGIN
template <typename UCursorT1, typename UCursorT2>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2) noexcept(false);// To optimize
template <typename UCursorT1, typename UCursorT2, typename FunctionT>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, FunctionT& equal_predication) noexcept(false);// To optimize
template <typename UCursorT1, typename UCursorT2>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2) noexcept(false);// To optimize
template <typename UCursorT1, typename UCursorT2, typename FunctionT>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2, FunctionT& equal_predication) noexcept(false);// To optimize

template <typename ObjectT>
ObjectT const& min(ObjectT const& object_1, ObjectT const& object_2) noexcept(false);// To optimize
template <typename ObjectT, typename FunctionT>
ObjectT const& min(ObjectT const& object_1, ObjectT const& object_2, FunctionT& less_predication) noexcept(false);// To optimize

template <typename ObjectT>
ObjectT const& max(ObjectT const& object_1, ObjectT const& object_2) noexcept(false);// To optimize
template <typename ObjectT, typename FunctionT>
ObjectT const& max(ObjectT const& object_1, ObjectT const& object_2, FunctionT& less_predication) noexcept(false);// To optimize

template <typename ObjectT>
ObjectT const& median(ObjectT const& object_1, ObjectT const& object_2, ObjectT const& object_3) noexcept(false);// To optimize
template <typename ObjectT, typename FunctionT>
ObjectT const& median(ObjectT const& object_1, ObjectT const& object_2, ObjectT const& object_3, FunctionT& less_predication) noexcept(false);// To optimize

ValidityType lexicographical_less(unsigned char const* begin_1, unsigned char const* end_1, unsigned char const* begin_2, unsigned char const* end_2) noexcept(true);
template <typename UCursorT1, typename UCursorT2>
ValidityType lexicographical_less(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2) noexcept(false);// To optimize
template <typename UCursorT1, typename UCursorT2, typename FunctionT>
ValidityType lexicographical_less(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2, FunctionT& less_predication) noexcept(false);// To optimize

template <typename UCursorT1, typename UCursorT2>
DDPair<UCursorT1, UCursorT2> mismatch(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2) noexcept(false);// To optimize
template <typename UCursorT1, typename UCursorT2, typename FunctionT>
DDPair<UCursorT1, UCursorT2> mismatch(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2, FunctionT& equal_predication) noexcept(false);// To optimize

template <typename UCursorT>
UCursorT adjacent_match(UCursorT begin, UCursorT end) noexcept(false);// To optimize

template <typename UCursorT, typename FunctionT>
UCursorT adjacent_match(UCursorT begin, UCursorT end, FunctionT& pattern_predication) noexcept(false);// To optimize

template <typename UCursorT>
UCursorT search_min(UCursorT begin, UCursorT end) noexcept(false);// To optimize
template <typename UCursorT, typename FunctionT>
UCursorT search_min(UCursorT begin, UCursorT end, FunctionT& less_predication) noexcept(false);// To optimize

template <typename UCursorT>
UCursorT search_max(UCursorT begin, UCursorT end) noexcept(false);// To optimize
template <typename UCursorT, typename FunctionT>
UCursorT search_max(UCursorT begin, UCursorT end, FunctionT& less_predication) noexcept(false);// To optimize

template <typename UCursorT, typename ValueT>
UCursorT search(UCursorT begin, UCursorT end, ValueT const& target) noexcept(false);// To optimize
template <typename UCursorT1, typename UCursorT2>
UCursorT1 search(UCursorT1 begin, UCursorT1 end, UCursorT2 target_begin, UCursorT2 target_end) noexcept(false);// To optimize

template <typename UCursorT, typename FunctionT>
UCursorT search_if(UCursorT begin, UCursorT end, FunctionT& predication) noexcept(false);// To optimize

template <typename UCursorT, typename ValueT>
CursorDifferenceType<UCursorT> count(UCursorT begin, UCursorT end, ValueT const& target) noexcept(false);// To optimize

template <typename UCursorT, typename FunctionT>
CursorDifferenceType<UCursorT> count_if(UCursorT begin, UCursorT end, FunctionT& predication) noexcept(false);// To optimize

template <typename ContainerT, typename FunctionT>
ProcessType for_each(ContainerT& container, FunctionT& operation) noexcept(false);// To optimize
template <typename UCursorT, typename FunctionT>
ProcessType for_each(UCursorT begin, UCursorT end, FunctionT operation) noexcept(false);// To optimize
template <typename UCursorT, typename FunctionT>
UCursorT for_each(UCursorT begin, CursorDifferenceType<UCursorT> length, FunctionT operation) noexcept(false);// To optimize

template <typename CursorT>
ProcessType swap_target(CursorT begin_1, CursorT begin_2) noexcept(false);// To optimize

DDIMPLEMENT_BEGIN
template <typename UCursorT1, typename UCursorT2>
inline UCursorT2 copy_(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin, DDFalseType) noexcept(false);// To optimize

template <typename PointerT1, typename PointerT2>
inline PointerT2 copy_(PointerT1 begin, PointerT1 end, PointerT2 result_begin, DDTrueType) noexcept(true);

DDIMPLEMENT_END

template <typename UCursorT1, typename UCursorT2>
UCursorT2 copy(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin) noexcept(false);// To optimize

template <typename UCursorT, typename ValueT>
ProcessType fill(UCursorT begin, UCursorT end, ValueT const& value) noexcept(false);// To optimize
template <typename UCursorT, typename ValueT>
UCursorT fill(UCursorT begin, CursorDifferenceType<UCursorT> length, ValueT const& value) noexcept(false);// To optimize

template <typename UCursorT, typename FunctionT>
ProcessType generate(UCursorT begin, UCursorT end, FunctionT& generation) noexcept(false);// To optimize
template <typename UCursorT, typename FunctionT>
UCursorT generate(UCursorT begin, CursorDifferenceType<UCursorT> length, FunctionT& generation) noexcept(false);// To optimize

template <typename UCursorT, typename ValueT1, typename ValueT2>
ProcessType replace(UCursorT begin, UCursorT end, ValueT1 const& target, ValueT2 const& new_value) noexcept(false);// To optimize

template <typename UCursorT, typename FunctionT, typename ValueT>
ProcessType replace_if(UCursorT begin, UCursorT end, FunctionT& predication, ValueT const& new_value) noexcept(false);// To optimize

template <typename BCursorT, typename ValueT>
BCursorT partition(BCursorT begin, BCursorT end, ValueT const& key) noexcept(false);// To optimize

template <typename BCursorT, typename FunctionT>
BCursorT partition_if(BCursorT begin, BCursorT end, FunctionT& predication) noexcept(false);// To optimize

DDIMPLEMENT_BEGIN
template <typename BCursorT>
ProcessType reverse_(BCursorT begin, BCursorT end, DDFalseType) noexcept(false);// To optimize
template <typename FCursorT>
ProcessType reverse_(FCursorT begin, FCursorT end, DDTrueType) noexcept(false);// To optimize

DDIMPLEMENT_END

template <typename BCursorT>
ProcessType reverse(BCursorT begin, BCursorT end) noexcept(false);// To optimize

template <typename FCursorT1, typename FCursorT2, typename FCursorT3>
FCursorT3 merge(FCursorT1 begin_1, FCursorT1 end_1, FCursorT2 begin_2, FCursorT2 end_2, FCursorT3 result_begin) noexcept(false);// To optimize
template <typename FCursorT1, typename FCursorT2, typename FCursorT3, typename FunctionT>
FCursorT3 merge(FCursorT1 begin_1, FCursorT1 end_1, FCursorT2 begin_2, FCursorT2 end_2, FCursorT3 result_begin, FunctionT& less_predication) noexcept(false);// To optimize

DD_END



DD_BEGIN
template <typename UCursorT1, typename UCursorT2>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2) noexcept(false) {
    for (; begin_1 != end_1; ++begin_1, ++begin_2) {
        if (*begin_1 != *begin_2) {
            return false;
        }
    }
    return true;
}


template <typename UCursorT1, typename UCursorT2, typename FunctionT>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, FunctionT& equal_predication) noexcept(false) {
    for (; begin_1 != end_1; ++begin_1, ++begin_2) {
        if (!equal_predication(*begin_1, *begin_2)) {
            return false;
        }
    }
    return true;
}

template <typename UCursorT1, typename UCursorT2>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2) noexcept(false) {
    for (; ; ++begin_1, ++begin_2) {
        if (begin_1 == end_1) {
            return begin_2 == end_2;
        } else if (begin_2 == end_2 || *begin_1 != *begin_2) {
            return false;
        }
    }
    return true;
}

template <typename UCursorT1, typename UCursorT2, typename FunctionT>
ValidityType equal(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2, FunctionT& equal_predication) noexcept(false) {
    for (; ; ++begin_1, ++begin_2) {
        if (begin_1 == end_1) {
            return begin_2 == end_2;
        } else if (begin_2 == end_2 || !equal_predication(*begin_1, *begin_2)) {
            return false;
        }
    }
    return true;
}


template <typename ObjectT>
inline ObjectT const& min(ObjectT const& object_1, ObjectT const& object_2) noexcept(false) {
    return object_2 < object_1 ? object_2 : object_1;
}

template <typename ObjectT, typename FunctionT>
inline ObjectT const& min(ObjectT const& object_1, ObjectT const& object_2, FunctionT& less_predication) noexcept(false) {
    return less_predication(object_2, object_1) ? object_2 : object_1;
}


template <typename ObjectT>
inline ObjectT const& max(ObjectT const& object_1, ObjectT const& object_2) noexcept(false) {
    return object_1 < object_2 ? object_2 : object_1;
}

template <typename ObjectT, typename FunctionT>
inline ObjectT const& max(ObjectT const& object_1, ObjectT const& object_2, FunctionT& less_predication) noexcept(false) {
    return less_predication(object_1, object_2) ? object_2 : object_1;
}


template <typename ObjectT>
ObjectT const& median(ObjectT const& object_1, ObjectT const& object_2, ObjectT const& object_3) noexcept(false) {
    if (object_3 < object_2) {
        if (object_2 < object_1) {
            return object_2;
        } else if (object_3 < object_1) {
            return object_1;
        } else {
            return object_3;
        }
    } else if (object_3 < object_1) {
        return object_3;
    } else if (object_2 < object_1) {
        return object_1;
    }
    return object_2;
}

template <typename ObjectT, typename FunctionT>
ObjectT const& median(ObjectT const& object_1, ObjectT const& object_2, ObjectT const& object_3, FunctionT& less_predication) noexcept(false) {
    if (less_predication(object_3, object_2)) {
        if (less_predication(object_2, object_1)) {
            return object_2;
        } else if (less_predication(object_3, object_1)) {
            return object_1;
        } else {
            return object_3;
        }
    } else if (less_predication(object_3, object_1)) {
        return object_3;
    } else if (less_predication(object_2, object_1)) {
        return object_1;
    }
    return object_2;
}

inline ValidityType lexicographical_less(unsigned char const* begin_1, unsigned char const* end_1, unsigned char const* begin_2, unsigned char const* end_2) noexcept(true) {
    auto const length_1 = end_1 - begin_1;
    auto const length_2 = end_2 - begin_2;
    auto const result = std::memcmp(begin_1, begin_2, DD::minimum(length_1, length_2));
    return result ? result < 0 : length_1 < length_2;
}

template <typename UCursorT1, typename UCursorT2>
ValidityType lexicographical_less(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2) noexcept(false) {
    for (; ; ++begin_1, ++begin_2) {
        if (begin_2 == end_2 || *begin_2 < *begin_1) {
            return false;
        }
        if (begin_1 == end_1) {
            break;
        }
    }
    return true;
}

template <typename UCursorT1, typename UCursorT2, typename FunctionT>
ValidityType lexicographical_less(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2, FunctionT& less_predication) noexcept(false) {
    for (; ; ++begin_1, ++begin_2) {
        if (begin_2 == end_2 || less_predication(*begin_2, *begin_1)) {
            return false;
        }
        if (begin_1 == end_1) {
            return true;
        }
    }
    return true;
}


template <typename UCursorT1, typename UCursorT2>
DDPair<UCursorT1, UCursorT2> mismatch(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2) noexcept(false) {
    while (*begin_1 == *begin_2 && begin_1 != end_1 && begin_2 != end_2) {
        ++begin_1;
        ++begin_2;
    }
    return DDPair<UCursorT1, UCursorT2>{begin_1, begin_2};
}

template <typename UCursorT1, typename UCursorT2, typename FunctionT>
DDPair<UCursorT1, UCursorT2> mismatch(UCursorT1 begin_1, UCursorT1 end_1, UCursorT2 begin_2, UCursorT2 end_2, FunctionT& equal_predication) noexcept(false) {
    while (equal_predication(*begin_1, *begin_2) && begin_1 != end_1 && begin_2 != end_2) {
        ++begin_1;
        ++begin_2;
    }
    return DDPair<UCursorT1, UCursorT2>{begin_1, begin_2};
}


template <typename UCursorT>
UCursorT adjacent_match(UCursorT begin, UCursorT end) {
    if (begin != end) {
        auto next = begin;
        for (; ++next != end; begin = next) {
            if (*begin == *next) {
                return begin;
            }
        }
    }
    return end;
}

template <typename UCursorT, typename FunctionT>
UCursorT adjacent_match(UCursorT begin, UCursorT end, FunctionT& pattern_predication) noexcept(false) {
    if (begin != end) {
        auto next = begin;
        for (; ++next != end; begin = next) {
            if (pattern_predication(*begin, *next)) {
                return begin;
            }
        }
    }
    return end;
}


template <typename UCursorT>
UCursorT search_min(UCursorT begin, UCursorT end) noexcept(false) {
    auto result = begin;
    while (++begin != end) {
        if (*begin < *result) {
            result = begin;
        }
    }
    return result;
}

template <typename UCursorT, typename FunctionT>
UCursorT search_min(UCursorT begin, UCursorT end, FunctionT& less_predication) noexcept(false) {
    auto result = begin;
    while (++begin != end) {
        if (less_predication(*begin, *result)) {
            result = begin;
        }
    }
    return result;
}


template <typename UCursorT>
UCursorT search_max(UCursorT begin, UCursorT end) noexcept(false) {
    auto result = begin;
    while (++begin != end) {
        if (*result < *begin) {
            result = begin;
        }
    }
    return result;
}

template <typename UCursorT, typename FunctionT>
UCursorT search_max(UCursorT begin, UCursorT end, FunctionT& less_predication) noexcept(false) {
    auto result = begin;
    while (++begin != end) {
        if (less_predication(*result, *begin)) {
            result = begin;
        }
    }
    return result;
}


template <typename UCursorT, typename ValueT>
UCursorT search(UCursorT begin, UCursorT end, ValueT const& target) noexcept(false) {
    while (*begin != target && begin != end) {
        ++begin;
    }
    return begin;
}

template <typename UCursorT1, typename UCursorT2>
UCursorT1 search(UCursorT1 begin, UCursorT1 end, UCursorT2 target_begin, UCursorT2 target_end) noexcept(false) {
    auto distance = DD::distance(begin, end);
    auto target_distance = DD::distance(target_begin, target_end);
    if (distance < target_distance) {
        return end;
    }
    auto current = begin;
    auto target_current = target_begin;
    while (target_current != target_end) {
        if (*current == *target_current) {
            ++current;
            ++target_current;
        } else {
            if (distance == target_distance) {
                return end;
            } else {
                current = ++begin;
                target_current = target_begin;
                --distance;
            }
        }
    }
    return begin;
}


template <typename UCursorT, typename FunctionT>
UCursorT search_if(UCursorT begin, UCursorT end, FunctionT& predication) noexcept(false) {
    while (!predication(*begin) && begin != end) {
        ++begin;
    }
    return begin;
}


template <typename UCursorT, typename ValueT>
CursorDifferenceType<UCursorT> count(UCursorT begin, UCursorT end, ValueT const& target) noexcept(false) {
    auto result = CursorDifferenceType<UCursorT>();
    for (; begin != end; ++begin) {
        if (*begin == target) {
            ++result;
        }
    }
    return result;
}


template <typename UCursorT, typename FunctionT>
CursorDifferenceType<UCursorT> count_if(UCursorT begin, UCursorT end, FunctionT& predication) noexcept(false) {
    auto result = CursorDifferenceType<UCursorT>();
    for (; begin != end; ++begin) {
        if (predication(*begin)) {
            ++result;
        }
    }
    return result;
}


template <typename ContainerT, typename FunctionT>
ProcessType for_each(ContainerT& container, FunctionT& operation) noexcept(false) {
    for (auto& element : container) {
        operation(element);
    }
    return;
}

template <typename UCursorT, typename FunctionT>
ProcessType for_each(UCursorT begin, UCursorT end, FunctionT operation) noexcept(false) {
    for (; begin != end; ++begin) {
        operation(*begin);
    }
    return;
}

template <typename UCursorT, typename FunctionT>
UCursorT for_each(UCursorT begin, CursorDifferenceType<UCursorT> length, FunctionT operation) noexcept(false) {
    constexpr auto end_sign = CursorDifferenceType<UCursorT>();
    for (; length > 0; ++begin, --length) {
        operation(*begin);
    }
    return begin;
}


template <typename CursorT>
inline ProcessType swap_target(CursorT cursor_1, CursorT cursor_2) noexcept(false) {
    DD::swap(*cursor_1, *cursor_2);
    return;
}


DDIMPLEMENT_BEGIN
template <typename UCursorT1, typename UCursorT2>
inline UCursorT2 copy_(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin, DDFalseType) noexcept(false) {
    for (; begin != end; ++begin, ++result_begin) {
        *result_begin = *begin;
    }
    return result_begin;
}


template <typename PointerT1, typename PointerT2>
inline PointerT2 copy_(PointerT1 begin, PointerT1 end, PointerT2 result_begin, DDTrueType) noexcept(true) {
    std::memmove(result_begin, begin, size_distance(begin, end));
    return result_begin + (end - begin);
}


DDIMPLEMENT_END


template <typename UCursorT1, typename UCursorT2>
inline UCursorT2 copy(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin) noexcept(false) {
    using ValueType1 = CursorValueType<UCursorT1>;
    using ValueType2 = CursorValueType<UCursorT2>;
    using IsSameValueType = DDIsSame<RemoveCV<ValueType1>, RemoveVolatile<ValueType2>>;
    using IsFastCopiable = And<DDIsTriviallyCopyAssignable<ValueType2>, IsSameValueType>;
    return DDImplement::copy_(begin, end, result_begin, And<DDIsPointer<UCursorT1, UCursorT2>, IsFastCopiable>());
}


template <typename UCursorT, typename ValueT>
ProcessType fill(UCursorT begin, UCursorT end, ValueT const& value) noexcept(false) {
    for (; begin != end; ++begin) {
        *begin = value;
    }
    return;
}

template <typename UCursorT, typename ValueT>
UCursorT fill(UCursorT begin, CursorDifferenceType<UCursorT> length, ValueT const& value) noexcept(false) {
    constexpr auto end_sign = CursorDifferenceType<UCursorT>();
    for (; length > end_sign; ++begin, --length) {
        *begin = value;
    }
    return begin;
}


template <typename UCursorT, typename FunctionT>
ProcessType generate(UCursorT begin, UCursorT end, FunctionT& generation) noexcept(false) {
    for (; begin != end; ++begin) {
        *begin = generation();
    }
    return;
}

template <typename UCursorT, typename FunctionT>
UCursorT generate(UCursorT begin, CursorDifferenceType<UCursorT> length, FunctionT& generation) noexcept(false) {
    constexpr auto end_sign = CursorDifferenceType<UCursorT>();
    for (; length > end_sign; ++begin, --length) {
        *begin = generation();
    }
    return begin;
}


template <typename UCursorT, typename ValueT1, typename ValueT2>
ProcessType replace(UCursorT begin, UCursorT end, ValueT1 const& target, ValueT2 const& new_value) noexcept(false) {
    for (; begin != end; ++begin) {
        if (*begin == target) {
            *begin = new_value;
        }
    }
    return;
}


template <typename UCursorT, typename FunctionT, typename ValueT>
ProcessType replace_if(UCursorT begin, UCursorT end, FunctionT& predication, ValueT const& new_value) noexcept(false) {
    for (; begin != end; ++begin) {
        if (predication(*begin)) {
            *begin = new_value;
        }
    }
    return;
}


template <typename BCursorT, typename ValueT>
BCursorT partition(BCursorT begin, BCursorT end, ValueT const& key) noexcept(false) {
    for (; ; ) {
        for (; ; ++begin) {
            if (begin == end) {
                return begin;
            } else if (key < *begin) {
                break;
            }
        }
        do {
            if (begin == --end) {
                return begin;
            }
        } while (key < *end);
        DD::swap(*begin, *end);
    }
    return begin;
}

template <typename BCursorT, typename FunctionT>
BCursorT partition_if(BCursorT begin, BCursorT end, FunctionT& predication) noexcept(false) {
    for (; ; ) {
        for (; ; ++begin) {
            if (begin == end) {
                return begin;
            } else if (!predication(*begin)) {
                break;
            }
        }
        do {
            if (begin == --end) {
                return begin;
            }
        } while (!predication(*end));
        DD::swap(*begin, *end);
    }
    return begin;
}


DDIMPLEMENT_BEGIN
template <typename BCursorT>
ProcessType reverse_(BCursorT begin, BCursorT end, DDFalseType) noexcept(false) {
    for (; begin != end && begin != --end; ++begin) {
        DD::swap(*begin, *end);
    }
    return;
}

template <typename FCursorT>
ProcessType reverse_(FCursorT begin, FCursorT end, DDTrueType) noexcept(false) {
    for (; begin < end; ++begin) {
        DD::swap(*begin, *--end);
    }
    return;
}


DDIMPLEMENT_END


template <typename BCursorT>
inline ProcessType reverse(BCursorT begin, BCursorT end) noexcept(false) {
    DDImplement::reverse_(begin, end, DDIsFCursor<BCursorT>());
    return;
}


template <typename FCursorT1, typename FCursorT2, typename FCursorT3>
FCursorT3 merge(FCursorT1 begin_1, FCursorT1 end_1, FCursorT2 begin_2, FCursorT2 end_2, FCursorT3 result_begin) noexcept(false) {
    for (; begin_2 != end_2; ++result_begin) {
        if (begin_1 == end_1) {
            return copy(begin_2, end_2, result_begin);
        }
        if (*begin_1 < *begin_2) {
            *result_begin = *begin_1;
            ++begin_1;
        } else {
            *result_begin = *begin_2;
            ++begin_2;
        }
    }
    return copy(begin_1, end_1, result_begin);
}

template <typename FCursorT1, typename FCursorT2, typename FCursorT3, typename FunctionT>
FCursorT3 merge(FCursorT1 begin_1, FCursorT1 end_1, FCursorT2 begin_2, FCursorT2 end_2, FCursorT3 result_begin, FunctionT& less_predication) noexcept(false) {
    for (; begin_2 != end_2; ++result_begin) {
        if (begin_1 == end_1) {
            return copy(begin_2, end_2, result_begin);
        }
        if (less_predication(*begin_1, *begin_2)) {
            *result_begin = *begin_1;
            ++begin_1;
        } else {
            *result_begin = *begin_2;
            ++begin_2;
        }
    }
    return copy(begin_1, end_1, result_begin);
}


DD_END



#endif