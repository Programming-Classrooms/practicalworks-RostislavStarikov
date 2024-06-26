#include "Matrix.hpp"

/*=============================================================================*/
/*==============================Конструкторы===================================*/
/*=============================================================================*/

Matrix::Matrix() : line(0), column(0), mtrx(nullptr)
{}
Matrix::Matrix(size_t initLine, size_t initColumn) : line(initLine), column(initColumn), mtrx(nullptr)
{
    mtrx = new double* [initLine];

    for (int i = 0; i < initLine; ++i)
    {
        mtrx[i] = new double[initColumn];
    }

    for (size_t i = 0; i < initLine; ++i)
    {
        for (size_t j = 0; j < initColumn; ++j)
        {
            mtrx[i][j] = 0;
        }
    }
}
Matrix::Matrix(const Matrix& rhs)
{
    this->column = rhs.column;
    this->line = rhs.line;
    this->mtrx = new double* [line];

    for (size_t i = 0; i < line; ++i)
    {
        mtrx[i] = new double[column];
    }

    for (size_t i = 0; i < line; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            mtrx[i][j] = rhs.mtrx[i][j];
        }
    }
}
Matrix::~Matrix()
{
    for (size_t i = 0; i < line; ++i)
    {
        delete[] mtrx[i];
    }
    delete[] mtrx;
}

/*=============================================================================*/
/*============================Оператор присваивания ===========================*/
/*=============================================================================*/

Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (this == &rhs) return *this;
    if (this->line != rhs.line || this->column != rhs.column) throw std::invalid_argument("Matrix sizes do not match");
    for (size_t i = 0; i < line; ++i)
    {
        mtrx[i] = new double[column];
    }

    for (size_t i = 0; i < line; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            mtrx[i][j] = rhs.mtrx[i][j];
        }
    }
    return *this;
}

/*=============================================================================*/
/*==========================Составные операторы присваивания===================*/
/*=============================================================================*/

Matrix Matrix::operator*=(const int32_t rhs)
{
    *this = (*this * rhs);
    return *this;
}
Matrix operator*=(const int32_t lhs, Matrix& rhs)
{
    rhs = lhs * rhs;
    return rhs;
}
Matrix Matrix::operator*=(const double rhs)
{
    *this = (*this * rhs);
    return *this;
}
Matrix operator*=(const double lhs, Matrix& rhs)
{
    rhs = lhs * rhs;
    return rhs;
}
Matrix Matrix::operator/=(const int32_t rhs)
{
    *this = (*this / rhs);
    return *this;
}
Matrix Matrix::operator/=(const double rhs)
{
    *this = (*this / rhs);
    return *this;
}
Matrix Matrix::operator+=(const Matrix& rhs)
{
    *this = *this + rhs;
    return *this;
}
Matrix Matrix::operator-=(const Matrix& rhs)
{
    *this = *this - rhs;
    return *this;
}

/*=============================================================================*/
/*========================Операторы умножения==================================*/
/*=============================================================================*/

Matrix Matrix::operator*(const int32_t rhs) const
{
    for (int32_t i = 0; i < this->line; ++i)
    {
        for (int32_t j = 0; j < this->column; ++j)
        {
            this->mtrx[i][j] *= rhs;
        }
    }
    return *this;
}
Matrix operator*(const int32_t lhs, const Matrix& rhs)
{
    return rhs * lhs;
}
Matrix Matrix::operator*(const double rhs) const
{
    for (int32_t i = 0; i < this->line; ++i)
    {
        for (int32_t j = 0; j < this->column; ++j)
        {
            this->mtrx[i][j] *= rhs;
        }
    }
    return *this;
}
Matrix operator*(const double lhs, const Matrix& rhs)
{
    return rhs * lhs;
}
Matrix Matrix::operator*(const Matrix& rhs) const
{

    if (this->column != rhs.line) throw std::runtime_error("The number of columns in the first factor is not equal to the number of rows in the second");
    Matrix result(this->line, rhs.column);
    for (size_t i = 0; i < result.line; ++i)
    {
        for (size_t j = 0; j < result.column; ++j)
        {
            result.mtrx[i][j] = 0;
            for (size_t k = 0; k < this->column; ++k)
            {
                result.mtrx[i][j] += this->mtrx[i][k] * rhs.mtrx[k][j]; 
            }
        }
    }
    return result;
}

/*=============================================================================*/
/*========================Операторы деления====================================*/
/*=============================================================================*/

