#include "src/Fraction/Fraction.hpp"
#include "src/Matrix/Matrix.hpp"
int main() {
    try
    {
        // Создаем объекты дробей
        Fraction f1(1, 2);
        Fraction f2(3, 4);

        // Выполняем операции с дробями
        Fraction f3 = f1 + f2;
        Fraction f4 = f1 - f2;
        Fraction f5 = f1 * f2;
        Fraction f6 = f1 / f2;

        // Выводим результаты операций
        std::cout << "f1 = " << f1 << std::endl;
        std::cout << "f2 = " << f2 << std::endl;
        std::cout << "f1 + f2 = " << f3.toDouble() << std::endl;
        std::cout << "f1 - f2 = " << f4.toDouble() << std::endl;
        std::cout << "f1 * f2 = " << f5.toDouble() << std::endl;
        std::cout << "f1 / f2 = " << f6.toDouble() << std::endl;

        // Проверка операций сравнения
        if (f1 > f2) {
            std::cout << "f1 > f2" << std::endl;
        }
        else {
            std::cout << "f1 <= f2" << std::endl;
        }

        ///*==========================================================================================*/
        Matrix A(2, 2); // Создание матрицы A размером 2x2
        Matrix B(2, 2); // Создание матрицы B размером 2x2


        // Заполнение матрицы A
        std::cout << "Enter elements of matrix A:" << std::endl;
        std::cin >> A;

        // Заполнение матрицы B
        std::cout << "Enter elements of matrix B:" << std::endl;
        std::cin >> B;

        // Операция сложения матриц
        std::cout << "Matrix A + Matrix B:" << A + B << std::endl;

        // Операция умножения матриц
        std::cout << "Matrix A * Matrix B:" << A * B << std::endl;

        //// Операция вычитания матриц
        std::cout << "Matrix A - Matrix B:" << A - B << std::endl;

        ///*====================================================================================*/
    }
    catch (const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
}