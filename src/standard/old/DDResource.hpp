// DDResource.hpp
#ifndef _DDRESOURCE_
 #define _DDRESOURCE_



 #include "DDCursor.hpp"



DD_BEGIN
template <typename CursorT, typename... ArgumentsT>
ProcessType construct(CursorT cursor, ArgumentsT&&... construct_arguments) noexcept(false);// To optimize

DDIMPLEMENT_BEGIN
template <typename FCursorT>
ProcessType destroy_(FCursorT begin_cursor, FCursorT end_cursor, DDTrueType) noexcept(true);
template <typename FCursorT>
ProcessType destroy_(FCursorT begin_cursor, FCursorT end_cursor, DDFalseType) noexcept(true);

DDIMPLEMENT_END

template <typename CursorT>
ProcessType destroy(CursorT cursor) noexcept(true);
template <typename FCursorT>
ProcessType destroy(FCursorT begin_cursor, FCursorT end_cursor) noexcept(true);


DD_END



DD_BEGIN
template <typename CursorT, typename... ArgumentsT>
inline ProcessType construct(CursorT cursor, ArgumentsT&&... construct_arguments) noexcept(false) {
    using ValueType = typename DDCursorValueType<CursorT>::Type;
    DDALLOCATE(new (address_of(*cursor)) ValueType(construct_arguments...), "Failed to construct. ", )
    return;
}


DDIMPLEMENT_BEGIN
template <typename UCursorT>
inline ProcessType destroy_(UCursorT begin_cursor, UCursorT end_cursor, DDTrueType) noexcept(true) {
    return;
}

template <typename UCursorT>
inline ProcessType destroy_(UCursorT begin_cursor, UCursorT end_cursor, DDFalseType) noexcept(true) {
    using ValueType = typename DDCursorValueType<UCursorT>::Type;
    while (begin_cursor != end_cursor) {
        (begin_cursor++)->~ValueType();
    }
    return;
}


DDIMPLEMENT_END


template <typename CursorT>
inline ProcessType destroy(CursorT cursor) noexcept(true) {
    using ValueType = typename DDCursorValueType<CursorT>::Type;
    cursor->~ValueType();
    return;
}

template <typename UCursorT>
ProcessType destroy(UCursorT begin_cursor, UCursorT end_cursor) noexcept(true) {
    DDImplement::destroy_(begin_cursor, end_cursor, DDIsTriviallyDestructible<typename DDCursorValueType<UCursorT>::Type>());
}


DD_END



#endif