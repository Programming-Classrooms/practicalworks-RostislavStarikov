#include "src/List/List.hpp"
#include "src/Product/Product.hpp"
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

        // Создание пустого списка
        List list;
        std::cout << "Empty list created." << std::endl;
        list.display();

        // Добавление элементов в конец списка
        Product p1("Milk", 1.5, 2022);
        list.InsertLast(p1);
        std::cout << "\nInserted " << p1.getName() << " at the end of the list. " << std::endl;
        list.display();

        // Копирование списка
        List copiedList(list);
        std::cout << "Copied list created. Copied list: " << std::endl;
        copiedList.display();

        // Присваивание списка
        List assignedList;
        assignedList = list;
        std::cout << "\nAssigned list created." << std::endl;

        // Добавление еще одного продукта в список
        Product p2("Water", 0.75, 2023);
        list.InsertLast(p2);
        std::cout << "\nInserted " << p2.getName() << " at the end of the list." << std::endl;
        list.display();

        // Добавление продукта в начало списка
        Product p3("Bread", 2.0, 2023);
        list.InsertFirst(p3);
        std::cout << "\nInserted " << p3.getName() << " at the beginning of the list. " << std::endl;
        list.display();

        // Удаление первого элемента списка
        list.DeleteFirst();
        std::cout << "\nDeleted the first element from the list. " << std::endl;
        list.display();

        // Удаление последнего элемента списка
        list.DeleteLast();
        std::cout << "\nDeleted the last element from the list. " << std::endl;
        list.display();

        // Удаление продукта из списка
        list.DeleteByValue(p1);
        std::cout << "\nDeleted " << p1.getName() << " from the list. " << std::endl;
        list.display();
    }
    catch (const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
}
