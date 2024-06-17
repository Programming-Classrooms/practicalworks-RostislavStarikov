#include "src/Functions/Functions.hpp"
int main()
{
    try
    {
        setlocale(LC_ALL, "RUS");
        int left, right, rows, cols;
        std::cout << "Введите количество строк матрицы:\t";
        std::cin >> rows;
        std::cout << "Введите число столбцов матрицы:\t\t";
        std::cin >> cols;
        CheckColsAndRows(rows, cols);
        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

        std::cout << "Введите диапазон для заполнения матрицы случайными значениями.\nОт:\t";
        std::cin >> left;
        std::cout << "До\t";
        std::cin >> right;
        CheckInterval(left, right);
        srand(time(NULL));
        FillingMatrix(matrix, left, right);
        Print(matrix);

        std::cout << "Удаление строки и столбца, на пересечении которых стоит максимальный элемент матрицы\n";
        DeleteRowsAndColsWithMaxElement(matrix);
        Print(matrix);

        std::cout << "Сортировка строки матрицы по возрастанию сумм элементов строк\n";
        SortRows(matrix);
        Print(matrix);
    }
    catch (std::exception& e)
    {
        std::cerr << "\nError: " << e.what() << std::endl;
    }



	return 0;
}
