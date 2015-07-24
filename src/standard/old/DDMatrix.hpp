// DDMatrix.hpp
#ifndef _DDMATRIX_
 #define _DDMATRIX_



 #include <DDGlobal.hpp>



 #define DDMATRIX_MEMBER(...) template <typename ValueT, LengthType HeightT, LengthType WidthT> __VA_ARGS__ DDMatrix<ValueT, HeightT, WidthT>



DD_BEGIN
template <typename ValueT, LengthType HeightT, LengthType WidthT>
class DDMatrix;


template <typename ValueT, LengthType HeightT, LengthType WidthT>
class DDMatrix {
    public:
    using ValueType = ValueT;
    
    public:
    DDMatrix();
    ~DDMatrix() noexcept;
    DDMatrix<ValueT, WidthT, HeightT> transpose() const;
    
    public:
    ValueT& operator ()(SubscriptType i, SubscriptType j);
    const ValueT& operator ()(SubscriptType i, SubscriptType j) const;
    
    private:
    SubscriptType& check_i(SubscriptType& i) const;
    SubscriptType& check_j(SubscriptType& j) const;
    
    private:
    ValueT m_content[HeightT][WidthT];
    
};


DD_END



DD_BEGIN
DDMATRIX_MEMBER(inline)::DDMatrix() : m_content{} {
}


DDMATRIX_MEMBER(inline)::~DDMatrix() noexcept {
}


DDMATRIX_MEMBER(DDMatrix<ValueT, WidthT, HeightT>)::transpose() const {
    DDMatrix<ValueT, WidthT, HeightT> tmp_matrix;
    for (auto i = 0; i < HeightT; ++i) {
        for (auto j = 0; j < WidthT; ++j) {
            tmp_matrix(j, i) = m_content[i][j];
        }
    }
    return tmp_matrix;
}


DDMATRIX_MEMBER(inline ValueT&)::operator ()(SubscriptType i, SubscriptType j) {
    return this->m_content[this->check_i(i)][this->check_j(j)];
}

DDMATRIX_MEMBER(inline const ValueT&)::operator ()(SubscriptType i, SubscriptType j) const {
    return this->m_content[this->check_i(i)][this->check_j(j)];
}


DDMATRIX_MEMBER(inline SubscriptType&)::check_i(SubscriptType& i) const {
    // to fill
    return i;
}


DDMATRIX_MEMBER(inline SubscriptType&)::check_j(SubscriptType& j) const {
    // to fill
    return j;
}


DD_END



#endif
/*
#include <iostream>
int main() {
    DD::DDMatrix<int, 3 ,2> a;
    std::cout << a(2, 1);
}
*/