#include <sstream>
#include <fstream>

#include "../../headers/core/Matrix.h"


template class Matrix<int>;
template class Matrix<double>;


template<typename T>
size_t Matrix<T>::row_c(

) const {
    return _rows;
}

template<typename T>
size_t Matrix<T>::col_c(

) const {
    return _cols;
}

template<typename T>
T** Matrix<T>::mat(

) const {
    return _mat;
}

template<typename T>
Matrix<T> Matrix<T>::copy(

) const {
    return Matrix(_rows, _cols, _mat);
}

template<typename T>
bool Matrix<T>::set_row_c(
    size_t row_c
) {
    if (row_c == _rows) {
        return false;
    }

    T** new_mat = new T*[row_c];
    for (size_t i = 0; i < row_c; i++) {
        new_mat[i] = new T[_cols];
        for (size_t j = 0; j < _cols; j++) {
            if (i < _rows) {
                new_mat[i][j] = _mat[i][j];
            } else {
                new_mat[i][j] = 0;
            }
        }
    }

    for (size_t i = row_c; i < _rows; i++) {
        delete[] _mat[i];
    }
    delete[] _mat;

    _rows = row_c;
    _mat = new_mat;

    return true;
}

template<typename T>
bool Matrix<T>::set_col_c(
    size_t col_c
) {
    if (col_c == _cols) {
        return false;
    }

    T** new_mat = new T*[_rows];
    for (size_t i = 0; i < _rows; i++) {
        new_mat[i] = new T[col_c];
        for (size_t j = 0; j < col_c; j++) {
            if (j < _cols) {
                new_mat[i][j] = _mat[i][j];
            } else {
                new_mat[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < _rows; i++) {
        delete[] _mat[i];
    }
    delete[] _mat;

    _cols = col_c;
    _mat = new_mat;

    return true;
}

template<typename T>
bool Matrix<T>::set_mat(
    size_t row_c,
    size_t col_c,
    T** mat
) {
    if (row_c > 0 && col_c > 0 && mat != _mat) {
        for (size_t i = 0; i < _rows; i++) {
            delete[] _mat[i];
        }
        delete[] _mat;

        _rows = row_c;
        _cols = col_c;

        _mat = new T*[_rows];
        for (size_t i = 0; i < _rows; i++) {
            _mat[i] = new T[_cols];
            for (size_t j = 0; j < _cols; j++) {
                _mat[i][j] = mat[i][j];
            }
        }

        return true;
    }

    return false;
}

template<typename T>
bool Matrix<T>::set_mat(
    size_t row_c,
    size_t col_c,
    std::string file_path,
    const char delimiter
) {
    T** new_mat = new T*[row_c];
    for (size_t i = 0; i < row_c; i++) {
        new_mat[i] = new T[col_c];
    }

    std::ifstream file(file_path);
    std::string line;

    size_t i = 0;
    while (std::getline(file, line)) {
        std::istringstream stream(line);

        size_t j = 0;

        T value;
        while (stream >> value) {
            new_mat[i][j++] = value;

            if (stream.peek() == delimiter) {
                stream.ignore();
            }
        }

        i++;
    }

    file.close();

    return set_mat(row_c, col_c, new_mat);
}

template<typename T>
T*& Matrix<T>::operator[](
    size_t index
) const {
    if (index < 0 || index >= _rows || index >= _cols) {
        throw std::out_of_range("Index out of range");
    }

    return _mat[index];
}

template<typename T>
bool Matrix<T>::operator==(
    const Matrix& other
) const {
    if (_rows != other._rows || _cols != other._cols) {
        return false;
    }

    const double eps = 1e-9;
    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < _cols; ++j) {
            if (std::fabs(_mat[i][j] - other._mat[i][j]) > eps) {
                return false;
            }
        }
    }

    return true;
}
