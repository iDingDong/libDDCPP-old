// DDMath.hpp
#ifndef _DDMATH_
 #define _DDMATH_



 #include "DDAlgorithm.hpp"



DD_BEGIN
class DDFactorial;


class DDFactorial final {
    public:
    DDFactorial();
    DDFactorial(const DDFactorial&) = delete;
    DDFactorial(DDFactorial&&) = delete;
    
    public:
    DDFactorial& operator =(const DDFactorial&) = delete;
    DDFactorial& operator =(DDFactorial&&) = delete;
    LongLongType operator ()(IntegerType number);
    
    private:
    static DDInventory<LongLongType> buffer;
    
};


template <typename NumberT>
NumberT absolute(const NumberT& number);

template <typename NumberT>
double sin(const NumberT& number);

UnsignedType gcd(UnsignedType x, UnsignedType y); 


DD_END



DD_BEGIN
inline DDFactorial::DDFactorial() {
}


inline LongLongType DDFactorial::operator ()(IntegerType number) {
    while (number >= buffer.get_length()) {
        auto new_factorial = buffer.get_top() * buffer.get_length();
        buffer.append(new_factorial);
    }
    return buffer[number];
}


template <typename NumberT>
inline NumberT absolute(const NumberT& number) {
    return number < 0 ? -number : number;
}


template <typename NumberT>
double sin(const NumberT& number) {
    DD_UNREALIZED;
}


inline UnsignedType gcd(UnsignedType x, UnsignedType y) {
    UnsignedType r;
    while ((r = x % y)) {
        x = y;
        y = r;
    }
    return y;
}


DD_END



#endif
