#include<iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix() //ctor
{
    size = 3;
    elements = new number*[size];

    for (int i = 0; i < size; i++)
    {
        elements[i] = new number[size];
        for (int j = 0; j < size; j++)
        {
            elements[i][j] = size * i + j;
        }
    }
}

Matrix::Matrix(int n) //ctor
{
    this->size = n;
    elements = new number*[this->size];

    for (int i = 0; i < this->size; i++)
    {
        elements[i] = new number[this->size];
        for (int j = 0; j < this->size; j++)
        {
            elements[i][j] = this->size * i + j;
        }
    }
}

Matrix::~Matrix() //dtor
{
    for (int i = 0; i < size; i++)
    {
        delete[] elements[i];
    }
    delete[] elements;
}

Matrix & Matrix::operator = (const Matrix &other)
{
    for (int i = 0; i < this->size; i++)
    {
        delete[] elements[i];
    }
    delete[] elements;

    this->size = other.size;

    this->elements = new number*[other.size];

    for (int i = 0; i < other.size; i++)
    {
        this->elements[i] = new number[other.size];
        for (int j = 0; j < other.size; j++)
        {
            this->elements[i][j] = other.elements[i][j];
        }
    }
    return *this;
}

void Matrix::input()
{
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> elements[i][j];
        }
    }
}

void Matrix::print()
{
    cout << "Matrix:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << elements[i][j] << " ";
        }
        cout << "\n";
    }
}

Matrix Matrix::transpose()
{
    Matrix transposeMatrix(this->size);
    transposeMatrix = *this;
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            transposeMatrix.elements[i][j] = this->elements[j][i];
        }
    }

    return transposeMatrix;
}

number Matrix::determinant()
{
    if (size == 1)
    {
        return elements[0][0];
    }
    else
    {
        Matrix temp(this->size);
        temp = *this;
        number det = 1;

        for (int i = 0; i < size; i++)
        {
            if (temp.elements[i][i] == 0)
            {
                int j;
                for (j = i + 1; j < size && temp.elements[j][i] == 0; j++) {}
                if (j == size)
                {
                    return 0;
                }
                swap(temp.elements[i], temp.elements[j]);
                det *= -1;
            }

            for (int j = i + 1; j < size; j++)
            {
                number deleter = temp.elements[j][i] / temp.elements[i][i];
                for (int k = i; k < size; k++)
                {
                    temp.elements[j][k] -= deleter * temp.elements[i][k];
                }
            }

            det *= temp.elements[i][i];
        }

        return det;
    }
}

int Matrix::rank()
{
    Matrix temp(this->size);
    temp = *this;

    int rank = 0;

    for (int i = 0; i < size; i++) {
        if (temp.elements[i][i] == 0) {
            int j;
            for (j = i + 1; j < size && temp.elements[j][i] == 0; j++) {}
            if (j == size) {
                continue;
            }
            swap(temp.elements[i], temp.elements[j]);
        }

        for (int j = i + 1; j < size; j++) {
            number deleter = temp.elements[j][i] / temp.elements[i][i];
            for (int k = i; k < size; k++) {
                temp.elements[j][k] -= deleter * temp.elements[i][k];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        bool nonzero = false;
        for (int j = 0; j < size; j++) {
            if (temp.elements[i][j] != 0) {
                nonzero = true;
                break;
            }
        }
        if (nonzero) {
            rank++;
        }
    }

    return rank;
}
