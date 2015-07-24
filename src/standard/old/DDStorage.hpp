#ifndef _DDSTORAGE_
 #define _DDSTORAGE_



 #include <DDGlobal>



DD_START
template <typename T>
class DDStorage;


template <typename T>
class DDStorage {
    public:
    DDStorage();
    DDStorage(int size);
    DDStorage(int size, const T &initial_value);
    DDStorage(const DDStorage<T> &origin);
    ~DDStorage();
    int get_length() const;
    bool is_empty() const;
    int find(const T *target) const;
    DDStorage<T> &clone(const DDStorage<T> &origin);
    DDStorage<T> &expand(int extra_size);
    DDStorage<T> &expand(int extra_size, const T &initial_value);
    DDStorage<T> &copy(const DDStorage<T> &origin, int start_index = 0);
    DDStorage<T> &append(const T &element);
    DDStorage<T> &append(const DDStorage<T> &follower);
    DDStorage<T> &insert(int index, const T &element);
    DDStorage<T> &remove(int index);
    DDStorage<T> &removeAll();
    DDStorage<T> &operator =(const DDStorage<T> &origin);
    DDStorage<T> &operator +=(const T &element);
    DDStorage<T> &operator +=(const DDStorage<T> &follower);
    T &operator [](int index);
    const T &operator [](int index) const;
    
    protected:
    T* contents;
    int length;
    
 #if DD_DEBUG >= 1
    private:
    static int object_count;
    
 #endif
};


DD_END



DD_START
 #define DDSTORAGE_MEMBER(type) template <typename T> type DDStorage<T>


DDSTORAGE_MEMBER()::DDStorage() {
 #if DD_DEBUG >= 1
    std::cout << "DD_Debug: Allocating inventory...";
 #endif
    contents = new T[length = 0];
 #if DD_DEBUG >= 1
    std::cout << "Complete." << std::endl;
    std::cout << "DD_Debug: Construction complete. " << std::endl;
    std::cout << "DD_Debug: " << ++object_count << " object(s) in memory." << std::endl;
 #endif
}

DDSTORAGE_MEMBER()::DDStorage(int size) {
 #if DD_DEBUG >= 1
    std::cout << "DD_Debug: Allocating inventory...";
 #endif
    contents = new T[length = size];
 #if DD_DEBUG >= 1
    std::cout << "Complete." << std::endl;
    std::cout << "DD_Debug: Construction complete. " << std::endl;
    std::cout << "DD_Debug: " << ++object_count << " object(s) in memory." << std::endl;
 #endif
}

DDSTORAGE_MEMBER()::DDStorage(int size, const T &initial_value) {
 #if DD_DEBUG >= 1
    std::cout << "DD_Debug: Allocating inventory...";
 #endif
    contents = new T[length = size];
 #if DD_DEBUG >= 1
    std::cout << "Complete." << std::endl;
 #endif
    for (int i = 0; i < length; ++i)
        contents[i] = initial_value;
 #if DD_DEBUG >= 1
    std::cout << "DD_Debug: Construction complete. " << std::endl;
    std::cout << "DD_Debug: " << ++object_count << " object(s) in memory." << std::endl;
 #endif
}

DDSTORAGE_MEMBER()::DDStorage(const DDStorage<T> &origin) {
 #if DD_DEBUG >= 1
    std::cout << "DD_Debug: Allocating inventory...";
 #endif
    contents = new T[length = origin.length];
 #if DD_DEBUG >= 1
    std::cout << "Complete." << std::endl;
 #endif
    for (int i = 0; i < length; ++i)
        contents[i] = origin.contents[i];
 #if DD_DEBUG >= 1
    std::cout << "DD_Debug: Construction complete. " << std::endl;
    std::cout << "DD_Debug: " << ++object_count << " object(s) in memory." << std::endl;
 #endif
}


DDSTORAGE_MEMBER()::~DDStorage() {
 #if DD_DEBUG >= 1
    std::cout << "DD_Debug: Freeing inventory...";
 #endif
    delete [] contents;
 #if DD_DEBUG >= 1
    std::cout << "Complete." << std::endl;
    std::cout << "DD_Debug: Destruction complete. " << std::endl;
    std::cout << "DD_Debug: " << ++object_count << " object(s) in memory." << std::endl;
 #endif
}


DDSTORAGE_MEMBER(int)::get_length() const {
    return length;
}


DDSTORAGE_MEMBER(bool)::is_empty() const {
    return length == 0;
}


DDSTORAGE_MEMBER(int)::find(const T *target) const {
    for (int i = 0; i < length; ++i)
        if (contents + i == target)
            return i;
    return -1;
}


DDSTORAGE_MEMBER(DDStorage<T>&)::clone(const DDStorage<T> &origin) {
    expand(origin.length - length);
    copy(origin);
    return *this;
}


DDSTORAGE_MEMBER(DDStorage<T>&)::expand(int extra_size) {
    if (extra_size) {
        T *tmp_contents = new T[length += extra_size];
        for (int i = 0; i < length && i < length - extra_size; ++i)
            tmp_contents[i] = contents[i];
        delete [] contents;
        contents = tmp_contents;
    }
    return *this;
}


DDSTORAGE_MEMBER(DDStorage<T>&)::expand(int extra_size, const T &initial_value) {
    if (extra_size) {
        T *tmp_contents = new T[length += extra_size];
        for (int i = 0; i < length && i < length - extra_size; ++i)
            tmp_contents[i] = contents[i];
        delete [] contents;
        contents = tmp_contents;
        for (int i = 1; i <= extra_size; ++i)
            contents[length - i] = initial_value;
    }
    return *this;
}


DDSTORAGE_MEMBER(DDStorage<T>&)::append(const T &element) {
    expand(1, element);
    return *this;
}


DDSTORAGE_MEMBER(DDStorage<T>&)::append(const DDStorage<T> &follower) {
    expand(follower.length);
    copy(follower, length - follower.length);
    return *this;
}


DDSTORAGE_MEMBER(DDStorage<T>&)::copy(const DDStorage<T> &origin, int start_index) {
    for (int i = 0; i < origin.length && i < length - start_index; ++i)
        contents[start_index + i] = origin.contents[i];
    return *this;
}


DDSTORAGE_MEMBER(DDStorage<T>&)::operator =(const DDStorage<T> &origin) {
    return clone(origin);
}


DDSTORAGE_MEMBER(T&)::operator [](int index) {
    if (index >= 0 && index < length)
        return contents[index];
}


DDSTORAGE_MEMBER(const T&)::operator [](int index) const {
    if (index >= 0 && index < length)
        return contents[index];
}


 #if DD_DEBUG >= 1
DDSTORAGE_MEMBER(int)::object_count = 0;


 #endif
 #undef DDSTORAGE_MEMBER
}



#endif