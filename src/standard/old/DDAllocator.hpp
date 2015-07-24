// DDAllocator.hpp
#ifndef _DDALLOCATOR_
 #define _DDALLOCATOR_



 #include "DDResource.hpp"
 #include <cstdlib>



 #ifndef DDALLOCATOR_SIMPLE_LIMIT
  #define DDALLOCATOR_SIMPLE_LIMIT 0
 #endif
 #define DDALLOCATOR_MEMBER(...) template <typename ValueT> __VA_ARGS__ DDAllocator<ValueT>



DD_BEGIN
DDIMPLEMENT_BEGIN
constexpr SizeType free_list_minimum_size = 8;
constexpr SizeType free_list_maximum_size = static_cast<SizeType>(DDALLOCATOR_SIMPLE_LIMIT) / 8 * 8;
constexpr SizeType free_list_quantity = free_list_maximum_size / free_list_minimum_size;


template <IntSignType sign_c>
class Allocator_;

template <IntSignType sign_c>
class SAllocator_;


DDIMPLEMENT_END


template <typename ValueT>
class DDAllocator;


DDIMPLEMENT_BEGIN


template <IntSignType sign_c>
class Allocator_ {
    static_assert(sign_c == 0, "Invalid use of implementation.");
    
    public:
    using HandlerType = ProcessType();
    
    protected:
    Allocator_() noexcept(true) = default;
    Allocator_(Allocator_<sign_c> const& origin) noexcept(true) = default;
    
    protected:
    ~Allocator_() noexcept(true) = default;
    
    protected:
    static GlobalPointerType allocate(SizeType size) noexcept(false);
    static GlobalPointerType reallocate(GlobalPointerType pointer, SizeType, SizeType new_size) noexcept(false);
    static ProcessType deallocate(GlobalPointerType pointer, SizeType) noexcept(false);
    
    public:
    static HandlerType* set_handler(HandlerType* new_handler) noexcept(true);
    
    protected:
    Allocator_<sign_c>& operator =(Allocator_<sign_c> const& origin) noexcept(false) = default;
    
    private:
    static GlobalPointerType allocate_failure_process(SizeType size) noexcept(false);
    static GlobalPointerType reallocate_failure_process(GlobalPointerType pointer, SizeType new_size) noexcept(false);
    
    private:
    static HandlerType* m_handler;
    
};


 #if DDALLOCATOR_SIMPLE_LIMIT < 16
using Allocator = Allocator_<0>;
 #else
  #error Unrealized Feature: DDAllocator(Efficient version)
using Allocator = SAllocator_<0>;
 #endif


DDIMPLEMENT_END


template <typename ValueT>
class DDAllocator : public DDImplement::Allocator {
    public:
    using ValueType = ValueT;
    using HandlerType = DDImplement::Allocator::HandlerType;
    
    public:
    DDAllocator() noexcept(true) = default;
    DDAllocator(DDAllocator<ValueT> const& origin) noexcept(true) = default;
    
    public:
    ~DDAllocator() noexcept(true) = default;
    
    public:
    static ValueT* allocate(LengthType length) noexcept(false);
    static ValueT* reallocate(ValueT* pointer, LengthType new_length) noexcept(false);
    static ProcessType deallocate(ValueT* pointer) noexcept(true);
    template <typename... ArgumentsT>
    static ProcessType construct(ValueT* pointer, ArgumentsT&&... construct_arguments) noexcept(false);// To optimize
    static ProcessType destroy(ValueT* pointer) noexcept(true);
    static ProcessType destroy(ValueT* begin_pointer, PointerType<ValueT> end_pointer) noexcept(true);
    
    public:
    DDAllocator<ValueT>& operator =(DDAllocator<ValueT> const& origin) noexcept(true) = default;
    
};


DD_END



DD_BEGIN
DDIMPLEMENT_BEGIN
template <IntSignType sign_c>
inline GlobalPointerType Allocator_<sign_c>::allocate(SizeType size) noexcept(false) {
    auto pointer = std::malloc(size);
    return pointer ? pointer : Allocator_::allocate_failure_process(size);
}


template <IntSignType sign_c>
inline GlobalPointerType Allocator_<sign_c>::reallocate(GlobalPointerType pointer, SizeType, SizeType new_size) noexcept(false) {
    return (pointer = std::realloc(pointer, new_size)) ? pointer : Allocator_::reallocate_failure_process(pointer, new_size);
}


template <IntSignType sign_c>
inline ProcessType Allocator_<sign_c>::deallocate(GlobalPointerType pointer, SizeType) noexcept(false) {
    std::free(pointer);
    return;
}


template <IntSignType sign_c>
inline typename Allocator_<sign_c>::HandlerType* Allocator_<sign_c>::set_handler(HandlerType* new_handler) noexcept(true) {
    auto old_handler = Allocator_::m_handler;
    Allocator_::m_handler = new_handler;
    return old_handler;
}


template <IntSignType sign_c>
GlobalPointerType Allocator_<sign_c>::allocate_failure_process(SizeType size) noexcept(false) {
    GlobalPointerType pointer;
    do {
        if (!Allocator_::m_handler) {
            throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate. ");
        }
        Allocator_::m_handler();
        pointer = std::malloc(size);
    } while (!pointer);
    return pointer;
}


template <IntSignType sign_c>
GlobalPointerType Allocator_<sign_c>::reallocate_failure_process(GlobalPointerType pointer, SizeType new_size) noexcept(false) {
    do {
        if (!Allocator_::m_handler) {
            throw DDError(DDErrorType::MEMORY_ALLOCATION_FAILURE, "Failed to allocate. ");
        }
        Allocator_::m_handler();
        pointer = std::realloc(pointer, new_size);
    } while (!pointer);
    return pointer;
}


template <IntSignType sign_c>
typename Allocator_<sign_c>::HandlerType* Allocator_<sign_c>::m_handler = nullptr;


DDIMPLEMENT_END


DDALLOCATOR_MEMBER(inline ValueT*)::allocate(LengthType length) noexcept(false) {
    return static_cast<PointerType<ValueT>>(DDImplement::Allocator::allocate(sizeof(ValueT) * length));
}


DDALLOCATOR_MEMBER(inline ValueT*)::reallocate(PointerType<ValueT> pointer, LengthType new_length) noexcept(false) {
    return static_cast<PointerType<ValueT>>(DDImplement::Allocator::reallocate(pointer, sizeof(ValueT) * new_length));
}


DDALLOCATOR_MEMBER(inline ProcessType)::deallocate(ValueT* pointer) noexcept(true) {
    DDImplement::Allocator::deallocate(pointer);
    return;
}


DDALLOCATOR_MEMBER(template <typename... ArgumentsT> inline ProcessType)::construct(ValueT* pointer, ArgumentsT&&... construct_arguments) noexcept(false) {
    DD::construct(pointer, construct_arguments...);
    return;
}


DDALLOCATOR_MEMBER(inline ProcessType)::destroy(ValueT* pointer) noexcept(true) {
    DD::destroy(pointer);
    return;
}

DDALLOCATOR_MEMBER(inline ProcessType)::destroy(ValueT* begin_pointer, PointerType<ValueT> end_pointer) noexcept(true) {
    DD::destroy(begin_pointer, end_pointer);
    return;
}


DD_END



#endif