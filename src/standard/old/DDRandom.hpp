// DDRandom.hpp
#ifndef _DDRANDOM_
 #define _DDRANDOM_



 #include "DDGlobal.hpp"
 #include <cstdlib>
 #include <ctime>



DD_BEGIN
class DDRandom;


enum class DDRandomSeedType {
    NONE = 0,
    SYSTEM_TIME = 1,
    
    LOCKED = -1,
};


class DDRandom {
    public:
    DDRandom();
    DDRandom(const DDRandom&) = delete;
    int roll(int argument = 0);
    int roll(DDRandomSeedType seed_type);// Always by time.
    int roll(int begin, int end, int argument = 0);
    int roll(int begin, int end, DDRandomSeedType seed_type);// Always by time.
    
    public:
    DDRandom &operator =(const DDRandom&) = delete;
    int operator ()(int argument = 0);
    int operator ()(DDRandomSeedType seed_type);
    int operator ()(int begin, int end, int argument = 0);
    
    protected:
    int current;
    
};


DDErrorType randomize(unsigned seed);
DDErrorType randomize(DDRandomSeedType seed_type = DDRandomSeedType::SYSTEM_TIME);

int random();
int random(unsigned limit);
int random(int begin, int end);


DD_END



DD_BEGIN
inline int random() {
    return std::rand();
}

inline int random(unsigned limit) {
    return std::rand() % limit;
}

inline int random(int begin, int end) {
    if (begin >= end) {
        throw DDError(DDErrorType::INVALID_ARGUMENT, "Invalid range to get random number from. ");
    }
    return begin + std::rand() % (end - begin);
}


extern DDRandom randomer;


DD_END



#endif
