#include "Matrix.hpp"

// Matrix constructor
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    this->arr = new int[rows * cols];

    for (int i = 0; i < rows * cols; i++)
    {
        this->arr[i] = 0;
    }
}   

// Matrix destructor
Matrix::~Matrix()
{
    delete[] this->arr;
}

// Getter method for rows
int Matrix::get_rows() const
{
    return this->rows;
}

// Getter method for columns
int Matrix::get_cols() const
{
    return this->cols;
}

// [] Operator overloading
int* Matrix::operator[](int index)
{
    return this->arr + index * this->cols;
}