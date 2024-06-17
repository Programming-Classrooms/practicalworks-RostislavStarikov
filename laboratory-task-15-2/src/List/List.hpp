
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdint.h>

#include "../Product/Product.hpp"

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

    // Оператор []
    Product& operator[](size_t);

    // Вставка нового элемента по индексу
    void InsertByIndex(const Product&, size_t);

    // Удаление элемента по индексу
    void DeleteByIndex(size_t);

    // Удаление элемента по значению
    void DeleteByValue(const Product&);
    
    // метод, выводящий содержимое списка от первого до последнего элемента в указанный поток
    std::ostream& OutputStream(std::ostream&);

    // сортировка списка по возрастанию или убыванию
    void Sort();

    // Проверка на пустоту
    bool isEmpty();

    // Просмотр списка с изменением всех значений
    void modifyAllValuse(Product) const;

    // Удаление листа
    void Clear();

    // Отображение содержимого списка
    friend std::ostream& operator<<(std::ostream&, List&);
};

#endif