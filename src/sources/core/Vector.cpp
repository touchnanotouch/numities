#include <sstream>
#include <fstream>

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

template <typename T>
Vector<T> Vector<T>::copy(

) const {
    return Vector(_rows, _vec);
}

template<typename T>
bool Vector<T>::set_row_c(
    size_t row_c
) {
    if (row_c == _rows) {
        return false;
    }

    T* new_vec = new T[row_c];
    for (size_t i = 0; i < row_c; i++) {
        if (i < _rows) {
            new_vec[i] = _vec[i];
        } else {
            new_vec[i] = 0;
        }
    }

    delete[] _vec;

    _rows = row_c;
    _vec = new_vec;

    return true;
}

template<typename T>
bool Vector<T>::set_vec(
    size_t row_c,
    T* vec
) {
    if ((row_c > 0) && (vec != _vec)) {
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
bool Vector<T>::set_vec(
    size_t row_c,
    std::string file_path,
    const char delimiter
) {
    T* new_vec = new T[row_c];

    std::ifstream file(file_path);
    std::string line;

    size_t i = 0;
    while (std::getline(file, line)) {
        std::istringstream stream(line);

        T value;
        while (stream >> value) {
            new_vec[i++] = value;

            if (stream.peek() == delimiter) {
                stream.ignore();
            }
        }
    }

    file.close();

    return set_vec(row_c, new_vec);
}

template<typename T>
T& Vector<T>::operator[](
    size_t index
) const {
    if (index < 0 || index >= _rows) {
        throw std::out_of_range("Index out of range");
    }

    return _vec[index];
}

template<typename T>
bool Vector<T>::operator==(
    const Vector& other
) const {
    if (_rows != other._rows) {
        return false;
    }

    const double eps = 1e-9;
    for (size_t i = 0; i < _rows; ++i) {
        if (std::fabs(_vec[i] - other._vec[i]) > eps) {
            return false;
        }
    }

    return true;
}

template<typename T>
Vector<T> Vector<T>::operator+(
    const Vector& other
) const {
    if (_rows != other._rows) {
        throw std::invalid_argument("Unmatching vector sizes");
    }

    Vector<T> result(_rows);
    for (size_t i = 0; i < _rows; i++) {
        result[i] = _vec[i] + other[i];
    }

    return result;
}

template<typename T>
Vector<T> Vector<T>::operator+(
    const T& scalar
) const {
    Vector result(_rows);
    for (size_t i = 0; i < _rows; i++) {
        result[i] = _vec[i] + scalar;
    }

    return result;
}

template<typename T>
Vector<T> Vector<T>::operator+=(
    const Vector& other
) const {
    if (_rows != other._rows) {
        throw std::invalid_argument("Unmatching vector sizes");
    }

    for (size_t i = 0; i < _rows; i++) {
        _vec[i] += other[i];
    }

    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+=(
    const T& scalar
) const {
    for (size_t i = 0; i < _rows; i++) {
        _vec[i] += scalar;
    }

    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator-(
    const Vector& other
) const {
    if (_rows != other._rows) {
        throw std::invalid_argument("Unmatching vector sizes");
    }

    Vector result(_rows);
    for (size_t i = 0; i < _rows; i++) {
        result[i] = _vec[i] - other[i];
    }

    return result;
}

template<typename T>
Vector<T> Vector<T>::operator-(
    const T& scalar
) const {
    Vector result(_rows);
    for (size_t i = 0; i < _rows; i++) {
        result[i] = _vec[i] - scalar;
    }

    return result;
}

template<typename T>
Vector<T> Vector<T>::operator-=(
    const Vector& other
) const {
    if (_rows != other._rows) {
        throw std::invalid_argument("Unmatching vector sizes");
    }

    for (size_t i = 0; i < _rows; i++) {
        _vec[i] -= other[i];
    }

    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator-=(
    const T& scalar
) const {
    for (size_t i = 0; i < _rows; i++) {
        _vec[i] -= scalar;
    }

    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator*(
    const T& scalar
) const {
    Vector result(_rows);
    for (size_t i = 0; i < _rows; i++) {
        result[i] = _vec[i] * scalar;
    }

    return result;
}

template<typename T>
Vector<T> Vector<T>::operator*=(
    const T& scalar
) const {
    for (size_t i = 0; i < _rows; i++) {
        _vec[i] *= scalar;
    }

    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator/(
    const T& scalar
) const {
    Vector result(_rows);
    for (size_t i = 0; i < _rows; i++) {
        result[i] = _vec[i] / scalar;
    }

    return result;
}

template<typename T>
Vector<T> Vector<T>::operator/=(
    const T& scalar
) const {
    for (size_t i = 0; i < _rows; i++) {
        _vec[i] /= scalar;
    }

    return *this;
}

template<typename T>
T Vector<T>::dot(
    const Vector<T>& other
) const {
    T result = 0;
    for (size_t i = 0; i < _rows; i++) {
        result += _vec[i] * other._vec[i];
    }

    return result;
}

template<typename T>
double Vector<T>::norm(
    int p
) const {
    double result = 0.0;

    switch (p) {
        case 1: {
            for (size_t i = 0; i < _rows; i++) {
                result += std::abs(_vec[i]);
            }
            break;
        }
        case 2: {
            result += std::sqrt(dot(*this));
            break;
        }
        default: {
            for (size_t i = 0; i < _rows; i++) {
                result += std::pow(std::abs(_vec[i]), p);
            }
            result = std::pow(result, 1.0 / p);
            break;
        }
    }

    return result;
}

template <typename T>
void Vector<T>::normalize(

) {
    *this /= norm(2);
}

template<typename T>
Vector<T> Vector<T>::normalized(
) const {
    return copy() / norm(2);
}
