#ifndef LIST_HPP
#define LIST_HPP
#include "src/Product/Product.hpp"
#include <iostream>

class List
{
protected:
    struct Node {
        Product* val;
        Node* next;
    };
    Node* first;

public:
    // Конструкторы
    List(const List&);
    List() { first = nullptr; }
    virtual ~List();
    // Клонирование
    void Clone(const List&);

    // Перегрузка оператора присваивания
    const List& operator=(const List&);

    // Вставка нового элемента в начало списка
    void InsertFirst(const Product&);

    // Bставка нового элемента в конец списка
    void InsertLast(const Product&);

    // Удаление первого элемента списка
    void DeleteFirst();

    // Удаление последнего элемента списка
    void DeleteLast();

    // Удаление элемента по значению
    void DeleteByValue(const Product&);

    // Проверка на пустоту
    bool isEmpty();

    // Поиск элемента по значению с подсчетом числа сравнений, выполненных в процессе поиска
    Node* Search(const Product&, size_t&);
    
    // Просмотр списка с изменением всех значений
    void modifyAllValuse(Product) const;

    // Просмотр списка с вызовом callback-функции
    void viewWitchCallback(void (*callback)(Product)) const;

    // Удаление листа
    void Clear();

    // Отображение содержимого списка
    void display() const;

    // Callback для функции вывода
    void prProductValue(Product) const;
};

#endif
