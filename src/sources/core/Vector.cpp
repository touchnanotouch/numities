#include "../../headers/core/Vector.h"


template class Vector<int>;
template class Vector<double>;


template<typename T>
size_t Vector<T>::row_c(

) const {
    return _rows;
}

template<typename T>
T* Vector<T>::vec(

) const {
    return _vec;
}

template<typename T>
bool Vector<T>::set_row_c(
    size_t row_c
) {
    if (row_c == _rows) {
        return false;
    }

    _rows = row_c;

    T* new_vec = new T[_rows];
    for (size_t i = 0; i < _rows; i++) {
        new_vec[i] = _vec[i];
    }

    delete[] _vec;
    _vec = new_vec;

    return true;
}

template<typename T>
bool Vector<T>::set_vec(
    T* vec,
    size_t row_c
) {
    if (row_c > 0) {
        delete[] _vec;
        _rows = row_c;

        _vec = new T[_rows];
        for (size_t i = 0; i < _rows; i++) {
            _vec[i] = vec[i];
        }

        return true;
    }

    return false;
}

template<typename T>
T& Vector<T>::operator[](
    size_t i
) const {
    if (i < 0 || i >= _rows) {
        throw std::out_of_range("Index out of range");
    }

    return _vec[i];
}
