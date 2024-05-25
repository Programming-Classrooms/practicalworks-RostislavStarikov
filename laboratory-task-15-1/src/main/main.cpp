#include "src/TDeque/TDeque.hpp"

#include <iostream>

void printElement(int element) {
    std::cout << element << " ";
}

void modifyElement(int& element) {
    element *= 2; // Пример модификации элемента: умножение на 2
}

int main() 
{
    try
    {

        TDeque<int> deque;

        // Вставка элементов в голову и хвост дека
        std::cout << "Insert elements at the front and rear of deque:\n";
        deque.InsertFront(1);
        deque.InsertRear(2);
        deque.InsertFront(0);
        deque.InsertRear(3);

        // Просмотр всех элементов дека
        std::cout << "Deque elements: ";
        deque.Browse(printElement);

        // Исключение элементов из головы и хвоста дека
        int temp;
        deque.DeleteFront(temp);
        std::cout << "\nDeleted front: " << temp;

        deque.DeleteRear(temp);
        std::cout << "\nDeleted rear: " << temp;

        // Просмотр всех элементов дека после удалений
        std::cout << "\nDeque elements after deletions: ";
        deque.Browse(printElement);

        // Получение элемента по индексу
        std::cout << "\nElement at index 0: " << deque.GetByIndex(0);

        // Изменение элемента по индексу
        deque.SetByIndex(5, 0);
        std::cout << "\nElement at index 0 after modification: " << deque.GetByIndex(0);

        // Модификация всех элементов дека
        std::cout << "\nModifying all elements in the deque:\n";
        deque.Browse(modifyElement);
        deque.Browse(printElement);
        std::cout << std::endl;

        // Создание копии дека
        TDeque<int> copiedDeque = deque;
        std::cout << "Copied deque elements: ";
        copiedDeque.Browse(printElement);
        std::cout << std::endl;

    }
    catch (std::exception& err)
    {
        std::cerr << err.what() << '\n';
    }
    return 0;
}