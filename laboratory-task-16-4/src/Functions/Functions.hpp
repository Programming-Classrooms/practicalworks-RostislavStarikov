#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
// Проверка введенных значений
void CheckColsAndRows(int, int);
void CheckInterval(int, int);
// Заполнение матрицы
void FillingMatrix(std::vector<std::vector<int>>&, int, int);
// Вывод матрицы в консоль
void Print(const std::vector<std::vector<int>>);
// Удаление строки и столбца матрицы, содержащий максимальный элемент
void DeleteRowsAndColsWithMaxElement(std::vector<std::vector<int>>&);
// Вычисление суммы элементов в строке
int CheckSum(const std::vector<std::vector<int>>, size_t);
// Сортировка строк согласно сумме элементов строки
void SortRows(std::vector<std::vector<int>>&);
#endif
