#include <iostream>

#include "../Product/Product.hpp"
#include "src/List/List.hpp"

int main() {
    try
    {
    // Создаем объекты Product
    Product p1("Product1", 10.0, 2021);
    Product p2("Product2", 5.0, 2022);
    Product p3("Product3", 15.0, 2023);
    Product p4("Product4", 7., 2024);

    // Создаем список и вставляем элементы
    List myList;
    myList.InsertByIndex(p1, 0);
    myList.InsertByIndex(p2, 1);
    myList.InsertByIndex(p3, 2);
    myList.InsertByIndex(p4, 3);

    // Отображаем список
    std::cout << "Original List: " << std::endl;
    std::cout << myList;

    // Проверка клонирования
    List clonedList(myList);
    std::cout << "Cloned List: " << std::endl;
    std::cout << clonedList;

    // Проверка удаления по индексу
    myList.DeleteByIndex(1);
    std::cout << "List after deleting index 1: " << std::endl;
    std::cout << myList;

    // Проверка удаления по значению
    myList.DeleteByValue(p3);
    std::cout << "List after deleting Product3: " << std::endl;
    std::cout << myList;

    // Проверка изменения всех значений
    Product newProduct("ModifiedProduct", 20.0, 2025);
    myList.modifyAllValuse(newProduct);
    std::cout << "List after modifying all values: " << std::endl;
    std::cout << myList;

    // Проверка сортировки
    myList.InsertByIndex(p1, 0);
    myList.InsertByIndex(p2, 1);
    myList.InsertByIndex(p3, 2);
    myList.InsertByIndex(p4, 3);
    myList.Sort();
    std::cout << "Sorted List: " << std::endl;
    std::cout << myList;

    // Проверка оператора присваивания
    List assignedList;
    assignedList = myList;
    std::cout << "Assigned List: " << std::endl;
    std::cout << assignedList;
}
catch(std::exception& err)
{
    std::cerr << err.what() << '\n';
}
    return 0;
}
