#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
//#include <stdexcept>
class Matrix
{
private:
	size_t line;
	size_t column;
	double** mtrx;

	// Функция для вычисления элемента результирующей матрицы после умножения
	friend double multiplication(const Matrix&, const Matrix&, size_t, size_t);
public:
	// Конструктор по умолчанию
	Matrix();
	// Конструктор с параметрами
	Matrix(size_t, size_t);
	// Конструктор копирования
	Matrix(const Matrix&);
	// Деструктор
	~Matrix();

	// Оператор присваивания
	Matrix& operator=(const Matrix&);

	// Составные операторы присваивания
	Matrix operator*=(const int32_t);
	friend Matrix operator*=(const int32_t, Matrix&);
	Matrix operator*=(const double);
	friend Matrix operator*=(const double, Matrix&);
	Matrix operator/=(const int32_t);
	Matrix operator/=(const double);
	Matrix operator+=(const Matrix&);
	Matrix operator-=(const Matrix&);

	// Операторы умножения
	Matrix operator*(const int32_t) const;
	friend Matrix operator*(const int32_t, const Matrix&);
	Matrix operator*(const double) const;
	friend Matrix operator*(const double, const Matrix&);
	Matrix operator*(const Matrix&) const;

	// Операторы деления матрицы на число
	Matrix operator/(const int32_t) const;
	Matrix operator/(const double) const;

	// Сравнение матриц на равенство и неравенство
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;

	// Сложение матриц
	Matrix operator+(const Matrix&);

	// Вычитание матриц
	Matrix operator-(const Matrix&);

	// Ввод и вывод матрицы
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);

};


#endif // !MATRIX_H
