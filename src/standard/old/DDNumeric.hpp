// DDNumeric.hpp
#ifndef _DDNUMERIC_
 #define _DDNUMERIC_



 #include "DDGlobal.hpp"



DD_BEGIN
template <typename UCursorT, typename ValueT>
ValueT accumulate(UCursorT begin, UCursorT end, ValueT initial_value) noexcept(false);// To optimize
template <typename UCursorT, typename ValueT, typename FunctionT>
ValueT accumulate(UCursorT begin, UCursorT end, ValueT initial_value, FunctionT& operation) noexcept(false);// To optimize

template <typename UCursorT1, typename UCursorT2>
UCursorT2 adjacent_difference(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin) noexcept(false);// To optimize
template <typename UCursorT1, typename UCursorT2, typename FunctionT>
UCursorT2 adjacent_difference(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin, FunctionT& operation) noexcept(false);// To optimize


DD_END



DD_BEGIN
template <typename UCursorT, typename ValueT>
inline ValueT accumulate(UCursorT begin, UCursorT end, ValueT initial_value) noexcept(false) {
    for (; begin != end; ++begin) {
        initial_value += *begin;
    }
    return initial_value;
}

template <typename UCursorT, typename ValueT, typename FunctionT>
inline ValueT accumulate(UCursorT begin, UCursorT end, ValueT initial_value, FunctionT& operation) noexcept(false) {
    for (; begin != end; ++begin) {
        initial_value = operation(initial_value, *begin);
    }
    return initial_value;
}


template <typename UCursorT1, typename UCursorT2>
UCursorT2 adjacent_difference(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin) noexcept(false) {
    using ValueType = decltype(*begin);
    if (begin == end) {
        return result_begin;
    }
    *result_begin = *begin - ValueType();
    for (auto previous = begin; ++begin != end; ++begin, ++previous) {
        *++result_begin = *begin - *previous;
    }
    return result_begin;
}

template <typename UCursorT1, typename UCursorT2, typename FunctionT>
UCursorT2 adjacent_difference(UCursorT1 begin, UCursorT1 end, UCursorT2 result_begin, FunctionT& operation) noexcept(false) {
    using ValueType = decltype(*begin);
    if (begin == end) {
        return result_begin;
    }
    *result_begin = operation(*begin, ValueType());
    for (auto previous = begin; ++begin != end; ++begin, ++previous) {
        *++result_begin = operation(*begin, *previous);
    }
    return result_begin;
}


DD_END



#endif