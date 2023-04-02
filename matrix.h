#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"

class Matrix
{
    public:
        Matrix();
        Matrix(int n);
        ~Matrix();

        void input();
        void print();

        number determinant();
        int rank();
        Matrix transpose();

        Matrix & operator = (const Matrix &other);
    protected:
        int size;
        number **elements;
    private:
};

#endif // MATRIX_H
