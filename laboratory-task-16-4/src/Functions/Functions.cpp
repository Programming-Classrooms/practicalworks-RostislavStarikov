#include "Functions.hpp"

void CheckColsAndRows(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        throw std::invalid_argument("Неверные данные для создания матрицы!!!\n");
    }
}

void CheckInterval(int left, int right)
{
    if (left >= right) throw std::runtime_error("Ошибка: некорректный интервал!");

}

void FillingMatrix(std::vector<std::vector<int>>& matrix, int left, int right)
{
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = rand() % (right - left + 1) + left;
        }
    }
}

void Print(const std::vector<std::vector<int>> matrix)
{
    std::cout << "\n=======================================\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << '\n';
    }
    std::cout << "=======================================\n";
}

void DeleteRowsAndColsWithMaxElement(std::vector<std::vector<int>>& matrix)
{
    int maxElement = matrix[0][0];
    size_t maxRow = 0, maxCol = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    std::cout << "Максимальный элемент матрицы -\t" << matrix[maxCol][maxRow];
    matrix.erase(matrix.begin() + maxRow);
    for (auto& row : matrix) {
        row.erase(row.begin() + maxCol);
    }
}

int CheckSum(const std::vector<std::vector<int>> matrix, size_t rows)
{
    int sum = 0;
    for (size_t i = 0; i < matrix[rows].size(); ++i)
    {
        sum += matrix[rows][i];
    }
    return sum;
}

void SortRows(std::vector<std::vector<int>>& matrix) {
    size_t numRows = matrix.size();
    for (size_t i = 0; i < numRows - 1; ++i) {
        for (size_t j = 0; j < numRows - i - 1; ++j) {
            int sum1 = CheckSum(matrix, j);
            int sum2 = CheckSum(matrix, j + 1);
            if (sum1 > sum2) {
                std::swap(matrix[j], matrix[j + 1]);
            }
        }
    }
}