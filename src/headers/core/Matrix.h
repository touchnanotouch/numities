#pragma once

#include <iostream>


template<typename T>
class Matrix {
    private:
        size_t _rows;
        size_t _cols;
        T** _mat;
};