Matrix Matrix::operator/(const int32_t rhs) const
{
    if (rhs == 0) throw std::invalid_argument("Division by zero!!!");
    for (int32_t i = 0; i < this->line; ++i)
    {
        for (int32_t j = 0; j < this->column; ++j)
        {
            this->mtrx[i][j] /= rhs;
        }
    }
    return *this;
}
Matrix Matrix::operator/(const double rhs) const
{
    if (rhs == 0) throw std::invalid_argument("Division by zero!!!");
    for (int32_t i = 0; i < this->line; ++i)
    {
        for (int32_t j = 0; j < this->column; ++j)
        {
            this->mtrx[i][j] /= rhs;
        }
    }
    return *this;
}

/*=============================================================================*/
/*================Сравнение матриц на равенство и неравенство==================*/
/*=============================================================================*/
bool Matrix::operator==(const Matrix& rhs) const
{
    if (this->column != rhs.column || this->line != rhs.line) throw std::invalid_argument("Matrix sizes do not match");
    for (size_t i = 0; i < rhs.line; ++i)
    {
        for (size_t j = 0; j < rhs.column; ++j)
        {
            if (this->mtrx[i][j] != rhs.mtrx[i][j]) return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& rhs) const
{
    return !(*this == rhs);
}

/*=============================================================================*/
/*=======================Сложение матриц=======================================*/
/*=============================================================================*/

Matrix Matrix::operator+(const Matrix& rhs)
{
    if (this->column != rhs.column || this->line != rhs.line) throw std::invalid_argument("Matrix sizes do not match");
    for (size_t i = 0; i < this->line; ++i)
    {
        for (size_t j = 0; j < this->column; ++j)
        {
            this->mtrx[i][j] += rhs.mtrx[i][j];
        }
    }
    return *this;
}

/*=============================================================================*/
/*=======================Вычитание матриц======================================*/
/*=============================================================================*/

Matrix Matrix::operator-(const Matrix& rhs)
{
    if (this->column != rhs.column || this->line != rhs.line) throw std::invalid_argument("Matrix sizes do not match");
    for (size_t i = 0; i < this->line; ++i)
    {
        for (size_t j = 0; j < this->column; ++j)
        {
            this->mtrx[i][j] -= rhs.mtrx[i][j];
        }
    }
    return *this;
}

/*================================================================================*/
/*====================== Функция нахождения миноров матрицы ======================*/
/*================================================================================*/

Matrix Matrix::getMatrixMinor(const Matrix& original, size_t row, size_t col) 
{
    Matrix newMatrix(original.line - 1, original.column - 1);

    size_t offsetRow = 0; 

    for (size_t i = 0; i < original.line - 1; ++i) 
    {
        if (i == row) offsetRow = 1;
    
        size_t offsetCol = 0;
    
        for (size_t j = 0; j < original.column - 1; ++j) 
        {
            if (j == col) offsetCol = 1;
            newMatrix.mtrx[i][j] = original.mtrx[i + offsetRow][j + offsetCol];
        }
    }
    return newMatrix;
}

/*================================================================================*/
/*======================== Функция нахождения определителя =======================*/
/*================================================================================*/

double Matrix::matrixDet(const Matrix& original, size_t size) {
    if (size == 1) return original.mtrx[0][0];
    if (size == 2) return original.mtrx[0][0] * original.mtrx[1][1] - original.mtrx[0][1] * original.mtrx[1][0];

    double det = 0;
    int degree = 1;

    for (size_t j = 0; j < size; ++j) 
    {
        Matrix newMatrix = getMatrixMinor(original, 0, j);
        det += degree * original.mtrx[0][j] * matrixDet(newMatrix, size - 1);
        degree *= -1;
    }

    return det;
}

/*================================================================================*/
/*================= Оболочка для функции нахождения определителя =================*/
/*================================================================================*/

double Matrix::det()
{
    if (this->column != this->line) throw std::runtime_error("Error when calculating the determinant! The matrix is ​​not square!!!");
    Matrix temp(*this);
    return matrixDet(temp,temp.column);
}

/*=============================================================================*/
/*========================Ввод и вывод матрицы=================================*/
/*=============================================================================*/

std::ostream& operator<<(std::ostream& out, const Matrix& rhs)
{
    out << '\n';
    for (size_t i = 0; i < rhs.line; ++i)
    {
        for (size_t j = 0; j < rhs.column; ++j)
        {
            out << rhs.mtrx[i][j] << '\t';
        }
        out << '\n';
    }
    return out;
}
std::istream& operator>>(std::istream& in, Matrix& obj)
{
    for (size_t i = 0; i < obj.line; ++i)
    {
        for (size_t j = 0; j < obj.column; ++j)
            in >> obj.mtrx[i][j];
    }
    return in;
}
